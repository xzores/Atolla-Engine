#include "Log.h"
#include "ccolor.h"
#include <windows.h>

const char Black = '0';
const char Blue = '1';
const char Green = *"2";
const char Red = *"4";
const char Purple = '5';
const char Yellow = '6';
const char White = '7';
const char Gray = '8';
const char LightBlue = '9';
const char LightGreen = 'A';
const char LightRed = 'C';
const char LightPurple = 'D';
const char LightYellow = 'E';
const char LightWhite = 'F';

void printWindows(Log::Color color, std::string message, bool bold, bool underline) {

	if (color == Log::red)
		system("COLOR 4");
	else if (color == Log::green)
		system("COLOR " + Green);
	else if (color == Log::yellow)
		system("COLOR " + Yellow);
	else if (color == Log::blue)
		system("COLOR " + Blue);
	else if (color == Log::cyan)
		system("COLOR " + Purple);
	else if (color == Log::grey)
		system("COLOR " + Gray);
	else if (color == Log::lightblack)
		system("COLOR " + Gray);
	else if (color == Log::lightred)
		system("COLOR " + LightRed);
	else if (color == Log::lightyellow)
		system("COLOR " + LightYellow);
	else if (color == Log::lightblue)
		system("COLOR " + LightBlue);
	else if (color == Log::lightgreen)
		system("COLOR " + LightGreen);

	std::cout << message.c_str() << std::endl;

	HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
	DWORD mode = 0;
	GetConsoleMode(hStdin, &mode);
	SetConsoleMode(hStdin, mode & (~ENABLE_ECHO_INPUT));
}

void printunix(Log::Color color, std::string message, bool bold, bool underline) {

	if (color == Log::red)
		std::cout << color::cc::fore::red;
	else if (color == Log::green)
		std::cout << color::cc::fore::green;
	else if (color == Log::yellow)
		std::cout << color::cc::fore::yellow;
	else if (color == Log::blue)
		std::cout << color::cc::fore::blue;
	else if (color == Log::cyan)
		std::cout << color::cc::fore::cyan;
	else if (color == Log::grey)
		std::cout << color::cc::fore::white;
	else if (color == Log::lightblack)
		std::cout << color::cc::fore::lightblack;
	else if (color == Log::lightred)
		std::cout << color::cc::fore::lightred;
	else if (color == Log::lightyellow)
		std::cout << color::cc::fore::lightyellow;
	else if (color == Log::lightblue)
		std::cout << color::cc::fore::lightblue;
	else if (color == Log::lightgreen)
		std::cout << color::cc::fore::lightgreen;

	if (bold)
		std::cout << color::cc::bold;

	if (underline)
		std::cout << color::cc::underline;

	std::cout << message.c_str() << color::cc::console << std::endl;
}

void Log::trace(std::string m) {

	print(lightblack, m, false, false);
}

void Log::log(std::string m) {

	print(grey, m, false, false);
}

void Log::warn(std::string m) {

	print(yellow, m, false, false);
}

void Log::error(std::string m) {

	print(red, m, false, false);
}

void Log::fatal(std::string m) {

	print(red, m, true, true);
}


void Log::print(Color color, std::string message, bool bold, bool underline) {

	printWindows(color, message, bold, underline);
	//printunix(color, message, bold, underline);
}