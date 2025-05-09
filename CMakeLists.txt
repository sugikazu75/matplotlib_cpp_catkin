cmake_minimum_required(VERSION 3.14)
project(matplotlib_cpp_test)

# Python3 executable
find_program(Python3_EXECUTABLE NAMES python3 REQUIRED)

# Python include dir
execute_process(
  COMMAND ${Python3_EXECUTABLE} -c "from distutils.sysconfig import get_python_inc; print(get_python_inc())"
  OUTPUT_VARIABLE PYTHON3_INCLUDE_DIR
  OUTPUT_STRIP_TRAILING_WHITESPACE
)

# Python lib path
find_library(PYTHON3_LIBRARY NAMES python3.8 python3.9 python3.10 python3.11 PATHS /usr/lib /usr/lib/x86_64-linux-gnu)

# NumPy include dir
execute_process(
  COMMAND ${Python3_EXECUTABLE} -c "import numpy; print(numpy.get_include())"
  OUTPUT_VARIABLE NUMPY_INCLUDE_DIR
  OUTPUT_STRIP_TRAILING_WHITESPACE
)

message(STATUS "Python3 executable: ${Python3_EXECUTABLE}")
message(STATUS "Python3 include: ${PYTHON3_INCLUDE_DIR}")
message(STATUS "Python3 library: ${PYTHON3_LIBRARY}")
message(STATUS "NumPy include: ${NUMPY_INCLUDE_DIR}")


find_package(Python3 COMPONENTS Development NumPy REQUIRED)
find_package(catkin REQUIRED)

catkin_package(
  INCLUDE_DIRS matplotlib-cpp
  CATKIN_DEPENDS
  DEPENDS Python3
  )

include_directories(
  matplotlib-cpp
  ${Python3_INCLUDE_DIRS}
  ${Python3_NumPy_INCLUDE_DIRS}
  )

add_executable(minimal src/minimal.cpp)
target_compile_features(minimal PRIVATE cxx_std_17)
target_link_libraries(minimal Python3::Python Python3::NumPy)

add_executable(basic src/basic.cpp)
target_compile_features(basic PRIVATE cxx_std_17)
target_link_libraries(basic Python3::Python Python3::NumPy)

add_executable(modern src/modern.cpp)
target_compile_features(modern PRIVATE cxx_std_17)
target_link_libraries(modern Python3::Python Python3::NumPy)

add_executable(xkcd src/xkcd.cpp)
target_compile_features(xkcd PRIVATE cxx_std_17)
target_link_libraries(xkcd Python3::Python Python3::NumPy)

add_executable(quiver src/quiver.cpp)
target_compile_features(quiver PRIVATE cxx_std_17)
target_link_libraries(quiver Python3::Python Python3::NumPy)

add_executable(3d src/3d.cpp)
target_compile_features(3d PRIVATE cxx_std_17)
target_link_libraries(3d Python3::Python Python3::NumPy)

# install(FILES package.xml DESTINATION share/${PROJECT_NAME})

install(TARGETS minimal basic modern xkcd quiver 3d
   RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION})
install(DIRECTORY matplotlib-cpp
   DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION})
