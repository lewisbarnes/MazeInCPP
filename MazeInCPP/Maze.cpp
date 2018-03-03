// Maze.cpp
#include "stdafx.h"
#include "Maze.h"
Maze::Maze(std::string maze_map)
{
	std::ifstream input_maze;
	input_maze.open("default.maz");
	if (input_maze.bad())
	{
		std::cout << "Unable to open file" << std::endl;
		exit(1);
	}
	// Open the file, read it, check for null or empty and push_back to map
	if (input_maze.is_open())
	{
		std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();
		std::string line;
		while (!input_maze.eof())
		{

			std::getline(input_maze, line);
			if (!line.empty())
			{
				room_string_vector.push_back(line);
			}
		}
		input_maze.close();
		input_maze.clear();
		std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();
		auto duration = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
		float mili = (float)duration / 1000;
	}
	create_initial_rooms();
	current_room = start_room;
}

void Maze::create_initial_rooms()
{
	std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();
	// For each entry into map create associated nodes
	for (std::vector<std::string>::iterator it = room_string_vector.begin(); it != room_string_vector.end(); ++it)
	{
		std::string line = *it;
		// Find the first occurrence of a character
		size_t pos = line.find_first_of(':');
		// Get the substring before the character position
		std::string room_name = line.substr(0, pos);
		if (room_name != "-")
		{
			// Reject room_name if "start" or "finish"
			if (!((room_name == "start") || (room_name == "finish")))
			{
				room_map[room_name] = new Room(room_name);
			}
		}
	}
	link_rooms();
	std::vector<std::string> zero_vec;
	room_string_vector.swap(zero_vec);
	std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
	float mili = (float)duration / 1000;
}

void Maze::link_rooms()
{
	std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();
	for (std::vector<std::string>::iterator it = room_string_vector.begin(); it != room_string_vector.end();++it)
	{
		std::string line = *it;
		size_t pos = line.find_first_of(':');
		std::string room_name = line.substr(0, pos);
		line.erase(0, pos + 1);
			if (room_name == "start")
			{
				pos = line.find_first_of(';');
				start_room = room_map[line.substr(0, pos)];
				line.erase(0, pos + 1);
			}
			if (room_name == "finish")
			{
				pos = line.find_first_of(';');
				finish_room = room_map[line.substr(0, pos)];
				line.erase(0, pos + 1);
			}
			if (!((room_name == "start") || (room_name == "finish")))
			{
				std::string linkname;
				char* direct = "neswt";
				std::string::iterator it1 = line.begin();
				int i = 0;
				while (line != "")
				{
					pos = line.find(';');
					linkname = line.substr(0, pos);
					if (linkname != "-")
					{
						room_map[room_name]->set_link(direct[i], room_map[linkname]);
					}
					line.erase(0, pos + 1);
					i++;
				}
			}

	}
	std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
	float mili = (float)duration / 1000;
	std::vector<std::string> empty_vec;
	std::map<std::string, Room*> empty_map;
	room_string_vector.swap(empty_vec);
	room_map.swap(empty_map);

	
}


std::string Maze::get_directions()
{
	return current_room->get_directions();
}

Maze * Maze::default_maze()
{

	return new Maze("0000000484848");
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
	// Switch on input, return int based on response.
	switch (tolower(direction))
	{
		case 'n':
			if (current_room->get_link('n') != NULL) 
			{
				move_order.append(current_room->get_name()+"->");
				std::cout << move_order << std::endl;
				current_room = current_room->get_link('n');
				return 1;
			}
			return 0;
		case 'e':
			if (current_room->get_link('e') != NULL) 
			{
				move_order.append(current_room->get_name()+"->");
				std::cout << move_order << std::endl;
				current_room = current_room->get_link('e');
				return 2;
			}
			return 0;
		case 's':
			if (current_room->get_link('s') != NULL) 
			{
				move_order.append(current_room->get_name()+"->");
				std::cout << move_order << std::endl;
				current_room = current_room->get_link('s');
				return 3;
			}
			return 0;
		case 'w':
			if (current_room->get_link('w') != NULL)
			{
				move_order.append(current_room->get_name()+"->");
				std::cout << move_order << std::endl;
				current_room = current_room->get_link('w');
				return 4;
			}
			return 0;
		case 't':
			if (current_room->get_link('t') != NULL)
			{
				move_order.append(current_room->get_name()+"->");
				std::cout << move_order << std::endl;
				current_room = current_room->get_link('t');
				return 5;
			}
			return 0;
		default:
			return 6;
	}
}
