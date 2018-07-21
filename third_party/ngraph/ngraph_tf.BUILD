licenses(["notice"])  # 3-Clause BSD

exports_files(["license.txt"])

filegroup(
    name = "LICENSE",
    srcs = [
        "license.txt",
    ],
    visibility = ["//visibility:public"],
)

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
        "src/ngraph_builder.h",
        "src/ngraph_builder.cc",
        "src/ngraph_cluster.h",
        "src/ngraph_cluster.cc",
        "src/ngraph_cluster_manager.h",
        "src/ngraph_cluster_manager.cc",
        "src/ngraph_device.cc",
        "src/ngraph_encapsulate_op.cc",
        "src/ngraph_encapsulate_pass.cc",
        "src/ngraph_freshness_tracker.h",
        "src/ngraph_freshness_tracker.cc",
        "src/ngraph_graph_rewrite_passes.cc",
        "src/ngraph_liberate_pass.cc",
        "src/ngraph_op_kernels.cc",
        "src/ngraph_stub_ops.cc",
        "src/ngraph_utils.h",
        "src/ngraph_utils.cc",
        "src/ngraph_send_recv_ops.cc",
        "src/ngraph_variable_ops.cc",
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
        "@org_tensorflow//tensorflow/core:protos_all_proto_text",
        "@org_tensorflow//tensorflow/core:framework_headers_lib",
        "@org_tensorflow//tensorflow/core:core_cpu_headers_lib",
        "@ngraph//:ngraph_core"
    ],
    copts = [
        "-I external/ngraph_tf/src",
        "-I external/ngraph_tf/logging",
        "-I external/ngraph/src",
    ],
    visibility = ["//visibility:public"],
)
