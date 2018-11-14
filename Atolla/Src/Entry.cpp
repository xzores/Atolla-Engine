#include "RendererApp.h"

int main(int argc, char *argv[]) {

	auto app = new Renderer();

	//---before program starts

	mainInit(argc, argv, app); //---loop until termination

	//---program has ended

	return 0;
}