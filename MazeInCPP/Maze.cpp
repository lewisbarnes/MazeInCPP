// Maze.cpp
#include "Maze.h"

Maze::Maze(std::string maze_map)
{
	std::vector<std::string> m_map;
	std::string map;
	std::string line;
	std::ifstream input_maze;
	input_maze.open("default.maz");
	if (!input_maze)
	{
		std::cout << "Unable to open file" << std::endl;
		exit(1);
	}
	if (input_maze.is_open())
	{
		while (!input_maze.eof())
		{
			std::getline(input_maze, line);
			map.append(line);
		}
	}
	input_maze.close();
	size_t pos = 0;
	std::string token;
	while ((pos = map.find('@')) != std::string::npos)
	{
		token = map.substr(0, pos);
		token.erase(std::remove_if(token.begin(), token.end(), ::isspace), token.end());
		room_map[token[0]] = new Room(token[0]);
		m_map.push_back(token);
		map.erase(0, pos + 1);
	}
	std::cout << room_map.size() << " rooms total" << std::endl;
	std::vector<std::string>::iterator it;
	for (it = m_map.begin(); it != m_map.end(); ++it)
	{
		pos = it[0].find(':');
		std::string room_name = it[0].substr(0, pos);
		std::cout << room_name << " ";
		it[0].erase(0, pos + 1);
		while ((pos = it[0].find(';')) != std::string::npos)
		{
			token = it[0].substr(0, pos);
			token =  token.substr(0, token.find('#'));
			std::cout << token << " ";
			it[0].erase(0, pos + 1);
		}
		std::cout << std::endl;
	}
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
