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
