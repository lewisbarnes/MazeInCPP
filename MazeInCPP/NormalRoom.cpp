#include "stdafx.h"
#include "NormalRoom.h"
using namespace MazeInCPP;
NormalRoom::NormalRoom(std::string n) : BaseRoom(n)
{
	name = n;
}
// Set the link based on char passed with pointer to room
void NormalRoom::set_link(char dir, BaseRoom * room)
{
	switch (tolower(dir))
	{
		case 't':
			trap = room;
			if (room != nullptr)
			{
				if (room->get_link('t') == nullptr)
				{
					room->set_link('t', this);
				}
			}
			break;
		default:
			BaseRoom::set_link(dir, room);
			break;
	}
}

// Get the linked room based on char passed to function
BaseRoom * NormalRoom::get_link(char dir)
{
	switch (tolower(dir))
	{
		case 't':
			return trap;
		default:
			return BaseRoom::get_link(dir);
	}
}
// Return the directions the user can traverse through the rooms
std::string NormalRoom::get_directions()
{
	std::string return_string = BaseRoom::get_directions();
	if (get_link('t') != nullptr)
	{
		return_string.append("(T)Trapdoor ");
	}
	return return_string;
}