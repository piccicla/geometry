#ifndef _H_MATH_VECTORS_
#define _H_MATH_VECTORS_
#include <cfloat>


// combine absolute tolerance and relative tolerance
// http://www.realtimecollisiondetection.net/pubs/Tolerances/
#define CMP(x, y)\
	(fabsf((x)-(y)) <= FLT_EPSILON * \
	fmaxf(1.0f, fmaxf(fabsf(x), fabsf(y)))\
) 
#define RAD2DEG(x) ((x) * 57.295754f)
#define DEG2RAD(x) ((x) * 0.0174533f)


typedef struct vec2 {

	union
	{
		struct
		{
			float x;
			float y;
		};
		float asArray[2];

	};

	float& operator[](int i)
	{
		return asArray[i];
	}

	vec2() : x(0.0f), y(0.0f) {}
	vec2(float _x, float _y) : x(_x), y(_y) {}

} vec2;

typedef struct vec3 {

	union
	{
		struct
		{
			float x;
			float y;
			float z;
		};
		float asArray[3];

	};

	float& operator[](int i)
	{
		return asArray[i];
	}

	vec3() : x(0.0f), y(0.0f), z(0.0f) {}
	vec3(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}

} vec3;


vec2 operator+(const vec2& l, const vec2& r);
vec3 operator+(const vec3& l, const vec3& r);
vec2 operator-(const vec2& l, const vec2& r);
vec3 operator-(const vec3& l, const vec3& r);
vec2 operator*(const vec2& l, const vec2& r);
vec3 operator*(const vec3& l, const vec3& r);
vec2 operator*(const vec2& l, float r);
vec3 operator*(const vec3& l, float r);
bool operator==(const vec2& l, const vec2& r);
bool operator==(const vec3& l, const vec3& r);
bool operator!=(const vec2& l, const vec2& r);
bool operator!=(const vec3& l, const vec3& r);


//dot product
float Dot(const vec2& l, const vec2& r);
float Dot(const vec3& l, const vec3& r);

//magnitudes
float Magnitude(const vec2& v);
float Magnitude(const vec3& v);
float MagnitudeSq(const vec2& v);
float MagnitudeSq(const vec3& v);

//distance between 2 points
float Distance(const vec3& p1, const vec3& p2);

// unit vector, change in place or return a new vector
void Normalize(vec2& v);
void Normalize(vec3& v);
vec2 Normalized(const vec2& v);
vec3 Normalized(const vec3& v);


// cross product
vec3 Cross(const vec3& l, const vec3& r);

// angle between vectors
float Angle(const vec2& l, const vec2& r);
float Angle(const vec3& l, const vec3& r);


#endif

