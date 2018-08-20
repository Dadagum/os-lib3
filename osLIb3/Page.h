#pragma once


class Page {
public:
	int number;
	bool R;
	Page(int number) {
		this->number = number;
		R = false;
	}
};