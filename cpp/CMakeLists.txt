set(PYTHON /usr/include/python3.8)
set(PROJECT cxx_python)
add_definitions("-I${PYTHON} -lpython3.8")
find_package(PythonLibs REQUIRED)
include_directories(${PYTHON_INCLUDE_DIRS})
add_executable(${PROJECT} test.cpp)
target_link_libraries(${PROJECT} ${PYTHON_LIBRARIES})

