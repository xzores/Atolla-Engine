#pragma once

#include <thread>

namespace Atolla {
	class Application {

	private:
		std::thread AppThread;
		bool running = true;

	public:

		Application();
		~Application();

		bool isRunning();

		void Init();

		virtual void Start();
		virtual void Update();
		virtual void Exit();

	};

	Atolla::Application* CreateApplication();
}