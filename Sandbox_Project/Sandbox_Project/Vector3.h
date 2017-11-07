#pragma once
#include <math.h>

class CVector3
{
public:
	union {
		struct {
			float x, y, z;
		};
		float v[3];
	};
	
	
	CVector3	operator*(const CVector3& vc_vector) const;
	CVector3	operator*(const float f_escalar) const;
	CVector3	operator-(const CVector3& vc_vector) const;
	CVector3	operator+(const CVector3& vc_vector) const;
	CVector3	operator / (const float f_denominador) const;
	CVector3	operator*=(const CVector3& vc_vector);
	CVector3	operator*=(const float f_escalar);	
	CVector3	operator-=(const CVector3& vc_vector);	
	CVector3	operator+=(const CVector3& vc_vector);	
	CVector3	operator /= (const float f_denominador);
	void		operator=(const float f_unit);

	CVector3	truncate(const float maxMg) const;
	CVector3	normalized() const;
	CVector3	normalize();
	CVector3	cross(const CVector3& vc_vector) const;
	float		magnitud() const;	
	float		dot(const CVector3& vc_vector) const;
	float		radAngle();
	float		degAngle();
	

	CVector3();
	CVector3(float f_x, float f_y, float f_z);
	CVector3(float f_x, float f_y);
	CVector3(float f_const);
	~CVector3();
};

float		dot(CVector3 a, CVector3 b);

