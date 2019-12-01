/************************************************
Filename:Animation.cpp
Version: 1.0
Author: Patrick Bobyn
Assignment Number:2
Assignment Name: Assignment 2
Course Name: C++
Course Code:CST219
Lab Section Number: 302
Professor's Name: Surbhi Bahri
Due Date: 2019/11/19
Submission Date:2019/11/06
List of source files: AnimationManager.cpp, Animation.cpp, Frame.cpp
Purpose: This cpp file will create the animations. The animations also hold all the frames.
**********************************/

#define _CRT_SECURE_NO_WARNINGS
#define _CRTDBG_MAP_ALLOC

#include <crtdbg.h>
#include <iostream>
#include <string>
#include <vector>
#include <forward_list>
using namespace std;
#include "Frame.h"
#include "Animation.h"
#include "AnimationManager.h"

/***********************************************
Function name: EditFrame
Purpose: Edits a Frame in the Forward_List

In parameters: void
Out Parameters: void
Version: 1.0
Author: Patrick Bobyn
************************************************/
void Animation::EditFrame() {
	
	// create local variables along with calculate the distance from the beginning of the list to the end
	int index, counter = 0;
	char name[50];
	double duration;
	int length = distance(this->frames.begin(), this->frames.end());

	// if the list is empty return 
	if (this->frames.empty()) {
		cout << "There are no Frames" << endl;
		return;
	}

	// printout and get user input for what frame to edit
	cout << "Edit Frame in the Animation" << endl;
	cout << "There are " << length << " Frame(s) in the list. Please specify the index (<=0) to edit at: ";
	cin >> index;

	// check to make sure frame is editable
	if (index >= length) {
		cout << "Not a Frame" << endl;
		return;
	}

	// go through the frames and edit the correct frame, break the loop when the frame is found
	for (Frame &frame : this->frames) {
		if (index == counter) {
			cout << "The name and duration of this frame are " << frame << ". What do you wish to replace them with?" << endl;
			cin >> name;
			cin >> duration;

			Frame temp = Frame(name, duration);
			frame = temp;
			break;
		}
		counter++;
	}
	cout << "Frame #" << index << " edit complete" << endl;
}

/***********************************************
Function name: DeleteFrame
Purpose: Delete a Frame from the list

In parameters: void
Out Parameters: void
Version: 1.0
Author: Patrick Bobyn
************************************************/
void Animation::DeleteFrame() {
	
	// return if there are no frames
	if (this->frames.empty()) {
		cout << "There are no Frames in the Animation" << endl;
		return;
	}
	
	// delete the frame from the front
	this->frames.pop_front();
	cout << "First Frame Deleted" << endl;
}

/***********************************************
Function name: operator>>
Purpose: Overwrite the input for animation

In parameters: istream&, Animation&
Out Parameters: istream&
Version: 1.0
Author: Patrick Bobyn
************************************************/
istream& operator>>(istream& stream, Animation& temp) {
	
	char name[50];
	double duration;

	// get info to insert a frame
	cout << "Insert a Frame in the Animation\nPlease enter the frameName: ";
	cin >> name;

	cout << "Please enter the Frame duration: ";
	cin >> duration;
	
	// add the frame to the front of the list
	temp.frames.push_front(Frame(name, duration));

	cout << "Frame " << name << " added at the front of frames" << endl;

	return stream;
}

/***********************************************
Function name: operator<<
Purpose: Output for the animations

In parameters: ostream&, Animation&
Out Parameters: ostream&
Version: 1.0
Author: Patrick Bobyn
************************************************/
ostream& operator<<(ostream& stream, Animation& temp) {

	stream << "\tAnimation Name is " << temp.animationName << endl;
	stream << "\tReport the animation" << endl;

	// no frames to print out
	if (temp.frames.empty()) {
		stream << "\tNo Frame in the Animation" << endl;
	}

	// prints out all the frames in the list
	int num = 0;
	forward_list<Frame>::iterator i; 
	for (i = temp.frames.begin(); i != temp.frames.end(); i++) {
		stream << "\tFrame " << num << ": " << *i << endl;
	}

	return stream;
}