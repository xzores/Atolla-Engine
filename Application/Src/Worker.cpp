#include "Worker.h"

static std::vector<std::thread*> a;

void Worker::WorkerLoop() {

	while (running)
	{

	}

}

void Worker::Init() {

	unsigned concurentThreadsSupported = std::thread::hardware_concurrency();

	while (getWorkers().size() < concurentThreadsSupported) {
		std::thread* t;
		getWorkers().push_back(new std::thread(t));
	};

}

std::vector<std::thread*> getWorkers() {

	static std::vector<std::thread*> a = std::vector<std::thread*>();

	return a;
}
