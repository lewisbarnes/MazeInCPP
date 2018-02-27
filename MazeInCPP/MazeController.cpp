// MazeController.cpp
#include "MazeController.h"
using namespace std::chrono_literals;
MazeController::MazeController()
{
	current_maze = nullptr;
	current_room = nullptr;
}
bool MazeController::collect_input()
{
	bool return_val;
	std::cout << "Choose a direction to travel: ";
	switch (current_maze->move(std::cin.get()))
	{
		case no_direction:
			system("CLS");
			std::cout << "There is nothing in that direction!" << std::endl;
			std::cout << "These are the directions you can travel: " << current_maze->current_room->get_directions() << std::endl;
			return_val = false;
			break;
		case north_direction:
			system("CLS");
			std::cout << "You continue ahead into the darkness";
			return_val = true;
			break;
		case east_direction:
			system("CLS");
			std::cout << "You turn to the right and continue ahead";
			return_val = true;
			break;
		case south_direction:
			system("CLS");
			std::cout << "You turn around and go back the way you came";
			return_val = true;
			break;
		case west_direction:
			system("CLS");
			std::cout << "You turn left and continue ahead";
			return_val = true;
			break;
		case trap_direction:
			system("CLS");
			std::cout << "You open the trapdoor and climb through";
			return_val = true;
		case wrong_input:
			system("CLS");
			std::cout << "That is not a valid direction!" << std::endl;
			std::cout << "These are the directions you can travel: " << current_maze->current_room->get_directions() << std::endl;
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
	std::cout << "You got the memes." << std::endl;
	//std::cout << "You are in room " << current_maze->current_room->get_name() << std::endl;
	//std::cout << "These are the directions you can travel: " << current_maze->current_room->get_directions() << std::endl;
}
void MazeController::set_maze(std::string maze_map)
{
	current_room = new Room();
	current_maze = new Maze(maze_map);
	current_room = current_maze->current_room;
}
void MazeController::start_loop()
{
	system("CLS");
	bool exited = false;
	main_menu();
	if (current_maze == nullptr)
	{
		std::cout << "An error has ocurred, the maze has not been set" << std::endl;
		getchar();
		exited = true;
	}
	while (!exited)
	{
		display_menu();
		bool v;
		do
		{
			v = collect_input();
		} while (!v);
		for (int i = 0; i < 3; ++i)
		{
			std::this_thread::sleep_for(0.5s);
			std::cout << '.';
		}
		system("CLS");
		std::this_thread::sleep_for(0.5s);
	}
	std::cout << "You reached the end of the maze. Well done." << std::endl;
	std::cout << "Play again? y/n: ";
	switch (tolower(std::cin.get()))
	{
	case 'y':
		current_maze->start_again();
	case 'n' :
		std::cout << "Bye... see you next time." << std::endl;
		std::cout << "Exiting";
		for (int i = 0; i < 3; ++i)
		{
			std::this_thread::sleep_for(500ms);
			std::cout << '.';
		}
		std::cout << std::endl;
		break;
	default: 
		break;
	}
}

void MazeController::main_menu()
{
	bool valid_input_achieved = false; 
	int response;
	system("CLS");
	std::cout << "Welcome to the text based maze game!\nWhich type of Maze would you like to play?\n1. Default maze\n2. User generated maze\n3. Randomly generated maze" << std::endl;
	std::cout << "Please choose an option from the list: ";
	std::cin >> response;
	std::cin.ignore();
	do
	{
		switch ((int)response)
		{
		case 1:
			valid_input_achieved = true;
			std::cin.clear();
			current_maze = current_maze->default_maze();
			break;
		case 2:
			valid_input_achieved = true;
			std::cin.clear();
			maze_from_file();
			break;
		case 3:
			valid_input_achieved = true;
			current_maze = current_maze->default_maze();
			break;
		default:
			std::cin.clear();
			std::cout << "You have not chosen a valid option, please choose again: ";
			std::cin >> response;
			break;
		}
		std::cin.clear();
	} while (!valid_input_achieved);
}

void MazeController::maze_from_file()
{
	bool file_good = false;
	std::string file_name;
	std::ifstream file;
	do
	{
		std::cout << "Please input the name of the file that you wish to use for the maze (must have .maz extension): ";
		std::getline(std::cin, file_name);
		const std::string ext = ".maz";

		// Check to see if the file name entered has the valid file extension
		if (std::mismatch(ext.rbegin(), ext.rend(), file_name.rbegin()).first != ext.rend())
		{
			std::cout << "Sorry, the file you have chosen does not have the correct file extension (.maz)." << std::endl;
		}
		else
		{
			file.open(file_name);		
			if (!file.good())
			{
				std::cout << "Sorry the file you have chosen does not exist." << std::endl;
			}
			else
			{
				file_good = true;

			}
			file.close();
		}

	} while (!file_good);
}
