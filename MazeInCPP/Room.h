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
	void set_link(char dir, Room* room);
	Room* get_link(char dir);
	Room * get_north();
	Room * get_east();
	Room * get_south();
	Room * get_west();
	Room * get_trap();
	char get_name();
	std::string get_directions();
};
