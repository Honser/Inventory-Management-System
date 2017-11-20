#pragma once
#include <string>

using namespace std;

class CItem
{
public:
	CItem(void);
	~CItem(void);

public:
	string name;
	int price;
	int Qty;
	int capacity;
	string status;
};

