licenses(["notice"])  # 3-Clause BSD

exports_files(["license.txt"])

filegroup(
    name = "LICENSE",
    srcs = [
        "license.txt",
    ],
    visibility = ["//visibility:public"],
)

# cc_library(
#     name = "mkl_headers",
#     srcs = glob(["include/*"]),
#     includes = ["include"],
#     visibility = ["//visibility:public"],
# )

cc_library(
    name = "ngraph_libs_linux",
    srcs = [
        "lib/libiomp5.so",
        "lib/libmklml_intel.so",
    ],
    visibility = ["//visibility:public"],
)


cc_library(
    name = "ngraph_tf",
    srcs = 
    [
        "src/ngraph_utils.cc",
        "src/ngraph_utils.h",
        "src/tf_graphcycles.cc",
        "logging/ngraph_log.h",
        "logging/ngraph_log.cc",
        "logging/tf_graph_writer.h",
        "logging/tf_graph_writer.cc",
    ],
    hdrs = [
        "src/tf_graphcycles.h"
    ],
    deps = [
        "@org_tensorflow//tensorflow/core:core_cpu",
        "@org_tensorflow//tensorflow/core:framework_headers_lib",
        "@org_tensorflow//tensorflow/core:protos_all_proto_text",
        "@ngraph//:ngraph_headers"
    ],
    copts = [
        "-I external/ngraph_tf/src",
        "-I external/ngraph_tf/logging",
        "-I external/ngraph/src",
    ],
    visibility = ["//visibility:public"],
    alwayslink=1
)
