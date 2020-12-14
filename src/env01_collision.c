#include "level01.h"
//Test Object = 1 



//courtyard area
extern MeshCollider env01_ground_collision_MeshVtx_0 [];
extern MeshColliderTri env01_ground_collision_MeshTri[];
extern MeshCollider env01_walls_collision_MeshVtx_0 [];
extern MeshColliderTri env01_walls_collision_MeshTri[];


//loadingzone 00-01 area
extern MeshCollider env01_wall_loadzone_collision_MeshVtx_0 [];
extern MeshColliderTri env01_wall_loadzone_collision_MeshTri[];
extern MeshCollider env01_ground_loadzone_collision_MeshVtx_0 [];
extern MeshColliderTri env01_ground_loadzone_collision_MeshTri[];


extern 	MeshCollider Landing003_MeshVtx_0 []	;
extern 	MeshColliderTri Landing003_MeshTri[]	;
extern 	MeshCollider Landing_Ground003_MeshVtx_0 []	;
extern 	MeshColliderTri Landing_Ground003_MeshTri[]	;

//NOTE: The tempTri is used to store the vertex and normal data to check with physics
MeshCollider tempTri[] =
{
	{ 0, 0, 0, 0, 0, 0}, 
	{ 0, 0, 0, 0, 0, 0}, 
	{ 0, 0, 0, 0, 0, 0}, 
};
MeshCollider tempGroundTri[] =
{
	{ 0, 0, 0, 0, 0, 0}, 
	{ 0, 0, 0, 0, 0, 0}, 
	{ 0, 0, 0, 0, 0, 0}, 
};



	//Vector3 currentCollisionPoint = {5000,5000,5000};
	Vector3 tempCollisionPoint;
	Vector3 tempGroundCollisionPoint;
	
	
	
	//u8 checkCollision = 0;
	//u8 nextPosCheck = 0;

	//u8 collidedWithObject = 0;
	Vector3 triNormalWall = {0.0, 0.0, 0.0}; //calculate the normal of the nearest plane that is being collided with
	u8 newWallPoint = 0; //if the nearest point on a wall has been updated, set to true
	u8 isAgainstWall = 0; //NOTE: if player is colliding with a wall or obstruction, set to true
	u8 closestTriWall = 0;
	
	Vector3 triNormalGround = {0.0, 0.0, 0.0}; // calculate the normal to be sliding across as colliding with a triangle
	u8 newGroundPoint = 0; //if the nearest point on a wall has been updated, set to true
	u8 isGrounded = 0; //NOTE: if player is colliding with the ground, set to true
	u8 closestTriGround = 0;
	u8 closestGroundTri[2] = {0,0}; //[0] = meshID 0, [1] = closest tri on meshID etc
	
	MeshCollider *lvl01_ground_collision_MeshVTXP[3] =
	{
		env01_ground_loadzone_collision_MeshVtx_0,
		env01_ground_collision_MeshVtx_0,
		Landing_Ground003_MeshVtx_0
		
	}; //mesh collider pointers
	MeshColliderTri *lvl01_ground_collision_MeshTriP[3] =
	{
		env01_ground_loadzone_collision_MeshTri,
		env01_ground_collision_MeshTri,
		Landing_Ground003_MeshTri
		
	}; //mesh collider pointers
	
	
u8 groundMesh_CollisionCheck(Sphere* sphereCollider)
{
	short counterB = 0;
	short triMeshLength = 121; // there are 3 verts per tri 	
	u8 meshID = 0;

	
	isGrounded = 0;
	groundCollisionPoints.lastCollisionPoint = groundCollisionPoints.currentCollisionPoint;	
	
	
	
	/*--------------------------------------------------------------------------*/
	/*----------Find The Nearest Point and Nearest Triangle on Mesh-------------*/
	/*-------------------------------------------------------------------------*/
	
	

	newGroundPoint = 0;

		//NOTE: refine this so it is less choppy? 
	
	/*
	tempGroundTri[0].vertex = lvl01_ground_collision_MeshVTXP[closestGroundTri[0]][lvl01_ground_collision_MeshTriP[closestGroundTri[0]][closestGroundTri[1]].tri[0]].vertex;
	tempGroundTri[1].vertex = lvl01_ground_collision_MeshVTXP[closestGroundTri[0]][lvl01_ground_collision_MeshTriP[closestGroundTri[0]][closestGroundTri[1]].tri[1]].vertex;
	tempGroundTri[2].vertex = lvl01_ground_collision_MeshVTXP[closestGroundTri[0]][lvl01_ground_collision_MeshTriP[closestGroundTri[0]][closestGroundTri[1]].tri[2]].vertex;
	newGroundPoint = LineToGroundPoint(&playerAvatar.sphereCollider, tempGroundTri[0],tempGroundTri[1],tempGroundTri[2], &tempGroundCollisionPoint);	
	*/

	if(newGroundPoint == 0)
	{
		for(meshID = 0; meshID < 3; meshID++)
		{
		
			if(lvl01_collision_trig_env[meshID].trigger.isActive == 1)		
			{					
					if(meshID == 0)
						triMeshLength = 55;
						
					if(meshID == 1)
						triMeshLength = 119;
					if(meshID == 2)
						triMeshLength = 62;
					
						for(counterB = 0; counterB < triMeshLength; counterB ++)
						{		
							newGroundPoint = 0;
							
							//NOTE: assign mesh data from array to tempGroundTri 
							tempGroundTri[0].vertex = lvl01_ground_collision_MeshVTXP[meshID][lvl01_ground_collision_MeshTriP[meshID][counterB].tri[0]].vertex;
							tempGroundTri[1].vertex = lvl01_ground_collision_MeshVTXP[meshID][lvl01_ground_collision_MeshTriP[meshID][counterB].tri[1]].vertex;
							tempGroundTri[2].vertex = lvl01_ground_collision_MeshVTXP[meshID][lvl01_ground_collision_MeshTriP[meshID][counterB].tri[2]].vertex;
							
							//NOTE: Extend a ray down from the center of the player collider and check each nearby tri to see if a collision is occuring. 
							//Get the closest point on the tri polygon and set the player's vertical position.
							newGroundPoint = LineToGroundPoint(&playerAvatar.sphereCollider, tempGroundTri[0],tempGroundTri[1],tempGroundTri[2], &tempGroundCollisionPoint);					
							

							if(newGroundPoint == 1)
							{
								GroundDistanceComparison(&playerAvatar.sphereCollider.center, tempGroundCollisionPoint, &groundCollisionPoints.currentCollisionPoint);

								groundCollisionPoints.currentCollisionPoint = tempGroundCollisionPoint;			
								closestGroundTri[0] = meshID;
								closestGroundTri[1] = counterB;
								groundCollisionPoints.triNum = closestGroundTri[1];

								playerAvatar.rigidBody.nextPos.z = tempGroundCollisionPoint.z;
							}		
							
						}
					
					
					if(newGroundPoint == 1)
					{
						groundCollisionPoints.currentCollisionPoint = tempGroundCollisionPoint;			
						//closestTriGround = counterB;
						groundCollisionPoints.triNum = closestGroundTri[1];
						playerAvatar.rigidBody.nextPos.z = tempGroundCollisionPoint.z;
					}	
			}
		}
	}
		
		isGrounded = AgainstGround(&playerAvatar.sphereCollider, &tempGroundCollisionPoint);

		
	/*END-------Find The Nearest Point and Nearest Triangle on Mesh-------------*/
	

return isGrounded;

}

	
u8 getGroundCheck(Sphere* sphereCollider)
{
	u8 tempBool;

		tempBool = 0;

		if(absDistance(groundCollisionPoints.currentCollisionPoint, playerAvatar.sphereCollider.center) <= 30)
			tempBool = 1;
			
		return tempBool;
			
			
}	

	
	
	
	
	
	
	u8 closestWallTri[2] = {0,0}; //[0] = meshID 0, [1] = closest tri on meshID etc
	
	MeshCollider *lvl01_wall_collision_MeshVTXP[3] =
	{
		env01_wall_loadzone_collision_MeshVtx_0,
		env01_walls_collision_MeshVtx_0,
		Landing003_MeshVtx_0
		
	}; //mesh collider pointers
	MeshColliderTri *lvl01_wall_collision_MeshTriP[3] =
	{
		env01_wall_loadzone_collision_MeshTri,
		env01_walls_collision_MeshTri,
		Landing003_MeshTri
	}; //mesh collider pointers
	
		
	
u8 testMesh_CollisionCheck(Sphere* sphereCollider, Dynamic* ddp)
{


	u8 meshID = 0;
	short counter = 0;
	short triMeshLength = 111; // there are 3 verts per tri 	
	isAgainstWall = 0;
	collisionPoints.lastCollisionPoint = collisionPoints.currentCollisionPoint;	
		
	newWallPoint = 0;	
		
		
	if(newGroundPoint == 0)
	{
		for(meshID = 0; meshID < 3; meshID++)
		{
		
			if(lvl01_collision_trig_env[meshID].trigger.isActive == 1)		
			{					
					if(meshID == 0) //loadzone 00-01
						triMeshLength = 18;						
					if(meshID == 1) //courtyard
						triMeshLength = 111;		
					if(meshID == 2) //courtyard
						triMeshLength = 110;		
		
		
					for(counter = 0; counter < triMeshLength; counter ++)
					{		
						newWallPoint = 0;
						
						//assign mesh data from array to tempTri 
						/*
							tempGroundTri[0].vertex = lvl01_ground_collision_MeshVTXP[meshID][lvl01_ground_collision_MeshTriP[meshID][counterB].tri[0]].vertex;
							tempGroundTri[1].vertex = lvl01_ground_collision_MeshVTXP[meshID][lvl01_ground_collision_MeshTriP[meshID][counterB].tri[1]].vertex;
							tempGroundTri[2].vertex = lvl01_ground_collision_MeshVTXP[meshID][lvl01_ground_collision_MeshTriP[meshID][counterB].tri[2]].vertex;
						
						*/
						
						
							tempTri[0].vertex = lvl01_wall_collision_MeshVTXP[meshID][lvl01_wall_collision_MeshTriP[meshID][counter].tri[0]].vertex;
							tempTri[1].vertex = lvl01_wall_collision_MeshVTXP[meshID][lvl01_wall_collision_MeshTriP[meshID][counter].tri[1]].vertex;
							tempTri[2].vertex = lvl01_wall_collision_MeshVTXP[meshID][lvl01_wall_collision_MeshTriP[meshID][counter].tri[2]].vertex;
						
						//check to see if a collision is possible and get the closest point on the current polygon.
						newWallPoint = SphereToMeshNearPoint(&playerAvatar.sphereCollider, &tempTri[0],&tempTri[1],&tempTri[2], &tempCollisionPoint);	
						
						if(newWallPoint == 1)
						{
							//closestTriWall = counter;
							closestWallTri[0] = meshID;
							closestWallTri[1] = counter;
						}		
						
					}
					
			}
		}
	}
		
	/*END-------Find The Nearest Point and Nearest Triangle on Mesh-------------*/

	/*--------------------------------------------------------------------------*/
	/*-------------Once the Nearest Point is Found, Check Collision-------------*/
	/*--------------------------------------------------------------------------*/
	
	//NOTE: check to see if any part of the player sphere collider is penetrating the mesh (aka isAgainstWall)
		isAgainstWall = AgainstWall(&playerAvatar.sphereCollider, &tempCollisionPoint);
		collisionPoints.triNum = closestWallTri[1];
		collisionPoints.currentCollisionPoint = tempCollisionPoint;
	
	/*END----------Once the Nearest Point is Found, Check Collision-------------*/
	
	
	
	
	/*--------------------------------------------------------------------------*/
	/*------------------Calculate New Position When Colliding-------------------*/
	/*--------------------------------------------------------------------------*/
		
	//NOTE: if player will be penetrating the wall in the next position, calculate a new adjusted position 
		if(isAgainstWall == 1)
		{
			clearVariables(1);
		
			tempTri[0].vertex = lvl01_wall_collision_MeshVTXP[closestWallTri[0]][lvl01_wall_collision_MeshTriP[closestWallTri[0]][closestWallTri[1]].tri[0]].vertex;
			tempTri[1].vertex = lvl01_wall_collision_MeshVTXP[closestWallTri[0]][lvl01_wall_collision_MeshTriP[closestWallTri[0]][closestWallTri[1]].tri[1]].vertex;
			tempTri[2].vertex = lvl01_wall_collision_MeshVTXP[closestWallTri[0]][lvl01_wall_collision_MeshTriP[closestWallTri[0]][closestWallTri[1]].tri[2]].vertex;
		
			//tempTri[0].vertex = env01_walls_collision_MeshVtx_0[env01_walls_collision_MeshTri[closestTriWall].tri[0]].vertex;
		//	tempTri[1].vertex = env01_walls_collision_MeshVtx_0[env01_walls_collision_MeshTri[closestTriWall].tri[1]].vertex;
			//tempTri[2].vertex = env01_walls_collision_MeshVtx_0[env01_walls_collision_MeshTri[closestTriWall].tri[2]].vertex;
			
			CalcTriNormal(&tempTri[0], &tempTri[1], &tempTri[2], &triNormalWall);
			CalcSlidingPlane(closestTriWall, &playerAvatar.rigidBody.velocity, &collisionPoints, &playerAvatar.sphereCollider, &tempCollisionPoint, triNormalWall, &playerAvatar.rigidBody.nextPos);

		}	
		
		else
		{
			//collidedWithObject = 0;
		}
	
	/*END---------------Calculate New Position When Colliding-------------------*/
	

	

return isAgainstWall;

}

	
	
	
	
u8 testMesh_CollisionCheckOLD(Sphere* sphereCollider, Dynamic* ddp)
{


	u8 meshID = 0;
	short counter = 0;
	short triMeshLength = 111; // there are 3 verts per tri 	
	isAgainstWall = 0;
	collisionPoints.lastCollisionPoint = collisionPoints.currentCollisionPoint;	
		
		if(newWallPoint == 0)
		{
			for(counter = 0; counter < triMeshLength; counter ++)
			{		
				newWallPoint = 0;
				
				//assign mesh data from array to tempTri 
				tempTri[0].vertex = env01_walls_collision_MeshVtx_0[env01_walls_collision_MeshTri[counter].tri[0]].vertex;
				tempTri[1].vertex = env01_walls_collision_MeshVtx_0[env01_walls_collision_MeshTri[counter].tri[1]].vertex;
				tempTri[2].vertex = env01_walls_collision_MeshVtx_0[env01_walls_collision_MeshTri[counter].tri[2]].vertex;
				
				//check to see if a collision is possible and get the closest point on the current polygon.
				newWallPoint = SphereToMeshNearPoint(&playerAvatar.sphereCollider, &tempTri[0],&tempTri[1],&tempTri[2], &tempCollisionPoint);	
				
				if(newWallPoint == 1)
				{
					closestTriWall = counter;
				}		
				
			}
		}
		
	/*END-------Find The Nearest Point and Nearest Triangle on Mesh-------------*/

	/*--------------------------------------------------------------------------*/
	/*-------------Once the Nearest Point is Found, Check Collision-------------*/
	/*--------------------------------------------------------------------------*/
	
	//NOTE: check to see if any part of the player sphere collider is penetrating the mesh (aka isAgainstWall)
		isAgainstWall = AgainstWall(&playerAvatar.sphereCollider, &tempCollisionPoint);
		collisionPoints.triNum = closestTriWall;
		collisionPoints.currentCollisionPoint = tempCollisionPoint;
	
	/*END----------Once the Nearest Point is Found, Check Collision-------------*/
	
	
	
	
	/*--------------------------------------------------------------------------*/
	/*------------------Calculate New Position When Colliding-------------------*/
	/*--------------------------------------------------------------------------*/
		
	//NOTE: if player will be penetrating the wall in the next position, calculate a new adjusted position 
		if(isAgainstWall == 1)
		{
			clearVariables(1);
		
			tempTri[0].vertex = env01_walls_collision_MeshVtx_0[env01_walls_collision_MeshTri[closestTriWall].tri[0]].vertex;
			tempTri[1].vertex = env01_walls_collision_MeshVtx_0[env01_walls_collision_MeshTri[closestTriWall].tri[1]].vertex;
			tempTri[2].vertex = env01_walls_collision_MeshVtx_0[env01_walls_collision_MeshTri[closestTriWall].tri[2]].vertex;
			
			CalcTriNormal(&tempTri[0], &tempTri[1], &tempTri[2], &triNormalWall);
			CalcSlidingPlane(closestTriWall, &playerAvatar.rigidBody.velocity, &collisionPoints, &playerAvatar.sphereCollider, &tempCollisionPoint, triNormalWall, &playerAvatar.rigidBody.nextPos);

		}	
		
		else
		{
			//collidedWithObject = 0;
		}
	
	/*END---------------Calculate New Position When Colliding-------------------*/
	

	

return isAgainstWall;

}

	/*--------------------------------------------------------------------------*/
	/*----------Find The Nearest Point and Nearest Triangle on Mesh-------------*/
	/*--------------------------------------------------------------------------*/
		
		//TO DO NOTES------------------------------------: 
		//Use pre-calculated normals exported from Blender to avoid making calculation at run time.
			//Calculate the trinormal using the existing function
			//Calculate it again combining the normals of the vertices into a single face
			//Try to export the face normal directly from blender
			
		//Break up collision into multiple segments 
			//Have a simple box collider for each segment that is slightly larger than the collision for that section. 
			//Check box collider to see if player is in general vicinity
			//if so, check the collision for this region
			//on export, keep track of the lowest x and lowest y values as well as the highest x and highest y values among the exported triangles
			//use this to create a bounding box for collision checks
		/*
		
			waterfall
			    |
	exit1 - [][][][] - exit2
			  [][]
		       []
			    |
			  exit 3
		*/
		//END TO DO NOTES------------------------------------: 

 
 
 