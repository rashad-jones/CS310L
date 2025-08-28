cmake_minimum_required(VERSION 3.21)

project(MathLibProject LANGUAGES Version 1.0 CXX)


set(CMAKE_CTEST_ARGUMENTS "--output-on-failure" "--output-junit" "junit.xml")
# This must be in the top-level CMakeLists.txt to enable CMake/CTest support.
include(CTest)

set(CMAKE_CXX_STANDARD 11)

add_execultable(MathApp src/main.cpp)

target_include_directories(MathApp PUBLIC inside)

enable_testing()

include(FetchContent)
FetchContent_Declare(
    Catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG V3.6.0
)

FetchContent_MakeAvaliable(Catch2)

add_execultable(unit_tests/math_tests.cpp src/math_functions.cpp)
target_link_libraries(unit_tests PRIVATE Catch2::Catch2WithMain)
target_include_directories(unit_tests PUBLIC include)

list(APPEND CMAKE_MODULE_PATH ${catch2_SOURCE_DIR}/extras)
include(CTest)
include(Catch)
catch_discover_tests(unit_tests)