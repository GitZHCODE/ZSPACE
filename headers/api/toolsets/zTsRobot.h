#pragma once

#include <headers/api/functionsets/zFnMesh.h>
#include <headers/api/functionsets/zFnGraph.h>

namespace zSpace
{

	/** \addtogroup API
	*	\brief The Application Program Interface of the library.
	*  @{
	*/

	/** \addtogroup zToolsets
	*	\brief Collection of toolsets for applications.
	*  @{
	*/

	/** \addtogroup zTsDigiFab
	*	\brief toolsets for digital fabrication related utilities.
	*  @{
	*/

	/** \addtogroup zInverseKinematics
	*	\brief toolsets for inverse kinematics chain.
	*  @{
	*/

	/*! \struct zDHparameter
	*	\brief A struct to store the DH parameters of IK chain.
	*	\since version 0.0.2
	*/

	/** @}*/

	/** @}*/

	/** @}*/

	/** @}*/

	struct zDHparameter
	{
		double d;
		double a;
		double alpha;
		double theta;

	};

	/** \addtogroup API
	*	\brief The Application Program Interface of the library.
	*  @{
	*/

	/** \addtogroup zToolsets
	*	\brief Collection of toolsets for applications.
	*  @{
	*/

	/** \addtogroup zTsDigiFab
	*	\brief toolsets for digital fabrication related utilities.
	*  @{
	*/

	/** \addtogroup zInverseKinematics
	*	\brief toolsets for inverse kinematics chain.
	*  @{
	*/

	/*! \struct zJointRotation
	*	\brief A struct to store the joint rotation related data.
	*	\since version 0.0.2
	*/

	/** @}*/

	/** @}*/

	/** @}*/

	/** @}*/

	struct zJointRotation
	{
		double rotation;

		double home;

		double minimum;
		double maximum;

		double pulse;
		double mask;
		double offset;
	};

	/** \addtogroup API
	*	\brief The Application Program Interface of the library.
	*  @{
	*/

	/** \addtogroup zToolsets
	*	\brief Collection of toolsets for applications.
	*  @{
	*/

	/** \addtogroup zTsDigiFab
	*	\brief toolsets for digital fabrication related utilities.
	*  @{
	*/

	/** \addtogroup zInverseKinematics
	*	\brief toolsets for inverse kinematics chain.
	*  @{
	*/

	/*! \struct zGCode
	*	\brief A struct to store the G-Code related data.
	*	\since version 0.0.2
	*/

	/** @}*/

	/** @}*/

	/** @}*/

	/** @}*/

	struct zGCode
	{
		vector<zJointRotation> rotations;
		double vel;
		int moveType; // 0 = movJ, 1 = movL 

		int endEffectorControl; // 0 - neutral , 1 - on , 2 -0ff

		zVector robotTCP_position;
		zVector target_position;


		double distDifference;
		bool targetReached;

	};

	/** \addtogroup API
	*	\brief The Application Program Interface of the library.
	*  @{
	*/

	/** \addtogroup zToolsets
	*	\brief Collection of toolsets for applications.
	*  @{
	*/

	/** \addtogroup zTsDigiFab
	*	\brief toolsets for digital fabrication related utilities.
	*  @{
	*/

	/** \addtogroup zInverseKinematics
	*	\brief toolsets for inverse kinematics chain.
	*  @{
	*/

	/*! \class zTsRobot
	*	\brief A class for inverse kinematics chain of a 6 Axis Robot.
	*	\since version 0.0.2
	*/

	/** @}*/

	/** @}*/

	/** @}*/

	/** @}*/

	class  zLink
	{
	public:

		//---- ATTRIBUTES

		/*! \brief stores transformation matrix of the link */
		zTransform T;	

		/*! \brief stores base transformation matrix of the link */
		zTransform TBase;			

		//---- DH ATTRIBUTES

		zDHparameter linkDH;

		//---- CONSTRUCTOR

		/*! \brief Default constructor.
		*	\since version 0.0.2
		*/
		zLink()
		{
			linkDH.alpha = linkDH.d = linkDH.theta = linkDH.a = 0.0;
		}

		/*! \brief Overloaded constructor.
		*
		*	\param		[in]	DH				- input DH Parameters.	
		*	\since version 0.0.2
		*/
		zLink(zDHparameter &DH)
		{
			linkDH = DH;			

			updateTransform();
		}

		//---- DESTRUCTOR

		/*! \brief Default destructor.
		*	\since version 0.0.2
		*/
		~zLink(){}

		//---- METHODS

		/*! \brief This method update the transform T
		*/
		void updateTransform()
		{
			T(0, 0) = cos(linkDH.theta);
			T(0, 1) = -sin(linkDH.theta) * cos(linkDH.alpha);
			T(0, 2) = sin(linkDH.theta) * sin(linkDH.alpha);
			T(0, 3) = linkDH.a * cos(linkDH.theta);

			T(1, 0) = sin(linkDH.theta);
			T(1, 1) = cos(linkDH.theta) * cos(linkDH.alpha);
			T(1, 2) = -cos(linkDH.theta)*sin(linkDH.alpha);
			T(1, 3) = linkDH.a * sin(linkDH.theta);

			T(2, 0) = 0;
			T(2, 1) = sin(linkDH.alpha);
			T(2, 2) = cos(linkDH.alpha);
			T(2, 3) = linkDH.d;

			T(3, 0) = 0;
			T(3, 1) = 0;
			T(3, 2) = 0;
			T(3, 3) = 1;
		}

	};


	/** \addtogroup API
	*	\brief The Application Program Interface of the library.
	*  @{
	*/

	/** \addtogroup zToolsets
	*	\brief Collection of toolsets for applications.
	*  @{
	*/

	/** \addtogroup zTsDigiFab
	*	\brief toolsets for digital fabrication related utilities.
	*  @{
	*/

	/** \addtogroup zInverseKinematics
	*	\brief toolsets for inverse kinematics chain.
	*  @{
	*/
	
	/*! \class zTsRobot
	*	\brief A class for inverse kinematics chain of a 6 Axis Robot.
	*	\since version 0.0.2
	*/

	/** @}*/

	/** @}*/

	/** @}*/

	/** @}*/

	class zTsRobot
	{
	protected:

		enum robotRotationType { zJoint = 200, zJointHome, zJointMinimum, zJointMaximum	};

		//--------------------------
		//---- PROTECTED ATTRIBUTES
		//--------------------------

		/*!	\brief core utilities Object  */
		zUtilsCore coreUtils;

		//--------------------------
		//---- JOINT ATTRIBUTES
		//--------------------------

		/*!	\brief pointer container to joint mesh objects  */
		vector<zObjMesh*> jointMeshObjs;

		/*!	\brief pointer to joint graph object  */
		zObjGraph *jointGraphObj;

		//--------------------------
		//---- ATTRIBUTES
		//--------------------------

		/*!	\brief stores robot scale  */
		double robot_scale = 1.0;

		/*!	\brief contatiner of robot links DH Parameters  */
		vector<zDHparameter> robot_DH;

		/*!	\brief contatiner of robot joint rotations  */
		vector<zJointRotation> jointRotations;

		/*!	\brief contatiner of robot links  */
		vector<zLink> Bars;

		/*!	\brief contatiner of robot joint matrices  */
		vector<zMatrixd> robotJoint_matrices;

		/*!	\brief contatiner of robot joint mesh matrices  */
		vector<zMatrixd> robotJointMesh_matrices;

		/*!	\brief robot base matrix  */
		zMatrixd robot_base_matrix;

		/*!	\brief robot target matrix  */
		zMatrixd robot_target_matrix;

		/*!	\brief robot end effector matrix  */
		zMatrixd robot_endEffector_matrix;


		/*!	\brief contatiner of robot GCode  */
		vector<zGCode> robot_gCode;

		//--------------------------
		//---- MESH ATTRIBUTES
		//--------------------------

		/*!	\brief contatiner of robot mesh dihedral angles  */
		vector<vector<double>> robot_jointMeshes_edgeAngle;

	public:
		//--------------------------
		//---- PUBLIC ATTRIBUTES
		//--------------------------

		/*!	\brief container of joint mesh function set  */
		vector<zFnMesh> fnMeshJoints;

		/*!	\brief joint graph function set  */
		zFnGraph fnGraphJoint;

		//--------------------------
		//---- CONSTRUCTOR
		//--------------------------

		/*! \brief Default constructor.
		*
		*	\since version 0.0.2
		*/
		zTsRobot() 
		{
			robot_scale = 1.0;

			for (int i = 0; i < DOF; i++)
			{
				zDHparameter DH;
				DH.alpha = DH.d = DH.theta = DH.a = 0.0;
				robot_DH.push_back(DH);

				zJointRotation jointRot;
				jointRot.home = jointRot.minimum = jointRot.maximum = jointRot.rotation = 0;
				jointRot.pulse = jointRot.mask = jointRot.offset = 0.0;
				jointRotations.push_back(jointRot);

				robotJoint_matrices.push_back(zMatrixd());
				robotJointMesh_matrices.push_back(zMatrixd());
			}

			for (int i = 0; i < DOF; i++) jointMeshObjs.push_back( nullptr);
			
			jointGraphObj = nullptr;
		}

		/*! \brief Overloaded constructor.
		*
		*	\param		[in]	_jointGraphObj			- input joint graph object.
		*	\param		[in]	_jointMeshObjs			- input container of joint mesh objects.
		*	\since version 0.0.2
		*/
		zTsRobot(zObjGraph &_jointGraphObj, vector<zObjMesh> &_jointMeshObjs)
		{
			jointGraphObj = &_jointGraphObj;
			fnGraphJoint = zFnGraph(_jointGraphObj);

			jointMeshObjs.clear();
			fnMeshJoints.clear();

			for (int i = 0; i < _jointMeshObjs.size(); i++)
			{
				jointMeshObjs.push_back(&_jointMeshObjs[i]);
				fnMeshJoints.push_back(_jointMeshObjs[i]);		
			}

		}

		//--------------------------
		//---- DESTRUCTOR
		//--------------------------

		/*! \brief Default destructor.
		*
		*	\since version 0.0.2
		*/
		~zTsRobot() {}

		//--------------------------
		//---- CREATE METHODS
		//--------------------------

		/*! \brief This method creates the robot from the input parameters.
		*
		*	\param		[in]	_d				- container of d values of DH Parameter per joint.
		*	\param		[in]	_a				- container of a values of DH Parameter per joint.
		*	\param		[in]	_alpha			- container of alpla values of DH Parameter per joint.
		*	\param		[in]	_theta			- container of theta values of DH Parameter per joint.
		*	\param		[in]	_robot_scale	- scale of robot.
		*/
		void createRobot(vector<double>(&_d), vector<double>(&_a), vector<double>(&_alpha), vector<double>(&_theta), double _robot_scale = 1.0)
		{
			robot_scale = _robot_scale;

			for (int i = 0; i < DOF; i++)
			{
				zDHparameter DH;

				DH.alpha = _alpha[i] * DEG_TO_RAD;
				DH.d = _d[i] * robot_scale;
				DH.theta = _theta[i] * DEG_TO_RAD;
				DH.a = _a[i] * robot_scale;

				Bars.push_back(zLink(DH));

				robot_DH.push_back(DH);
			}


			for (int i = 0; i < DOF; i++)
			{
				zJointRotation jointRot;
				jointRot.home = jointRot.minimum = jointRot.maximum = jointRot.rotation = 0;
				jointRot.pulse = jointRot.mask = jointRot.offset = 0.0;
				jointRotations.push_back(jointRot);


				robotJoint_matrices.push_back(zMatrixd());
				robotJointMesh_matrices.push_back(zMatrixd());
			}

			createRobotJointGraph();
			
		}
	
		/*! \brief This method creates the robot from the input file.
		*
		*	\param [in]		path			- input file name including the directory path and extension.
		*	\param [in]		type			- type of file to be imported.
		*	\since version 0.0.2
		*/
		void createRobotfromFile(string path, zFileTpye type)
		{
			if (type == zJSON)
			{
				fromJSON(path);
				createRobotJointGraph();
			}
			else throw std::invalid_argument(" invalid file type.");
		}


		/*! \brief This method creates the robot from the input file.
		*
		*	\param [in]		directory		- input file directory path.
		*	\param [in]		type			- type of file to be imported.
		*	\since version 0.0.2
		*/
		void createRobotJointMeshesfromFile(string directory, zFileTpye type)
		{
			fnMeshJoints.clear();

			if (type == zJSON)
			{
				// import Base
				for (int i = 0; i < 1; i++)
				{
					string path = directory;
					path.append("/r_base.json");
					fnMeshJoints[0].from(path, type); 
				}
				
				// import joints
				for (int i = 1; i <= DOF; i++)
				{
					string path = directory;
					path.append("/r_");
					path.append(to_string(i));
					path.append(".json");
					fnMeshJoints[i].from(path, type);
				}

				// import EE
				for (int i = 0; i < 1; i++)
				{
					string path = directory;
					path.append("/r_EE.json");
					fnMeshJoints[8].from(path, type);
				}

			}

			else if (type == zOBJ)
			{
				// import Base
				for (int i = 0; i < 1; i++)
				{
					string path = directory;
					path.append("/r_base.obj");
					fnMeshJoints[0].from(path, type);
				}

				// import joints
				for (int i = 1; i <= DOF; i++)
				{
					string path = directory;
					path.append("/r_");
					path.append(to_string(i));
					path.append(".obj");
					fnMeshJoints[i].from(path, type);
				}

				// import EE
				for (int i = 0; i < 1; i++)
				{
					string path = directory;
					path.append("/r_EE.obj");
					fnMeshJoints[8].from(path, type);
				}
			}

			else throw std::invalid_argument(" error: invalid zFileTpye type");

		
		}

		//--------------------------
		//----KINMATICS METHODS
		//--------------------------

		/*! \brief This Methods computes the joint positionsof the zRobot.
		*
		*	\since version 0.0.2
		*/
		void computeJoints()
		{
			zTransform Tbase;
			Tbase.setIdentity();

			for (int i = 0; i < DOF; i++)
			{		 
				Tbase = Tbase * Bars[i].T;
				robotJoint_matrices[i] = Tbase;
			}

			update_robotJointGraph();

			update_robotJointMeshes();
		}

		/*! \brief This Methods computes the forward kinematics chain of zRobot for the specified joint rotation values.
		*
		*	\param		[in]	type		- robot joint rotation type.
		*	\since version 0.0.2
		*/
		zVector forwardKinematics(robotRotationType rotType = zJoint)
		{
			zVector out;


			if (rotType != zJoint)
			{
				for (int i = 0; i < DOF; i++)
				{
					if (rotType == zJointHome) jointRotations[i].rotation = jointRotations[i].home;
					if (rotType == zJointMinimum) jointRotations[i].rotation = jointRotations[i].minimum;
					if (rotType == zJointMaximum) jointRotations[i].rotation = jointRotations[i].maximum;
				}
			}

			for (int i = 0; i < DOF; i++)
			{
				if (isnan(jointRotations[i].rotation))
				{
					printf("\n joint %i roation isNAN.", i);
				}

				Bars[i].linkDH.theta = (jointRotations[i].rotation)  * DEG_TO_RAD;
			}

			for (int i = 0; i < DOF; i++)Bars[i].updateTransform();

			computeJoints();
			out = zVector(robotJoint_matrices[DOF - 1](0, 3), robotJoint_matrices[DOF - 1](1, 3), robotJoint_matrices[DOF - 1](2, 3));

			return out;

		}

		/*! \brief This Methods computes the inverse kinematics chain of the robot .
		*
		*	\since version 0.0.2
		*/
		zVector inverseKinematics()
		{
			// compute target for joint 6
			zMatrixd Target_J6 = robot_target_matrix * robot_endEffector_matrix;

			// CALCULATE WRIST CENTER
			zVector wristC = zVector(Target_J6(0, 3), Target_J6(1, 3), Target_J6(2, 3));

			wristC -= (zVector(Target_J6(0, 2), Target_J6(1, 2), Target_J6(2, 2)) * Bars[5].linkDH.d * 1);

			// CALCULATE FIRST 3 ANGLES
			double th0 = atan2(wristC.y, wristC.x);

			// x and y of wc in joint 1's basis
			double r = sqrt(wristC.x * wristC.x + wristC.y * wristC.y) - Bars[0].linkDH.a;
			double s = Bars[0].linkDH.d - wristC.z;

			// relevant joint lengths
			double a1 = Bars[1].linkDH.a;
			double a2 = sqrt(Bars[2].linkDH.a * Bars[2].linkDH.a + Bars[3].linkDH.d * Bars[3].linkDH.d);

			// 3rd angle
			double d = (r * r + s * s - a1 * a1 - a2 * a2) / (2.0 * a1 * a2);
			double th2 = atan2(sqrt(1.0 - d * d), d); // negate for alt sol'n

													  // 2nd angle
			double k1 = a1 + a2 * cos(th2);
			double k2 = a2 * sin(th2);
			double th1 = atan2(s, r) - atan2(k2, k1);


			jointRotations[0].rotation = th0 * RAD_TO_DEG;
			jointRotations[1].rotation = (th1)* RAD_TO_DEG;

			double dq2 = atan2(Bars[2].linkDH.a, Bars[3].linkDH.d);
			jointRotations[2].rotation = (((th2 + dq2) * RAD_TO_DEG) - 90 /*- home_rotations[2]*/) * 1;

			

			// SET FORWARD
			forwardKinematics();


			// SOLVE LAST 3 ANGLES

			zMatrixd r03 = Bars[0].T * Bars[1].T * Bars[2].T;		

			zMatrixd r36 = r03.transpose() * Target_J6;
			double t = r36(2, 2);

			double th3 = atan2(-r36(1, 2), -r36(0, 2));
			double th4 = atan2(1.0 * sqrt(1.0 - t * t), t);
			double th5 = atan2(-r36(2, 1), r36(2, 0));

			jointRotations[3].rotation = (th3 * RAD_TO_DEG);
			jointRotations[4].rotation = (th4 * RAD_TO_DEG) ;
			jointRotations[5].rotation = (th5 * RAD_TO_DEG);

			// SET FORWARD
			forwardKinematics();

			zVector out(robotJoint_matrices[DOF - 1](0, 3), robotJoint_matrices[DOF - 1](1, 3), robotJoint_matrices[DOF - 1](2, 3));

			return out;
		}

		//--------------------------
		//----GCODE METHODS
		//--------------------------

	protected:

		/*! \brief This method create a graph connecting all the joint positions.
		*
		*	\since version 0.0.2
		*/
		void createRobotJointGraph()
		{
			vector<zVector> positions;
			vector<int> edgeConnects;

			positions.push_back(zVector());

			for (int i = 0; i < DOF; i++)
			{
				zVector pos; 
				pos.x = robotJoint_matrices[i](0, 3);
				pos.y = robotJoint_matrices[i](1, 3);
				pos.z = robotJoint_matrices[i](2, 3);

				positions.push_back(pos);
			}

			for (int i = 1; i < positions.size(); i++)
			{
				edgeConnects.push_back(i - 1);
				edgeConnects.push_back(i);
			}

			fnGraphJoint.create(positions, edgeConnects);

		}

		/*! \brief This method updates the joint graph based on the jint rotation matrices.
		*
		*	\since version 0.0.2
		*/
		void update_robotJointGraph()
		{
			for (int i = 0; i < DOF; i++)
			{
				zVector pos;
				pos.x = robotJoint_matrices[i](0, 3);
				pos.y = robotJoint_matrices[i](1, 3);
				pos.z = robotJoint_matrices[i](2, 3);

				fnGraphJoint.setVertexPosition(i + 1, pos);				
			}
		}

		/*! \brief This method update the positions of the joint meshes based on joint positions.
		*
		*	\since version 0.0.2
		*/
		void update_robotJointMeshes()
		{
			zMatrixd standardBasis;
			standardBasis.setIdentity();

			// find transfrom from standard basis to new basis
			zMatrixd basisTransform = coreUtils.PlanetoPlane(standardBasis, robot_base_matrix);

			zMatrixd robot_EE_matrices = robotJointMesh_matrices[DOF - 1];

			for (int i = 0; i < fnMeshJoints.size(); i++)
			{
				// transform each joint to local coordinates

				zMatrixd tMat_local;
				tMat_local.setIdentity();

				if (i > 0 && i <= DOF) 	tMat_local = robotJointMesh_matrices[i - 1];
				if (i > DOF) tMat_local = robot_EE_matrices;

				zMatrixd result_toLocal = coreUtils.toLocalMatrix(tMat_local);

				//printf("\n robotJointMesh_matrices : %i ", robotJointMesh_matrices.size());

				for (int j = 0; j < fnMeshJoints[i].numVertices(); j++)
				{

					zVector pos = fnMeshJoints[i].getVertexPosition(j);

					zVector new_pos = pos * result_toLocal;

					if (!isnan(new_pos.x) && !isnan(new_pos.y) && !isnan(new_pos.z))
					{
						fnMeshJoints[i].setVertexPosition(j, new_pos);

					}

				}

				// transform to world coordinates
				if (i > 0 && i <= DOF)
				{
					zMatrixd tMat_world = robotJoint_matrices[i - 1];
					zMatrixd result_toWorld = coreUtils.toWorldMatrix(tMat_world);

					for (int j = 0; j < fnMeshJoints[i].numVertices(); j++)
					{

						zVector pos = fnMeshJoints[i].getVertexPosition(j);

						zVector new_pos = pos * result_toWorld;

						if (!isnan(new_pos.x) && !isnan(new_pos.y) && !isnan(new_pos.z))
						{
							fnMeshJoints[i].setVertexPosition(j, new_pos);
						}



					}

					robotJointMesh_matrices[i - 1] = robotJoint_matrices[i - 1];
				}

				if (i > DOF)
				{
					zMatrixd tMat_world = robotJoint_matrices[DOF - 1];
					zMatrixd result_toWorld = coreUtils.toWorldMatrix(tMat_world);

					for (int j = 0; j < fnMeshJoints[i].numVertices(); j++)
					{

						zVector pos = fnMeshJoints[i].getVertexPosition(j);
						zVector new_pos = pos * result_toWorld;

						if (!isnan(new_pos.x) && !isnan(new_pos.y) && !isnan(new_pos.z))
						{
							fnMeshJoints[i].setVertexPosition(j, new_pos);
						}
					}

				}
			}
		}

		//--------------------------
		//---- FACTORY METHODS
		//--------------------------

		/*! \brief This method imports robot from a JSON file format using JSON Modern Library.
		*
		*	\param [in]		infilename			- input file name including the directory path and extension.
		*	\since version 0.0.2
		*/
		void fromJSON(string infilename)
		{
			json j;
			zUtilsJsonRobot robotJSON;

			ifstream in_myfile;
			in_myfile.open(infilename.c_str());

			int lineCnt = 0;

			if (in_myfile.fail())
			{
				cout << " error in opening file  " << infilename.c_str() << endl;
				return;
			}

			in_myfile >> j;
			in_myfile.close();


			// READ Data from JSON
			
			robotJSON.scale = (j["scale"].get<int>());

			robot_scale = robotJSON.scale;

			//DH
			robotJSON.d = (j["d"].get<vector<double>>());

			robotJSON.a = (j["a"].get<vector<double>>());

			robotJSON.alpha = (j["alpha"].get<vector<double>>());

			robotJSON.theta = (j["theta"].get<vector<double>>());

			for (int i = 0; i < DOF; i++)
			{
				zDHparameter DH;

				DH.alpha = robotJSON.alpha[i] * DEG_TO_RAD;
				DH.d = robotJSON.d[i] * robot_scale;
				DH.theta = robotJSON.theta[i] * DEG_TO_RAD;
				DH.a = robotJSON.a[i] * robot_scale;

				Bars.push_back(zLink(DH));

				robot_DH.push_back(DH);
			}

			// joint rotation

			robotJSON.jointRotations_home = (j["jointRotations_home"].get<vector<double>>());

			robotJSON.jointRotations_minimum = (j["jointRotations_minimum"].get<vector<double>>());

			robotJSON.jointRotations_maximum = (j["jointRotations_maximum"].get<vector<double>>());

			robotJSON.jointRotations_pulse = (j["jointRotations_pulse"].get<vector<double>>());

			robotJSON.jointRotations_mask = (j["jointRotations_mask"].get<vector<double>>());

			robotJSON.jointRotations_offset = (j["jointRotations_offset"].get<vector<double>>());


			for (int i = 0; i < DOF; i++)
			{
				zJointRotation jointRot;
				jointRot.home = robotJSON.jointRotations_home[i];
				jointRot.minimum = robotJSON.jointRotations_minimum[i];
				jointRot.maximum = robotJSON.jointRotations_maximum[i];
				jointRot.rotation = 0;
				jointRot.pulse = robotJSON.jointRotations_pulse[i];
				jointRot.mask = robotJSON.jointRotations_mask[i];
				jointRot.offset = robotJSON.jointRotations_offset[i];
				jointRotations.push_back(jointRot);


				robotJoint_matrices.push_back(zMatrixd());
				robotJointMesh_matrices.push_back(zMatrixd());
			}

		}
	};

}