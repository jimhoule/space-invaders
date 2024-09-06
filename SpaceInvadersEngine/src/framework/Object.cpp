#include "framework/Core.h"
#include "framework/Object.h"

namespace si
{
	Object::Object()
		: m_IsDestructionPending(false)
	{}

	Object::~Object()
	{
		LOG("Object destroyed");
	}

	void Object::Destroy()
	{
		m_IsDestructionPending = true;
	}

	bool Object::IsDestructionPending() const
	{
		return m_IsDestructionPending;
	}
}