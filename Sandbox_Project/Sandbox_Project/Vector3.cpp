#include "stdafx.h"
#include "Vector3.h"

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

CVector3 CVector3::truncate(float maxMg)
{
	return (this->magnitud() > maxMg ? this->normalized() * maxMg : *(this));	
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
	CVector3 cv_result;
	for (int i = 0; i < 3; i++)
		cv_result.v[i] = this->v[i] - vc_vector.v[i];
	return cv_result;
}

CVector3 CVector3::operator+(CVector3 & vc_vector)
{
	CVector3 cv_result;
	for (int i = 0; i < 3; ++i)
		cv_result.v[i] = this->v[i] + vc_vector.v[i];
	return cv_result;
}

void CVector3::operator=(float f_unit)
{	
	for (int i = 0; i < 3; i++)
		this->v[i] = f_unit;	
}

CVector3::CVector3()
{
	this->x = 0;
	this->y = 0;
	this->z = 0;
}

CVector3::CVector3(float f_x, float f_y, float f_z)
{
	this->x = f_x;
	this->y = f_y;
	this->z = f_z;
}

CVector3::CVector3(float f_x, float f_y)
{
	this->x = f_x;
	this->y = f_y;
	this->z = 0;
}

CVector3::CVector3(float f_const)
{
	*(this) = f_const;
}


CVector3::~CVector3()
{
}

float dot(CVector3 a, CVector3 b)
{
	return (a.x*b.x) + (a.y*b.y) + (a.z*b.z);
}
