#include "vectors.h"
#include <cmath>


vec2 operator+(const vec2& l, const vec2& r)
{
	return { l.x + r.x, l.y + r.y };
}
vec3 operator+(const vec3& l, const vec3& r)
{
	return { l.x + r.x, l.y + r.y, l.z + r.z };
}

vec2 operator-(const vec2& l, const vec2& r)
{
	return { l.x - r.x, l.y - r.y };
}
vec3 operator-(const vec3& l, const vec3& r)
{
	return { l.x - r.x, l.y - r.y, l.z - r.z };
}

vec2 operator*(const vec2& l, const vec2& r)
{
	return { l.x * r.x, l.y * r.y };
}
vec3 operator*(const vec3& l, const vec3& r)
{
	return { l.x * r.x, l.y * r.y, l.z * r.z };
}

vec2 operator*(const vec2& l, float r)
{
	return { l.x * r, l.y * r };
}
vec3 operator*(const vec3& l, float r)
{
	return { l.x * r, l.y * r, l.z * r };
}

bool operator==(const vec2& l, const vec2& r)
{
	return CMP(l.x, r.x) && CMP(l.y, r.y);

}
bool operator==(const vec3& l, const vec3& r)
{
	return CMP(l.x, r.x) && CMP(l.y, r.y) && CMP(l.z, r.z);
}

bool operator!=(const vec2& l, const vec2& r)
{
	return !(l == r);
}
bool operator!=(const vec3& l, const vec3& r)
{
	return !(l == r);
}

//dot product
float Dot(const vec2& l, const vec2& r)
{
	return l.x * r.x + l.y * r.y;
}
float Dot(const vec3& l, const vec3& r)
{
	return l.x * r.x + l.y * r.y + l.z * r.z;
}

//magnitudes
float Magnitude(const vec2& v)
{
	return sqrtf(Dot(v, v));
}
float Magnitude(const vec3& v)
{
	return sqrtf(Dot(v, v));
}
float MagnitudeSq(const vec2& v)
{
	return Dot(v, v);
}
float MagnitudeSq(const vec3& v)
{
	return Dot(v, v);
}

//distance between 2 points
float Distance(const vec3& p1, const vec3& p2)
{
	vec3 t = p1 - p2;
	return Magnitude(t);
}

// unit vector, change in place or return a new vector
void Normalize(vec2& v)
{
	v = v * (1.0f / Magnitude(v));
}
void Normalize(vec3& v)
{
	v = v * (1.0f / Magnitude(v));
}
vec2 Normalized(const vec2& v)
{
	return v * (1.0f / Magnitude(v));
}
vec3 Normalized(const vec3& v)
{
	return v * (1.0f / Magnitude(v));
}

// cross product
vec3 Cross(const vec3& l, const vec3& r)
{
	vec3 result;
	result.x = l.y * r.z - l.z * r.y;
	result.y = l.z * r.x - l.x * r.z;
	result.z = l.x * r.y - l.y * r.x;
	return result; 
}


// angle between vectors in radians, use RAD2DEG(Angle(a,b)) for degrees
float Angle(const vec2& l, const vec2& r)
{
	float m = sqrtf(MagnitudeSq(l) * MagnitudeSq(r));
	return acos(Dot(l, r) / m);
}
float Angle(const vec3& l, const vec3& r)
{
	float m = sqrtf(MagnitudeSq(l) * MagnitudeSq(r));
	return acos(Dot(l, r) / m);
}