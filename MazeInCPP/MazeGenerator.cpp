#include "MazeGenerator.h"

// Perform a random shuffle on the set, each permutation is just as likely as any other
template<typename T>
void fy_shuffle(std::vector<T>& data)
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

MazeGenerator * MazeGenerator::generate_random(int num_rooms)
{
	std::vector<char> directions = { 'n','e','s','w','t' };
	for (int i = 1; i <= num_rooms; ++i)
	{
		auto_rooms.push_back(new AutoRoom(std::to_string(i)));
	}

	fy_shuffle(auto_rooms);

	start_room = auto_rooms[0];
	finish_room = auto_rooms[auto_rooms.size() - 1];

	while (auto_rooms.size() > 0)
	{
		int j = (auto_rooms.size() > 6) ? 6 : auto_rooms.size();
		for (int i = 1; i < j; ++i)
		{
			auto_rooms[i - 1]->set_link(directions[i - 1], auto_rooms[i]);
			(auto_rooms[i - 1]->get_link(directions[i - 1])) ? { std::cout << auto_rooms[i - 1]->get_link(directions[i - 1])->get_name() } : 0;
		}
		(auto_rooms.size() > 6) ? auto_rooms.erase(auto_rooms.begin(), auto_rooms.begin() + 6) : auto_rooms.erase(auto_rooms.begin(), auto_rooms.begin() + auto_rooms.size());
	}
	return this;
}


