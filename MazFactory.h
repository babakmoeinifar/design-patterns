
/*Class MazeFactory can create components of mazes. It builds rooms, walls, and doors between
rooms.It might be used by a program that reads plans for mazes from a file and builds the corresponding
maze.Or it might be used by a program that builds mazes randomly.Programs that build mazes take a Abstract Factory
MazeFactory as an argument so that the programmer can specify the classes of rooms, walls, and doors to construct.*/
#pragma once

class MazFactory {

public:
	MazFactory();

	virtual Maze* MakeMaze() const {
		return new Maze;
	}
	virtual Wall* MakeWall() const {
		return new Wall;
	}
	virtual Room* MakeRoom(int n) const {
		return new Room(n);
	}
	virtual Door* MakeDoor(Room* r1, Room* r2) const {
		return new Door(r1, r2);
	}
};

