// Room.cpp
#include "stdafx.h"
#include "Room.h"
Room::Room(std::string n)
{
	name = n;
}
std::string Room::get_name()
{
	return name;
}
Room::Room()
{

}
// Set link based on char passed
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
// Return connected link based on char passed
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

// Return the directions the user can traverse
std::string Room::get_directions()
{
	std::string return_string;
	if (get_link('n') != NULL)
	{
		return_string.append("(N)North ");
	}
	if (get_link('e') != NULL)
	{
		return_string.append("(E)East ");
	}
	if (get_link('s') != NULL)
	{
		return_string.append("(S)South ");
	}
	if (get_link('w') != NULL)
	{
		return_string.append("(W)West ");
	}
	if (get_link('t') != NULL)
	{
		return_string.append("(T)Trapdoor ");
	}
	if (return_string == "")
	{
		return_string.append("None");
	}
	return return_string;
}