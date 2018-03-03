#pragma once
#include "Includes.h"
#include "Room.h"
class Maze
{
private:
	Room * start_room;
	Room * finish_room;
	std::vector<std::string> room_string_vector;
	std::vector<std::string> room_link_vector; // Gets cleared after each room created
	std::map<std::string, Room*> room_map;
	Room * current_room;
public:
	Maze(std::string maze_map);
	Room * get_current_room();
	Room * get_start_room();
	Room * get_finish_room();
	int move(char direction);
	void start_again();
	bool is_complete();
	void create_initial_rooms();
	void link_rooms();
	std::string get_directions();
	Maze * default_maze();
	std::string move_order;
};