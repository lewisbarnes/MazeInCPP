// Room.cpp
#include "Room.h"
Room::Room(char n)
{
	name = n;
}
char Room::get_name()
{
	return name;
}
Room::Room()
{

}
void Room::set_link(char dir, Room * room)
{
	switch (tolower(dir))
	{
	case 'n':
		north = room;
		room->south = this;
		break;
	case 'e':
		east = room;
		room->west = this;
		break;
	case 's':
		south = room;
		room->north = this;
		break;
	case 'w':
		west = room;
		room->east = this;
		break;
	case 't':
		trap = room;
		room->trap = this;
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