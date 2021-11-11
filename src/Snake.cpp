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

void Snake::Segment::InitHead(const Location& in_loc)
{
	loc = in_loc;
}

void Snake::Segment::InitBody()
{
	//TODO
}

void Snake::Segment::Follow(const Segment& next)
{
	loc = next.loc;
}

void Snake::Segment::Draw(Board& brd)
{
	brd.DrawCell(loc, 0, 100, 0);
}

void Snake::Segment::MoveBy(const Location& delta_loc)
{
	//assert(abs(delta_loc.x) + abs(delta_loc.y) == 1);
	loc.Add(delta_loc);
}

Location Snake::Segment::GetLocation() const
{
	return loc;
}
