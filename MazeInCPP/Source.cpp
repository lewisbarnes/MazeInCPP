#include "Maze.h"
int main(int c, char* v[])
{
	MazeController* mc = new MazeController();
	mc->set_maze("A-B--C\nstart:A\nfinish:C");
	mc->start_loop();
	return 0;
}