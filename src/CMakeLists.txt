cmake_minimum_required(VERSION 3.25)
project(raylib-example)

set(CMAKE_DISABLE_IN_SOURCE_BUILD ON)

# Generate compile_commands.json
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

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

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED On)
# Dependencies
set(RAYLIB_VERSION 5.0.0)
find_package(raylib ${RAYLIB_VERSION} QUIET) # QUIET or REQUIRED
if (NOT raylib_FOUND)
	include(FetchContent)
	FetchContent_Declare(
		raylib
		URL https://github.com/raysan5/raylib/archive/refs/tags/${RAYLIB_VERSION}.tar.gz
	)
	FetchContent_GetProperties(raylib)
	if (NOT raylib_POPULATED) # Have we downloaded raylib yet?
		set(FETCHCONTENT_QUIET NO)
		FetchContent_Populate(raylib)
		set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE) # don't build the supplied examples
		add_subdirectory(${raylib_SOURCE_DIR} ${raylib_BINARY_DIR})
	endif()
endif()


set(SOURCE_FILES
	main.c
)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} PRIVATE raylib)
