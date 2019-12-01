/************************************************
Filename:Frame.cpp
Version: 1.0
Author: Patrick Bobyn
Assignment Number:2
Assignment Name: Assignment2
Course Name: C++
Course Code:CST219
Lab Section Number: 302
Professor's Name: Surbhi Bahri
Due Date: 2019/11/19
Submission Date:2019/11/06
List of source files: AnimationManager.cpp, Animation.cpp, Frame.cpp
Purpose: This is the cpp file responsible for the creation of the frames.
**********************************/

#define _CRT_SECURE_NO_WARNINGS
#define _CRTDBG_MAP_ALLOC

#include <iostream>
using namespace std;
#include "Frame.h"#include <crtdbg.h>
#include <iostream>
#include <string>
#include <vector>
#include <forward_list>
using namespace std;
#include "Frame.h"
#include "Animation.h"
#include "AnimationManager.h"


/***********************************************
Function name: Frame
Purpose: Constructor

In parameters: char*, double
Out Parameters: void
Version: 1.0
Author: Patrick Bobyn
************************************************/
Frame::Frame(char* name, double duration) {
	// give the frame a name and duration
	this->frameName = new char[strlen(name)+1];
	strcpy(this->frameName, name);
	this->duration = duration;
}

/**********************************************
Function name: Frame
Purpose: Constructor

In parameters: Frame&
Out Parameters: void
Version: 1.0
Author: Patrick Bobyn
************************************************/
Frame::Frame(const Frame& temp) {
	// copy the temp Frame into another frame
	this->frameName = new char[strlen(temp.frameName) + 1];
	strcpy(this->frameName, temp.frameName);
	this->duration = temp.duration;
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
}

/***********************************************
Function name: Operator=
Purpose: Overrides the = operator for Frame

In parameters: Frame&
Out Parameters: Frame&
Version: 1.0
Author: Patrick Bobyn
************************************************/
Frame& Frame::operator=(const Frame& temp) {
	
	// delete the old frame name
	delete this->frameName;

	// cope the new information over
	this->frameName = new char[strlen(temp.frameName) + 1];
	strcpy(this->frameName, temp.frameName);
	this->duration = temp.duration;

	return *this;
}

/***********************************************
Function name: operator<<
Purpose: overrides the print out method for frame

In parameters: ostream&, Frame&
Out Parameters: ostream&
Version: 1.0
Author: Patrick Bobyn
************************************************/
ostream& operator<<(ostream& stream, Frame& temp) {
	
	stream << "frameName: " << temp.frameName << "; Duration: " << temp.duration;

	return stream;
}