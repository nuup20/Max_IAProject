#include "stdafx.h"
#include "Vector3.h"


CVector3::CVector3()
{
}

CVector3::CVector3(float f_x, float f_y, float f_z)
{
}

CVector3::CVector3(float f_x, float f_y)
{
}

CVector3::CVector3(float f_const)
{
}


CVector3::~CVector3()
{
}

float CVector3::magnitud()
{
	float f_mg = 0;
	for (int i = 0; i < 3; ++i)
		f_mg += pow(this->v[i], 2);
	f_mg = sqrt(f_mg);
	return f_mg;
}

CVector3 CVector3::normalized()
{
	CVector3 vc_normalized;
	float f_mag = this->magnitud();
	f_mag = 1 / f_mag;
	for (int i = 0; i < 3; ++i)
		vc_normalized.v[i] = this->v[i] * f_mag;
	return vc_normalized;
}

CVector3 CVector3::operator*(CVector3 & vc_vector)
{
	CVector3 cv_product;
	for (int i = 0; i < 3; ++i)
		cv_product.v[i] = this->v[i] * vc_vector.v[i];
	return cv_product;
}

CVector3 CVector3::operator*(float f_escalar)
{
	CVector3 cv_product;
	for (int i = 0; i < 3; ++i)
		cv_product.v[i] = this->v[i] * f_escalar;
	return cv_product;
}

CVector3 CVector3::operator-(CVector3 & vc_vector)
{
	return CVector3();
}

CVector3 CVector3::operator+(CVector3 & vc_vector)
{
	return CVector3();
}

void CVector3::operator=(float f_unit)
{
}
