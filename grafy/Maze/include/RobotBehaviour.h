#pragma once
#include <climits>
#include <vector>
#include <utility>
#include "RobotBehaviourBase.h"
#include "Robot.h"
#include "Position.h"
#include "Maze.h"

class RobotBehaviour : public RobotBehaviourBase
{
public:
	RobotBehaviour(size_t const xSize, size_t const ySize, Robot & robot);

	virtual void reinit() override;

	virtual std::pair <double, std::vector<Position>> exploreD(Position const& startPosition, Direction const & startDirection) override;
	virtual std::pair <double, std::vector<Position>> exploreA(Position const& startPosition, Direction const & startDirection, size_t const& xlen, size_t const& ylen) override;

private:
	Robot & robot;
};

class VRecord
{
	public:
		Position pos;
		//Direction dir;
		double cost;
};

class DijkstraNode
{
	public:
		double value = INT_MAX;
		Position parent = Position{INT_MAX, INT_MAX};
};

class CMP
{
    public:
        bool operator() (VRecord rhs, VRecord lhs){
            return rhs.cost > lhs.cost;
        }
};