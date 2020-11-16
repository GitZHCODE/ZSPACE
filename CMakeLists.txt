project(zspace)
cmake_minimum_required(VERSION 3.13)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include_directories(
cpp
)

## 
## sharedlibrary 
##
add_library(zspaceBase SHARED
cpp/source/zCore/base/zColor.cpp
cpp/source/zCore/base/zVector.cpp
cpp/source/zCore/base/zDate.cpp
cpp/source/zCore/base/zQuaternion.cpp
cpp/source/zCore/base/zDomain.cpp
cpp/source/zCore/base/zTransformationMatrix.cpp
cpp/source/zCore/base/zMatrix.cpp
)

target_compile_definitions(zspaceBase PUBLIC
    ZSPACE_DYNAMIC_LIBRARY
    ZSPACE_CORE=""
)

##
## one test executable
##
add_executable(zapp
    cpp/source/zApp/zApp.cpp
)
target_compile_definitions(zapp PUBLIC
    ZSPACE_CUDA_CALLABLE=""
)

#target_compile_features(zapp PRIVATE cxx_std_17)
target_link_libraries(zapp PRIVATE
    zspaceBase
    GL
)
