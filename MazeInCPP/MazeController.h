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
	void set_maze(std::string maze_map);
	void start_loop();
	MazeController();
	void main_menu();

};

enum MOVE_DIR { no_direction, north_direction, east_direction, south_direction, west_direction, trap_direction, wrong_input };