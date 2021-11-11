#ifndef LOCATION_H
#define LOCATION_h

struct Location
{
	void Add(const Location& val)
	{
		x += val.x;
		y += val.y;
	}

	//rhs == right hand side // ex 5 == 5; 5 == 7 -> 5 and 7 on the right is the RHS
	//important note! this only defines == for const operators, if wanting to compare non const need to make a new non const operator here
	bool operator==(const Location& rhs) const
	{
		return x == rhs.x && y == rhs.y;
	}

	int x;
	int y;
};

#endif