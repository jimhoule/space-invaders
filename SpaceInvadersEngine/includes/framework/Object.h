# pragma once

namespace si
{
	class Object
	{
	public:
		Object();
		virtual ~Object();

		void Destroy();
		bool IsDestructionPending() const;

	private:
		bool m_IsDestructionPending;
	};
}