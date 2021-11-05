#ifndef VECTOR3_H
#define VECTOR_H

class Vector3
{
public:
	
	Vector3();

	Vector3(const Vector3& other);

	Vector3(float x);

	Vector3(float x, float y, float z);

	Vector3& operator=(const Vector3& other);

	Vector3 operator+(const Vector3& other);

	Vector3 operator-(const Vector3& other);

	Vector3 operator*(const Vector3& other);

	Vector3 operator*(float x);

	bool operator==(const Vector3& other);

	bool operator!=(const Vector3& other);

	float x;
	float y;
	float z;
};

#endif // VECTOR3_H