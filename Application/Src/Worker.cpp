#include "Worker.h"

static std::vector<std::thread*> a;

static void WorkerLoop() {

}

void Worker::Init() {
	
	static std::vector<std::thread*> a;
	
	&workers = &a;

	unsigned concurentThreadsSupported = std::thread::hardware_concurrency();

	while (workers.size() < concurentThreadsSupported) {
		workers.push_back(new std::thread(WorkerLoop));
	};

}

