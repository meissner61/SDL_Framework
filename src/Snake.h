#ifndef SNAKE_H
#define SNAKE_H

#include "Board.h"

class Snake
{
public:
	class Segment
	{
	public:
		void InitHead(const Location& in_loc);
		void InitBody();
		void Follow(const Segment& next);
		void Draw(Board& brd);
		void MoveBy(const Location& delta_loc);
	public:
		Location loc;

	};
public:
	Snake(const Location& loc);
	void MoveBy(const Location& delta_loc);
	void Grow();
	void Draw(Board& brd);
	int GetSegments();


public:
	static constexpr int nSegmentsMax = 100;
	Segment segments[nSegmentsMax];
	int  nSegments = 1;




};

#endif

