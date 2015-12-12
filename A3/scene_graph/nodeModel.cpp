#include "NodeModel.h"
#include "Point.h"
#include <stdio.h> //needed for printf command
#include <gl\glut.h>

NodeModel::NodeModel(ModelType whatType){	//constructor
	nodeType = model;
	modelType = whatType;
	isDrawable = true;
}

//as the node moves down through it, we want to perform down action
//which in this case means drawing the model
void NodeModel::nodeSpecificCodeDown(){
	switch (modelType){
	case Sphere:
		glutSolidSphere(1, 50, 50);
		break;
	case Cube:
		glutSolidCube(1);
		break;
	case Cone:
		glutSolidCone(0.5,1,50,50);
		break;
	case Torus:
		glutSolidTorus(0.5,0.5,50,50);
		break;
	case Dodecahedron:
		glutSolidDodecahedron();
		break;
	case Lighting:
		glutSolidSphere(0.5,50,50);
		break;
	}
}