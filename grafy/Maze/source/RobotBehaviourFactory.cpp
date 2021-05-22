#include "RobotBehaviourFactory.h"
#include <memory>
#include "Robot.h"
#include "RobotBehaviourBase.h"
#include "RobotBehaviour.h"

std::unique_ptr<RobotBehaviourBase> RobotBehaviourFactory::create(size_t const xSize, size_t const ySize, Robot& robot)
{
	return std::make_unique<RobotBehaviour>(xSize, ySize, robot);
}
