cmake_minimum_required(VERSION 3.25)

project(raylib-example
	VERSION 0.1.0
	DESCRIPTION "A template for raylib"
	LANGUAGES C
)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED On)

# Disable useless warnings

# Avoid warning about DOWNLOAD_EXTRACT_TIMESTAMP in CMake 3.24
if (CMAKE_VERSION VERSION_GREATER_EQUAL "3.24.0")
	cmake_policy(SET CMP0135 NEW)
endif()
if (CMAKE_VERSION VERSION_GREATER_EQUAL "3.13.0")
	cmake_policy(SET CMP0077 NEW)
endif()

# Disable useless compiler warnings
if (MSVC)
	add_compile_options(/wd4068) # Disable unknown pragma warning.
	add_compile_options(/wd4996) # Disable unsecure function warnings. (e.g. sprintf())
endif()

add_subdirectory(src)
