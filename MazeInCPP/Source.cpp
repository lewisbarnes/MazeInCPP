// Source.cpp
#include "MazeController.h"
#include <sstream>

void main(void)
{
	//Create an instance of MazeController and start the loop
	MazeController* mc = new MazeController();
	mc->start_loop();
}