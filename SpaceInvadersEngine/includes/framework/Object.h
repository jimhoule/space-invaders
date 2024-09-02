# pragma once

namespace si
{
	class Object
	{
	public:
		Object();
		virtual ~Object();

		void Destroy();
		bool GetIsPendingDestroy() const { return m_IsPendingDestroy; }

	private:
		bool m_IsPendingDestroy;
	};
}