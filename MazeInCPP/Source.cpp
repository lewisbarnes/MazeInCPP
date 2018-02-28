#include "MazeController.h"
int main(void)
{
	MazeController* mc = new MazeController();
	mc->start_loop();
	//mc->start_loop();
	getchar();
	return 0;
}