#pragma once

#include <SFML/Graphics.hpp>

namespace si
{
	sf::Vector2f ConvertRotationToVector(float Rotation);
	float ConvertDegreesToRadians(float Degrees);
	float ConvertRadiansToDegrees(float Radians);

	template<typename T>
	float GetVectorLength(const sf::Vector2<T>& Vector)
	{
		return std::sqrt((Vector.x * Vector.x) + (Vector.y * Vector.y));
	}

	template<typename T>
	sf::Vector2<T>& ScaleVector(sf::Vector2<T>& Vector, float Amount)
	{
		// NOTE: Because is Vector is not passed as a const, values are being modified in place (inside the Vector directly)
		Vector.x *= Amount;
		Vector.y *= Amount;

		return Vector;
	}

	template<typename T>
	sf::Vector2<T>& NormalizeVector(sf::Vector2<T>& Vector)
	{
		float Length = GetVectorLength<T>(Vector);
		if (Length == 0.f) {
			return sf::Vector2<T>();
		}

		return ScaleVector<T>(Vector, Length / 1.f);
	}
}