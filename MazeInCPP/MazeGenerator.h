#pragma once
#include "AutoRoom.h"
#include "Maze.h"
#include <deque>

class MazeGenerator : public Maze
{
private:
	std::deque<NormalRoom*> auto_rooms;
public:
	MazeGenerator();
	MazeGenerator * generate_random(int num_rooms);
};
