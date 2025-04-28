cmake_minimum_required(VERSION 3.10)
project(qrcodegen_dll LANGUAGES CXX)

add_library(qrcodegen SHARED
    qrcodegen.cpp
    wrapper.cpp
)

target_include_directories(qrcodegen PUBLIC
    ${PROJECT_SOURCE_DIR}
)

# 👇 加这两句，保证Windows正确导出 DLL 符号
target_compile_definitions(qrcodegen PRIVATE QR_DLL_EXPORTS)
set_target_properties(qrcodegen PROPERTIES
    WINDOWS_EXPORT_ALL_SYMBOLS ON
    OUTPUT_NAME "qrcodegen"
)
