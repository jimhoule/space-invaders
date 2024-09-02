#include "framework/Core.h"
#include "framework/Object.h"

namespace si
{
	Object::Object()
		: m_IsPendingDestroy(false)
	{}

	Object::~Object()
	{
		LOG("Object destroyed");
	}

	void Object::Destroy()
	{
		m_IsPendingDestroy = true;
	}
}