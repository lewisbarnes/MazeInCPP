// Room.cpp
#include "Room.h"
Room::Room(char n)
{
	name = n;
}
// Default constructor
Room::Room()
{
}
#pragma region Set Room Links
// The methods in this region allow setting of the links to other rooms

void Room::set_link(char dir, Room * room)
{
	switch (tolower(dir))
	{
	case 'n':
		north = room;
	case 'e':
		east = room;
	case 's':
		south = room;
	case 'w':
		west = room;
	case 't':
		trap = room;
	}
}

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
	}
}
#pragma endregion

#pragma region Get Room Links
// The methods in this region return the room links to other rooms

char Room::get_name()
{
	return name;
}
#pragma endregion
// Return the directions the user can traverse
std::string Room::get_directions()
{
	std::string return_string;
	if (north != nullptr)
	{
		return_string.append("(N)North ");
	}
	if (east != nullptr)
	{
		return_string.append("(E)East ");
	}
	if (south != nullptr)
	{
		return_string.append("(S)South ");
	}
	if (west != nullptr)
	{
		return_string.append("(W)West ");
	}
	if (trap != nullptr)
	{
		return_string.append("(T)Trapdoor ");
	}
	if (return_string == "")
	{
		return_string.append("None");
	}
	return return_string;
}