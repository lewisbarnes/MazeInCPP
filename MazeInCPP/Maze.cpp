// Maze.cpp
#include "stdafx.h"
#include "Maze.h"
Maze::Maze(std::vector<std::string> room_strings)
{
	auto initial = create_initial_rooms(room_strings);
	link_rooms(room_strings,initial);
	current_room = start_room;
}
std::map<std::string, Room*> Maze::create_initial_rooms(std::vector<std::string> room_strings)
{
	std::map<std::string, Room*> room_map;
	// For each entry into map create associated nodes
	for (std::vector<std::string>::iterator it = room_strings.begin(); it != room_strings.end(); ++it)
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
	return room_map;
}

void Maze::link_rooms(std::vector<std::string> room_strings, std::map<std::string, Room*> room_map)
{
	std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();
	for (std::vector<std::string>::iterator it = room_strings.begin(); it != room_strings.end(); ++it)
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
			char* direct = "neswt";
			std::string::iterator it1 = line.begin();
			int i = 0;
			while (line != "")
			{
				pos = line.find(';');
				std::string linkname = line.substr(0, pos);
				(linkname != "-") ? room_map[room_name]->set_link(direct[i], room_map[linkname]) : 0;
				line.erase(0, pos + 1);
				i++;
			}
		}

	}
}

Maze* Maze::from_file(std::string path)
{
	std::vector<std::string> room_string_vector;
	std::ifstream input_maze;
	input_maze.open(path);
	// Open the file, read it, check for null or empty and push_back to room_string_vector
	if (input_maze.good() && input_maze.is_open())
	{
		std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();
		std::string line;
		while (!input_maze.eof())
		{
			std::getline(input_maze, line);
			!line.empty() ? room_string_vector.push_back(line) : void();
		}
		input_maze.close();
		input_maze.clear();
	}
	else
	{
		std::cout << "Unable to open file" << std::endl;
		exit(1);
	}
	return new Maze(room_string_vector);
}
int Maze::move(char direction)
{
	// Switch on input, return int based on response.
	switch (tolower(direction))
	{
	case 'n':
		return current_room->get_link('n') ? set_next_room('n', 1) : 0;
	case 'e':
		return current_room->get_link('e') ? set_next_room('e', 2) : 0;
	case 's':
		return current_room->get_link('s') ? set_next_room('s', 3) : 0;
	case 'w':
		return current_room->get_link('w') ? set_next_room('w', 4) : 0;
	case 't':
		return current_room->get_link('t') ? set_next_room('t', 5) : 0;
	default:
		return 6;
	}
}
// Take the char of direction, append move, set current room and increment steps taken;
int Maze::set_next_room(char c, int ret)
{
	append_move();
	current_room = current_room->get_link(c);
	steps_taken++;
	return ret;
}