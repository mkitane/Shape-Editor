#Shape Editor

##Introduction
Shape Editor is a basic command line shape editor that allows you to create and design different shapes using a terminal without any graphic part.
The application handles circles, rectangles, lines, polygonal chains and aggregate objects.
It allows you to do some basic tasks on this objects like add, move, delete, undo, redo.
You can also save your work and load it.


##Build and Run

	cd src/Debug
	make ./B3424


##Specifications 

The supported commands are the following : 

*	C name x1 y1	:	Create a circle

*	R name x1 y1 x2 y2	:	Create a rectangle

*	L name x1 y1 x2 y2	:	Create a line

*	PL name x1 y1 x2 y2 .. xn yn	: Create a polygonal chain

*	OA name object1 .. objectn	: Create an aggregate using previously created objects

*	MOVE name x1 y1

*	List

*	UNDO

*	REDO

*	DELETE name

*	CLEAR

*	SAVE file

*	LOAD file

*	EXIT


##Go further
For more informations please see (In French) :

	/ doc / Conception_B3424.pdf
	/ doc / Perfs_B3424.pdf

