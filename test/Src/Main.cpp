#include <Atolla.h>
#include <App.h>

#include <stdio.h>
#include <time.h>
#include <Windows.h>

class Sandbox : public Atolla::Application {

public:

	void Start() {

		printf("start\n");
	};

	void Update() {
		Sleep(500);
		printf("update\n");
	};

	void Exit() {

		printf("exit\n");
	};

};


Atolla::Application* Atolla::CreateApplication() {
	return new Sandbox();
}