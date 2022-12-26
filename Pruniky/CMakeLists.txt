# CMakeList.txt : CMake project for pruniky, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("pruniky")

# Add source to this project's executable.
add_executable (pruniky "pruniky.cpp" "pruniky.h" "funkce.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET pruniky PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
