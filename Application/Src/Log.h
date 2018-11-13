#pragma once

#include <iostream>

namespace Log {

	enum Color {
		grey,
		red,
		green,
		yellow,
		blue,
		cyan,
		lightred,
		lightgreen,
		lightyellow,
		lightblue,
		lightblack	
	};



	void trace(std::string m);
	void log(std::string m);
	void warn(std::string m);
	void error(std::string m);
	void fatal(std::string m);

	void print(Color color, std::string message, bool bold, bool underline);

};
