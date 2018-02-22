#pragma once
#include "Includes.h"
#include "Room.h"
class Maze
{
private:
	Room * start_room;
	Room * finish_room;
	std::map<char, Room*> room_map;
public:
	Maze(std::string maze_map);
	Room * get_current_room();
	Room * get_start_room();
	Room * get_finish_room();
	int move(char direction);
	Room * current_room;
	void start_again();
	bool is_complete();
};