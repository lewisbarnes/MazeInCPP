// Room.cpp
#include "stdafx.h"
#include "Room.h"
Room::Room(std::string n){name = n;}
std::string Room::get_name(){return name;}
Room::Room(){}
void Room::set_link(char dir, Room * room)
{
	switch (tolower(dir))
	{
	case 'n':
		north = room;
		break;
	case 'e':
		east = room;
		break;
	case 's':
		south = room;
		break;
	case 'w':
		west = room;
		break;
	case 't':
		trap = room;
		break;
	default:
		break;
	}
}

// Get linked room in direction char
Room * Room::get_link(char dir)
{
	switch (tolower(dir))
	{
	case 'n':
		return north;
	case 'e':
		return east;
	case 's':
		return south;
	case 'w':
		return west;
	case 't':
		return trap;
	default:
		return nullptr;
	}
}

// Return the directions available for travel
std::string Room::get_directions()
{
	std::string return_string;
	get_link('n') ? return_string.append("(N)North ") : void();
	get_link('e') ? return_string.append("(E)East ") : void();
	get_link('s') ? return_string.append("(S)South ") : void();
	get_link('w') ? return_string.append("(W)West ") : void();
	get_link('t') ? return_string.append("(T)Trapdoor ") : void();
	return return_string;
}