#include "vec3.hpp"


void vec3::rotX(float rad){
	float tY=this->y;float tZ=this->z;
	this->y=cos(rad)*tY-sin(rad)*tZ;
	this->z=sin(rad)*tY+cos(rad)*tZ;
}

void vec3::rotY(float rad){
	float tX=this->x;float tZ=this->z;
	this->x=cos(rad)*tX+sin(rad)*tZ;
	this->z=-sin(rad)*tX+cos(rad)*tZ;
}

void vec3::rotZ(float rad){
	float tX=this->x;float tY=this->y;
	this->x=cos(rad)*tX-sin(rad)*tY;
	this->y=sin(rad)*tX+cos(rad)*tY;
}

void vec3::scale(float coef){
	this->x*=coef;
	this->y*=coef;
	this->z*=coef;
}

float vec3::distance(vec3& v) {
    float dx,dy,dz;
    dx = this->x - v.x;
    dy = this->y - v.y;
    dz = this->z - v.z;
    return (float) sqrt(dx*dx + dy*dy + dz*dz);
}

void vec3::print(){
    std::cout<<"("<<this->x<<","<<this->y<<","<<this->z<<")"<<std::endl;
}

void vec3::assign(float xV,float yV,float zV){
	this->x=xV;this->y=yV;this->z=zV;
}

bool vec3::disp2D(){
	return (this->x>=0&&this->y>=0)?true:false;
}

vec3::vec3(){
	this->x=0.0;this->y=0.0;this->z=0.0;
}

vec3::vec3(float xVal,float yVal,float zVal){
	this->x=xVal;this->y=yVal;this->z=zVal;
}

float vec3::norm() {
    return sqrt(x*x + y*y + z*z);
}
