cmake_minimum_required(VERSION 3.27)
project(weasel-lsp
	VERSION 0.0.1
	DESCRIPTION "A Weasel language server protocol"
	HOMEPAGE_URL "https://github.com/aglis-lab/weasel-lsp"
	LANGUAGES "CXX"
)

# CMAKE LINKER
set(CMAKE_LINKER ld64.lld)

# CMAKE GENERATOR
set(CMAKE_GENERATOR "Ninja")

# APPEND LIST INCLUDE PATH
list(PREPEND CMAKE_INCLUDE_PATH build/include include third-party)

# SET CMAKE
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_TOOLCHAIN_FILE=$ENV{VCPKG_CMAKE})

# Export Compile Command and use it for vscode settings
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# CXX
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# CONFIGURE INFO
set(SERVER_NAME ${PROJECT_NAME})
set(SERVER_VERSION ${PROJECT_VERSION})
configure_file(.info include/wlsp/version.h @ONLY)

# CHECKING
message(STATUS "PROJECT NAME ${PROJECT_NAME}")
message(STATUS "CMAKE INCLUDE PATH ${CMAKE_INCLUDE_PATH}")
message(STATUS "VCPKG ROOT PATH $ENV{VCPKG_ROOT}")
message(STATUS "VCPKG CMAKE PATH $ENV{VCPKG_CMAKE}")
message(STATUS "GENERATOR IS SET TO ${CMAKE_GENERATOR}")

# PACKAGES
find_package(RapidJSON CONFIG REQUIRED)
find_package(Plog CONFIG REQUIRED)

# The library itself
add_library(${PROJECT_NAME} STATIC)

# INCLUDE DIRECTORY
include_directories(${CMAKE_INCLUDE_PATH})

# # Sources Library
add_subdirectory(lib)

# Sources Example
add_subdirectory(examples)

# Set target link libraries
target_link_libraries(
	${PROJECT_NAME} PRIVATE
	rapidjson
	plog::plog
)
