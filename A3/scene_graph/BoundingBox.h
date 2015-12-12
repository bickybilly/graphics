#ifndef __BOUNDINGBOX_H__	//guard against cyclic dependancy
#define __BOUNDINGBOX_H__
#include "node.h"

#include <gl/glut.h>
#include "plane.h"

class BoundingBox {
public:
	//constructor
	BoundingBox(double size);

	//destructor
	~BoundingBox();

	bool intersects(int x, int y);
	double intersects(double* near, double* far);
private:
	Plane * top;
	Plane * bottom;
	Plane * left;
	Plane * right;
	Plane * front;
	Plane * back;
	//int objectSize;
};

#endif