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
void Room::set_north(Room * room)
{
	north = room;
}
void Room::set_east(Room * room)
{
	east = room;
}

void Room::set_south(Room * room)
{
	south = room;
}
void Room::set_west(Room * room)
{
	west = room;
}
void Room::set_trap(Room * room)
{
	trap = room;
}
#pragma endregion

#pragma region Get Room Links
// The methods in this region return the room links to other rooms
Room * Room::get_north()
{
	return north;
}
Room * Room::get_east()
{
	return east;
}
Room * Room::get_south()
{
	if (south != nullptr)
	{
		return south;
	}
	else
	{
		return nullptr;
	}
}
Room * Room::get_west()
{
	return west;
}
Room * Room::get_trap()
{
	return trap;
}

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