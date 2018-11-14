#pragma once

#include "../Src/Application.h"

static std::shared_ptr<spdlog::logger> CoreLog;

static void mainInit(int argc, char *argv[], Atolla::Application* app) {

	CoreLog = spdlog::stdout_color_mt("Core");
	CoreLog->set_level(spdlog::level::trace);

	spdlog::set_pattern("%^[%T] %n: %v%$");
	CoreLog->info("Executable path: " + std::string(argv[0]));
	CoreLog->trace("Core Starting... creating App");

	app->setAbselutePath(std::string(argv[0]));
	app->Init();

	CoreLog->trace("App creation succes!");

	bool shoudlrun = true;

	while (shoudlrun) {

		shoudlrun = app->isRunning();
	}
}
