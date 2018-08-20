#pragma once
#include"Ram.h"
#include"ListNode.h"
#include<iostream>
using namespace std;

class RamClockMethod : public Ram{
private:
	ListNode* head;
	void init() {
		ListNode* temp = head;
		for (int i = 1; i < size; i++) {
			temp->ptr = new ListNode(-1);
			temp = temp->ptr;
		}
		temp->ptr = head;
		temp = NULL;
	}

public:
	RamClockMethod(int size):Ram(size){
		head = new ListNode(-1);
		init();
	}

	virtual bool inRam(int page) {
		return !(s.find(page) == s.end());
	}

	virtual void update(int page) {
		// find page first
		ListNode* temp = head;
		if (temp->page== page) {
			temp->R = true;
			return;
		}
		for (temp = temp->ptr; temp != head; temp = temp->ptr)
			if (temp->page == page) {
				temp->R = true;
				return;
			}
	}

	virtual bool isFull() {
		return size == s.size();
	}

	virtual void insert(int page) {
		s.insert(page);
		head->page = page;
		head = head->ptr;
	}

	virtual void replace(int page) {
		while (head->R) {
			head->R = false;
			head = head->ptr;
		}
		s.insert(page);
		s.erase(head->page);
		head->page = page;
		head = head->ptr;
	}

	virtual void print() {
		cout << "Pages in memory right now : ";
		if (head->page != -1) cout << head->page << " ";
		for (ListNode* temp = head->ptr; temp != head; temp = temp->ptr)
			if (temp->page != -1) cout << temp->page << " ";
		cout << endl;
	}

	virtual void printMethod() {
		cout << "Using Clock method with the memory size of " << size << "K";
	}
};