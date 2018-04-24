#include "stdafx.h"
#include "MazeGenerator.h"
#include <sstream>
using namespace MazeInCPP;
MazeGenerator::MazeGenerator() {

}
// Implementation of Fisher-Yates shuffle https://en.wikipedia.org/wiki/Fisher%E2%80%93Yates_shuffle
void fy_shuffle(std::deque<NormalRoom*>& data)
{
	srand((unsigned int)time(NULL));
	for (int i = data.size()-1; i > 0; --i)
	{
		int r = rand() % (i + 1);
		std::swap(data[i], data[r]);
	}
}
// Auto generate a maze based on integer passed to method
MazeGenerator * MazeGenerator::generate_random(int num_rooms) {
	std::deque<NormalRoom*> auto_rooms;
	std::vector<char> directions{ 'n','e','s','w','t' };
	// Add x amount of rooms to the queue
	for (int i = 1; i <= num_rooms; ++i) {
		auto_rooms.push_back(new NormalRoom(std::to_string(i)));
	}
	fy_shuffle(auto_rooms);
	// Set start room to the first element of the deque and set the finish room last element
	start_room = auto_rooms.front();
	finish_room = auto_rooms.back();
	// Link all rooms to the next rooms 
	while (auto_rooms.size() > 0) {
		auto current = auto_rooms.front();
		int j = (auto_rooms.size() > 6) ? 6 : auto_rooms.size();
		for (int i = 1; i < j; ++i) {
			current->set_link(directions[i-1], auto_rooms[i]);
		}
		// Pop front to remove it from the deque
		auto_rooms.pop_front();
	}
	current_room = start_room;
	return this;
}