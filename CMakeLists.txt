cmake_minimum_required(VERSION 3.14)
project(matplotlib_cpp_test)

find_package(Python COMPONENTS Development NumPy REQUIRED)

include_directories(
  matplotlib-cpp
  ${Python_INCLUDE_DIRS}
  ${Python_NumPy_INCLUDE_DIRS}
  )

add_executable(minimal src/minimal.cpp)
target_compile_features(minimal PRIVATE cxx_std_17)
target_link_libraries(minimal Python::Python Python::NumPy)

add_executable(basic src/basic.cpp)
target_compile_features(basic PRIVATE cxx_std_17)
target_link_libraries(basic Python::Python Python::NumPy)

add_executable(modern src/modern.cpp)
target_compile_features(modern PRIVATE cxx_std_17)
target_link_libraries(modern Python::Python Python::NumPy)

add_executable(xkcd src/xkcd.cpp)
target_compile_features(xkcd PRIVATE cxx_std_17)
target_link_libraries(xkcd Python::Python Python::NumPy)

add_executable(quiver src/quiver.cpp)
target_compile_features(quiver PRIVATE cxx_std_17)
target_link_libraries(quiver Python::Python Python::NumPy)

add_executable(3d src/3d.cpp)
target_compile_features(3d PRIVATE cxx_std_17)
target_link_libraries(3d Python::Python Python::NumPy)

