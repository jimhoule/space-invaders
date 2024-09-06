#pragma once

#include <string>

std::string GetResourceDir()
{
// If release build
#ifdef NDEBUG
	return "assets/";
// If debug build
#else
	return "C:/Users/jimmy.houle/Desktop/SpaceInvaders/SpaceInvadersGame/assets/";
#endif
}
