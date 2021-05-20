#pragma once
#include "RobotBehaviourBase.h"
#include "Robot.h"
#include "Position.h"
#include "Maze.h"

class RobotBehaviour : public RobotBehaviourBase
{
public:
	RobotBehaviour(size_t const xSize, size_t const ySize, Robot & robot);

	virtual void reinit() override;

	virtual void explore(Position const& startPosition, Direction const & startDirection) override;

private:
	Robot & robot;
};

