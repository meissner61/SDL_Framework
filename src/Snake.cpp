#include "Snake.h"
#include <assert.h>

Snake::Snake(const Location& loc)
{
	segments[0].InitHead(loc);
}

void Snake::MoveBy(const Location& delta_loc)
{
	for (int i = nSegments-1; i > 0; i--)
	{
		segments[i].Follow(segments[i - 1]);
	}

	segments[0].MoveBy(delta_loc);
}

Location Snake::GetNextHeadLocation(const Location& delta_loc) const
{
	Location l(segments[0].GetLocation());
	l.Add(delta_loc);
	return l;
}

void Snake::Grow()
{
	if (nSegments < nSegmentsMax)
	{
		segments[nSegments].InitBody();
		nSegments++;
	}
}

void Snake::Draw(Board& brd)
{
	for (int i = 0; i < nSegments; i++)
	{
		segments[i].Draw(brd);
	}
}

int Snake::GetSegments()
{
	return nSegments;
}

//Bug here Where if the snake is about to hit the last tail segment which will move on the next frame it still considers it a collision
//Fix is to not check the last tail segment
bool Snake::IsInTileExceptEnd(const Location& target) const
{
	for (int i = 0; i < nSegments-1; i++)
	{
		if (segments[i].GetLocation() == target)
		{
			return true;
		}
	}

	return false;
}

bool Snake::IsInTile(const Location& target) const
{
	for (int i = 0; i < nSegments; i++)
	{
		if (segments[i].GetLocation() == target)
		{
			return true;
		}
	}

	return false;
}

void Snake::Segment::InitHead(const Location& in_loc)
{
	//TODO add head color
	color = {255, 255, 0};
	loc = in_loc;
}

void Snake::Segment::InitBody()
{
	//TODO add body color
}

void Snake::Segment::Follow(const Segment& next)
{
	loc = next.loc;
}

void Snake::Segment::Draw(Board& brd)
{

	//brd.DrawCell(loc, 0, 100, 0);
	brd.DrawCell(loc, color);

}

void Snake::Segment::MoveBy(const Location& delta_loc)
{
	//assert(abs(delta_loc.x) + abs(delta_loc.y) == 1);
	loc.Add(delta_loc);
}

const Location& Snake::Segment::GetLocation() const
{
	return loc;
}
