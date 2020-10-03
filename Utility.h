#pragma once
#include <iostream>
#include "Graph.h"
#include "Vector.h"
using namespace std;

int getCityCode(string str) {

	//Islamabad 0
	//NewYork 1
	//Paris 2
	//Tokyo 3
	//London 4
	//Singapore 5
	//HongKong 6
	//Berlin 7
	//Seoul 8
	//Amsterdam 9
	// Sydney 10

	for (int i = 0; i < str.length(); i++)
		if (str[i] < 97)
			str[i] += 32;

	if (str == "islamabad")
		return 0;
	if (str == "newyork")
		return 1;
	if (str == "paris")
		return 2;
	if (str == "tokyo")
		return 3;
	if (str == "london")
		return 4;
	if (str == "singapore")
		return 5;
	if (str == "hongkong")
		return 6;
	if (str == "berlin")
		return 7;
	if (str == "seoul")
		return 8;
	if (str == "amsterdam")
		return 9;
	if (str == "sydney")
		return 10;

}


string getCityName(int code) {



	//Islamabad 0
	//NewYork 1
	//Paris 2
	//Tokyo 3
	//London 4
	//Singapore 5
	//HongKong 6
	//Berlin 7
	//Seoul 8
	//Amsterdam 9
	// Sydney 10


	if (code == 0)
		return "Islamabad";
	if (code == 1)
		return "NewYork";
	if (code == 2)
		return "Paris";
	if (code == 3)
		return "Tokyo";
	if (code == 4)
		return "London";
	if (code == 5)
		return "Singpore";
	if (code == 6)
		return "HongKong";
	if (code == 7)
		return "Berlin";
	if (code == 8)
		return "Seoul";
	if (code == 9)
		return "Amsterdam";
	if (code == 10)
		return "Sydney";

	return "";
}




string Normalize(int num, short digits) {

	string str = to_string(num);

	if (str.length() >= digits)
		return str;

	for (int i = str.length(); i < digits; i++)
		str += " ";
	return str;

}



int findMinInCol(int array[][11], int col, Vector <int> & list) {

	int min = 99999999;
	int r = 0;

	for (int i = 0; i < 11; i++) {

		if (array[i][col] < min) {
			if (list.find(i) == 0) {
				min = array[i][col];
				r = i;
			}
		}

	}


	return r;
}




int Menue() {
	int c = 0;

	cout << "Enter number of desired senerio:-\n";
	cout << "1) Wants to book a non-connecting (i.e., direct) flight going to a certaindestination on a specific date and time.\n";

	cin >> c;
	return c;
}






bool check(string actuall, string inserted) {

	short mis = 0;

	if (abs((int)actuall.length() - (int)inserted.length()) > 1)
		mis += 2;


	for (int i = 0; i < actuall.length(); i++) {

		if (i < inserted.length()) {
			if (actuall[i] == inserted[i])
				continue;
			else if (i - 1 >= 0)
				if (actuall[i] == inserted[i - 1])
					continue;
				else
					mis++;
		}

		else if (i + 1 < inserted.length())
			if (actuall[i] != inserted[i + 1])
				mis++;

	}

	return (mis < 3) ? 1 : 0;
}


void conver_to_lower_case(string & s) {

	for (int i = 0; i < s.length(); i++) {

		if (s[i] >= 65 && s[i] <= 90) {
			s[i] += 32;
		}

	}

}
