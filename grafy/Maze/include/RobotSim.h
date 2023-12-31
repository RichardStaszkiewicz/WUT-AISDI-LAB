#pragma once
#include "Robot.h"
#include "RobotBehaviourBase.h"
#include "MazeBoard.h"
#include "RobotBehaviourFactory.h"
#include "Position.h"
#include <memory>
#include <utility>
#include <string>
#include <vector>

class RobotSim : public Robot
{
public:
	RobotSim(MazeBoard& mazeBoard, RobotBehaviourFactory & robotBehaviourFactory);

	void reinit();

	virtual void teleport(Position const& position) override;
	virtual void forward() override;
	virtual void backward() override;
	virtual void turnLeft() override;
	virtual void turnRight() override;

	virtual bool isWallFront() const override;
	virtual bool isWallBack() const override;
	virtual bool isWallLeft() const override;
	virtual bool isWallRight() const override;

	virtual bool isInExit() const override;

	std::pair <double, std::vector<Position>> explore(const std::string &algorithm=std::string("D"));
private:
	MazeBoard & _mazeBoard;

	std::unique_ptr<RobotBehaviourBase> robot;
};

