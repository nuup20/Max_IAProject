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

	float		magnitud();
	CVector3	normalized();
	CVector3	truncate(const float maxMg);
	CVector3	operator*(CVector3& vc_vector);
	CVector3	operator*=(CVector3& vc_vector);
	CVector3	operator*(float f_escalar);
	CVector3	operator*=(float f_escalar);
	CVector3	operator-(CVector3& vc_vector);
	CVector3	operator-=(CVector3& vc_vector);
	CVector3	operator+(CVector3& vc_vector);
	CVector3	operator+=(CVector3& vc_vector);
	void		operator=(float f_unit);

	CVector3();
	CVector3(float f_x, float f_y, float f_z);
	CVector3(float f_x, float f_y);
	CVector3(float f_const);
	~CVector3();
};

float		dot(CVector3 a, CVector3 b);

