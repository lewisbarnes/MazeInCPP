// Maze.cpp
#include "Maze.h"

Maze::Maze(std::string maze_map)
{
	Room* rooms[5];
	rooms[0] = new Room('A');
	rooms[1] = new Room('B');
	rooms[2] = new Room('C');
	rooms[3] = new Room('D');
	rooms[0]->set_north(rooms[1]);
	rooms[1]->set_west(rooms[2]);
	rooms[2]->set_east(rooms[3]);
	rooms[1]->set_south(rooms[0]);
	start_room = rooms[0];
	finish_room = rooms[3];
	current_room = get_start_room();
	/*size_t pos = 0;
	std::string token;
	while ((pos = maze_map.find(':')) != std::string::npos)
	{
		token = maze_map.substr(0, pos);
		room_map[token[0]] = new Room(token[0]);
		maze_map.erase(0, pos + 1);
		pos = maze_map.find(';');
	}*/
}
void Maze::start_again()
{
	current_room = start_room;
}
Room * Maze::get_current_room()
{
	return current_room;
}

Room * Maze::get_start_room()
{
	return start_room;
}
Room * Maze::get_finish_room()
{
	return finish_room;
}
bool Maze::is_complete()
{
	if (current_room == finish_room)
	{
		return true;
	}
	else
	{
		return false;
	}
}
int Maze::move(char direction)
{
	std::string* return_string = new std::string;
	switch (tolower(direction))
	{
		case 'n':
			if(current_room->get_north() == nullptr)
			{
				return 0;
			}
			else
			{
				current_room = current_room->get_north();
				return 1;
			}
			break;
		case 'e':
			if (current_room->get_east() == nullptr)
			{
				return 0;
			}
			else
			{
				current_room = current_room->get_east();
				return 2;
			}
			break;
		case 's':
			if (current_room->get_south() == nullptr)
			{
				return 0;
			}
			else
			{
				current_room = current_room->get_south();
				return 3;
			}
			break;
		case 'w':
			if (current_room->get_west() == nullptr)
			{
				return 0;
			}
			else
			{
				current_room = current_room->get_west();
				return 4;
			}
			break;
		case 't':
			if (current_room->get_trap() == nullptr)
			{
				return 0;
			}
			else
			{
				current_room = current_room->get_trap();
				return 5;
			}
			break;
		default:
			return 6;
			break;
	}
}
