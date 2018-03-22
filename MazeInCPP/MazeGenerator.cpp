#include "MazeGenerator.h"
#include <sstream>

// Perform a random shuffle on the set, each permutation is just as likely as any other
template<typename T>
void fy_shuffle(std::deque<T>& data)
{
	srand(time(NULL));
	for (int i = data.size()-1; i > 0; --i)
	{
		int r = rand() % (i + 1);
		std::swap(data[i], data[r]);
	}
}
MazeGenerator::MazeGenerator()
{
}
// Auto generate a maze based on integer passed to method
MazeGenerator * MazeGenerator::generate_random(int num_rooms)
{
	for (int i = 1; i <= num_rooms; ++i)
	{
		auto_rooms.push_back(new NormalRoom(std::to_string(i)));
	}

	fy_shuffle(auto_rooms);
	std::vector<char> directions{ 'n','e','s','w','t' };
	start_room = auto_rooms[0];
	finish_room = auto_rooms[auto_rooms.size() - 1];
	while (auto_rooms.size() > 0)
	{
		auto current = auto_rooms.front();
		int j = (auto_rooms.size() > 6) ? 6 : auto_rooms.size();
		for (int i = 1; i < j; ++i)
		{
			fy_shuffle(auto_rooms);
			current->set_link(directions[i-1], auto_rooms[i]);
		}
		auto_rooms.pop_front();
	}
	current_room = start_room;
	return this;
}




