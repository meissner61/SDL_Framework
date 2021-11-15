#include "Goal.h"

Goal::Goal(std::mt19937& rng, const Board& brd, const Snake& snake)
{
	Respawn(rng,brd,snake);
}

void Goal::Respawn(std::mt19937& rng, const Board& brd, const Snake& snake)
{
	std::uniform_int_distribution<int> xDist(brd.GetOffSetX(), (brd.GetWidth() - 1) + brd.GetOffSetX());
	std::uniform_int_distribution<int> yDist(brd.GetOffSetY(), (brd.GetHeight() - 1) + brd.GetOffSetY());


	//TODO: come back and test it out just by setting loc directily instead of using newLoc
	Location newLoc;
	do
	{
		newLoc.x = xDist(rng);
		newLoc.y = yDist(rng);
	} while (snake.IsInTile(newLoc));

	loc = newLoc;
}

void Goal::Draw(Board& brd) const
{
	brd.DrawCell(loc, c);
}

const Location& Goal::GetLocation() const
{
	return loc;
}
