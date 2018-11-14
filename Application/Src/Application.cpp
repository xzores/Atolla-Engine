#include "Application.h"

#include <iostream>
#include <memory>

void loopThread(Atolla::Application* app) {

	app->Start();

	while(app->isRunning()){

		app->Update();
	}

	app->Exit();

}

bool Atolla::Application::isRunning() const {

	return running;
}

void Atolla::Application::Init() {


	logger = spdlog::stdout_color_mt(appName);
	logger->set_level(spdlog::level::trace);
	logger->trace("initialized logger: " + appName);

	loopThread(this);
}

Atolla::Application::Application() {

}

Atolla::Application::~Application() {

	logger->warn("application closing");
}

void Atolla::Application::Start() {

}

void Atolla::Application::Update() {

}

void Atolla::Application::Exit() {

	Exit();
}

void Atolla::Application::setAbselutePath(const std::string& path) {

	abselutePath = path;
}

void Atolla::Application::trace(const std::string& message) {

	logger->trace(message);

}

void Atolla::Application::info(const std::string& message) {

	logger->info(message);
}

void Atolla::Application::warn(const std::string& message) {

	logger->warn(message);
}

void Atolla::Application::critical(const std::string& message) {

	logger->critical(message);

}

void Atolla::Application::error(const std::string&  message) {
	
	logger->error(message);

}