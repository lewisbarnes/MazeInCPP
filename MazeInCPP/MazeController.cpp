// MazeController.cpp
#include "Maze.h"
using namespace std::chrono_literals;
MazeController::MazeController()
{
}
bool MazeController::collect_input()
{
	bool return_val;
	std::cout << "Choose a direction to travel: ";
	switch (current_maze->move(std::cin.get()))
	{
		case no_direction:
			std::cout << "There is nothing in that direction!" << std::endl;
			return_val = false;
			break;
		case north_direction:
			system("CLS");
			std::cout << "You continue ahead into the darkness." << std::endl;
			return_val = true;
			break;
		case east_direction:
			system("CLS");
			std::cout << "You turn to the right and continue ahead." << std::endl;
			return_val = true;
			break;
		case south_direction:
			system("CLS");
			std::cout << "You turn around and go back the way you came." << std::endl;
			return_val = true;
			break;
		case west_direction:
			system("CLS");
			std::cout << "You turn left and continue ahead." << std::endl;
			return_val = true;
			break;
		case trap_direction:
			system("CLS");
			std::cout << "You open the trapdoor and climb through." << std::endl;
			return_val = true;
		case wrong_input:
			system("CLS");
			std::cout << "That is not a valid direction!" << std::endl;
			return_val = false;
			break;
		default:
			return_val = false;
			break;
	}
	std::cin.ignore();
	return return_val;
}
void MazeController::display_menu()
{
	std::cout << "You are in room " << current_maze->current_room->get_name() << std::endl;
	std::cout << "These are the directions you can travel: " << current_maze->current_room->get_directions() << std::endl;
}
void MazeController::set_maze(std::string maze_map)
{
	current_room = new Room();
	current_maze = new Maze(maze_map);
	current_room = current_maze->current_room;
}
void MazeController::start_loop()
{
	std::string welcome = "You are standing at the entrance to the maze, it is dark.\nYou peer into the entrance, the only thing you see is black.\nYou make the decision to enter the maze.\nDid you choose right?";
	std::this_thread::sleep_for(500ms);
	system("CLS");
	do
	{
		display_menu();
		bool v = collect_input();
		if (!v)
		{
			display_menu();
			collect_input();
		}

		for (int i = 0; i < 3; ++i)
		{
			std::this_thread::sleep_for(0.5s);
			std::cout << '.';
		}
		system("CLS");
		std::this_thread::sleep_for(0.5s);
	} while (!current_maze->is_complete());
	getchar();
}
