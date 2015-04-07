Author:   	Lance Encarnado 100938069 and Angus Leung 100923995
Date:     	April 7, 2015                                                         
Purpose:  	Modified BMS that implements a templated collection
		class and uses an STL list class and incorporates
		polymorphism

Polymorphic behaviour:
A function that displays what each Pirate has looted is invoked
polymorphically, with each type of Pirate stealing a different thing.
This is accessible through option 3 on the main menu.
The classes involved are Pirate (abstract class), Borc, Dorc, and Porc
(all concrete classes inheriting from Pirate).
The virtual function involved in implementing the polymorphic behaviour
is loot(), which is pure virtual in Pirate, and has a concrete
implementation in Borc, Dorc, and Porc.

List of header files:
Borc.h
Brig.h
BrigManager.h
Cell.h
defs.h
Dorc.h
Pirate.h
Porc.h
Queue.h
UIManager.h

List of source files:
Borc.cc
Brig.cc
BrigManager.cc
Cell.cc
Dorc.cc
main.cc
Pirate.cc
Porc.cc
random.cc
UIManager.cc

Other files:
assignment5UML.pdf
Makefile
readme.txt

Exact compilation command:
make a5

Exact launching command: 
./a5

Operating instructions:
- 	To run normally, use the command ./a5 and follow the instructions
	in the console
-	Or, to check if the memory has been properly managed, 
	use the command valgrind ./a5

