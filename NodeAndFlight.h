#pragma once
#include "Vector.h"
#include "Time.h"
#include "Date.h"
#include <iostream>
using namespace std;

class Flight;
class Node;

class Flight {
public:
	short flying_hours;
	Time time_of_take_off;
	Time time_of_landing;
	Date date;
	double price;
	string destination_city;
	string AirLine_name;
	Node* destination_adress;
	short destinaation_code;
	Date arrival_date;
public:
	bool operator == (Flight& t) {
		if (this->AirLine_name == t.AirLine_name && this->destinaation_code == t.destinaation_code)
			if (this->destination_adress == t.destination_adress && this->destination_city == this->destination_city)
				if (this->flying_hours == t.flying_hours && this->price == t.price)
					if (this->time_of_landing == t.time_of_landing && this->time_of_take_off == t.time_of_take_off)
						if (this->date == t.date)
							if (this->arrival_date == t.arrival_date)
								return 1;

		return 0;
	}

	Flight & operator = (Flight & flt) {
		this->AirLine_name = flt.AirLine_name;
		this->date = flt.date;
		this->destinaation_code = flt.destinaation_code;
		this->destination_adress = flt.destination_adress;
		this->destination_city = flt.destination_city;
		this->flying_hours = flt.flying_hours;
		this->price = flt.price;
		this->time_of_landing = flt.time_of_landing;
		this->time_of_take_off = flt.time_of_take_off;
		this->arrival_date = flt.arrival_date;
		return *this;
	}


};



class Node {

public:

	string city_name;
	double cost_of_stay;
	Vector <Flight> flights;

};
