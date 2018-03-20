#include "AutoRoom.h"

bool AutoRoom::visit()
{
	if (!visited)
	{
		visited = true;
	}
	return visited;
}

AutoRoom::AutoRoom(std::string n)
{
	name = n;
}

AutoRoom::AutoRoom()
{
}

std::string AutoRoom::get_directions()
{
	std::string return_string;
	get_link('n') ? return_string.append("(N)North ") : void();
	get_link('e') ? return_string.append("(E)East ") : void();
	get_link('s') ? return_string.append("(S)South ") : void();
	get_link('w') ? return_string.append("(W)West ") : void();
	get_link('t') ? return_string.append("(T)Trapdoor ") : void();
	return return_string;
}
