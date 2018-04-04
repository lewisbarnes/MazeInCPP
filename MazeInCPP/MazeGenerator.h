#pragma once
#include "stdafx.h"
#include "Maze.h"
namespace MazeInCPP {
	class MazeGenerator : public Maze
	{
	private:
		std::deque<NormalRoom*> auto_rooms;
	public:
		MazeGenerator();
		MazeGenerator * generate_random(int num_rooms);
	};
}

