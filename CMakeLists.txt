cmake_minimum_required(VERSION 3.27)
project(weasel-lsp
	VERSION 0.0.1
	DESCRIPTION "A Weasel language server protocol"
	HOMEPAGE_URL "https://github.com/aglis-lab/weasel-lsp"
	LANGUAGES "CXX"
)

# Append Include Path
list(
	PREPEND CMAKE_INCLUDE_PATH
	include
	third-party
)

message(STATUS "PROJECT NAME ${PROJECT_NAME}")
message(STATUS "CMAKE INCLUDE PATH ${CMAKE_INCLUDE_PATH}")
message(STATUS "VCPKG ROOT PATH $ENV{VCPKG_ROOT}")
