#pragma once
#include "Includes.h"
#include "NormalRoom.h"
#include "AbstractRoom.h"
class Maze
{
protected:
	AbstractRoom * start_room;
	AbstractRoom * finish_room;
	std::string move_order;
	AbstractRoom * current_room;
	int steps_taken;
public:
	Maze(std::vector<std::string> room_strings);
	Maze();
	AbstractRoom * get_current_room() { return current_room; }
	AbstractRoom * get_start_room() { return start_room; }
	AbstractRoom * get_finish_room() { return finish_room; }
	int move(char direction);
	void start_again() { current_room = start_room; }
	bool is_complete() { return (current_room == finish_room) ? true : false; }
	std::map<std::string, AbstractRoom*> create_initial_rooms(std::vector<std::string> room_strings);
	void link_rooms(std::vector<std::string> room_strings, std::map<std::string, AbstractRoom*> room_map);
	static Maze * default_maze();
	static Maze* from_file(std::string path);
	std::string get_directions() { return current_room->get_directions(); }
	std::string get_move_order() { return move_order.erase(move_order.find_last_not_of("->")+1)+"->"+current_room->get_name(); }
	int get_steps_taken() { return steps_taken; }
	void append_move() { move_order.append(current_room->get_name() + "->"); }
	int set_next_room(char c,int ret);
};