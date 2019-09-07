#include "0516097_matrix33.h"
#include <iostream>
#include <iomanip>
using namespace std;

matrix33::matrix33(){
}
matrix33::matrix33(const matrix33 &v){
	x = v.x ;
	y = v.y ;
	z = v.z ;
}

matrix33::matrix33(const vector3 &a,const vector3 &b,const vector3 &c){
	x = a ;
	y = b ;
	z = c ;
}

matrix33 matrix33::identity(){
	x.x = 1;	y.x = 0;	z.x = 0;
	x.y = 0;	y.y = 1; 	z.y = 0;
	x.z = 0;	y.z = 0; 	z.z = 1;
}

void matrix33::printMatrix() const{
	cout<<setw(3)<<x.x<<setw(3)<<" "<<setw(3)<<y.x <<setw(3)<<" "<<setw(3)<<z.x<<setw(3)<<" "<<endl;
	cout<<setw(3)<<x.y<<setw(3)<<" "<<setw(3)<<y.y <<setw(3)<<" "<<setw(3)<<z.y<<setw(3)<<" "<<endl;
	cout<<setw(3)<<x.z<<setw(3)<<" "<<setw(3)<<y.z <<setw(3)<<" "<<setw(3)<<z.z<<setw(3)<<" "<<endl;
}

float matrix33::determinant(){
	float det;
	det = x.x*y.y*z.z + x.y*y.z*z.x + x.z*y.x*z.y - x.z*y.y*z.x - y.x*x.y*z.z - x.x*y.z*z.y;
		return det;
}

matrix33 matrix33::invert(){
	matrix33 temp;
	temp.x.x = (y.y*z.z-z.y*y.z)/determinant();		
	temp.x.y = -(x.y*z.z-z.y*x.z)/determinant();		
	temp.x.z = (x.y*y.z-y.y*x.z)/determinant();
	temp.y.x = -(y.x*z.z-z.x*y.z)/determinant();
	temp.y.y = (x.x*z.z-z.x*x.z)/determinant();
	temp.y.z = -(x.x*y.z-y.x*x.z)/determinant();
	temp.z.x = (y.x*z.y-z.x*y.y)/determinant();
	temp.z.y = -(x.x*z.y-z.x*x.y)/determinant();
	temp.z.z = (x.x*y.y-y.x*x.y)/determinant();
	return temp;
}


matrix33 &matrix33::operator = (const matrix33 &v){
	if(&v != this){
		x = v.x;
		y = v.y;
		z = v.z;
	}
	return *this;
}

matrix33 & matrix33::operator += (const matrix33 &v){
	x = x + v.x;
	y = y + v.y;
	z = z + v.z;
	return *this;
}

matrix33 &matrix33::operator -= (const matrix33 &v){
	x = x - v.x;
	y = y - v.y;
	z = z - v.z;
	return *this;	
}

matrix33 &matrix33::operator*=(float f){
	x = x*f;
	y = y*f;
	z = z*f;
	return *this;
}

matrix33 &matrix33::operator/=(float f){
	x = x/f;
	y = y/f;
	z = z/f;
	return *this;
}

bool operator == (const matrix33 &a, const matrix33 &b){
	if(a.x==b.x && a.y ==b.y && a.z == b.z){
		return true;
	}
	else{
		return false;
	}
}
bool operator != (const matrix33 &a, const matrix33 &b){
	if(a.x==b.x && a.y ==b.y && a.z == b.z){
		return false;
	}
	else{
		return true;
	}
}

matrix33 operator - (const matrix33 &v){
	return matrix33(-v.x,-v.y,-v.z);
}
matrix33 operator + (const matrix33 &a, const matrix33 &b){
	
	return matrix33(a.x+b.x, a.y+b.y, a.z+b.z) ; 
}

matrix33 operator - (const matrix33 &a, const matrix33 &b){
	
	return matrix33(a.x-b.x, a.y-b.y, a.z-b.z) ; 
}

matrix33 operator * (const matrix33 &v, float f){
	
	return matrix33(v.x*f, v.y*f, v.z*f); 
}


matrix33 operator * (float f,const matrix33 &v ){
	
	return matrix33(v.x*f, v.y*f, v.z*f); 
}

matrix33 operator / (const matrix33 &v, float f){
	
	return matrix33(v.x/f, v.y/f, v.z/f);
}

matrix33 operator * (const matrix33 &a, const matrix33 &b){
	matrix33 temp;
	temp.x.x = a.x.x*b.x.x + a.y.x*b.x.y + a.z.x*b.x.z;
	temp.y.x = a.x.x*b.y.x + a.y.x*b.y.y + a.z.x*b.y.z;
	temp.z.x = a.x.x*b.z.x + a.y.x*b.z.y + a.z.x*b.z.z;
	temp.x.y = a.x.y*b.x.x + a.y.y*b.x.y + a.z.y*b.x.z;
	temp.y.y = a.x.y*b.y.x + a.y.y*b.y.y + a.z.y*b.y.z;
	temp.z.y = a.x.y*b.z.x + a.y.y*b.z.y + a.z.y*b.z.z;
	temp.x.z = a.x.z*b.x.x + a.y.z*b.x.y + a.z.z*b.x.z;
	temp.y.z = a.x.z*b.y.x + a.y.z*b.y.y + a.z.z*b.y.z;	
	temp.z.z = a.x.z*b.z.x + a.y.z*b.z.y + a.z.z*b.z.z;
	return temp;
	
}

vector3 &  matrix33::operator[] ( unsigned int r ) {
	
  	if(r==0){
		return x;
	}
	if(r==1){
		return y;
	}
	if(r==2){
		return z;
	}
}





