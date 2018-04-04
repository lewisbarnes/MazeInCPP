#pragma once
#include "stdafx.h"
#include "NormalRoom.h"
#include "AbstractRoom.h"
#include "Global.h"
namespace MazeInCPP {
	class Maze {
		protected:
			AbstractRoom * start_room;
			AbstractRoom * finish_room;
			std::string move_order;
			AbstractRoom * current_room;
			int steps_taken;
			void append_move();
		public:
			Maze(std::vector<std::string> room_strings);
			Maze();
			AbstractRoom * get_current_room();
			AbstractRoom * get_start_room();
			AbstractRoom * get_finish_room();
			int move(char direction);
			void start_again();
			bool is_complete();
			std::map<std::string, AbstractRoom*> create_initial_rooms(std::vector<std::string> room_strings);
			void link_rooms(std::vector<std::string> room_strings, std::map<std::string, AbstractRoom*> room_map);
			Maze * default_maze();
			static Maze* from_file(std::string path);
			std::string get_directions();
			std::string get_move_order();
			int get_steps_taken();
			int set_next_room(char c, int ret);
	};
}
