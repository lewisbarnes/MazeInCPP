// MazeController.h
#pragma once
#include "Maze.h"
class MazeController
{
private:
	Room * current_room;
	Maze * current_maze;
	void display_menu();
	bool collect_input();
	bool set_default_maze();
	bool maze_from_file();
public:
	void start_loop();
	MazeController();
	void main_menu();
};
enum MOVE_DIR { no_dir, n_dir, e_dir, s_dir, w_dir, t_dir, w_input };