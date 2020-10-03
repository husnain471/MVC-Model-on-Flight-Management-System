#pragma once
#include <iostream>
using namespace std;


template <class T>

class Vector {
	T* array;
	int size;
	int capacity;

public:

	Vector() :capacity(5) {
		array = new T[capacity];
		size = 0;
	}

	void push_back(T data) {
		if (size + 1 < capacity)
			array[size] = data;
		else {
			increaseCapacity();
			array[size] = data;
		}
		size++;
	}

	void increaseCapacity() {
		capacity *= 2;
		T* temp = new T[capacity];
		for (int i = 0; i <= size; i++) {
			temp[i] = array[i];
		}
		T* hold = array;
		array = temp;
		delete[] hold;

	}


	Vector <T> operator = (Vector <T> t) {
		this->capacity = t.capacity;
		this->size = t.size;

		delete[] array;

		array = new T[capacity];
		for (int i = 0; i <= size; i++)
			array[i] = t.array[i];
		return *this;
	}




	T operator [] (int num) {
		return array[num];
	}

	T* getArray() { return array; }


	bool find(T value) {
		for (int i = 0; i < size; i++)
			if (array[i] == value)
				return 1;
		return 0;
	}


	T pop_back() {
		T temp = array[size];
		size--;
		return temp;
	}

	void remove() {
		size--;
		return;
	}

	int Size() { return size; }

	void clear() {
		delete[] array;
		size = 0;
		capacity = 5;
		array = new T[5];

	}


};


