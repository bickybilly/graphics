
#include <stdio.h> //needed for printf command
#include <gl\glut.h>
#include <limits>
#include "boundingBox.h"

BoundingBox::BoundingBox(float objectSize) {
	this->size = objectSize;
	this->top = new Plane(Point(0.0, 1.0, 0.0), Point(0.0, size/2.0, 0.0)); //y is positive
	this->bottom = new Plane(Point(0.0, -1.0, 0.0), Point(0.0, -(size/2.0), 0.0)); //y is negative
	this->left = new Plane(Point(-1.0, 0.0, 0.0), Point(-(size/2.0), 0.0, 0.0)); //x is negative
	this->right = new Plane(Point(1.0, 0.0, 0.0), Point(size/2.0, 0.0, 0.0)); //x is positive
	this->front = new Plane(Point(0.0, 0.0, -1.0), Point(0.0, 0.0, -(size/2.0))); //z is negative
	this->back = new Plane(Point(0.0, 0.0, 1.0), Point(0.0, 0.0, size/2.0)); //z is positive
	this->low = Point(-size/2, -size/2, -size/2);
	this->high = Point(size/2, size/2, size/2);
}

BoundingBox::~BoundingBox() {

}

void BoundingBox::translateBox(float x, float y, float z){
	this->top = new Plane(Point(0.0, 1.0, 0.0), Point(0.0, size/2.0+y, 0.0)); //y is positive
	this->bottom = new Plane(Point(0.0, -1.0, 0.0), Point(0.0, -(size/2.0)+y, 0.0)); //y is negative
	this->left = new Plane(Point(-1.0, 0.0, 0.0), Point(-(size/2.0)+x, 0.0, 0.0)); //x is negative
	this->right = new Plane(Point(1.0, 0.0, 0.0), Point(size/2.0+x, 0.0, 0.0)); //x is positive
	this->front = new Plane(Point(0.0, 0.0, -1.0), Point(0.0, 0.0, -(size/2.0)+z)); //z is negative
	this->back = new Plane(Point(0.0, 0.0, 1.0), Point(0.0, 0.0, size/2.0+z)); //z is positive
}

void BoundingBox::scaleBox(float x, float y, float z){
	this->top = new Plane(Point(0.0, 1.0, 0.0), Point(0.0, size/2.0*y, 0.0)); //y is positive
	this->bottom = new Plane(Point(0.0, -1.0, 0.0), Point(0.0, -(size/2.0)*y, 0.0)); //y is negative
	this->left = new Plane(Point(-1.0, 0.0, 0.0), Point(-(size/2.0)*x, 0.0, 0.0)); //x is negative
	this->right = new Plane(Point(1.0, 0.0, 0.0), Point(size/2.0*x, 0.0, 0.0)); //x is positive
	this->front = new Plane(Point(0.0, 0.0, -1.0), Point(0.0, 0.0, -(size/2.0)*z)); //z is negative
	this->back = new Plane(Point(0.0, 0.0, 1.0), Point(0.0, 0.0, size/2.0*z)); //z is positive
}

double BoundingBox::intersects(double* nearPoint, double* farPoint){
	Point* intersections[6];
	intersections[0] = top->intersects(nearPoint, farPoint);
	intersections[1] = bottom->intersects(nearPoint, farPoint);
	intersections[2] = left->intersects(nearPoint, farPoint);
	intersections[3] = right->intersects(nearPoint, farPoint);
	intersections[4] = back->intersects(nearPoint, farPoint);
	intersections[5] = front->intersects(nearPoint, farPoint);
	double closest = std::numeric_limits<double>::infinity();
	double distance;
	for (int i = 0; i < 6; i++){
		// distance = slab(intersections[i]);
		// if (distance < closest) closest = distance;
	}
	return distance;
}

bool BoundingBox::slab(double* p0, double* pd){
		if (slab(p0[0], pd[0], low.x, high.x)||slab(p0[1], pd[1], low.y, high.y)||slab(p0[2], pd[2], low.z, high.z)){
			return true;
		}
		return false;
}

bool BoundingBox::slab(double a0d, double add, float ah, float al){
	float Tnear = -1000;
	float Tfar = 1000;
	float T1 = 0;
	float T2 = 0;
	float a0 = (float)a0d;
	float ad = (float)add;
	if (ad = 0){
		if (ad < al || a0 > ah){
			return false;
		}
	}
	else{
		T1 = (al-a0)/ad;
		T2 = (ah-a0)/ad;
	}
	if (T1>T2){
		float temp = T1;
		T1 = T2;
		T2 = temp;
	}
	if(T1>Tnear) Tnear = T1;
	if(T2<Tfar) Tfar = T2;
	if(Tnear>Tfar) return false;
	if(Tfar<0) return false;
	return true;		
}