#include "stdafx.h"
#include "Vector3.h"

float CVector3::magnitud()
{
	float f_mg = pow(this->x, 2) + pow(this->y, 2) + pow(this->z, 2);	
	return sqrt(f_mg);
}

CVector3 CVector3::normalized()
{
	CVector3 vc_normalized;
	float f_mag = this->magnitud();
	f_mag = 1 / f_mag;
	vc_normalized.x = this->x * f_mag;
	vc_normalized.y = this->y * f_mag;
	vc_normalized.z = this->z * f_mag;	
	return vc_normalized;
}

CVector3 CVector3::truncate(float maxMg)
{
	return (this->magnitud() > maxMg ? this->normalized() * maxMg : *(this));	
}

CVector3 CVector3::operator*(CVector3 & vc_vector)
{
	CVector3 cv_product;
	cv_product.x = this->x * vc_vector.x;
	cv_product.y = this->y * vc_vector.y;
	cv_product.z = this->z * vc_vector.z;	
	return cv_product;
}

CVector3 CVector3::operator*=(CVector3 & vc_vector)
{
	this->x *= vc_vector.x;
	this->y *= vc_vector.y;
	this->z *= vc_vector.z;
	return *(this);
}

CVector3 CVector3::operator*(float f_escalar)
{
	CVector3 cv_product;
	cv_product.x = this->x * f_escalar;
	cv_product.y = this->y * f_escalar;
	cv_product.z = this->z * f_escalar;
	return cv_product;
}

CVector3 CVector3::operator*=(float f_escalar)
{
	this->x *= f_escalar;
	this->y *= f_escalar;
	this->z *= f_escalar;
	return *(this);
}

CVector3 CVector3::operator-(CVector3 & vc_vector)
{
	CVector3 cv_result;
	cv_result.x = this->x - vc_vector.x;
	cv_result.y = this->y - vc_vector.y;
	cv_result.z = this->z - vc_vector.z;
	return cv_result;
}

CVector3 CVector3::operator-=(CVector3 & vc_vector)
{
	this->x -= vc_vector.x;
	this->y -= vc_vector.y;
	this->z -= vc_vector.z;
	return *(this);
}

CVector3 CVector3::operator+(CVector3 & vc_vector)
{
	CVector3 cv_result;
	cv_result.x = this->x + vc_vector.x;
	cv_result.y = this->y + vc_vector.y;
	cv_result.z = this->z + vc_vector.z;
	return cv_result;
}

CVector3 CVector3::operator+=(CVector3 & vc_vector)
{
	this->x += vc_vector.x;
	this->y += vc_vector.y;
	this->z += vc_vector.z;
	return *(this);
}

CVector3 CVector3::operator/(float f_denominador)
{	
	return CVector3(this->x / f_denominador, this->y / f_denominador, this->z / f_denominador);
}

CVector3 CVector3::operator/=(float f_denominador)
{
	this->x /= f_denominador;
	this->y /= f_denominador;
	this->z /= f_denominador;
	
	return (*this);
}

void CVector3::operator=(float f_unit)
{	
	this->x = f_unit;
	this->y = f_unit;
	this->z = f_unit;
}

float CVector3::dot(CVector3 & vc_vector)
{
	return (this->x*vc_vector.x) + (this->y*vc_vector.y) + (this->z*vc_vector.z);
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
