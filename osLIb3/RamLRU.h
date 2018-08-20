#pragma once
#include"Ram.h"
#include<iostream>
using namespace std;

class RamLRU : public Ram {
public:
	ListNode* head;
	ListNode* tail;
	RamLRU(int size) :Ram(size) {
		head = new ListNode(-1);
		tail = head;
	}

	virtual bool inRam(int page) {
		return !(s.find(page) == s.end());
	}

	virtual void update(int page) {
		ListNode* temp = head;
		for (; temp->ptr->page!= page; temp = temp->ptr);
		tail->ptr = temp->ptr;
		tail = tail->ptr;
		temp->ptr = tail->ptr;
		tail->ptr = NULL;
		temp = NULL;
	}

	virtual bool isFull() {
		return size == s.size();
	}

	virtual void insert(int page) {
		tail->ptr = new ListNode(page);
		s.insert(page);
		tail = tail->ptr;
	}

	virtual void replace(int page) {
		tail->ptr = head->ptr;
		tail = tail->ptr;
		head->ptr = tail->ptr;
		tail->ptr = NULL;
		s.erase(tail->page);
		s.insert(page);
		tail->page = page;
	}

	virtual void print() {
		cout << "Pages in memory right now : ";
		for (ListNode* temp = head; temp->ptr != NULL; temp = temp->ptr)
			cout << temp->ptr->page << " ";
		cout << endl;
	}

	virtual void printMethod() {
		cout << "Using LRU method with the memory size of " << size << "K";
	}
};

