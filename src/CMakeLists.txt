# Dependencies
include(FetchContent)

FetchContent_Declare(
  raylib
  GIT_REPOSITORY "https://github.com/raysan5/raylib"
  GIT_TAG "5.5"
  GIT_SHALLOW On
)

FetchContent_MakeAvailable(raylib)

set(SOURCE_FILES
	main.c
)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} PRIVATE raylib)
