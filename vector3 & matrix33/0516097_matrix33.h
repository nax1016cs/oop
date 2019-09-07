#ifndef _MATRIX33_H_
#define _MATRIX33_H_
#include "0516097_vector3.h"
#include <iomanip>


class matrix33 
{ 
	public:
		
		vector3 x,y,z;
		
		matrix33();
		
		matrix33(const vector3 &a, const vector3 &b,const vector3 &c);
		
		matrix33(const matrix33 &v);
		
		matrix33 identity();		
		
		matrix33 invert();
		
		float determinant();
		
		void printMatrix() const;
	public:
		vector3	  				&operator[] ( unsigned int r ) ;
		matrix33              &operator =  (const matrix33 &v);
		matrix33              &operator += (const matrix33 &v);
		matrix33              &operator -= (const matrix33 &v);
		matrix33              &operator *= (float f);
		matrix33              &operator /= (float f);
		friend bool            operator == (const matrix33 &a, const matrix33 &b);
		friend bool            operator != (const matrix33 &a, const matrix33 &b);
		friend matrix33        operator * (const matrix33 &a, const matrix33 &b);
		friend matrix33        operator - (const matrix33 &a);
		friend matrix33        operator + (const matrix33 &a, const matrix33 &b);
		friend matrix33        operator - (const matrix33 &a, const matrix33 &b);
		friend matrix33        operator * (const matrix33 &v, float f);
		friend matrix33        operator * (float f, const matrix33 &v);
		friend matrix33        operator / (const matrix33 &v, float f);
	private:
		int *ptr;
};

#endif
