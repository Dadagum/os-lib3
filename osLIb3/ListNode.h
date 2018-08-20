#pragma once
#include<iostream>
#include"Page.h"


class ListNode {
public:
	int page;
	bool R;
	ListNode* ptr;
	ListNode(int page, ListNode* ptr = NULL) {
		this->page = page;
		this->R = false;
		this->ptr = ptr;
	}
};