#include <gl/glut.h>
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include "sceneObj.h"

/*SceneObj*/
SceneObj::SceneObj(int ID, NodeTransform *transNode, NodeTransform *scaleNode, NodeTransform *rotNode, NodeMaterial *matNode, NodeModel *modelNode){ //modify this to include instantiation of material, later
	this->ID = ID;
	this->transNode = transNode;
	this->scaleNode = scaleNode;
	this->rotNode = rotNode;
	this->matNode = matNode;
	this->modelNode = modelNode;

	//add bounding box
}

void SceneObj::rotate(float angleX, float angleY, float angleZ){
	rotNode->amount3.x += angleX;
	rotNode->amount3.y += angleY;
	rotNode->amount3.z += angleZ;
	printf("angleX = %f \n",rotNode->amount3.x);
		printf("angleY = %f \n",rotNode->amount3.y);
		printf("angleZ = %f \n",rotNode->amount3.z);
}

void SceneObj::scale(float x, float y, float z){
	scaleNode->amount3.x += x;
	scaleNode->amount3.y += y;
	scaleNode->amount3.z += z;
}

void SceneObj::translate(float x, float y, float z){
	transNode->amount3.x += x;
	transNode->amount3.y += y;
	transNode->amount3.z += z;
	printf("hello");
}

//print method
//makes use of Point print method as well
// void SceneObj::print(){
// 	printf("position: ");
// 	this->position.print();
// 	printf("scale: ");
// 	this->scaleFactor.print();
// 	printf("orientation: ");
// 	this->orientation.print();
// }

/*TESTING
int main(int argc, char** argv){
	float array[4] = {0.5,0.5,0.5,1};
	Material someMat = Material(array, array, array, array, 0.5);
	SceneObj* sphere1 = new SceneObj(SPHERE, someMat);
	sphere1->print();
	printf("\n");
	sphere1->scale(-2,4,6);
	sphere1->scale(0.5,0.5,0.5);
	sphere1->move(-1,-2,1);
	sphere1->move(1,2,0);
	sphere1->print();
	return 0;
}*/