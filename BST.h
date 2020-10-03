#pragma once
#include <iostream>
#include "Vector.h"
#include "NodeAndFlight.h"
using namespace std;



class BSTNode {
public:
	Vector <Flight> flight;
	int data;
	int data1;
	BSTNode* left, * right;
};


class BinarySearchTree {
	BSTNode* root;

public:

	BinarySearchTree() { root = NULL; }

	void Insert(Vector <Flight> flt, int d, int d1) {

		BSTNode* newData = new BSTNode;
		newData->flight = flt;
		newData->left = NULL;
		newData->right = NULL;
		newData->data = d;
		newData->data1 = d1;

		if (root == NULL)
			root = newData;

		else {


			BSTNode* temp = root;
			BSTNode* y = NULL;

			while (temp != NULL) {
				y = temp;
				if (d < temp->data)
					temp = temp->left;
				else
					temp = temp->right;
			}

			if (y == NULL)
				y = newData;
			else if (d > y->data)
				y->right = newData;
			else if (d < y->data)
				y->left = newData;

			return;
		}

	}


	void inOrder(BSTNode * root, int num) {
		if (root != NULL) {
			inOrder(root->left, num++);
			bool b = false;
			for (int j = 0; j < root->flight.Size(); j++) {
				cout << "\n\t\t\t\t\t";
				cout << "Air Line: " << root->flight.getArray()[j].AirLine_name << "\n\t\t\t\t\t";
				cout << "To: " << root->flight.getArray()[j].destination_city << "\n\t\t\t\t\t";
				cout << "D.date: " << root->flight.getArray()[j].date.toString() << "\n\t\t\t\t\t";
				cout << "D.time: " << root->flight.getArray()[j].time_of_take_off.toString() << "\n\t\t\t\t\t";
				cout << "A.time: " << root->flight.getArray()[j].time_of_landing.toString() << "\n\t\t\t\t\t";
				cout << "Price: " << root->flight.getArray()[j].price;

				if (j != root->flight.Size() - 1)
					cout << "\n\n\t\t\t\t\tConnecting to...  \n\n\t\t\t\t\t";


				if (j + 1 < root->flight.Size()) {
					if (root->flight.getArray()[j + 1].date == root->flight.getArray()[j].date) {
						if (root->flight.getArray()[j + 1].time_of_take_off - root->flight.getArray()[j].time_of_landing > 12)
							b = true;
					}
					else {
						int t = 0;
						Time temp = root->flight.getArray()[j + 1].time_of_take_off;
						t = (temp.addInHours(24)) - root->flight.getArray()[j].time_of_landing;
						if (t > 12)
							b = true;

					}
				}

			}
			if (b == true) {
				cout << "\n\n\t\t\t\t\tAdditional cost of stay in hotel added";
				cout << "\n\t\t\t\t\tTotall cost: " << root->data;
			}
			else
				cout << "\n\n\t\t\t\t\tTotall cost: " << root->data;
			cout << "\n\t\t\t\t\tTotall flying hours: " << root->data1;
			cout << "\n\t\t\t------------------------------------------------------\n\t\t\t\t\t";

			inOrder(root->right, num++);
		}
	}

	void inOrder1(BSTNode * root, int num) {


		if (root != NULL) {
			inOrder1(root->left, num++);
			bool b = false;
			int cost = 0;
			for (int j = 0; j < root->flight.Size(); j++) {

				cout << "\n\t\t\t\t\t";
				cout << "Air Line: " << root->flight.getArray()[j].AirLine_name << "\n\t\t\t\t\t";
				cout << "To: " << root->flight.getArray()[j].destination_city << "\n\t\t\t\t\t";
				cout << "D.date: " << root->flight.getArray()[j].date.toString() << "\n\t\t\t\t\t";
				cout << "D.time: " << root->flight.getArray()[j].time_of_take_off.toString() << "\n\t\t\t\t\t";
				cout << "A.time: " << root->flight.getArray()[j].time_of_landing.toString() << "\n\t\t\t\t\t";
				cout << "Price: " << root->flight.getArray()[j].price;

				if (j != root->flight.Size() - 1)
					cout << "\n\n\t\t\t\t\tConnecting to...  \n\n\t\t\t\t\t";

				if (j + 1 < root->flight.Size()) {

					if (root->flight.getArray()[j + 1].date == root->flight.getArray()[j].date) {
						if (root->flight.getArray()[j + 1].time_of_take_off - root->flight.getArray()[j].time_of_landing > 12)
							b = true;
					}
					else {
						int t = 0;
						Time temp = root->flight.getArray()[j + 1].time_of_take_off;
						t = (temp.addInHours(24)) - root->flight.getArray()[j].time_of_landing;
						if (t > 12)
							b = true;

					}
				}



			}
			if (b == true) {
				cout << "\n\n\t\t\t\t\tAdditional cost of stay in hotel added";
				cout << "\n\t\t\t\t\tTotall cost: " << root->data;
			}
			else
				cout << "\n\t\t\t\t\tTotall cost: " << root->data;
			//cout << "\n\t\t\t\t\tTotall cost: " << root->data1;
			cout << "\n\t\t\t------------------------------------------------------\n\t\t\t\t\t";

			inOrder1(root->right, num++);
		}
	}


	void inOrderTraversal1() {
		inOrder1(root, 1);
	}



	void inOrderTraversal() {
		inOrder(root, 1);
	}




	bool isEmpty() {
		return (root == NULL) ? 1 : 0;
	}

};