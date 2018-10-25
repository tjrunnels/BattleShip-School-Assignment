Tom Runnels - Lab 8

The battleship program prints out a 2d map of the ocean.  The ~ marks indicate the ocean, 
the o marks indicate missed shot, and the H marks indicate a hit.  To fire a shot, type in
the row coordinate followed by a space followed by a column coordinate (i.e. “21 4”).  

The initial map is loaded in from a file, which contains a list of ships that are to be loaded into the game.  The format of the lvl.txt file is a character indicating the type of ship, followed immediately by an ‘r’ if the position is to be randomly generated, or a ‘.’ if the coordinates are given afterwards.  Said coordinates follow the “.” one at a time separated by spaces.  

The first few lines of the program are used to display how I implemented templates and operator overloading, since I could not think of a good way to implement them into the game.  

As for the rest of the requirements, here is how they were used and (where to find an example):

Classes-   Ship and Inherited ships (Ship.h)
Inheritance-   Different ship types inherit from Ship (InheritedShips.h)
Polymorphism-   the isThere function (InheritedShipsDriver.cpp)
Random- Random ship position generator (readShipsFromFile function in Source.cpp)
Pointers and Double Pointers-   Map generation (main function in Source.cpp)
Array-  Used to hold this ships (main function in Source.cpp)
Operator Overloading- the == operator for Cruiser ships (Cruiser in InheritedShipsDriver.cpp)
Templates-  Calculating area from typename T   (top of Source.cpp file)
File Processing-   Generating ships for the map (readShipsFromFile function in Source.cpp)
Exception Handling-  If the format of the file is wrong(Header.h and readShipsFromFile)


