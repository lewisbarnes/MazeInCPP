// Source.cpp
#include "stdafx.h"
#include "MazeController.h"
using namespace MazeInCPP;
void main(void)
{
	//Create an instance of MazeController and start the loop
	MazeController* mc = new MazeController();
	mc->start_loop();
}