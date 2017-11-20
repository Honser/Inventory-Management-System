#pragma once

#include <string>
#include "capacity.h"
#include "Item.h"

using namespace std;



class CInventory
{
public:
	CInventory(void);
	~CInventory(void);

private:
	CItem itemInfo[maxListSize];
	int numOfItem;
public:
	bool FindItem();
	bool ItemList();
	bool Add();
	void MainMenu();
	bool Stock(int index);
	bool Release(int index);
	void Setting(int index);
	void Info(int index);
	void ChangePrice(int index);
	void ChangeCapacity(int index);
	void Initiation(string name, int price, int Qty, int capacity);
};

