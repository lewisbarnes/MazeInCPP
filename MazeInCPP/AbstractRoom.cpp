#include "AbstractRoom.h"

AbstractRoom::AbstractRoom()
{
}

AbstractRoom::AbstractRoom(std::string n)
{
	name = n;
}

void AbstractRoom::set_link(char dir, AbstractRoom * room)
{
	switch (tolower(dir))
	{
	case 'n':
		north = room;
		if (room->get_link('s') == nullptr)
		{
			room->set_link('s', this);
		}
		break;
	case 'e':
		east = room;
		if (room->get_link('w') == nullptr)
		{
			room->set_link('w', this);
		}
		break;
	case 's':
		if (south == nullptr)
		{
			south = room;
			if (room->get_link('n') == nullptr)
			{
				room->set_link('n', this);
			}
		}
		break;
	case 'w':
		if (west == nullptr)
		{
			west = room;
			if (room->get_link('e') == nullptr)
			{
				room->set_link('e', this);
			}
		}
		west = room;
		break;
	default:
		break;
	}
}

AbstractRoom * AbstractRoom::get_link(char dir)
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

std::string AbstractRoom::get_directions()
{
	std::string return_string;
	get_link('n') ? return_string.append("(N)North ") : void();
	get_link('e') ? return_string.append("(E)East ") : void();
	get_link('s') ? return_string.append("(S)South ") : void();
	get_link('w') ? return_string.append("(W)West ") : void();
	return return_string;
}

std::string AbstractRoom::get_name()
{
	return name;
}
