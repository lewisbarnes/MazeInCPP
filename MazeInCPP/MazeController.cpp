// MazeController.cpp
#include "stdafx.h"
#include "MazeController.h"
using namespace MazeInCPP;
// Map strings to enum for use in collect_input function
std::map<MOVE_DIR, std::string> directions{ { n_dir,"north" },{ e_dir,"east" },{ s_dir,"south" },{ w_dir,"west" } };
MazeController::MazeController()
{
	current_maze = nullptr;
}
// Receive input from the user and handle it
bool MazeController::collect_input()
{
	bool return_val;
	std::cout << "Choose a direction to travel: ";
	auto input = std::cin.get();
	if (input == 'q') {
		exit(0);
	}
	auto move_val = current_maze->move(input);
	std::cout << std::endl;
	system("CLS");
	if (move_val == no_dir) {
		std::cout << "There is nothing in that direction\n" << std::endl;
		std::cin.ignore();
		return_val = false;
	}
	else if (move_val == t_dir) {
		std::cout << "You open the trapdoor and climb through\n";
		return_val = true;
	}
	else if (move_val == w_input) {
		std::cout << "That is not a valid direction!" << std::endl;
		std::cout << "These are the directions you can travel: " << current_maze->get_directions() << std::endl;
		return_val = false;
	}
	else {
		std::cout << "You head " << directions[(MOVE_DIR)move_val] << std::endl;
		return_val = true;
	}
	std::cin.ignore();
	return return_val;
}

// Set the default maze layout
bool MazeController::set_default_maze()
{
	std::cin.clear();
	current_maze = current_maze->default_maze();
	return true;
}

// Display the options for travel to the user
void MazeController::display_info() {
	std::cout << "Hit \'q\' then hit enter to quit the maze" << std::endl;
	std::cout << "Get to room: " << current_maze->get_finish_room()->get_name() << std::endl;
	std::cout << "You are in room " << current_maze->get_current_room()->get_name() << std::endl;
	std::cout << "These are the directions you can travel: " << current_maze->get_directions() << std::endl;
}
// Show the main menu to the user
void MazeController::main_menu() {
	bool valid_input_achieved = false;
	bool valid_int_supplied = false;
	int i_response;
	std::string str_response;
	std::cout << "Welcome to C++ Text Based Maze Game!\n" << std::endl;
ask_maze:
	std::cout << "Which type of Maze would you like to play?\n1.Default maze\n2.User generated maze\n3.Randomly generated maze\n4.Quit" << std::endl;
	std::cout << "Please choose an option from the list: ";
	std::cin >> str_response;
    try {
		i_response = std::stoi(str_response, nullptr, 0);
	}
	catch(std::invalid_argument e) {
		std::cout << "You did not enter a valid integer!" << std::endl;
		goto ask_maze;
	}
	std::cin.ignore();
	MazeGenerator* gen_maze = new MazeGenerator();
	do {
		// Switch on the user response
		switch(i_response) {
		case 1:
			system("CLS");
			valid_input_achieved = set_default_maze();
			break;
		case 2:
			valid_input_achieved = maze_from_file();
			break;
		case 3:
			valid_input_achieved = true;
			std::cin.clear();
			while (!valid_int_supplied)
			{
				std::cout << "Choose how many rooms in maze: ";
				std::getline(std::cin, str_response);
				try {
					i_response = std::stoi(str_response, nullptr, 0);
					valid_int_supplied = true;
				}
				catch (std::invalid_argument e) {
					std::cout << "You have not provided an integer value." << std::endl;
				}
			}
			system("CLS");
			current_maze = gen_maze->generate_random(i_response);
			break;
		case 4:
			exit(0);
		default:
			std::cin.clear();
			std::cout << "You have not chosen a valid option, please choose again: ";
			std::cin >> str_response;
			break;
		}
		std::cin.clear();
	} while (!valid_input_achieved);
}

// Set the maze from file, declared by user
bool MazeController::maze_from_file() {
	std::string file_name;
	std::ifstream file;
	do {
		const std::string ext = ".maz";
		std::cout << "Please input the name of the file that you wish to use for the maze (must have .maz extension): ";

		std::getline(std::cin, file_name);

		// Check to see if the file name entered has the valid file extension
		if (std::mismatch(ext.rbegin(), ext.rend(), file_name.rbegin()).first != ext.rend()) {
			std::cout << "Sorry, the file you have chosen does not have the correct file extension (.maz)." << std::endl;
		}
		else {
			file.open(file_name);		
			if (!file.good()) { 
				std::cout << "Sorry the file you have chosen does not exist." << std::endl; 
			}
			file.close();
		}
	} while (!file.good());
	current_maze = Maze::from_file(file_name);
	return true;
}