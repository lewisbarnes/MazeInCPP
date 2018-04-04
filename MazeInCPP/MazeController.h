// MazeController.h
#pragma once
#include "stdafx.h"
#include "Maze.h"
#include "MazeGenerator.h"
namespace MazeInCPP
{
	class MazeController
	{
	private:
		Maze * current_maze;
		void display_info();
		bool collect_input();
		bool set_default_maze();
		bool maze_from_file();
		void main_menu();
	public:
		void start_loop();
		MazeController();
	};
	enum MOVE_DIR { no_dir, n_dir, e_dir, s_dir, w_dir, t_dir, w_input };
}
