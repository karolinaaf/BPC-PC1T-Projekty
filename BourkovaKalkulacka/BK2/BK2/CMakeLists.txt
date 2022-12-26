# CMakeList.txt : CMake project for BK2, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("BK2")

# Add source to this project's executable.
add_executable (BK2 "BK2.cpp" "BK2.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET BK2 PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
