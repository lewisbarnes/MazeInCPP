#pragma once
#include "AutoRoom.h"
#include "Maze.h"

class MazeGenerator : public Maze
{
private:
	std::vector<AutoRoom*> auto_rooms;

public:
	MazeGenerator();
	MazeGenerator * generate_random(int num_rooms);
};
