// This file is part of zspace, a simple C++ collection of geometry data-structures & algorithms, 
// data analysis & visualization framework.
//
// Copyright (C) 2019 ZSPACE 
// 
// This Source Code Form is subject to the terms of the MIT License 
// If a copy of the MIT License was not distributed with this file, You can 
// obtain one at https://opensource.org/licenses/MIT.
//
// Author : Vishu Bhooshan <vishu.bhooshan@zaha-hadid.com>
//

#ifndef ZSPACE_OBJ_H
#define ZSPACE_OBJ_H

#pragma once

#include <headers/zCore/utilities/zUtilsCore.h>
#include <headers/zCore/utilities/zUtilsJson.h>

#ifndef ZSPACE_UNREAL_INTEROP
#include <headers/zCore/utilities/zUtilsDisplay.h>
#endif // !ZSPACE_UNREAL_INTEROP

namespace zSpace
{
	/** \addtogroup zInterface
	*	\brief The Application Program Interface of the library.
	*  @{
	*/

	/** \addtogroup zObjects
	*	\brief The object classes of the library.
	*  @{
	*/

	/*! \class zObj
	*	\brief The base object class.
	*	\since version 0.0.2
	*/

	/** @}*/

	/** @}*/

	class ZSPACE_API zObj
	{
	protected:
		
#ifndef ZSPACE_UNREAL_INTEROP
		/*! \brief pointer to display utilities object	*/
		zUtilsDisplay *displayUtils;
#endif
	
		/*! \brief core utilities object	*/
		zUtilsCore coreUtils;

		/*! \brief boolean for displaying the object		*/
		bool showObject;

		/*! \brief boolean for displaying the object transform		*/
		bool showObjectTransform;

	public:
		//--------------------------
		//----  ATTRIBUTES
		//--------------------------		
			

		/*! \brief object transformation matrix			*/
		zTransformationMatrix transformationMatrix;
		

		//--------------------------
		//---- CONSTRUCTOR
		//--------------------------

		/*! \brief Default constructor.
		*
		*	\since version 0.0.2
		*/
		zObj();

		//--------------------------
		//---- DESTRUCTOR
		//--------------------------

		/*! \brief Default destructor.
		*
		*	\since version 0.0.2
		*/
		~zObj();

		//--------------------------
		//---- VIRTUAL METHODS
		//--------------------------
		
		/*! \brief This method displays the object type.
		*
		*	\since version 0.0.2
		*/
		virtual void draw();
		
		/*! \brief This method gets the bounds of the object.
		*
		*	\since version 0.0.2
		*/
		virtual void getBounds(zPoint &minBB, zPoint &maxBB);
	
		//--------------------------
		//---- SET METHODS
		//--------------------------

		/*! \brief This method sets show object boolean.
		*
		*	\param		[in]	_showObject				- input show object boolean.
		*	\since version 0.0.2
		*/
		void setShowObject(bool _showObject);

		/*! \brief This method sets show object transform boolean.
		*
		*	\param		[in]	_showObjectTransform				- input show object transform boolean.
		*	\since version 0.0.2
		*/
		void setShowTransform(bool _showObjectTransform);

#ifndef ZSPACE_UNREAL_INTEROP
		/*! \brief This method sets display utils.
		*
		*	\param		[in]	_displayUtils			- input display utils.
		*	\param		[in]	_coreUtils				- input core utils.
		*	\since version 0.0.2
		*/
		void setUtils(zUtilsDisplay &_displayUtils);

#endif // !ZSPACE_UNREAL_INTEROP
		

	};

	/** \addtogroup zCore
	*	\brief The core datastructures of the library.
	*  @{
	*/

	/** \addtogroup zBase
	*	\brief  The base classes, enumerators ,defintions of the library.
	*  @{
	*/

	/** \addtogroup zTypeDefs
	*	\brief  The type defintions of the library.
	*  @{
	*/

	/** \addtogroup Container
	*	\brief  The container typedef of the library.
	*  @{
	*/

	/*! \typedef zObjArray
	*	\brief A vector of zObj.
	*
	*	\since version 0.0.4
	*/
	typedef vector<zObj> zObjArray;

	/*! \typedef zObjPointerArray
	*	\brief A vector of zObj pointers.
	*
	*	\since version 0.0.4
	*/
	typedef vector<zObj*> zObjPointerArray;

	/** @}*/
	/** @}*/
	/** @}*/
	/** @}*/

}

#if defined(ZSPACE_STATIC_LIBRARY)  || defined(ZSPACE_DYNAMIC_LIBRARY)
// All defined OK so do nothing
#else
#include<source/zInterface/objects/zObj.cpp>
#endif

#endif