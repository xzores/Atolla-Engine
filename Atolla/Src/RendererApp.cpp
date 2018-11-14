#include "RendererApp.h"

int t = 0;

Renderer::Renderer() {
	appName = "Renderer-App";
}

void Renderer::Start() {

	trace("RendererStarting");
};

void Renderer::Update() {
	Sleep(2000);
	trace("Update");

	if (t > 5)
		running = false;

	t++;
};

void Renderer::Exit() {


	trace("Renderer stopping");
	Sleep(2000);
};