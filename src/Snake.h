#ifndef SNAKE_H
#define SNAKE_H

#include "Board.h"
#include "Color.h"

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
		const Location& GetLocation() const;
	private:
		Location loc;
		Color color = { 0,255,0 };

	};
public:
	Snake(const Location& loc);
	void MoveBy(const Location& delta_loc);
	Location GetNextHeadLocation(const Location& delta_loc) const;
	void Grow();
	void Draw(Board& brd);
	int GetSegments();
	bool IsInTileExceptEnd( const Location& target) const;



public:
	static constexpr int nSegmentsMax = 100;
	Segment segments[nSegmentsMax];
	int  nSegments = 1;




};

#endif

