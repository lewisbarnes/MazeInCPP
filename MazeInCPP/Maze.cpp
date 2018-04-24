// Maze.cpp
#include "stdafx.h"
#include "Maze.h"
#include <sstream>
using namespace MazeInCPP;
Maze::Maze() {
}
Maze::Maze(std::vector<std::string> room_strings) {
	auto initial = create_initial_rooms(room_strings);
	link_rooms(room_strings,initial);
	current_room = start_room;
}

// Return the current room's directions
std::string Maze::get_directions() {
	return current_room->get_directions();
}

// Return the moves that the user took to reach the end of the maze
std::string Maze::get_move_order() {
	return move_order.erase(move_order.find_last_not_of("->") + 1) + "->" + current_room->get_name();
}


// Return the number of steps the user has taken
int Maze::get_steps_taken() {
	return steps_taken;
}

// Append the name of the current room to the move order
void Maze::append_move() {
	move_order.append(current_room->get_name() + "->");
}


// Get the start room 
BaseRoom * Maze::get_start_room() {
	return start_room;
}

// Get the end room
BaseRoom * Maze::get_finish_room() {
	return finish_room;
}

// Get the current room that the user is in
BaseRoom * Maze::get_current_room() {
	return current_room;
}

// Return the completion status of the maze
bool Maze::is_complete() { 
	return (current_room == finish_room) ? true : false; 
}
// Set the current room back to the start room
void Maze::start_again() {
	current_room = start_room;
}

std::map<std::string, BaseRoom*> Maze::create_initial_rooms(std::vector<std::string> room_strings) {
	std::map<std::string, BaseRoom*> room_map;
	// For each entry into map create associated nodes
	for each(std::string s in room_strings) {
		// Find the first occurrence of a character
		size_t pos = s.find_first_of(':');
		// Get the substring before the character position
		if (s.substr(0,pos) != "-") {
			// Reject room_name if "start" or "finish"
			if (!((s.substr(0, pos) == "start") || (s.substr(0, pos) == "finish"))) {
				room_map[s.substr(0, pos)] = new NormalRoom(s.substr(0, pos));
			}
		}
	}
	return room_map;
}

// Link the rooms together
void Maze::link_rooms(std::vector<std::string> room_strings, std::map<std::string, BaseRoom*> room_map) {
	for each(std::string s in room_strings)
	{
		size_t pos = s.find_first_of(':');
		std::string room_name = s.substr(0, pos);
		s.erase(0, pos + 1);
		if (room_name == "start") {
			pos = s.find_first_of(';');
			start_room = room_map[s.substr(0, pos)];
			s.erase(0, pos + 1);
		}
		if (room_name == "finish") {
			pos = s.find_first_of(';');
			finish_room = room_map[s.substr(0, pos)];
			s.erase(0, pos + 1);
		}
		if (!((room_name == "start") || (room_name == "finish"))) {
			std::string direct = "neswt";
			int i = 0;
			while (s != "") {
				pos = s.find(';');
				(s.substr(0,pos) != "-") ? room_map[room_name]->set_link(direct[i], room_map[s.substr(0,pos)]) : 0;
				s.erase(0, pos + 1);
				++i;
			}
		}
	}
}
Maze * Maze::default_maze() {
	std::vector<std::string> maze_strings{ "A:-;C;F;-;-;",
		"B:-;-;C;-;-;",
		"C:B;D;G;A;H;",
		"D:-;E;-;C;-;",
		"A:-;C;F;-;-;",
		"B:-;-;C;-;-;",
		"C:B;D;G;A;H;",
		"D:-;E;-;C;-;",
		"E:-;-;-;D;-;",
		"F:-;-;J;-;K;",
		"G:C;-;-;-;-;",
		"H:-;I;L;-;M;",
		"I:-;-;-;H;-;",
		"J:F;-;-;-;-;",
		"K:L;-;-;-;-;",
		"L:H;-;K;-;-;",
		"M:N;-;-;-;H;",
		"N:-;-;S;-;-;",
		"start:A;",
		"finish:N;" };
	return new Maze(maze_strings);
}
// Create a maze from the file provided by the user.
Maze* Maze::from_file(std::string path) {
	std::vector<std::string> room_string_vector;
	std::ifstream input_maze;
	input_maze.open(path);
	// Open the file, read it, check for null or empty and push_back to room_string_vector
	if (input_maze.good() && input_maze.is_open()) {
		std::string line;
		while (!input_maze.eof()) {
			std::getline(input_maze, line);
			!line.empty() ? room_string_vector.push_back(line) : 0;
		}
		input_maze.close();
		input_maze.clear();
	} 
	else {
		std::cout << "Unable to open file" << std::endl;
		exit(1);
	}
	return new Maze(room_string_vector);
}

int Maze::move(char direction) {
	// Switch on input, return int based on response.
	switch (tolower(direction)) {
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

// Get char direction as parameter, get link and return int passed as parameter
int Maze::set_next_room(char c, int ret) {
	append_move();
	current_room = current_room->get_link(c);
	steps_taken++;
	return ret;
}

void Maze::finish()
{
	for each(BaseRoom* room in rooms)
	{
		delete &room;
	}
}