//ABSTRACTFACTORY



/* Recall that the member function CreateMaze builds a small maze consisting of two rooms
with a door between them. CreateMaze hard-codes the class names, making it difficult to create mazes with different components.
Here's a version of CreateMaze that remedies that shortcoming by taking a MazeFactory as a parameter: */
Maze* aMazeGame::CreateMaze(MazFactory& factory) {
	Maze* aMaze = factory.MakeMaze();
	Room* r1 = factory.MakeRoom(1);
	Room* r2 = factory.MakeRoom(2);
	Door* aDoor = factory.MakeDoor(r1, r2);

	aMaze->AddRoom(r1);
	aMaze->AddRoom(r2);

	r1->SetSide(North, factory.MakeWall());
	r1->SetSide(East, aDoor);
	r1->SetSide(South, factory.MakeWall());
	r1->SetSide(West, factory.MakeWall());


	r2->SetSide(North, factory.MakeWall());
	r2->SetSide(East, factory.MakeWall());
	r2->SetSide(South, factory.MakeWall());
	r2->SetSide(West, aDoor);

	return aMaze;
}

/* We can create EnchantedMazeFactory, a factory for enchanted mazes, by subclassing MazeFactory.
EnchantedMazeFactory will override different member functions and return different subclasses of Room, Wall, etc.*/
class EnchantedMazeFactory : public MazFactory {
public:
	EnchantedMazeFactory();

	virtual Room* MakeRoom(int n)const {
		return new EnchantedRoom(n, CastSpell());
	}
	virtual Door* MakeDoor(Room* r1, Room* r2)const {
		return new DoorNeedingSpell(r1, r2);
	}

protected:
	Spell* CastSpell()const;

};

/*Now suppose we want to make a maze game in which a room can have a bomb set in it. If the bomb goes
off, it will damage the walls (at least). We can make a subclass of Room keep track of whether the room
has a bomb in it and whether the bomb has gone off. We'll also need a subclass of Wall to keep track of
the damage done to the wall. We'll call these classes RoomWithABomb and BombedWall.
The last class we'll define is BombedMazeFactory, a subclass of MazeFactory that ensures walls
are of class BombedWall and rooms are of class RoomWithABomb. BombedMazeFactory only
needs to override two functions: */
Wall* BombedMazeFatctory::MakeRoom()const {
	return new BombedWall;
}
Room* BombedMazeFactory::MakeRoom(int n)const {
	return new RoomWithABomb(n);
}

/*To build a simple maze that can contain bombs, we simply call CreateMaze with a BombedMazeFactory.*/
MazeGame game;
game.CreateMaze(factory);

/*CreateMaze can take an instance of EnchantedMazeFactory just as well to build enchanted mazes.
Notice that the MazeFactory is just a collection of factory methods. This is the most common way to
implement the Abstract Factory pattern. Also note that MazeFactory is not an abstract class; thus it
acts as both the AbstractFactory and the ConcreteFactory. This is another common implementation for
simple applications of the Abstract Factory pattern. Because the MazeFactory is a concrete class
consisting entirely of factory methods, it's easy to make a new MazeFactory by making a subclass and
overriding the operations that need to change.
CreateMaze used the SetSide operation on rooms to specify their sides. If it creates rooms with a
BombedMazeFactory, then the maze will be made up of RoomWithABomb objects with
BombedWall sides. If RoomWithABomb had to access a subclass-specific member of BombedWall,
then it would have to cast a reference to its walls from Wall* to BombedWall*. This downcasting is
safe as long as the argument is in fact a BombedWall, which is guaranteed to be true if walls are built
solely with a BombedMazeFactory.
Dynamically typed languages such as Smalltalk don't require downcasting, of course, but they might
produce run-time errors if they encounter a Wall where they expect a subclass of Wall. Using Abstract
Factory to build walls helps prevent these run-time errors by ensuring that only certain kinds of walls can
be created.
Let's consider a Smalltalk version of MazeFactory, one with a single make operation that takes the
kind of object to make as a parameter. Moreover, the concrete factory stores the classes of the products it
creates.
First, we'll write an equivalent of CreateMaze in Smalltalk:

createMaze: aFactory
| room1 room2 aDoor |
room1 := (aFactory make: #room) number: 1.
room2 := (aFactory make: #room) number: 2.
aDoor := (aFactory make: #door) from: room1 to: room2.
room1 atSide: #north put: (aFactory make: #wall).
room1 atSide: #east put: aDoor.
room1 atSide: #south put: (aFactory make: #wall).
room1 atSide: #west put: (aFactory make: #wall).
room2 atSide: #north put: (aFactory make: #wall).
room2 atSide: #east put: (aFactory make: #wall).
Abstract Factory
room2 atSide: #south put: (aFactory make: #wall).
room2 atSide: #west put: aDoor.
^ Maze new addRoom: room1; addRoom: room2; yourself

As we discussed in the Implementation section, MazeFactory needs only a single instance variable
partCatalog to provide a dictionary whose key is the class of the component. Also recall how we implemented the make: 
method:
make: partName
^ (partCatalog at: partName) new
Now we can create a MazeFactory and use it to implement createMaze. We'll create the factory
using a method createMazeFactory of class MazeGame.
createMazeFactory
^ (MazeFactory new
addPart: Wall named: #wall;
addPart: Room named: #room;
addPart: Door named: #door;
yourself)
A BombedMazeFactory or EnchantedMazeFactory is created by associating different classes
with the keys. For example, an EnchantedMazeFactory could be created like this:
createMazeFactory
^ (MazeFactory new
addPart: Wall named: #wall;
addPart: EnchantedRoom named: #room;
addPart: DoorNeedingSpell named: #door;
yourself)*/