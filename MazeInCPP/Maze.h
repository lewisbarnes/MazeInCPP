#pragma once
#include "stdafx.h"
#include "NormalRoom.h"
#include "AbstractRoom.h"
#include "Global.h"
namespace MazeInCPP {
	class Maze {
		protected:
			BaseRoom * start_room;
			BaseRoom * finish_room;
			std::string move_order;
			BaseRoom * current_room;
			int steps_taken;
			void append_move();
			std::vector<BaseRoom*> rooms;
			std::map<std::string, BaseRoom*> create_initial_rooms(std::vector<std::string> room_strings);
			void link_rooms(std::vector<std::string> room_strings, std::map<std::string, BaseRoom*> room_map);
		public:
			Maze(std::vector<std::string> room_strings);
			Maze();
			BaseRoom * get_current_room();
			BaseRoom * get_start_room();
			BaseRoom * get_finish_room();
			int move(char direction);
			void start_again();
			bool is_complete();
			Maze * default_maze();
			static Maze* from_file(std::string path);
			std::string get_directions();
			std::string get_move_order();
			int get_steps_taken();
			int set_next_room(char c, int ret);
			void finish();
	};
}
