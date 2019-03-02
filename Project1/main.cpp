#include "vectors.h"

#include <iostream>

int main(int argc, char* argv[])
{
		
	vec3 right = { 1.0f,0.0f,0.0f };

	std::cout << "Component 0: " << right.x << "\n";
	std::cout << "Component 0: " << right.asArray[0] << "\n";
	std::cout << "Component 0: " << right[0] << "\n";

	vec3 up = { 0.0f,1.0f,0.0f };

	std::cout << "angle radians right/up: " << Angle(right, up) << "\n";
	std::cout << "angle degree right/up: " << RAD2DEG(Angle(right, up)) << "\n";
}
