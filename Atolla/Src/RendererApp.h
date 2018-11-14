#pragma once
#include <App.h>

#include <stdio.h>
#include <Windows.h>
#include <GL\glew.h>

class Renderer : public Atolla::Application {

public:

	Renderer();

	void Start();

	void Update();

	void Exit();

};