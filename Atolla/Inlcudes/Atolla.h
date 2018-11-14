#pragma once

#include <iostream>
#include <vector>

#include "spdlog/spdlog.h"
#include "spdlog/logger.h"
#include "spdlog/sinks/stdout_color_sinks.h"

#include <mutex>

namespace Atolla{


	std::vector<int> findLocation(const std::string& sample, const char& findIt)
	{
		std::vector<int> characterLocations = std::vector<int>();
		for (int i = 0; i < sample.size(); i++)
			if (sample.at(i) == findIt)
				characterLocations.push_back(i);

		return characterLocations;
	}

	void threadStart(const std::string& folderPath) {
		//int result = system((folderPath + std::string("\\Atolla.exe")).c_str());

		std::shared_ptr<spdlog::logger> preLog;
		preLog = spdlog::stdout_color_mt("PreRenderer");
		preLog->set_level(spdlog::level::trace);

		std::string path  = (folderPath + std::string("\\Atolla.exe")).c_str();
		STARTUPINFO si;
		PROCESS_INFORMATION processInfo;

		ZeroMemory(&si, sizeof(si));
		si.cb = sizeof(si);
		ZeroMemory(&processInfo, sizeof(processInfo));

		bool sucess = CreateProcess(TEXT(path.c_str()), NULL, NULL, NULL, FALSE, NULL, NULL, NULL, &si, &processInfo);

		if (!sucess) {
			preLog->error("renderer faild to inicialize");
			return;
		}

		DWORD ret = WaitForSingleObject(processInfo.hProcess, -1);

		CloseHandle(processInfo.hProcess);
		CloseHandle(processInfo.hThread);

		if(ret != 0)
			preLog->error(std::string("Executable Renderer return: ") + std::to_string(ret));
		else
			preLog->info(std::string("Executable Renderer return: ") + std::to_string(ret));
		
	}

	void StartRenderer(const std::string& appExecutablePath) {
		
		std::shared_ptr<spdlog::logger> log;

		log = spdlog::stdout_color_mt("Pre-Renderer");
		log->set_level(spdlog::level::trace);

		std::vector<int> loca =  findLocation(appExecutablePath, '\\');

		if (loca.size() < 1)
		{
			log->error("Could not intanciate renderer, unresolved path error!!!");
			return;
		}

		try {
			std::string s = appExecutablePath.substr(0,loca.at(loca.size() - 1));

			log->warn("Executable folder: " + s);

			threadStart(s);

		}
		catch(...) {
			log->error("Could not intanciate renderer, unresolved unknown error!!!");
		}
	}
}