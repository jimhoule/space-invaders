#pragma once

#include <map>
#include <memory>
#include <stdio.h>
#include <unordered_map>
#include <vector>

namespace si
{
	template<typename T>
	using UniquePtr = std::unique_ptr<T>;

	template<typename T>
	using SharedPtr = std::shared_ptr<T>;

	template<typename T>
	using WeakPtr = std::weak_ptr<T>;

	template<typename T>
	using List = std::vector<T>;

	// NOTE: The predictae determines the order of each element in the map
	template<typename TKey, typename TValue, typename TPredicate = std::less<TKey>>
	using Map = std::map<TKey, TValue, TPredicate>;

	template<typename TKey, typename TValue, typename THasher = std::hash<TKey>>
	using Dictionary = std::unordered_map<TKey, TValue, THasher>;

	// LOG macro to log in the console
	// NOTE: uses variadic to get any amount of arguments
	#define LOG(Text, ...) printf(Text "\n", ##__VA_ARGS__);
}