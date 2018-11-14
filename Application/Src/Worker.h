#pragma once

#include "Job.h"
#include <vector>
#include <thread>

class Worker {

private:

	static bool running = true;
	
	void WorkerLoop();

	static std::vector<std::thread*> getWorkers();

public:

	static void Init();


};
