#include "stdafx.h"
#include "AbstractRoom.h"
using namespace MazeInCPP;
BaseRoom::BaseRoom(std::string n)
{
	name = n;
}

void BaseRoom::set_link(char dir, BaseRoom * room)
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
	default:
		break;
	}
}

BaseRoom* BaseRoom::get_link(char dir)
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
	default:
		return nullptr;
	}
}

std::string BaseRoom::get_directions()
{
	std::string return_string;
	if (get_link('n') != nullptr)
	{
		return_string.append("(N)North ");
	}
	if (get_link('e') != nullptr)
	{
		return_string.append("(E)East ");
	}
	if (get_link('s') != nullptr)
	{
		return_string.append("(S)South ");
	}
	if (get_link('w') != nullptr)
	{
		return_string.append("(W)West ");
	}
	return return_string;
}

std::string BaseRoom::get_name()
{
	return name;
}