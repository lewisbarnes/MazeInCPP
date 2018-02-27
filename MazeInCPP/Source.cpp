#include "MazeController.h"
int main(int c, char* v[])
{
	MazeController* mc = new MazeController();
    //mc->set_maze("A-B--C\nstart:A\nfinish:C");
	mc->start_loop();
	//Maze* m = new Maze("Memes");
	getchar();
	return 0;
}