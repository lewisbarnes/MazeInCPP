// Maze.cpp
#include "Maze.h"

Maze::Maze(std::string maze_map)
{
	std::vector<std::string> room_name_map;
	std::string map;
	std::ifstream input_maze;
	input_maze.open("default.maz");
	if (!input_maze)
	{
		std::cout << "Unable to open file" << std::endl;
		exit(1);
	}
	// Open the file, read to the end and output result to string
	if (input_maze.is_open())
	{
		std::string line;
		while (!input_maze.eof())
		{
			std::getline(input_maze, line);
			map.append(line);
		}
	}
	input_maze.close();
	// Loop through the map string and split on new line
	while (size_t pos = map.find(';') != std::string::npos)
	{
		std::string token = map.substr(0, pos);
		token.erase(std::remove_if(token.begin(), token.end(), ::isspace), token.end());
		room_name_map.push_back(token);
		map.erase(0, pos + 1);
	}
	// For each entry into room_name_map create associated nodes



	//Room * A = new Room('A');
	//Room * B = new Room('B');
	//Room * C = new Room('C');
	//Room * D = new Room('D');
	//A->set_north(B);
	//B->set_east(C);
	//C->set_west(D);
	//start_room = A;
	//current_room = start_room;
	//finish_room = D;
}

void Maze::create_initial_rooms(std::vector<std::string> &name_map)
{
	for (std::vector<std::string>::iterator it = name_map.begin(); it != name_map.end(); ++it)
	{
		size_t pos = it[0].find(':');
		std::string room_name = it[0].substr(0, pos);
		if (it[0][0] != '-')
		{
			room_list[it[0][0]] = new Room(it[0][0]);
			std::cout << "Room " << it[0][0] << " created!" << std::endl;
		}
		it[0].erase(0, pos + 1);
	}
}

Maze * Maze::default_maze()
{
	return nullptr;
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
