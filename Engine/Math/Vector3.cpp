#include "Vector3.h"

Vector3::Vector3()
{
	x = 0;
	y = 0;
	z = 0;
}

Vector3::Vector3(const Vector3& other)
{
	x = other.x;
	y = other.y;
	z = other.z;
}

Vector3::Vector3(float x) : 
	x(x),
	y(x),
	z(x)
{
}

Vector3::Vector3(float x, float y, float z) : 
	x(x),
	y(x),
	z(z)
{

}

Vector3& Vector3::operator=(const Vector3& other)
{
	x = other.x;
	y = other.y;
	z = other.z;

	return *this;
}

Vector3 Vector3::operator+(const Vector3& other)
{
	Vector3 returnVector;
	returnVector.x = x + other.x;
	returnVector.y = y + other.y;
	returnVector.z = z + other.z;

	return returnVector;
}

Vector3 Vector3::operator-(const Vector3& other)
{
	Vector3 returnVector;
	returnVector.x = x - other.x;
	returnVector.y = y - other.y;
	returnVector.z = z - other.z;

	return returnVector;
}

Vector3 Vector3::operator*(const Vector3& other)
{
	Vector3 returnVector;
	returnVector.x = x * other.x;
	returnVector.y = y * other.y;
	returnVector.z = z * other.z;

	return returnVector;
}

Vector3 Vector3::operator*(float toMultiply)
{
	Vector3 returnVector;
	returnVector.x = x * toMultiply;
	returnVector.y = y * toMultiply;
	returnVector.z = z * toMultiply;

	return returnVector;
}

bool Vector3::operator==(const Vector3& other)
{
	return (x == other.x && y == other.y && z == other.z);
}

bool Vector3::operator!=(const Vector3& other)
{
	return (x != other.x && y != other.y && z != other.z);
}
