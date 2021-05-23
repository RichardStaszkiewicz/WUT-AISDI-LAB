#pragma once
#include <utility>
#include <vector>
#include "Robot.h"
#include "Position.h"

class RobotBehaviourBase
{
public:
	RobotBehaviourBase(size_t const xSize, size_t const ySize, Robot& robot)
	{
	}
	virtual void reinit() = 0;
	virtual std::pair <double, std::vector<Position>> exploreD(Position const& startPosition, Direction const & startDirection) = 0;
	virtual std::pair <double, std::vector<Position>> exploreA(Position const& startPosition, Direction const & startDirection, size_t const& xlen, size_t const& ylen) = 0;
};

