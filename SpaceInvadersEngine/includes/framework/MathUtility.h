#pragma once

#include <SFML/Graphics.hpp>

namespace si
{
	sf::Vector2f ConvertRotationToVector(float Rotation);
	float ConvertDegreesToRadians(float Degrees);
	float ConvertRadiansToDegrees(float Radians);
}