#pragma once

#include <iostream>
#include <string>
using namespace std;

class Time {

	int hours;
	int minutes;

public:

	Time();
	Time(int h, int m);
	void setTime(int h, int m);
	float operator- (Time t);
	string toString();
	Time addInHours(int num);


	bool operator == (Time& t) {
		if (this->hours == t.hours && this->minutes == t.hours)
			return 1;
		return 0;
	}

	Time& operator = (Time & t) {
		this->hours = t.hours;
		this->minutes = t.minutes;
		return *this;
	}




};


Time Time::addInHours(int num) {
	this->hours += num;
	return *this;
}


Time::Time() {}

Time::Time(int h, int m) {

	if (h >= 0 && h <= 24 && m >= 0 && m <= 59) {
		hours = h;
		minutes = m;
	}

	else
		hours = minutes = -1;
}

void Time::setTime(int h, int m) {
	if (h >= 0 && h <= 24 && m >= 0 && m <= 59) {
		hours = h;
		minutes = m;
	}

	else
		hours = minutes = -1;
}


float Time::operator- (Time t) {
	return (this->hours - t.hours) + (abs(this->minutes - t.minutes) * 0.01);
}


string Time::toString() {
	string s = "";
	s += to_string(this->hours);
	s += ":";
	s += to_string(this->minutes);
	return s;
}
