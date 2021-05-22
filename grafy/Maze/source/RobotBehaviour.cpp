#include <cstdlib>
#include <iostream>
#include <queue>
#include <vector>
#include <set>
#include <climits>
#include "RobotBehaviour.h"

RobotBehaviour::RobotBehaviour(size_t const xSize, size_t const ySize, Robot & robot) : RobotBehaviourBase(xSize, ySize, robot), robot(robot)
{
}

void RobotBehaviour::reinit()
{
}


void RobotBehaviour::explore(Position const& startPosition, Direction const& startDirection)
{
	// PQ with smallest costs on top
	std::priority_queue<VRecord, std::vector<VRecord>, CMP> vert;
	vert.push(VRecord{startPosition, 0});

	// graph to store Dijkstra results in
	DijkstraNode graph[256][256];

	// set to hold possible exits
	std::set<Position> exits;

	// set the robots direction always towards east
	while (startDirection != Direction::E) robot.turnLeft();

	while(!vert.empty())
	{
		VRecord now = vert.top();
		robot.teleport(now.pos);
		if (!robot.isWallFront()){
			if(now.cost + 1 < graph[now.pos._x + 1][now.pos._y].value){
				graph[now.pos._x + 1][now.pos._y].value = now.cost + 1;
				graph[now.pos._x + 1][now.pos._y].parent = now.pos;
				vert.push(VRecord{Position{now.pos._x + 1, now.pos._y}, now.cost + 1});
			}
		}
		if (!robot.isWallRight())
			if(now.cost + 1 < graph[now.pos._x][now.pos._y + 1].value){
				graph[now.pos._x][now.pos._y + 1].value = now.cost + 1;
				graph[now.pos._x][now.pos._y + 1].parent = now.pos;
				vert.push(VRecord{Position{now.pos._x, now.pos._y + 1}, now.cost + 1});
			}
		if (!robot.isWallBack())
			if(now.cost + 1 < graph[now.pos._x - 1][now.pos._y].value){
				graph[now.pos._x - 1][now.pos._y].value = now.cost - 1;
				graph[now.pos._x - 1][now.pos._y].parent = now.pos;
				vert.push(VRecord{Position{now.pos._x - 1, now.pos._y}, now.cost + 1});
			}
		if (!robot.isWallLeft())
			if(now.cost + 1 < graph[now.pos._x][now.pos._y - 1].value){
				graph[now.pos._x][now.pos._y - 1].value = now.cost + 1;
				graph[now.pos._x][now.pos._y - 1].parent = now.pos;
				vert.push(VRecord{Position{now.pos._x, now.pos._y - 1}, now.cost + 1});
			}
		if (robot.isInExit())
			auto x = exits.insert(now.pos);
		vert.pop();
	}

	// while (!robot.isInExit())
	// {
	// 	int availableDirection = 0;
	// 	if (!robot.isWallFront())
	// 		++availableDirection;
	// 	if (!robot.isWallRight())
	// 		++availableDirection;
	// 	if (!robot.isWallBack())
	// 		++availableDirection;
	// 	if (!robot.isWallLeft())
	// 		++availableDirection;

	// 	int direction = rand() % availableDirection;

	// 	if (robot.isWallFront())
	// 		++direction;
	// 	if (robot.isWallRight() && direction > 0)
	// 		++direction;
	// 	if (robot.isWallBack() && direction > 1)
	// 		++direction;
	// 	while (direction > 0)
	// 	{
	// 		robot.turnRight();
	// 		--direction;
	// 	}
	// 	robot.forward();
	// }
}

