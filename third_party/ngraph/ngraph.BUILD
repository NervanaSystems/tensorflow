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
#     name = "ngraph_libs_linux",
#     srcs = [
#         "lib/libiomp5.so",
#         "lib/libmklml_intel.so",
#     ],
#     visibility = ["//visibility:public"],
# )

cc_library(
    name = "ngraph",
    srcs = glob([
        "src/ngraph/**/*.cpp",
        "src/ngraph/**/*.hpp",],
        exclude = ["src/ngraph/runtime/gpu/*"]
    ),
    hdrs = ["src/ngraph/file_util.hpp"],
    deps = [
        "@mkl_dnn",
        "@nlohmann_json_arcive",
        "@llvm"
    ],
    copts = ["-I external/ngraph/src"],
    visibility = ["//visibility:public"],
)
