/************************************************
Filename: Frame.cpp
Version: 1.0
Author: Patrick Bobyn
Assignment Number:1
Assignment Name: Animation Project in C++
Course Name: C++
Course Code:CST219
Lab Section Number: 302
Professor's Name: Surbhi Bahri
Due Date: 2019/10/12
Submission Date:2019/10/02
List of source files: Animation.cpp, Frame.cpp
Purpose: Until the User quits the program. It will read a valid response from the keyboard
in order to go through the process of either creating a frame of animation,editing a frame
,displaying all frames or even delete a frame.
**********************************/

#include <iostream>

#include "Frame.h"

/***********************************************
Function name: Frame
Purpose: Constructor

In parameters: void
Out Parameters: void
Version: 1.0
Author: Patrick Bobyn
************************************************/

Frame::Frame() {
	frameName = nullptr;
	pNext = nullptr;
}

/***********************************************
Function name: ~Frame
Purpose: Deconstructor

In parameters: void
Out Parameters: void
Version: 1.0
Author: Patrick Bobyn
************************************************/

Frame::~Frame() {
	delete this->frameName;
	delete this->pNext;
}