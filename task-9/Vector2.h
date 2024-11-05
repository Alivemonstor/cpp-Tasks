#pragma once


class Vector2
{
public:
	float x;
	float y;
public:
	Vector2()
	{
		x = 0.0f;
		y = 0.0f;
	}
	Vector2(float a, float b)
	{
		x = a;
		y = b;
	}
	Vector2(const Vector2& other)
	{
		x = other.x;
		y = other.y;
	}
	Vector2 operator*(float scalar)
	{
		x *= scalar;
		y *= scalar;
		return *this;
	}
	Vector2 operator+(Vector2& other)
	{
		x += other.x;
		y += other.y;
		return *this;
	}
	Vector2 operator-(Vector2& other)
	{
		x -= other.x;
		y -= other.y;
		return *this;
	}
	Vector2 operator-()
	{
		x = -x;
		y = -y;
		return *this;
	}
	Vector2 operator=(Vector2& other)
	{
		x = other.x;
		y = other.y;
		return *this;
	}
	static float Dot(Vector2& a, Vector2& b)
	{
		float result;
		result = a.x*b.x+a.y*b.y;
		return result;
	}
	float Magnitude()
	{
		return sqrt(pow(x, 2) + pow(y, 2));
	}
	Vector2 Normalized()
	{
		float mag = Magnitude();
		x /= mag;
		y /= mag;
		return *this;
	}
	void Normalize()
	{
		float mag = Magnitude();
		x /= mag;
		y /= mag;
	}
	static float Distance(Vector2& a, Vector2& b)
	{
		Vector2 result;
		result.x = a.x - b.x;
		result.y = a.y - b.y;
		float distancesqrd = sqrt((result.x) * (result.x) + (result.y) * (result.y));
		return distancesqrd;
	}
};