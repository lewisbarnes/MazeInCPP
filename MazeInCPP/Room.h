#pragma once
#include "stdafx.h"
#include "Includes.h"
class Room
{
private:
	std::string name;
	Room * north;
	Room * east;
	Room * south;
	Room * west;
	Room * trap;
public:
	Room(std::string n);
	void set_link(char dir, Room* room);
	Room* get_link(char dir);
	std::string get_name();
	std::string get_directions();
};