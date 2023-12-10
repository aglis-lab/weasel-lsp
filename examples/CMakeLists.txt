cmake_minimum_required(VERSION 3.13.0)
project(example LANGUAGES "CXX")

if (MSVC)
    # warning level 4
    add_compile_options(/W4)
else()
    # additional warnings
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# The binary itself
add_executable(example main.cpp)

target_link_libraries(example PRIVATE weasel-lsp rapidjson plog::plog)
