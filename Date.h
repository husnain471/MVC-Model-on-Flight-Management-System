#pragma once
#include<iostream>
#include<string>
#include <cstdlib>
using namespace std;


class Date {

	int year;
	int month;
	int day;

public:
	Date();
	Date(int year, int month, int day);
	int getDay()const;
	int getMonth()const;
	int getYear()const;
	void setDay(int);
	void setMonth(int);
	void setYear(int);
	bool isLeapYear()const;
	string toString();
	void add(const int& days);
	void add(const int& months, const int& days);
	void add(Date& date);
	void subtract(const int& days);
	void subtract(const int& months, const int& days);
	void subtract(Date& date);
	void addWeeks(const int& weeks);
	bool operator == (Date t);
	int getDifference(Date dt1, Date dt2);
	Date& operator = (Date& dt);
	bool operator > (Date dt);
};


Date::Date() {}

Date::Date(int year, int month, int day) {
	if (year > 0 && month > 0 && day > 0) {
		switch (month) {
		case 4:case 6:case 9:case 11:
			if (day <= 30) {
				this->year = year;
				this->month = month;
				this->day = day;
			}
			else
			{
				this->year = 0;
				this->month = 0;
				this->day = 0;

			}
			break;
		case 2:
			if ((year % 4 == 0 && year % 100 == 0 && year % 400 == 0) || (year % 4 == 0 && year % 100 != 0)) {
				if (day <= 29) {
					this->year = year;
					this->month = month;
					this->day = day;
				}
			}
			else if (day <= 28) {
				this->year = year;
				this->month = month;
				this->day = day;

			}
			else
			{
				this->year = 0;
				this->month = 0;
				this->day = 0;

			}
			break;
		default:
			if (day <= 31) {
				this->year = year;
				this->month = month;
				this->day = day;
			}
			else
			{
				this->year = 0;
				this->month = 0;
				this->day = 0;

			}

		}
	}
}

int Date::getDay()const {
	return day;
}

int Date::getMonth()const {
	return month;
}

int Date::getYear()const {
	return year;
}


void Date::setDay(int d) { this->day = d; }

void Date::setMonth(int m) { this->month = m; }

void Date::setYear(int y) { this->year = y; }

bool Date::isLeapYear()const {
	if ((year % 4 == 0 && year % 100 == 0 && year % 400 == 0) || (year % 4 == 0 && year % 100 != 0))
		return true;
	return false;
}

void Date::add(const int& days) {
	if (days > 0) {
		switch (month) {
		case 4:case 6:case 9:case 11:
			day += days;
			if (day > 30) {
				day -= 30;
				month += 1;
			}
			break;
		case 2:
			day += days;
			if ((year % 4 == 0 && year % 100 == 0 && year % 400 == 0) || (year % 4 == 0 && year % 100 != 0)) {
				if (day > 29) {
					day -= 29;
					month += 1;
				}
			}
			else {
				if (day > 28) {
					day -= 28;
					month += 1;
				}
			}
			break;
		default:
			day += days;
			if (day > 31) {
				day -= 31;
				month += 1;
				if (month > 12) {
					month -= 12;
					year += 1;
				}
			}

		}
	}
}

void Date::add(const int& months, const int& days) {
	if (months > 0 && months < 13 && days>0 && days < 32) {
		day += days;
		if (day > 31) {
			day -= 31;
			month += 1;
		}
		month += months;
		if (month > 12) {
			month -= 12;
			year += 1;
		}
	}
}

void Date::add(Date & date) {
	switch (month) {
	case 4:case 6:case 9:case 11:
		day += date.getDay();
		if (day > 30) {
			day -= 30;
			month += 1;
		}
		break;
	case 2:
		day += date.getDay();
		if ((year % 4 == 0 && year % 100 == 0 && year % 400 == 0) || (year % 4 == 0 && year % 100 != 0)) {
			if (day > 29) {
				day -= 29;
				month += 1;
			}
		}
		else {
			if (day > 28) {
				day -= 28;
				month += 1;
			}
		}
		break;
	default:
		day += date.getDay();
		if (day > 31) {
			day -= 31;
			month += 1;
			if (month > 12) {
				month -= 12;
				year += 1;
			}
		}

	}
	month += date.getMonth();
	if (month > 12) {
		month -= 12;
		year += 1;
	}
	year += date.getYear();
}

void Date::subtract(const int& days) {
	if (days > 0) {
		switch (month) {
		case 4:case 6:case 9:case 11:
			day -= days;
			if (day < 1) {
				day += 31;
				month -= 1;
			}
			break;
		case 2:
			day += days;
			if ((year % 4 == 0 && year % 100 == 0 && year % 400 == 0) || (year % 4 == 0 && year % 100 != 0)) {
				if (day < 1) {
					day += 31;
					month -= 1;
				}
			}
			else {
				if (day < 1) {
					day += 31;
					month -= 1;
				}
			}
			break;
		default:
			day += days;
			if (month == 1) {
				if (day < 1) {
					day += 31;
					month -= 1;
				}
			}
			else if (day < 1) {
				day += 30;
				month -= 1;
			}

		}
		while (month < 1) {
			month += 12;
			year -= 1;
		}
	}
}

void Date::subtract(const int& months, const int& days) {
	if (days >= 0 && months >= 0) {
		switch (month) {
		case 4:case 6:case 9:case 11:
			day -= days;
			if (day < 1) {
				day += 31;
				month -= 1;
			}
			break;
		case 2:
			day += days;
			if ((year % 4 == 0 && year % 100 == 0 && year % 400 == 0) || (year % 4 == 0 && year % 100 != 0)) {
				if (day < 1) {
					day += 31;
					month -= 1;
				}
			}
			else {
				if (day < 1) {
					day += 31;
					month -= 1;
				}
			}
			break;
		default:
			day += days;
			if (month == 1) {
				if (day < 1) {
					day += 31;
					month -= 1;
				}
			}
			else if (day < 1) {
				day += 30;
				month -= 1;
			}

		}
		month -= months;
		while (month < 1) {
			month += 12;
			year -= 1;
		}
	}
}

void Date::subtract(Date & date) {
	switch (month) {
	case 4:case 6:case 9:case 11:
		day -= date.getDay();
		while (day < 1) {
			day += 31;
			month -= 1;
		}
		break;
	case 2:
		day += date.getDay();
		if ((year % 4 == 0 && year % 100 == 0 && year % 400 == 0) || (year % 4 == 0 && year % 100 != 0)) {
			while (day < 1) {
				day += 31;
				month -= 1;
			}
		}
		else {
			while (day < 1) {
				day += 31;
				month -= 1;
			}
		}
		break;
	default:
		day += date.getDay();
		if (month == 1) {
			while (day < 1) {
				day += 31;
				month -= 1;
			}
		}
		else if (day < 1) {
			while (day < 1) {
				day += 30;
				month -= 1;
			}
		}

	}
	month -= date.getMonth();
	while (month < 1) {
		month += 12;
		year -= 1;
	}
	year -= date.getYear();
}

void Date::addWeeks(const int& weeks) {
	if ((weeks * 7) > 0) {
		switch (month) {
		case 4:case 6:case 9:case 11:
			day += (weeks * 7);
			if (day > 30) {
				day -= 30;
				month += 1;
			}
			break;
		case 2:
			day += (weeks * 7);
			if ((year % 4 == 0 && year % 100 == 0 && year % 400 == 0) || (year % 4 == 0 && year % 100 != 0)) {
				if (day > 29) {
					day -= 29;
					month += 1;
				}
			}
			else {
				if (day > 28) {
					day -= 28;
					month += 1;
				}
			}
			break;
		default:
			day += (weeks * 7);
			if (day > 31) {
				day -= 31;
				month += 1;
				if (month > 12) {
					month -= 12;
					year += 1;
				}
			}

		}
	}
}

string Date::toString() {
	string s = "";
	s += to_string(day);
	s += "/";
	s += to_string(month);
	s += "/";
	s += to_string(year);
	return s;
}




bool Date::operator == (Date t) {
	if (this->day == t.day && this->month == t.month && this->year == t.year)
		return 1;
	return 0;
}


int Date::getDifference(Date dt1, Date dt2)
{
	const int monthDays[12] = { 31, 28, 31, 30, 31, 30,
	  31, 31, 30, 31, 30, 31 };
	// COUNT TOTAL NUMBER OF DAYS BEFORE FIRST DATE 'dt1'

	// initialize count using years and day
	long int n1 = dt1.year * 365 + dt1.day;

	// Add days for months in given date
	for (int i = 0; i < dt1.month - 1; i++)
		n1 += monthDays[i];

	// SIMILARLY, COUNT TOTAL NUMBER OF DAYS BEFORE 'dt2'

	long int n2 = dt2.year * 365 + dt2.day;
	for (int i = 0; i < dt2.month - 1; i++)
		n2 += monthDays[i];

	// return difference between two counts
	return (n2 - n1);
}


Date & Date::operator = (Date & dt) {

	this->day = dt.day;
	this->month = dt.month;
	this->year = dt.year;
	return *this;

}



bool Date::operator > (Date dt) {

	if (this->year > dt.year)
		return 1;
	else if (this->year < dt.year)
		return 0;
	if (this->month > dt.month)
		return 1;
	else if (this->month < dt.month)
		return 0;
	if (this->day > dt.day)
		return 1;
	else if (this->day < dt.day)
		return 0;

	return 0;
}