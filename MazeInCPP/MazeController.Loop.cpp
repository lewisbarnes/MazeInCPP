#include "stdafx.h"
#include "MazeController.h"
using namespace MazeInCPP;
// Main loop for the maze game
void MazeController::start_loop() {
start:
	bool exited = false;
	main_menu();
	if (current_maze == nullptr)
	{
		std::cout << "An error has ocurred, the maze has not been set" << std::endl;
		exited = true;
	}
	while (!exited)
	{
		while (!current_maze->is_complete())
		{
			display_info();
			bool valid_input;
			do
			{
				std::cout << std::endl;
				valid_input = collect_input();
			} while (!valid_input); // While input is invalid, loop collecting input until valid
		}
		std::cout << "You arrive at room " << current_maze->get_current_room()->get_name() << "\n" << std::endl;
		std::cout << "You reached the end of the maze. Well done." << std::endl;
		std::cout << current_maze->get_move_order() << std::endl;
		std::cout << "Steps taken: " << current_maze->get_steps_taken() << std::endl;
	ask_main_menu:
		std::cout << std::endl << "Would you like to go back to the main menu?: ";
		switch (tolower(std::cin.get()))
		{
		case 'y':
			system("CLS");
			goto start;
		case 'n':
			exited = true;
			break;
		default:
			std::cin.ignore();
			std::cout << "That is not a valid option" << std::endl;
			goto ask_main_menu; // Go back up to label, ask again
			break;
		}
	}
}