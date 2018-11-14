#pragma once

#include "Job.h"
#include <vector>
#include <thread>

class Worker {

private:
	Worker();
	~Worker();

	static std::vector<std::thread*> workers;

public:

	static void Init();


};
