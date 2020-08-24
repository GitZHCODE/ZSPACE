project(zcoreexec)
cmake_minimum_required(VERSION 3.13)


# finally, there should then also be a line add_library(zspace) that defines all of zspace as a library
add_library(zcoreheaders SHARED IMPORTED)

# set(CMAKE_CXX_STANDARD 17)
# set(CMAKE_CXX_STANDARD_REQUIRED ON)
 set(CMAKE_CXX_EXTENSIONS OFF)

set_property(TARGET zcoreheaders PROPERTY INTERFACE_INCLUDE_DIRECTORIES
    "${CMAKE_CURRENT_SOURCE_DIR}/cpp/headers/zCore"
    "${CMAKE_CURRENT_SOURCE_DIR}/cpp/"
    )

# one test executable
add_executable(zcoreexec
	exampleExec/main.cpp
)
set_target_properties(zcoreexec PROPERTIES
CXX_STANDARD 17
    )

target_compile_features(zcoreexec PRIVATE cxx_std_17)
# link the test executable with the zcoreheaders
# should finally link with all of zspace, not just the core headers
target_link_libraries(zcoreexec PRIVATE
	zcoreheaders
)


