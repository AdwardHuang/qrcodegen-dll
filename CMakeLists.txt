cmake_minimum_required(VERSION 3.10)
project(qrcodegen_dll LANGUAGES CXX)

add_library(qrcodegen SHARED
    qrcodegen.cpp
    wrapper.cpp
)

target_include_directories(qrcodegen PUBLIC
    ${PROJECT_SOURCE_DIR}
)

set_target_properties(qrcodegen PROPERTIES
    OUTPUT_NAME "qrcodegen"
)