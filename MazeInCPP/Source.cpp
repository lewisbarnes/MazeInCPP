#include "MazeController.h"
int main(int c, char* v[])
{
	MazeController* mc = new MazeController();
	mc->set_maze("A-B--C\nstart:A\nfinish:C");
	//Maze* m = new Maze("A:B:C:D:");
	mc->start_loop();
	getchar();
	return 0;
}