#pragma once

namespace si
{
	class Application;

	class World
	{
	public:
		World(Application* App);
		virtual ~World();

		void BeginPlayInternal();
		void TickInternal(float DeltaTime);
	private:
		Application* m_App;
		bool m_HasBegunPlay;

		void BeginPlay();
		void Tick(float DeltaTime);
	};
}