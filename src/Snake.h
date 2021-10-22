#ifndef SNAKE_H
#define SNAKE_H

#include "Board.h"

class Snake
{
private:
	class Segment
	{
	public:
		void InitHead(const Location& in_loc);
		void InitBody();
		void Follow(const Segment& next);
		void Draw(Board& brd);
		void MoveBy(const Location& delta_loc);
	private:
		Location loc;

	};
public:
	Snake(const Location& loc);
	void MoveBy(const Location& delta_loc);
	void Grow();
	void Draw(Board& brd);


private:
	static constexpr int nSegmentsMax = 100;
	Segment segments[nSegmentsMax];
	int  nSegments = 1;




};

#endif

