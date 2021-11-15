//#pragma once
#ifndef GOAL_H
#define GOAL_H

#include <random>
#include "Snake.h"
#include"Board.h"
#include "Color.h"

class Goal
{
public:
	Goal(std::mt19937& rng, const Board& brd, const Snake& snake);
	void Respawn(std::mt19937& rng, const Board& brd, const Snake& snake);
	void Draw( Board& brd) const;
	const Location& GetLocation() const;



private:

	//Figuure out why I cannot have static constexpr Color c;
	Color c = { 255,0,0 };
	Location loc;


};


#endif