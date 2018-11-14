#pragma once

#include "spdlog/spdlog.h"
#include "spdlog/logger.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Atolla {
	class Application {

	private:
		
	
	protected:
		bool running = true;
		std::shared_ptr<spdlog::logger> logger;
		std::string abselutePath;

		std::string appName = "App";

	public:
		
		Application();
		~Application();

		bool isRunning() const;

		void Init();

		void setAbselutePath(const std::string& path);

		void trace(const std::string& message);
		void info(const std::string& message);
		void warn(const std::string& message);
		void critical(const std::string& message);
		void error(const std::string& message);

		virtual void Start();
		virtual void Update();
		virtual void Exit();

	};

}