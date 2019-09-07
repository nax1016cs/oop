#include "0516097_vector3.h"
#include <iostream>
using namespace std;
#include <math.h>
#include <iomanip>
vector3::vector3(){
}
vector3::vector3(float inX, float inY, float inZ){
	x = inX;
	y = inY;
	z = inZ;
}
vector3::vector3(const vector3 &v){
	x = v.x;
	y = v.y;
	z = v.z;
}

vector3 &vector3::operator = (const vector3 &v){
	if(&v != this){
		x = v.x;
		y = v.y;
		z = v.z;
	}
	return *this;
}
vector3 &vector3::operator += (const vector3 &v){
	x = x + v.x;
	y = y + v.y;
	z = z + v.z;
	return *this;
}

vector3 &vector3::operator -= (const vector3 &v){
	x = x - v.x;
	y = y - v.y;
	z = z - v.z;
	return *this;	
}

vector3 &vector3::operator*=(float f){
	x = x*f;
	y = y*f;
	z = z*f;
	return *this;
}

vector3 &vector3::operator/=(float f){
	x = x/f;
	y = y/f;
	z = z/f;
	return *this;
}

bool operator == (const vector3 &a, const vector3 &b){
	if(a.x==b.x && a.y ==b.y && a.z == b.z){
		return true;
	}
	else{
		return false;
	}
}
bool operator != (const vector3 &a, const vector3 &b){
	if(a.x==b.x && a.y ==b.y && a.z == b.z){
		return false;
	}
	else{
		return true;
	}
}

vector3 operator - (const vector3 &a){
	return vector3(-a.x, -a.y, -a.z) ;
}
vector3 operator + (const vector3 &a, const vector3 &b){
	
	return vector3(a.x+b.x, a.y+b.y, a.z+b.z) ; 
}

vector3 operator - (const vector3 &a, const vector3 &b){
	
	return vector3(a.x-b.x, a.y-b.y, a.z-b.z) ; 
}

vector3 operator * (const vector3 &v, float f){
	
	return vector3(v.x*f, v.y*f, v.z*f); 
}


vector3 operator * (float f,const vector3 &v ){
	
	return vector3(v.x*f, v.y*f, v.z*f); 
}

vector3 operator / (const vector3 &v, float f){
	
	return vector3(v.x/f, v.y/f, v.z/f);
}
float vector3::length() const{
	int square;
	square = x*x + y*y + z*z;
	return sqrt(square);
}

void vector3::set(float xIn, float yIn, float zIn){
	x = xIn;
	y = yIn;
	z = zIn;
}

float &vector3::operator[](unsigned int index){
	if(index==0){
		return x;
	}
	if(index==1){
		return y;
	}
	if(index==2){
		return z;
	}
	
}

const float &vector3::operator[](unsigned int index) const{
	if(index==0){
		return x;
	}
	if(index==1){
		return y;
	}
	if(index==2){
		return z;
	}
}

void vector3::printVector3() const{
	cout<< "(" << x << "," << y << "," << z << ")";
}
