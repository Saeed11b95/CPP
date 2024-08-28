cmake_minimum_required(VERSION 3.29)
project(Tensor)

set(CMAKE_CXX_STANDARD 20)

# Set the CMake toolchain file for vcpkg
set(CMAKE_TOOLCHAIN_FILE "/opt/vcpkg/scripts/buildsystems/vcpkg.cmake")

# Set the CMake prefix path to the vcpkg installed directory inside the project
# set(CMAKE_PREFIX_PATH "${CMAKE_SOURCE_DIR}/vcpkg_installed/x64-linux/share" CACHE STRING "")

# Find packages
find_package(range-v3 CONFIG REQUIRED)
find_package(fmt CONFIG REQUIRED)
add_executable(Tensor main.cpp)

# Link the libraries to the target executable
target_link_libraries(Tensor PRIVATE range-v3::meta range-v3::concepts range-v3::range-v3)
target_link_libraries(Tensor PRIVATE fmt::fmt-header-only)