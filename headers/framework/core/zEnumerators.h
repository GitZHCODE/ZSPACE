#pragma once


	/*!	\namespace	zSpace
	*	\brief		namespace for the library.
	*	\since		version 0.0.1
	*/
namespace zSpace
{
	/** \addtogroup zCore
	*	\brief The core classes, enumerators ,defintions and utility methods of the library.
	*  @{
	*/

	/** \addtogroup zCoreEnumerators
	*	\brief Collection of all the enumerators in the library.
	*  @{
	*/

	/*! \enum	zHEData
	*	\brief	Data types of a halfedge data structure.
	*	\since	version 0.0.1
	*/	
	enum zHEData { zVertexData = 0, zEdgeData, zFaceData};

	/*! \enum	zScalarfieldData
	*	\brief	Algorithm types for field navigation.
	*	\since	version 0.0.1
	*/
	enum zScalarfieldData { zGradientDescent=30, zGradientAscent };

	/*! \enum	zColorData
	*	\brief	Data types of color.
	*	\since	version 0.0.1
	*/	
	enum zColorType { zRGB = 40, zHSV };



	/*! \enum	zIntergrationType
	*	\brief	Integration types.
	*	\since	version 0.0.1
	*/
	enum zIntergrationType { zEuler = 60, zRK4 , zPixel };

	/*! \enum	zDiffusionType
	*	\brief	Diffusion or averaging types.
	*	\since	version 0.0.1
	*/
	enum zDiffusionType { zLaplacian = 70, zAverage, zLaplacianAdjacent};

	/*! \enum	zSlimeParameter
	*	\brief	Slime mold parameters.
	*	\since	version 0.0.1
	*/
	enum zSlimeParameter { zSO = 80, zSA, zRA, zdepT};


	/*! \enum	zSQLCommand
	*	\brief SQLite database command types.
	*	\since	version 0.0.1
	*/
	enum zSQLCommand { zCreate = 90, zInsert, zSelect, zSelectExists, zSelectCreate, zSelectCount, zUpdate, zDrop, zExportCSV };

	/*! \enum	zDataLevel
	*	\brief	Grid levels for data in London.
	*	\since	version 0.0.1
	*/
	enum zDataLevel { zLsoaData = 50, zMsoaData, zPostcodeData };

	
	/*! \enum	zDataBuilding
	*	\brief	Grid levels for data in London.
	*	\since	version 0.0.1
	*/
	enum zDataBuilding { zCommercialBuilding = 100, zResidentialBuilding, zPublicBuilding, zUniversityBuilding, zUndefinedBuilding};
	
	/*! \enum	zDataStreet
	*	\brief	Grid levels for data in London.
	*	\since	version 0.0.1
	*/
	enum zDataStreet { zTrunkStreet = 20, zPrimaryStreet, zSecondaryStreet, zTertiaryStreet, zResidentialStreet, zPedestrianStreet, zCycleStreet, zServiceStreet, zUndefinedStreet };

	/*! \enum	zDatatypes
	*	\brief	Grid levels for data in London.
	*	\since	version 0.0.1
	*/
	enum zDatatypes { zInt = 110, zFloat, zDouble, zString };

	/*! \enum	zWalkTypes
	*	\brief	walk types for Shortest Path Trees.
	*	\since	version 0.0.1
	*/
	enum zWalkType { zEdgePath = 120, zEdgeVisited};

	/*! \enum	zFieldValueType
	*	\brief	field value sampling types.
	*	\since	version 0.0.1
	*/
	enum zFieldValueType { zFieldIndex = 130, zFieldNeighbourWeighted, zFieldAdjacentWeighted, zFieldContainedWeighted};

	/*! \enum	zFieldStreamType
	*	\brief	field stream sampling types.
	*	\since	version 0.0.1
	*/
	enum zFieldStreamType { zForward = 140, zBackward, zForwardBackward};

	/*! \enum	zFileTpye
	*	\brief	input and ouput file types.
	*	\since	version 0.0.1
	*/
	enum zFileTpye { zJSON = 150, zOBJ, zTXT, zCSV, zBMP, zMESH , zGRAPH};

	/*! \enum	zDiagramType
	*	\brief	diagram types for vaults.
	*	\since	version 0.0.1
	*/
	enum zDiagramType { zFormDiagram = 190, zForceDiagram, zResultDiagram };

	/** @}*/

	/** @}*/ 
}