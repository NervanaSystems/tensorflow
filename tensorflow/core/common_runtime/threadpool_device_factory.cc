/* Copyright 2015 The TensorFlow Authors. All Rights Reserved.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
==============================================================================*/

// Register a factory that provides CPU devices.
#include "tensorflow/core/common_runtime/threadpool_device.h"

#include <vector>
#include "tensorflow/core/common_runtime/device_factory.h"
#include "tensorflow/core/framework/allocator.h"
#include "tensorflow/core/lib/io/path.h"
#include "tensorflow/core/public/session_options.h"

namespace tensorflow {

// TODO(zhifengc/tucker): Figure out the bytes of available RAM.
class ThreadPoolDeviceFactory : public DeviceFactory {
 public:
  Status CreateDevices(const SessionOptions& options, const string& name_prefix,
                       std::vector<Device*>* devices) override {
    // TODO(zhifengc/tucker): Figure out the number of available CPUs
    // and/or NUMA configuration.
    int n = 1;
    auto iter = options.config.device_count().find("CPU");
    if (iter != options.config.device_count().end()) {
      n = iter->second;
    }
    for (int i = 0; i < n; i++) {
      string name = strings::StrCat(name_prefix, "/device:CPU:", i);
      devices->push_back(new ThreadPoolDevice(
          options, name, Bytes(256 << 20), DeviceLocality(), cpu_allocator()));
    }

    return Status::OK();
  }
};

REGISTER_LOCAL_DEVICE_FACTORY("CPU", ThreadPoolDeviceFactory, 60);

#if defined(INTEL_NGRAPH)
string GetTensorflowRoot() {
  string executable_path = Env::Default()->GetExecutablePath();

  // Check to see if this is a Python executable
  auto executable_name = io::Basename(executable_path);
  VLOG(1) << "Executable: " << executable_name;

  if (std::string(executable_name)
          .compare(0, std::string("python").length(), "python") == 0) {
    // if (!StringPiece(str_util::Lowercase(executable_name)).find("python")) {
    VLOG(1) << "TensorFlow is loaded from Python" << std::endl;
    // Now run the executable and get the Python Site Packages
    FILE* pipe =
        popen((executable_path + " -c \"from distutils.sysconfig import "
                                 "get_python_lib; print(get_python_lib())\"")
                  .c_str(),
              "r");
    if (!pipe) {
      LOG(FATAL) << "Couldn't launch program: " << executable_path;
    }

    char buffer[256];
    int len = 0;
    string python_site_pkg_dir;
    while (fgets(buffer, sizeof(buffer), pipe) != nullptr) {
      len += sizeof(buffer);
      if (len > PATH_MAX) {
        // Python path too long - something is wrong
        LOG(FATAL) << "Path too long. Abort";
      }
      python_site_pkg_dir += buffer;
    }

    str_util::StripTrailingWhitespace(&python_site_pkg_dir);
    string tf_install_root = python_site_pkg_dir + "/tensorflow";
    return tf_install_root;
  }

  // We are getting loaded by a C++ app?
  return executable_path;
}  // namespace tensorflow

bool InitNGraph() {
  // Locate the nGraph device
  auto tf_root_dir = GetTensorflowRoot();

  // Load it
  string lib_path(
      "/localdisk/avijitch/projects/upstream/tf-fork/lib/python2.7/"
      "site-packages/tensorflow/libngraph_device.so");
  VLOG(1) << "Loading file: " << lib_path;
  void* handle;
  auto result = Env::Default()->LoadLibrary(lib_path.c_str(), &handle);
  if (result != Status::OK()) {
    VLOG(1) << "Cannot load Plugin library: " << result.error_message();
    return false;
  }
}

volatile bool ngraph_initialized = InitNGraph();
#endif
}  // namespace tensorflow
