#ifndef VEC3_HPP
#define VEC3_HPP


#include <iostream>
#include <cmath>

class vec3{
public:
	float x;
	float y;
	float z;

	void rotX(float);
	void rotY(float);
	void rotZ(float);
	void scale(float);

    float distance(vec3& v);

	void print();
	void assign(float,float,float);
	bool disp2D();

	vec3();
	vec3(float,float,float);
	vec3 operator+(const vec3&pt){
		vec3 res;
		res.x = this->x + pt.x;
		res.y = this->y + pt.y;
		res.z = this->z + pt.z;
		return res;
	};
	
	void operator+=(const vec3&pt){
		this->x += pt.x;
		this->y += pt.y;
		this->z += pt.z;
	};

	void operator/=(const float&a){
		this->x /= a;
		this->y /= a;
		this->z /= a;
	};

	void operator*=(const float&a){
		this->x *= a;
		this->y *= a;
		this->z *= a;
	};

	vec3 operator-(const vec3&pt){
		vec3 res;
		res.x = this->x - pt.x;
		res.y = this->y - pt.y;
		res.z = this->z - pt.z;
		return res;
	};
	
	void operator-=(const vec3&pt){
		this->x -= pt.x;
		this->y -= pt.y;
		this->z -= pt.z;
	};

	vec3 operator/(const float&a){
		vec3 res;
		res.x = this->x / a;
		res.y = this->y / a;
		res.z = this->z / a;
		return res;
	};

	vec3 operator*(const float&a){
		vec3 res;
		res.x = this->x * a;
		res.y = this->y * a;
		res.z = this->z * a;
		return res;
	};

    float norm();
};

#endif // VEC3_HPP
