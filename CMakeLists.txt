project(zspace)
cmake_minimum_required(VERSION 3.13)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include_directories(
cpp
cpp/headers/zCore
)

## 
## sharedlibrary 
##
add_library(zspace SHARED
# cpp/source/zCore/geometry/zGraph.cpp
# cpp/source/zCore/geometry/zHEGeomTypes.cpp
cpp/source/zCore/geometry/zMesh.cpp
# cpp/source/zCore/geometry/zPointCloud.cpp
)

set_target_properties(zspace PROPERTIES
CXX_STANDARD 17
    )
    target_compile_features(zspace PRIVATE cxx_std_17)

##
## one test executable
##
#add_executable(zapp
#cpp/source/zApp/zApp.cpp
#)

#target_compile_features(zapp PRIVATE cxx_std_17)

#target_link_libraries(zapp PRIVATE#
#	zspace
#)
