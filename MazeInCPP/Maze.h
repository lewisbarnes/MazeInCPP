#pragma once
#include "Includes.h"
class Room
{
private:
	char name;
	Room * north;
	Room * east;
	Room * south;
	Room * west;
	Room * trap;

public:
	Room(char n);
	Room();
	void set_north(Room* room);
	void set_east(Room* room);
	void set_south(Room* room);
	void set_west(Room* room);
	void set_trap(Room* room);
	Room * get_north();
	Room * get_east();
	Room * get_south();
	Room * get_west();
	Room * get_trap();
	char get_name();
	std::string get_directions();
};

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

class MazeController
{
private:
	Room * current_room;
	Maze * current_maze;
	void display_menu();
	bool collect_input();
	~MazeController();
public:
	void set_maze(std::string maze_map);
	void start_loop();
	MazeController();
};

enum MOVE_DIR {no_direction,north_direction,east_direction,south_direction,west_direction,trap_direction,wrong_input};