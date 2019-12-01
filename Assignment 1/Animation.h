//Animation.h
#pragma once
#include"Frame.h"

class Animation
{
	char* animationName;
	Frame* frames;
public:
	Animation();
	~Animation();
	void InsertFrame();
	void EditFrame();
	void DeleteFrame();
	void ReportAnimation();
};
