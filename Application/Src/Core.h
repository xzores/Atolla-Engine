#pragma once

#include "Application.h"
#include "Log.h"

#include <iostream>
#include <string>
#include <windows.h>

int main(int argc, char *argv[]) {

	HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
	DWORD mode = 0;
	GetConsoleMode(hStdin, &mode);
	SetConsoleMode(hStdin, mode & (~ENABLE_ECHO_INPUT));

	auto app = Atolla::CreateApplication();
	app->Init();

	std::string input = std::string();;

	while (app->isRunning()) {
		std::getline(std::cin, input);

		Log::error((std::string("you have typed: ") + input + "\n").c_str());

	}

	return 0;
}