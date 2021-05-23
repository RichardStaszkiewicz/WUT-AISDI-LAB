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


std::pair <double, std::vector<Position>> RobotBehaviour::exploreD(Position const& startPosition, Direction const& startDirection)
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
}

double offset(const Position &curPos, const std::pair <double, double> &center)
{
	return std::abs(curPos._x - center.first) + std::abs(curPos._y - center.second);
}

std::pair <double, std::vector<Position>> RobotBehaviour::exploreA(Position const& startPosition, Direction const & startDirection, size_t const& xlen, size_t const& ylen)
{
	// A* heuristic policy:
	// The cost of each verticle is described by the equation:
	// cost = min_route_from_start + center_delta_x + center_delta_y

	// graph to store A* results in (max maze size)
	DijkstraNode graph[256][256];

	// pair describing the position of the center
	std::pair<double, double> center = std::make_pair(double(xlen)/2, double(ylen)/2);

	// PQ with smallest costs on top
	std::priority_queue<VRecord, std::vector<VRecord>, CMP> vert;
	vert.push(VRecord{startPosition, offset(startPosition, center)});

	// set the robots direction always towards east
	if (startDirection == Direction::N) robot.turnRight();
	if (startDirection == Direction::S) robot.turnLeft();
	if (startDirection == Direction::E) {robot.turnRight(); robot.turnRight();}

	int it = 0;
	VRecord now{startPosition, 0};
	// Dijkstra to fill up the graph
	while(!robot.isInExit())
	{
		std::cout << it << '\n';
		it++;
		now = vert.top();

		// return to unheuristic cost & move robot to current position
		now.cost -= offset(now.pos, center);
		robot.teleport(now.pos);

		// check for first neighbour
		if (!robot.isWallFront()){
			if(now.cost + 1 < graph[now.pos._x + 1][now.pos._y].value){
				graph[now.pos._x + 1][now.pos._y].value = now.cost + 1;
				graph[now.pos._x + 1][now.pos._y].parent = now.pos;
				vert.push(VRecord{Position{now.pos._x + 1, now.pos._y}, now.cost + offset(Position{now.pos._x + 1, now.pos._y}, center) + 1});
			}
		}

		// check for second neighbour
		if (!robot.isWallRight()){
			if(now.cost + 1 < graph[now.pos._x][now.pos._y + 1].value){
				graph[now.pos._x][now.pos._y + 1].value = now.cost + 1;
				graph[now.pos._x][now.pos._y + 1].parent = now.pos;
				vert.push(VRecord{Position{now.pos._x, now.pos._y + 1}, now.cost + offset(Position{now.pos._x, now.pos._y + 1}, center) + 1});
			}
		}

		// check for the third neighbour
		if (!robot.isWallBack()){
			if(now.cost + 1 < graph[now.pos._x - 1][now.pos._y].value){
				graph[now.pos._x - 1][now.pos._y].value = now.cost - 1;
				graph[now.pos._x - 1][now.pos._y].parent = now.pos;
				vert.push(VRecord{Position{now.pos._x - 1, now.pos._y}, now.cost + offset(Position{now.pos._x - 1, now.pos._y}, center) + 1});
			}
		}

		// check for the fourth neighbour
		if (!robot.isWallLeft()){
			if(now.cost + 1 < graph[now.pos._x][now.pos._y - 1].value){
				graph[now.pos._x][now.pos._y - 1].value = now.cost + 1;
				graph[now.pos._x][now.pos._y - 1].parent = now.pos;
				vert.push(VRecord{Position{now.pos._x, now.pos._y - 1}, now.cost + offset(Position{now.pos._x, now.pos._y - 1}, center) + 1});
			}
		}
		vert.pop();
	}
	std::vector <Position> traceroot;
	Position min_par = now.pos;
	traceroot.push_back(min_par);
	while(min_par != startPosition)
	{
		min_par = graph[min_par._x][min_par._y].parent;
		traceroot.push_back(min_par);
	}
	return std::make_pair(traceroot.size() - 2, traceroot);
}
