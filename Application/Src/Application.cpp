#include "Application.h"

void loopThread(Atolla::Application* app) {

	app->Start();

	while(app->isRunning())
		app->Update();
	
	app->Exit();

}

bool Atolla::Application::isRunning() {

	return running;
}

void Atolla::Application::Init() {

	AppThread = std::thread(loopThread, this);
}

Atolla::Application::Application() {


}

Atolla::Application::~Application() {

}

void Atolla::Application::Start() {

}

void Atolla::Application::Update() {

}

void Atolla::Application::Exit() {

}