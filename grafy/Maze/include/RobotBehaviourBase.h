#pragma once
#include <utility>
#include <vector>
#include "Robot.h"

class RobotBehaviourBase
{
public:
	RobotBehaviourBase(size_t const xSize, size_t const ySize, Robot& robot)
	{
	}
	virtual void reinit() = 0;
	virtual std::pair <double, std::vector<Position>> explore(Position const& startPosition, Direction const & startDirection) = 0;
};

