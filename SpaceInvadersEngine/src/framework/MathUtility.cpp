#include "framework/MathUtility.h"

namespace si
{
	const float PI = 3.1415926535;

	sf::Vector2f ConvertRotationToVector(float Rotation)
	{
		float Radians = ConvertDegreesToRadians(Rotation);

		return sf::Vector2f(std::cos(Radians), std::sin(Radians));
	}

	float ConvertDegreesToRadians(float Degrees)
	{
		return Degrees * (PI / 180.f);
	}

	float ConvertRadiansToDegrees(float Radians)
	{
		return Radians * (180.f / PI);
	}
}