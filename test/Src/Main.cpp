#include <Atolla.h>
#include <App.h>

#include <string>
#include <stdio.h>
#include <time.h>
#include <Windows.h>

class Sandbox : public Atolla::Application {

public:

	Sandbox(std::string name) {
		appName = name;
	}

	void Start() {

		trace("Starting up");
		Atolla::StartRenderer(abselutePath);
	};

	void Update() {
		Sleep(1000);
		
	};

	void Exit() {

		warn("exiting");
	};

};


int main(int argc, char *argv[]) {

	auto app = new Sandbox("Sandbox");

	//---before program starts

	mainInit(argc, argv, app); //---loop until termination

	//---program has ended

	return 0;
}