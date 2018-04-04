#include "stdafx.h"
#include "NormalRoom.h"
using namespace MazeInCPP;
NormalRoom::NormalRoom(std::string n) : AbstractRoom(n)
{
	name = n;
}

NormalRoom::NormalRoom()
{
}

// Set the link based on char passed with pointer to room
void NormalRoom::set_link(char dir, AbstractRoom * room)
{
	switch (tolower(dir))
	{
	case 'n':
		north = room;
		if (room != nullptr)
		{
			if (room->get_link('s') == nullptr)
			{
				room->set_link('s', this);
			}
		}
		break;
	case 'e':
		east = room;
		if (room != nullptr)
		{
			if (room->get_link('w') == nullptr)
			{
				room->set_link('w', this);
			}
		}
		break;
	case 's':
		south = room;
		if (room != nullptr)
		{
			if (room->get_link('n') == nullptr)
			{
				room->set_link('n', this);
			}
		}
		break;
	case 'w':
		west = room;
		if (room != nullptr)
		{
			if (room->get_link('e') == nullptr)
			{
				room->set_link('e', this);
			}
		}
		break;
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
		break;
	}
}

// Get the linked room based on char passed to function
AbstractRoom * NormalRoom::get_link(char dir)
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


// Return the directions the user can traverse through the rooms
std::string NormalRoom::get_directions()
{
	std::string return_string;
	get_link('n') ? return_string.append("(N)North ") : void();
	get_link('e') ? return_string.append("(E)East ") : void();
	get_link('s') ? return_string.append("(S)South ") : void();
	get_link('w') ? return_string.append("(W)West ") : void();
	get_link('t') ? return_string.append("(T)Trapdoor ") : void();
	return return_string;
}