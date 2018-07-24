licenses(["notice"])  # 3-Clause BSD

exports_files(["license.txt"])

filegroup(
    name = "LICENSE",
    srcs = [
        "license.txt",
    ],
    visibility = ["//visibility:public"],
)

# # https://docs.bazel.build/versions/master/be/c-cpp.html#cc_binary
# cc_binary(
#     name = "ngraph_cpu_header_gen",
#     srcs = [
#         "src/resource/main.cpp",
#         "src/resource/util.hpp",
#         "src/resource/util.cpp",
#         "src/resource/uncomment.hpp",
#         "src/resource/uncomment.cpp",
#         "src/resource/header_rewrite.hpp",
#         "src/resource/header_rewrite.cpp",
#     ],
#     copts = [
#         "-I external/ngraph/src",
#         "-I external/ngraph_llvm_lib/include",
#         '-D NGRAPH_HEADERS_PATH=\\"src/ngraph/\\"',
#         '-D CLANG_BUILTIN_HEADERS_PATH=\\"external/ngraph_llvm_lib/include\\"',
#         '-D CLANG_BUILTIN_HEADERS_PATH=\\"external/ngraph_llvm_lib/include\\"',
#         '-D EIGEN_HEADERS_PATH=\\"external/eigen_archive/Eigen/src\\"',
#         '-D MKLDNN_HEADERS_PATH=\\"external/mkl_dnn/include\\"',
#     ],
#     deps = [],
# )

# cc_library(
#     name = "ngraph_cpu_codegen",
#     srcs = glob([
#             "src/ngraph/codegen/code_writer.hpp",
#             "src/ngraph/codegen/code_writer.cpp",
#             "src/ngraph/codegen/compiler.hpp",
#             "src/ngraph/codegen/compiler.cpp",
#             "src/ngraph/codegen/execution_engine.hpp",
#             "src/ngraph/codegen/execution_engine.cpp",
#         ]),
#     #hdrs = glob(["src/ngraph/**/*.hpp"]),
#     deps = [
#         "@mkl_dnn",
#         "@eigen_archive//:eigen",
#         "@ngraph_llvm_lib//:llvm_headers",
#         "@ngraph_llvm_lib//:llvm_libs_linux"
#     ],
#     copts = [
#         "-I external/ngraph/src",
#         "-I external/ngraph_llvm_lib/include",
#     #    '-D SHARED_LIB_EXT=\\".so\\"',
#     #    '-D NGRAPH_VERSION=\\"0.5.0\\"',
#     ],
#     visibility = ["//visibility:public"],
#     alwayslink=1
# )

cc_library(
    name = "ngraph_core",
    srcs = glob([
            "src/ngraph/*.cpp",
            "src/ngraph/autodiff/*.cpp",
            "src/ngraph/builder/*.cpp",
            "src/ngraph/descriptor/*.cpp",
            "src/ngraph/descriptor/layout/*.cpp",
            "src/ngraph/op/*.cpp",
            "src/ngraph/op/util/*.cpp",
            "src/ngraph/pattern/*.cpp",
            "src/ngraph/pattern/*.hpp",
            "src/ngraph/pass/*.cpp",
            "src/ngraph/pass/*.hpp",
            "src/ngraph/runtime/*.cpp",
            "src/ngraph/type/*.cpp",
            "src/ngraph/runtime/interpreter/*.cpp",
            "src/ngraph/runtime/interpreter/*.hpp",
        ]),
    hdrs = glob(["src/ngraph/**/*.hpp"]),
    deps = [
        #"@mkl_dnn",
        "@eigen_archive//:eigen",
        "@nlohmann_json_lib",
        #":ngraph_cpu_codegen"
    ],
    copts = [
        "-I external/ngraph/src",
        "-I external/nlohmann_json_lib/include/",
        '-D SHARED_LIB_EXT=\\".so\\"',
        '-D NGRAPH_VERSION=\\"0.5.0\\"',
    ],
    visibility = ["//visibility:public"],
    alwayslink=1
)
