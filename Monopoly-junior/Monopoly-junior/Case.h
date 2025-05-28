#pragma once

class Case
{
protected: 
	int position ; 

public : 
	Case(int position);
	Case();

	int getPosition() const;
	void setPosition(int newPostion);
};

