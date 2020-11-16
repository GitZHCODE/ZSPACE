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
cpp/source/zCore/display/zObjBuffer.cpp
cpp/source/zCore/field/zBin.cpp
cpp/source/zCore/field/zField2D.cpp
cpp/source/zCore/field/zField3D.cpp
cpp/source/zCore/zCore.cpp
cpp/source/zCore/dynamics/zParticle.cpp
cpp/source/zCore/utilities/zUtilsBMP.cpp
cpp/source/zCore/utilities/zUtilsCore.cpp
cpp/source/zCore/utilities/zUtilsDisplay.cpp
cpp/source/zCore/base/zColor.cpp
cpp/source/zCore/base/zVector.cpp
cpp/source/zCore/base/zDate.cpp
cpp/source/zCore/base/zQuaternion.cpp
cpp/source/zCore/base/zDomain.cpp
cpp/source/zCore/base/zTransformationMatrix.cpp
cpp/source/zCore/base/zMatrix.cpp
cpp/source/zCore/geometry/zMesh.cpp
cpp/source/zCore/geometry/zPointCloud.cpp
cpp/source/zCore/geometry/zHEGeomTypes.cpp
cpp/source/zCore/geometry/zGraph.cpp
cpp/source/zCore/data/zDatabase.cpp
cpp/source/zInterOp/interOp/zIOMeshSurface.cpp
cpp/source/zInterOp/interOp/zIONurbsSurface.cpp
cpp/source/zInterOp/interOp/zIONurbsCurve.cpp
cpp/source/zInterOp/interOp/zIOMesh.cpp
cpp/source/zInterOp/core/zRhinoCore.cpp
# cpp/source/zInterOp/functionSets/zMayaFnMesh.cpp
# cpp/source/zInterOp/functionSets/zMayaFnGraph.cpp
# cpp/source/zInterOp/functionSets/zUnrealFnMesh.cpp
cpp/source/zInterOp/functionSets/zRhinoFnGraph.cpp
cpp/source/zInterOp/functionSets/zRhinoFnMesh.cpp
cpp/source/zInterface/iterators/zItMeshField.cpp
cpp/source/zInterface/iterators/zItMesh.cpp
cpp/source/zInterface/iterators/zItPointCloud.cpp
cpp/source/zInterface/iterators/zIt.cpp
cpp/source/zInterface/iterators/zItPointField.cpp
cpp/source/zInterface/iterators/zItGraph.cpp
cpp/source/zInterface/model/zModel.cpp
cpp/source/zInterface/objects/zObjPointCloud.cpp
cpp/source/zInterface/objects/zObjParticle.cpp
cpp/source/zInterface/objects/zObjGraph.cpp
cpp/source/zInterface/objects/zObjMeshField.cpp
cpp/source/zInterface/objects/zObj.cpp
cpp/source/zInterface/objects/zObjPointField.cpp
cpp/source/zInterface/objects/zObjSpatialBin.cpp
cpp/source/zInterface/objects/zObjMesh.cpp
cpp/source/zInterface/functionsets/zFnPointField.cpp
cpp/source/zInterface/functionsets/zFnMesh.cpp
cpp/source/zInterface/functionsets/zFnMeshDynamics.cpp
cpp/source/zInterface/functionsets/zFnParticle.cpp
cpp/source/zInterface/functionsets/zFnGraph.cpp
cpp/source/zInterface/functionsets/zFnSpatialBin.cpp
cpp/source/zInterface/functionsets/zFnPointCloud.cpp
cpp/source/zInterface/functionsets/zFnMeshField.cpp
cpp/source/zInterface/functionsets/zFnGraphDynamics.cpp
cpp/source/zInterface/functionsets/zFn.cpp
cpp/source/zArchGeom/zAgRoof.cpp
cpp/source/zArchGeom/zAGColumn.cpp
cpp/source/zArchGeom/zAgSlab.cpp
cpp/source/zArchGeom/zAgFacade.cpp
cpp/source/zArchGeom/zAgObj.cpp
cpp/source/zArchGeom/zAgWall.cpp
cpp/source/zCudaToolsets/energy/zTsSolarAnalysis.cpp
cpp/source/zToolsets/statics/zTsVault.cpp
cpp/source/zToolsets/statics/zTsSpatialStructure.cpp
cpp/source/zToolsets/statics/zTsTopOpt.cpp
cpp/source/zToolsets/statics/zTsPolytopal.cpp
cpp/source/zToolsets/digiFab/zTsRobot.cpp
cpp/source/zToolsets/geometry/zTsRemesh.cpp
cpp/source/zToolsets/geometry/zTsMesh2Pix.cpp
cpp/source/zToolsets/geometry/zTsVariableExtrude.cpp
cpp/source/zToolsets/geometry/zTsSpectral.cpp
cpp/source/zToolsets/geometry/zTsGraphPolyhedra.cpp
cpp/source/zToolsets/data/zTsOSM.cpp
cpp/source/zToolsets/data/zTsKMeans.cpp
cpp/source/zToolsets/pathNetworks/zTsSlimeMould.cpp
cpp/source/zToolsets/pathNetworks/zTsShortestPath.cpp
cpp/source/zToolsets/streamlines/zTsStreams2D.cpp
cpp/source/zApp/zApp.cpp
cpp/source/zHousing/architecture/zHcUnit.cpp
cpp/source/zHousing/architecture/zHcStructure.cpp
cpp/source/zHousing/architecture/zHcAggregation.cpp
)

set_target_properties(zspace PROPERTIES
CXX_STANDARD 17
    )
target_compile_features(zspace PRIVATE cxx_std_17)
target_compile_definitions(zspace PUBLIC
ZSPACE_DYNAMIC_LIBRARY
ZSPACE_CORE=""
)

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
