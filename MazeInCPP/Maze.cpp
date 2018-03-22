// Maze.cpp
#include "Maze.h"
#include <sstream>
Maze::Maze(std::vector<std::string> room_strings)
{
	auto initial = create_initial_rooms(room_strings);
	link_rooms(room_strings,initial);
	current_room = start_room;
}
Maze::Maze()
{
}
std::map<std::string, AbstractRoom*> Maze::create_initial_rooms(std::vector<std::string> room_strings)
{
	std::map<std::string, AbstractRoom*> room_map;
	// For each entry into map create associated nodes
	for each(std::string s in room_strings)
	{
		// Find the first occurrence of a character
		size_t pos = s.find_first_of(':');
		// Get the substring before the character position
		if (s.substr(0,pos) != "-")
		{
			// Reject room_name if "start" or "finish"
			if (!((s.substr(0, pos) == "start") || (s.substr(0, pos) == "finish")))
			{
				room_map[s.substr(0, pos)] = new NormalRoom(s.substr(0, pos));
			}
		}
	}
	return room_map;
}
// Link the rooms to each other
void Maze::link_rooms(std::vector<std::string> room_strings, std::map<std::string, AbstractRoom*> room_map)
{
	for each(std::string s in room_strings)
	{
		size_t pos = s.find_first_of(':');
		std::string room_name = s.substr(0, pos);
		s.erase(0, pos + 1);
		if (room_name == "start")
		{
			pos = s.find_first_of(';');
			start_room = room_map[s.substr(0, pos)];
			s.erase(0, pos + 1);
		}
		if (room_name == "finish")
		{
			pos = s.find_first_of(';');
			finish_room = room_map[s.substr(0, pos)];
			s.erase(0, pos + 1);
		}
		if (!((room_name == "start") || (room_name == "finish")))
		{
			std::string direct = "neswt";
			int i = 0;
			while (s != "")
			{
				pos = s.find(';');
				(s.substr(0,pos) != "-") ? room_map[room_name]->set_link(direct[i], room_map[s.substr(0,pos)]) : 0;
				s.erase(0, pos + 1);
				++i;
			}
		}
	}
}
Maze * Maze::default_maze() {
	//auto A = new NormalRoom("A");
	//auto B = new NormalRoom("B");
	//auto C = new NormalRoom("C");
	//auto D = new NormalRoom("D");
	//auto E = new NormalRoom("E");
	//auto F = new NormalRoom("F");
	//auto G = new NormalRoom("G");
	//auto H = new NormalRoom("H");
	//auto I = new NormalRoom("I");
	//auto J = new NormalRoom("J");
	//auto K = new NormalRoom("K");
	//auto L = new NormalRoom("L");
	//auto M = new NormalRoom("M");
	//auto N = new NormalRoom("N");
	//A->set_link('e', C);
	//A->set_link('s', F);
	//B->set_link('s', C);
	//C->set_link('n', B);
	//C->set_link('e', D);
	//C->set_link('s', G);
	//C->set_link('w', A);
	//C->set_link('t', H);
	//D->set_link('e', E);
	//D->set_link('w', C);
	//E->set_link('w', D);
	//F->set_link('s', J);
	//F->set_link('t', K);
	//G->set_link('n', C);
	//H->set_link('e', I);
	//H->set_link('s', L);
	//H->set_link('t', M);
	//I->set_link('w', H);
	//J->set_link('n', F);
	//K->set_link('n', L);
	//L->set_link('n', H);
	//L->set_link('s', K);
	//M->set_link('n', N);
	//M->set_link('t', H);
	//N->set_link('s', M);
	//start_room = A;
	//finish_room = N;
	//current_room = start_room;
	//return this;
	return Maze::from_file("default.maz");
}
// Create a maze from the file provided by the user.
Maze* Maze::from_file(std::string path)
{
	std::vector<std::string> room_string_vector;
	std::ifstream input_maze;
	input_maze.open(path);
	// Open the file, read it, check for null or empty and push_back to room_string_vector
	if (input_maze.good() && input_maze.is_open())
	{
		std::string line;
		while (!input_maze.eof())
		{
			std::getline(input_maze, line);
			!line.empty() ? room_string_vector.push_back(line) : 0;
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
// Get char direction as parameter, get link and return int passed as parameter
int Maze::set_next_room(char c, int ret)
{
	append_move();
	current_room = current_room->get_link(c);
	steps_taken++;
	return ret;
}