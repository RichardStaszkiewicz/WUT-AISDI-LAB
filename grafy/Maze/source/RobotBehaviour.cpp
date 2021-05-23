#include <cstdlib>
#include <iostream>
#include <queue>
#include <vector>
#include <set>
#include <climits>
#include <algorithm>
#include <utility>
#include "RobotBehaviour.h"

RobotBehaviour::RobotBehaviour(size_t const xSize, size_t const ySize, Robot & robot) : RobotBehaviourBase(xSize, ySize, robot), robot(robot)
{
}

void RobotBehaviour::reinit()
{
}


std::pair <double, std::vector<Position>> RobotBehaviour::explore(Position const& startPosition, Direction const& startDirection)
{
	// PQ with smallest costs on top
	std::priority_queue<VRecord, std::vector<VRecord>, CMP> vert;
	vert.push(VRecord{startPosition, 0});

	// graph to store Dijkstra results in (max maze size)
	DijkstraNode graph[256][256];

	// set to hold possible exits
	std::vector<Position> exits;

	// set the robots direction always towards east
	if (startDirection == Direction::N) robot.turnRight();
	if (startDirection == Direction::S) robot.turnLeft();
	if (startDirection == Direction::E) {robot.turnRight(); robot.turnRight();}

	int it = 0;
	// Dijkstra to fill up the graph
	while(!vert.empty())
	{
		std::cout << it << '\n';
		it++;
		VRecord now = vert.top();
		robot.teleport(now.pos);

		// check for first neighbour
		if (!robot.isWallFront()){
			if(now.cost + 1 < graph[now.pos._x + 1][now.pos._y].value){
				graph[now.pos._x + 1][now.pos._y].value = now.cost + 1;
				graph[now.pos._x + 1][now.pos._y].parent = now.pos;
				vert.push(VRecord{Position{now.pos._x + 1, now.pos._y}, now.cost + 1});
			}
		}

		// check for second neighbour
		if (!robot.isWallRight()){
			if(now.cost + 1 < graph[now.pos._x][now.pos._y + 1].value){
				graph[now.pos._x][now.pos._y + 1].value = now.cost + 1;
				graph[now.pos._x][now.pos._y + 1].parent = now.pos;
				vert.push(VRecord{Position{now.pos._x, now.pos._y + 1}, now.cost + 1});
			}
		}

		// check for the third neighbour
		if (!robot.isWallBack()){
			if(now.cost + 1 < graph[now.pos._x - 1][now.pos._y].value){
				graph[now.pos._x - 1][now.pos._y].value = now.cost - 1;
				graph[now.pos._x - 1][now.pos._y].parent = now.pos;
				vert.push(VRecord{Position{now.pos._x - 1, now.pos._y}, now.cost + 1});
			}
		}

		// check for the fourth neighbour
		if (!robot.isWallLeft()){
			if(now.cost + 1 < graph[now.pos._x][now.pos._y - 1].value){
				graph[now.pos._x][now.pos._y - 1].value = now.cost + 1;
				graph[now.pos._x][now.pos._y - 1].parent = now.pos;
				vert.push(VRecord{Position{now.pos._x, now.pos._y - 1}, now.cost + 1});
			}
		}

		// if it's exit, save position to the exits (may be redundant, there is no significant amount)
		if (robot.isInExit())
			exits.push_back(now.pos);
		vert.pop();
	}

	int min_cost = INT_MAX;
	Position min_par = Position{0, 0};
	for (int i = 0;  i < exits.size(); i++)
	{
		if(graph[exits[i]._x][exits[i]._y].value < min_cost){
			min_cost = graph[exits[i]._x][exits[i]._y].value;
			min_par = graph[exits[i]._x][exits[i]._y].parent;
		}
	}
	std::vector <Position> traceroot;
	traceroot.push_back(min_par);
	while(min_par != startPosition)
	{
		min_par = graph[min_par._x][min_par._y].parent;
		traceroot.push_back(min_par);
	}
	return std::make_pair(min_cost, traceroot);

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

