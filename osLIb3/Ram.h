#pragma once
#include<set>
#include<iostream>
using namespace std;

class Ram {
protected:
	int size;
	set<int> s;
public:
	Ram(int size) {
		this->size = size;
	}

	virtual bool inRam(int page) = 0;
	virtual void update(int page) = 0;
	virtual bool isFull() = 0;
	virtual void insert(int page) = 0;
	virtual void replace(int page) = 0;
	virtual void print() = 0;
	virtual void printMethod() = 0;
};