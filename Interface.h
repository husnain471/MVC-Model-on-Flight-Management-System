#pragma once
#include<iostream>
#include"Graph.h"
#include "Trie.h"
#include <Windows.h>
using namespace std;
string AirlineName(int val) {
	if (val == 1) {
		return "Emirates";
	}
	else if (val == 2) {
		return "Qatar";
	}
	else if (val == 3) {
		return "ANA";
	}
	return "";
}
string UpperCase(string str) {
	if (int(str[0]) < 65 || int(str[0]) > 90) {
		str[0] = char(int(str[0]) - 32);
	}
	return str;
}



void Start() {
	system("color 30");
	ifstream i("Draw.txt");

	string s;
	do {
		getline(i, s);
		cout << s << endl;
	} while (!i.eof());
	cout << "\n\n\n\n\n\n\t\t\t\t\t\t  ";
	for (int i = 0; i < 8; i++) {
		cout << "_ ";
		Sleep(350);
	}
	system("CLS");
}



void Interface() {
	Start();
	system("color F0");
	graph go;
	TRIE t("Dictionary.txt");
	cout << "\t\t\t\t\t\tFLIGHT RESERVATION SYSTEM";
	cout << endl << endl;
	cout << "Enter Departure airport:";
	string origin;
	cin >> origin;
	origin = UpperCase(t.SpellChecker(origin));
	cout << endl;
	cout << "Enter Arrival Airport:";
	string destination;
	cin >> destination;
	cout << endl;
	destination = UpperCase(t.SpellChecker(destination));
	cout << "Write your date of travel\n";
	Date dt;
	int day, month, year;
	cout << "Enter Day:";
	cin >> day;
	cout << endl;
	cout << "Enter Month:";
	cin >> month;
	cout << endl;
	cout << "Enter Year:";
	cin >> year;
	cout << endl;
	dt.setDay(day);
	dt.setMonth(month);
	dt.setYear(year);
	int Direct_check = 0;
	int Company_check = 0;
	int costTimecheck = 0;
	int airline = 0;
	cout << "If you want a direct flight specifically enter 1 and if you want a transit stay enter 2 else any other number:";
	cin >> Direct_check;
	cout << "If you want to travel on a specific airline enter 1 else enter anyother number:";
	cin >> Company_check;
	cout << endl;
	if (Company_check == 1) {
		cout << "If you want to travel on Emirates enter 1\n";
		cout << "If you want to travel on Qatar enter 2\n";
		cout << "If you want to travel on ANA enter 3\n";
		cin >> airline;
	}
	if (Direct_check != 1 && Direct_check != 2) {
		cout << "If you want to have flights with lowest travel cost enter 1 else enter 2 if you want to travel on a flight with lowest time else enter anyother number\n";
		cin >> costTimecheck;
	}
	if (Direct_check == 1) {
		go.DisplayDirectFlight(getCityCode(origin), getCityCode(destination), dt, AirlineName(airline));
	}
	else if (Direct_check == 2) {
		go.scenerio3(getCityCode(origin), getCityCode(destination), dt);
	}
	else if (costTimecheck == 1 && Company_check == 1) {
		go.scenerio1(getCityCode(origin), getCityCode(destination), dt, AirlineName(airline));
	}
	else if (costTimecheck == 1) {
		go.scenerio2(getCityCode(origin), getCityCode(destination), dt);
	}
	else if (costTimecheck == 2 && Company_check == 1) {
		go.scenerio5(getCityCode(origin), getCityCode(destination), dt, AirlineName(airline));
	}
	else if (costTimecheck == 2) {
		go.scenerio4(getCityCode(origin), getCityCode(destination), dt);
	}
	else if (Company_check == 1) {
		go.scenerio5(getCityCode(origin), getCityCode(destination), dt, AirlineName(airline));
	}
	else {
		go.DisplayDirectFlight(getCityCode(origin), getCityCode(destination), dt, AirlineName(airline));
		go.scenerio3(getCityCode(origin), getCityCode(destination), dt);
	}
}