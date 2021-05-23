// call: ./program [-d] [Path to labyrinth description]
#include <iostream>
#include <string>
#include <ctime>
#include "MazeBoard.h"
#include "RobotSim.h"
#include "RobotBehaviourFactory.h"
#include "Position.h"

int main( int argc, char * argv[])
{
	srand(time(nullptr));
	if (argc < 2 || argc > 3)
	{
		std::cerr << "Incorrect number of parameters." << std::endl;
		return -2;
	}

	bool displayDebugInfo = false;
	if (argc == 3)
	{
		std::string par(argv[1]);
		if (par == "-d")
			displayDebugInfo = true;
	}

	MazeBoard maze( displayDebugInfo);
	maze.read( argv[argc-1]);
	RobotBehaviourFactory robotBehaviourFactory;

	RobotSim robot( maze, robotBehaviourFactory );

	robot.reinit();

	maze.dispaly(std::cout);

	std::pair <double, std::vector<Position>> answer = robot.explore(std::string("A*"));

	// if (!robot.explore())
	// {
	// 	maze.dispaly(std::cout);
	// 	if( displayDebugInfo)
	// 		std::cout << "Exploration error. " << std::endl;
	// 	std::cout << -1 << std::endl;
	// 	return -1;
	// }

	maze.dispaly(std::cout);
	if (displayDebugInfo)
		std::cout << "Exploration success. " << std::endl;

	//std::cout << maze.getCost() << std::endl;
	std::cout << "Minimum distance: " << answer.first << '\n';
	for(int i = 0; i < answer.second.size(); i++) std::cout << answer.second[i] << std::endl;
	return 0;
}
