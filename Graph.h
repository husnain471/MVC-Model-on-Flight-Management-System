#pragma once
#include "NodeAndFlight.h"
#include "BST.h"
#include <string>
#include <iostream>
#include <fstream>
#include "Utility.h"
#define inf 99999999
using namespace std;

class point {
public:
	int weight;
	int parent;
	point() { weight = inf; parent = inf; }
};



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

class graph {
	Node array[11];
public:
	graph();
	void AddVertex(Flight flt, int src, int des);
	void Display();
	void ShowReleventFlights(int d);
	//	void printAllPathsUtil(int u, int d, bool visited[],int path[], int &pIndex,Date dt, 
		//							Vector <Flight> & flt , int &max_weight , Vector < Vector<Flight> > & dif  );
		//void printAllPaths(int s, int d, string airline,Date dt);


	void DisplayDirectFlight(int src, int des, Date dt, string al); // Show direct flight of all airlines

	void scenerio1(int src, int des, Date dt, string al);
	void scenerio1rec(int u, int d, bool visited[], int path[], int& pIndex, Date dt,
		Vector <Flight>& flt, BinarySearchTree& dif, string al, int date_off);  // sce1 includes date and airline prefence

	void scenerio2(int src, int des, Date dt);
	void scenerio2rec(int u, int d, bool visited[], int path[], int& pIndex, Date dt,
		Vector <Flight>& flt, BinarySearchTree& dif, int date_off); // sce2 only includes date

	void scenerio3(int src, int des, Date dt);
	void scenerio3rec(int u, int d, bool visited[], int path[], int& pIndex, Date dt,
		Vector <Flight>& flt, BinarySearchTree& dif, int date_off); // sce3 only includes date and tells connected flight

	void scenerio4(int src, int des, Date dt);
	void scenerio4rec(int u, int d, bool visited[], int path[], int& pIndex, Date dt,
		Vector <Flight>& flt, BinarySearchTree& dif, int date_off); // sce4 only includes date and sort flights by traveling time

	void scenerio5(int src, int des, Date dt, string al);
	void scenerio5rec(int u, int d, bool visited[], int path[], int& pIndex, Date dt,
		Vector <Flight>& flt, BinarySearchTree& dif, string al, int date_off);  // sce5 includes date and airline prefence and sorts flight by travelling time

};



graph::graph() {

	// Initializing all cities

	fstream file("HotelCharges_perday.txt");
	string s1, s2;
	int i = 0;
	do {
		getline(file, s1, ' ');
		getline(file, s2);
		array[i].city_name = s1;
		array[i].cost_of_stay = stod(s2);
		i++;
	} while (!file.eof());

	file.close();

	////// Initializing all flights


	Flight flt;
	ifstream ifile("Flights.txt");
	string source;
	string desti;
	string day;
	string month;
	string year;
	string hours;
	string minutes;
	string temp;
	do
	{
		getline(ifile, source, ' ');
		getline(ifile, desti, ' ');
		getline(ifile, day, '/');
		getline(ifile, month, '/');
		getline(ifile, year, ' ');
		getline(ifile, hours, ':');
		getline(ifile, minutes, ' ');
		Time t1(stoi(hours), stoi(minutes));
		flt.time_of_take_off.setTime(stoi(hours), stoi(minutes));
		getline(ifile, hours, ':');
		getline(ifile, minutes, ' ');
		flt.time_of_landing.setTime(stoi(hours), stoi(minutes));
		Time t2(stoi(hours), stoi(minutes));
		getline(ifile, temp, ' ');
		flt.price = stoi(temp);
		getline(ifile, temp, '\n');
		flt.AirLine_name = temp;
		flt.destination_city = desti;
		flt.date.setDay(stoi(day));
		flt.date.setMonth(stoi(month));
		flt.date.setYear(stoi(year));
		if (t2 - t1 < 0) {
			Time temp = t2;
			flt.flying_hours = (temp.addInHours(24)) - t1;
		}
		else
			flt.flying_hours = t2 - t1;
		AddVertex(flt, getCityCode(source), getCityCode(desti));
	} while (!ifile.eof());
	ifile.close();
	return;
}



void graph::AddVertex(Flight flt, int src, int des) {
	flt.destination_adress = &array[des];
	flt.destinaation_code = des;
	array[src].flights.push_back(flt);
}


void graph::Display() {
	for (int i = 0; i < 11; i++) {
		cout << "Flights from " << array[i].city_name << " :\n\t";
		for (int j = 0; j < array[i].flights.Size(); j++)
			cout << array[i].flights.getArray()[j].destination_city << "\t" << array[i].flights.getArray()[j].date.toString() << "\n\t";
		cout << endl;
	}
}



void graph::ShowReleventFlights(int d) { // d is the code of city from where all flights will be shown
	cout << "Flights from " << array[d].city_name << " :\n\t";
	for (int j = 0; j < array[d].flights.Size(); j++)
		cout << array[d].flights.getArray()[j].destination_city << " " << array[d].flights.getArray()[j].date.toString() << " "
		<< array[d].flights.getArray()[j].AirLine_name << " " << array[d].flights.getArray()[j].flying_hours << "\n\t";
	cout << endl;
}




void graph::DisplayDirectFlight(int src, int des, Date dt, string al = "") {
	cout << "All direct flights from " << getCityName(src) << " to " << getCityName(des) << " are: " << endl << endl;
	int k = 0;
	for (int i = 0; i < array[src].flights.Size(); i++) {
		if (array[src].flights.getArray()[i].destinaation_code == des && abs(dt.getDifference(array[src].flights.getArray()[i].date, dt)) <= 1)
			if (al == "" || al == array[src].flights.getArray()[i].AirLine_name)
			{
				k++;
				cout << "\t\t\t\t\tName of Air line: " << array[src].flights.getArray()[i].AirLine_name << "\n";
				cout << "\t\t\t\t\tDate: " << array[src].flights.getArray()[i].date.toString() << "\n";
				cout << "\t\t\t\t\tDestination: " << array[src].flights.getArray()[i].destination_city << "\n";
				cout << "\t\t\t\t\tTime of takeoff: " << array[src].flights.getArray()[i].time_of_take_off.toString() << "\n";
				cout << "\t\t\t\t\tlanding time: " << array[src].flights.getArray()[i].time_of_landing.toString() << "\n";
				cout << "\t\t\t\t\tCost: " << array[src].flights.getArray()[i].price << "\n";
				cout << endl;

			}
	}

	if (k == 0) {
		cout << "OOPS no flight found. Try searching for connected flights or change Airline prefernece\n";

	}

}





void graph::scenerio1(int src, int des, Date dt, string al) {

	// Initilizing parmeters to be passed in reccursive function
	bool* visited = new bool[11];
	int* path = new int[11];
	int pIndex = 0;
	Vector <Flight> f;
	BinarySearchTree vvc;
	for (int i = 0; i < 11; i++)
		visited[i] = false;




	scenerio1rec(src, des, visited, path, pIndex, dt, f, vvc, al, 0);

	cout << "Possible direct or connected flights of " << al << " from " << array[src].city_name << " to " << getCityName(des) << " sorted by cost (low to high) are:-\n";

	if (vvc.isEmpty()) {
		cout << "\nOOPS. No fight found to your destination on your desired date.\n";
		cout << "Do you wants to search for nearest dates? If yes enter y else enter n: ";
		string s;
		cin >> s;

		if (s == "y") {
			system("cls");
			f.clear();
			scenerio1rec(src, des, visited, path, pIndex, dt, f, vvc, al, 1);
			cout << "possible direct or connected flights of " << al << " from " << array[src].city_name << " to " << getCityName(des) << " sorted by cost (low to high) are:-\n";
			if (vvc.isEmpty())
				cout << "still no flight found";
			else
				vvc.inOrderTraversal();
		}
	}
	else
		vvc.inOrderTraversal();

}





void graph::scenerio1rec(int u, int d, bool visited[], int path[], int& pIndex, Date dt,
	Vector <Flight> & flt, BinarySearchTree & dif, string al, int date_off)
{

	visited[u] = true;
	path[++pIndex] = u;

	if (u == d) {

		bool b = true;
		int max_weight = 0;
		int max_weight1 = 0;


		for (int i = 0; i < flt.Size(); i++) {
			if (flt[i].date.getDifference(flt[i].date, flt[i + 1].date) < 0 || (flt[i].date == flt[i + 1].date && flt[i + 1].time_of_take_off - flt[i].time_of_landing < 0)) {
				b = false;
				max_weight = 0;
				max_weight1 = 0;

			}
			else {


				max_weight += flt[i].price;
				max_weight1 += flt[i].flying_hours;
				double t = 0;
				if (i + 1 < flt.Size()) {
					int t = 0;
					if (flt[i + 1].date == flt[i].date) {
						t = flt[i + 1].time_of_take_off - flt[i].time_of_landing;
						max_weight1 += t;
						if (t > 12) {
							max_weight += array[flt[i].destinaation_code].cost_of_stay;
						}

					}
					else {
						Time temp = flt[i + 1].time_of_take_off;
						t = (temp.addInHours(24)) - flt[i].time_of_landing;
						max_weight1 += t;

						if (t > 12) {
							max_weight += array[flt[i].destinaation_code].cost_of_stay;
						}
					}

				}

			}
		}

		if (b == true) {
			dif.Insert(flt, max_weight, max_weight1);
			max_weight = 0;
		}

	}
	else {

		for (int i = 0; i < array[u].flights.Size(); i++) {
			if (array[u].flights.getArray()[i].AirLine_name == al)
				if (abs(dt.getDifference(dt, array[u].flights.getArray()[i].date)) <= date_off)
					if (!visited[array[u].flights.getArray()[i].destinaation_code]) {
						flt.push_back(array[u].flights.getArray()[i]);
						scenerio1rec(array[u].flights.getArray()[i].destinaation_code, d, visited, path,
							pIndex, dt, flt, dif, al, date_off);
					}
		}
	}

	pIndex--;
	flt.remove();
	visited[u] = false;
}






void graph::scenerio2(int src, int des, Date dt) {

	// Initilizing parmeters to be passed in reccursive function
	bool* visited = new bool[11];
	int* path = new int[11];
	int pIndex = 0;
	Vector <Flight> f;
	BinarySearchTree vvc;
	for (int i = 0; i < 11; i++)
		visited[i] = false;




	scenerio2rec(src, des, visited, path, pIndex, dt, f, vvc, 0);

	cout << "Possible direct or connected flights from " << array[src].city_name << " to " << getCityName(des) << " sorted by cost (low to high) are:-\n";

	if (vvc.isEmpty()) {
		cout << "\nOOPS. No fight found to your destination on your desired date.\n";
		cout << "Do you wants to search for nearest dates? If yes enter y else enter n: ";
		string s;
		cin >> s;

		if (s == "y") {
			system("cls");
			f.clear();
			scenerio2rec(src, des, visited, path, pIndex, dt, f, vvc, 1);
			cout << "possible direct or connected flights from " << array[src].city_name << " to " << getCityName(des) << " sorted by cost (low to high) are:-\n";
			if (vvc.isEmpty())
				cout << "still no flight found";
			else
				vvc.inOrderTraversal();
		}
	}
	else
		vvc.inOrderTraversal();

}





void graph::scenerio2rec(int u, int d, bool visited[], int path[], int& pIndex, Date dt,
	Vector <Flight> & flt, BinarySearchTree & dif, int date_off)
{

	visited[u] = true;
	path[++pIndex] = u;

	if (u == d) {

		bool b = true;
		int max_weight = 0;
		int max_weight1 = 0;

		if (flt.Size() == 1) {
			max_weight1 = flt[0].flying_hours;
			max_weight = flt[0].price;
		}
		else {
			for (int i = 0; i < flt.Size(); i++) {
				if (flt[i].date.getDifference(flt[i].date, flt[i + 1].date) < 0 || (flt[i].date == flt[i + 1].date && flt[i + 1].time_of_take_off - flt[i].time_of_landing < 0)) {
					b = false;
					max_weight = 0;
					max_weight1 = 0;
				}
				else {


					max_weight += flt[i].price;
					max_weight1 += flt[i].flying_hours;
					double t = 0;
					if (i + 1 < flt.Size()) {
						int t = 0;
						if (flt[i + 1].date == flt[i].date) {
							t = flt[i + 1].time_of_take_off - flt[i].time_of_landing;
							max_weight1 += t;
							if (t > 12) {
								max_weight += array[flt[i].destinaation_code].cost_of_stay;
							}

						}
						else {
							Time temp = flt[i + 1].time_of_take_off;
							t = (temp.addInHours(24)) - flt[i].time_of_landing;
							max_weight1 += t;

							if (t > 12) {
								max_weight += array[flt[i].destinaation_code].cost_of_stay;
							}
						}

					}



				}
			}
		}
		if (b == true) {
			dif.Insert(flt, max_weight, max_weight1);
			max_weight = 0;
		}

	}
	else {
		for (int i = 0; i < array[u].flights.Size(); i++) {
			if (abs(dt.getDifference(dt, array[u].flights.getArray()[i].date)) <= date_off)
				if (!visited[array[u].flights.getArray()[i].destinaation_code]) {
					flt.push_back(array[u].flights.getArray()[i]);
					scenerio2rec(array[u].flights.getArray()[i].destinaation_code, d, visited, path,
						pIndex, dt, flt, dif, date_off);
				}
		}
	}

	pIndex--;
	flt.remove();
	visited[u] = false;
}







void graph::scenerio4(int src, int des, Date dt) {

	// Initilizing parmeters to be passed in reccursive function
	bool* visited = new bool[11];
	int* path = new int[11];
	int pIndex = 0;
	Vector <Flight> f;
	BinarySearchTree vvc;
	for (int i = 0; i < 11; i++)
		visited[i] = false;




	scenerio4rec(src, des, visited, path, pIndex, dt, f, vvc, 0);

	cout << "Possible direct or connected flights from " << array[src].city_name << " to " << getCityName(des) << " sorted by totall flying time (low to high) are:-\n";

	if (vvc.isEmpty()) {
		cout << "\nOOPS. No flight found to your destination on your desired date.\n";
		cout << "Do you wants to search for nearest dates? If yes enter y else enter n: ";
		string s;
		cin >> s;

		if (s == "y") {
			system("cls");
			f.clear();
			scenerio4rec(src, des, visited, path, pIndex, dt, f, vvc, 1);
			cout << "possible direct or connected flights of emirates from " << array[src].city_name << " to " << getCityName(des) << " sorted by totall flying time (low to high) are:-\n";
			if (vvc.isEmpty())
				cout << "still no flight found";
			else
				vvc.inOrderTraversal1();
		}
	}
	else
		vvc.inOrderTraversal1();

}





void graph::scenerio4rec(int u, int d, bool visited[], int path[], int& pIndex, Date dt,
	Vector <Flight> & flt, BinarySearchTree & dif, int date_off)
{

	visited[u] = true;
	path[++pIndex] = u;

	if (u == d) {

		bool b = true;
		int max_weight = 0;
		int max_weight1 = 0;

		for (int i = 0; i < flt.Size(); i++) {
			if (flt[i].date.getDifference(flt[i].date, flt[i + 1].date) < 0 || (flt[i].date == flt[i + 1].date && flt[i + 1].time_of_take_off - flt[i].time_of_landing < 0)) {
				b = false;
				max_weight = 0;
				max_weight1 = 0;

			}
			else {
				max_weight1 += flt[i].price;
				max_weight += flt[i].flying_hours;
				double t = 0;
				if (i + 1 < flt.Size()) {
					int t = 0;
					if (flt[i + 1].date == flt[i].date) {
						t = flt[i + 1].time_of_take_off - flt[i].time_of_landing;
						max_weight += t;
						if (t > 12) {
							max_weight1 += array[flt[i].destinaation_code].cost_of_stay;
						}

					}
					else {
						Time temp = flt[i + 1].time_of_take_off;
						t = (temp.addInHours(24)) - flt[i].time_of_landing;
						max_weight += t;

						if (t > 12) {
							max_weight1 += array[flt[i].destinaation_code].cost_of_stay;
						}
					}

				}

			}
		}

		if (b == true) {
			dif.Insert(flt, max_weight, max_weight1);
			max_weight = 0;
		}

	}
	else {

		for (int i = 0; i < array[u].flights.Size(); i++) {
			if (abs(dt.getDifference(dt, array[u].flights.getArray()[i].date)) <= date_off)
				if (!visited[array[u].flights.getArray()[i].destinaation_code]) {
					flt.push_back(array[u].flights.getArray()[i]);
					scenerio4rec(array[u].flights.getArray()[i].destinaation_code, d, visited, path,
						pIndex, dt, flt, dif, date_off);
				}
		}
	}

	pIndex--;
	flt.remove();
	visited[u] = false;
}






void graph::scenerio5(int src, int des, Date dt, string al) {

	// Initilizing parmeters to be passed in reccursive function
	bool* visited = new bool[11];
	int* path = new int[11];
	int pIndex = 0;
	Vector <Flight> f;
	BinarySearchTree vvc;
	for (int i = 0; i < 11; i++)
		visited[i] = false;




	scenerio5rec(src, des, visited, path, pIndex, dt, f, vvc, al, 0);

	cout << "Possible direct or connected flights of " << al << " from " << array[src].city_name << " to " << getCityName(des) << " sorted by flying Time (low to high) are:-\n";

	if (vvc.isEmpty()) {
		cout << "\nOOPS. No fight found to your destination on your desired date.\n";
		cout << "Do you wants to search for nearest dates? If yes enter y else enter n: ";
		string s;
		cin >> s;

		if (s == "y") {
			system("cls");
			f.clear();
			scenerio5rec(src, des, visited, path, pIndex, dt, f, vvc, al, 1);
			cout << "possible direct or connected flights of emirates from " << array[src].city_name << " to " << getCityName(des) << " sorted by cost (low to high) are:-\n";
			if (vvc.isEmpty())
				cout << "still no flight found";
			else
				vvc.inOrderTraversal1();
		}
	}
	else
		vvc.inOrderTraversal1();

}





void graph::scenerio5rec(int u, int d, bool visited[], int path[], int& pIndex, Date dt,
	Vector <Flight> & flt, BinarySearchTree & dif, string al, int date_off)
{

	visited[u] = true;
	path[++pIndex] = u;

	if (u == d) {

		bool b = true;
		int max_weight = 0;
		int max_weight1 = 0;

		for (int i = 0; i < flt.Size(); i++) {
			if (flt[i].date.getDifference(flt[i].date, flt[i + 1].date) < 0 || (flt[i].date == flt[i + 1].date && flt[i + 1].time_of_take_off - flt[i].time_of_landing < 0)) {
				b = false;
				max_weight = 0;
				max_weight1 = 0;
			}
			else {
				max_weight1 += flt[i].price;
				max_weight += flt[i].flying_hours;
				double t = 0;
				if (i + 1 < flt.Size()) {
					int t = 0;
					if (flt[i + 1].date == flt[i].date) {
						t = flt[i + 1].time_of_take_off - flt[i].time_of_landing;
						max_weight += t;
						if (t > 12) {
							max_weight1 += array[flt[i].destinaation_code].cost_of_stay;
						}

					}
					else {
						Time temp = flt[i + 1].time_of_take_off;
						t = (temp.addInHours(24)) - flt[i].time_of_landing;
						max_weight += t;

						if (t > 12) {
							max_weight1 += array[flt[i].destinaation_code].cost_of_stay;
						}
					}

				}
			}
		}

		if (b == true) {
			dif.Insert(flt, max_weight, max_weight1);
			max_weight = 0;
		}

	}
	else {

		for (int i = 0; i < array[u].flights.Size(); i++) {
			if (array[u].flights.getArray()[i].AirLine_name == al)
				if (abs(dt.getDifference(dt, array[u].flights.getArray()[i].date)) <= date_off)
					if (!visited[array[u].flights.getArray()[i].destinaation_code]) {
						flt.push_back(array[u].flights.getArray()[i]);
						scenerio5rec(array[u].flights.getArray()[i].destinaation_code, d, visited, path,
							pIndex, dt, flt, dif, al, date_off);
					}
		}
	}

	pIndex--;
	flt.remove();
	visited[u] = false;
}









void graph::scenerio3(int src, int des, Date dt) {

	// Initilizing parmeters to be passed in reccursive function
	bool* visited = new bool[11];
	int* path = new int[11];
	int pIndex = 0;
	Vector <Flight> f;
	BinarySearchTree vvc;
	for (int i = 0; i < 11; i++)
		visited[i] = false;




	scenerio3rec(src, des, visited, path, pIndex, dt, f, vvc, 0);

	cout << "Possible connected flights from " << array[src].city_name << " to " << getCityName(des) << " sorted by cost (low to high) are:-\n";

	if (vvc.isEmpty()) {
		cout << "\nOOPS. No fight found to your destination on your desired date.\n";
		cout << "Do you wants to search for nearest dates? If yes enter y else enter n: ";
		string s;
		cin >> s;

		if (s == "y") {
			system("cls");
			f.clear();
			scenerio3rec(src, des, visited, path, pIndex, dt, f, vvc, 1);
			cout << "possible  connected flights from " << array[src].city_name << " to " << getCityName(des) << " sorted by cost (low to high) are:-\n";
			if (vvc.isEmpty())
				cout << "still no flight found";
			else
				vvc.inOrderTraversal();
		}
	}
	else
		vvc.inOrderTraversal();

}





void graph::scenerio3rec(int u, int d, bool visited[], int path[], int& pIndex, Date dt,
	Vector <Flight> & flt, BinarySearchTree & dif, int date_off)
{

	visited[u] = true;
	path[++pIndex] = u;

	if (u == d) {

		bool b = true;
		int max_weight = 0;
		int max_weight1 = 0;

		for (int i = 0; i < flt.Size(); i++) {
			if (flt[i].date.getDifference(flt[i].date, flt[i + 1].date) < 0 || (flt[i].date == flt[i + 1].date && flt[i + 1].time_of_take_off - flt[i].time_of_landing < 0)) {
				b = false;
				max_weight = 0;
				max_weight1 = 0;
			}
			else {
				max_weight += flt[i].price;
				max_weight1 += flt[i].flying_hours;
				double t = 0;
				if (i + 1 < flt.Size()) {
					int t = 0;
					if (flt[i + 1].date == flt[i].date) {
						t = flt[i + 1].time_of_take_off - flt[i].time_of_landing;
						max_weight1 += t;
						if (t > 12) {
							max_weight += array[flt[i].destinaation_code].cost_of_stay;
						}

					}
					else {
						Time temp = flt[i + 1].time_of_take_off;
						t = (temp.addInHours(24)) - flt[i].time_of_landing;
						max_weight1 += t;

						if (t > 12) {
							max_weight += array[flt[i].destinaation_code].cost_of_stay;
						}
					}

				}

			}
		}

		if (b == true) {
			if (flt.Size() > 1)
				dif.Insert(flt, max_weight, max_weight1);
			max_weight = 0;
		}

	}
	else {
		for (int i = 0; i < array[u].flights.Size(); i++) {
			if (abs(dt.getDifference(dt, array[u].flights.getArray()[i].date)) <= date_off)
				if (!visited[array[u].flights.getArray()[i].destinaation_code]) {
					flt.push_back(array[u].flights.getArray()[i]);
					scenerio3rec(array[u].flights.getArray()[i].destinaation_code, d, visited, path,
						pIndex, dt, flt, dif, date_off);
				}
		}
	}

	pIndex--;
	flt.remove();
	visited[u] = false;
}


