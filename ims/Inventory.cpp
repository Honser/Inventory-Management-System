#include "Inventory.h"
#include <iostream>
#include <assert.h>

using namespace std;

CInventory::CInventory(void)
	:numOfItem(-1)
{
}


CInventory::~CInventory(void)
{
}



bool CInventory::FindItem()
{
	string name;

	if(numOfItem < 0)
	{
		cout << "등록된 물품이 없습니다.\n";

		return false;
	} else {
	cout  << "물품명을 입력하세요\n:";
	cin >> name;
	cout << endl << endl;

	//for(int i = 0; i < maxListSize; i++)
	for(int i = 0; i <= numOfItem; i++)
	{
		if(itemInfo[i].name==name)
		{
			cout << endl << endl;
			Info(i);
		}
	}
	
	return true;
	} 
}


bool CInventory::ItemList()
{
	if(numOfItem < 0)
		return false;
	else{
		for(int i = 0; i <= numOfItem; i++)
		{
			cout << "|----------------------------------------------------------\n"
				 << "| " << i << ": " << itemInfo[i].name << "   수량: " << itemInfo[i].Qty << "/" << itemInfo[i].capacity
				 << "    재고상태: " << itemInfo[i].status << endl
				 << "|----------------------------------------------------------\n";
		}
		
		int menu;
		cout << "초기메뉴로 돌아가려면 1, 프로그램을 종료하려면 0을 입력해주세요.\n:";
		cin >> menu;
		
		if (menu)
		{
			MainMenu();
		} else {
			exit(0);
		}
		return true;
	}
}

bool CInventory::Add()
{
	string name;
	int price, Qty, capacity;
	cout << "추가하고자 하는 물품의 정보를 입력하세요\n";
	cout << "물품명: ";
	cin >> name;
	cout << "수량: ";
	cin >> Qty;
	cout << "가격: ";
	cin >> price;
	cout << "최대 수용량: ";
	cin >> capacity;
	
	while (capacity < Qty) {
		cout << "입력하신 최대 수용량이 수량보다 작습니다. 다시 입력하세요." << endl;
		cin >> capacity; 
		}
	

	cout << endl << endl;

	itemInfo[numOfItem].name = name;
	itemInfo[numOfItem].Qty = Qty;
	itemInfo[numOfItem].price = price;
	itemInfo[numOfItem].capacity = capacity;
	
	if(Qty / capacity >= sufficientCondition)
	{
		itemInfo[numOfItem].status = "충분";
	} else if(lackCondition <= Qty / capacity && Qty / capacity < sufficientCondition) {
		itemInfo[numOfItem].status = "적정";
	} else if(Qty / capacity < lackCondition) {
		itemInfo[numOfItem].status = "부족";
	}

	int menu;
	cout << "1.입력한 물품 정보를 확인\n"
		    "2.다른 물품 추가\n"
			"3.초기메뉴\n"
			"4.프로그램 종료\n";
	cin >> menu;
	cout << endl << endl;

	numOfItem++;

	switch(menu)
	{
		case 1:
			Info(numOfItem - 1);
			break;
		
		case 2:
			assert(Add());
			break;
		
		case 3:
			MainMenu();
			break;
		case 4:
			exit(0);
	}
	
	
	return true;
}


void CInventory::MainMenu()
{
	int menu;

	cout << "|----------------------------------------------------------|\n"
		 << "|---------------------재고관리 시스템----------------------|\n"
		 << "|----------------------------------------------------------|\n"
		 << "|     1) 물품검색                       2) 재고현황        |\n"
		 << "|                                                          |\n"
		 << "|     3) 물품추가                                          |\n"
		 << "|----------------------------------------------------------|\n"
		 << "|----------------------------------------------------------|\n"
		 << "|----------------------------------------------------------|\n";
	
	cout << "원하는 메뉴의 번호를 입력하세요\n:";
	cin >> menu;
	cout << endl << endl;

		switch(menu)
		{
			case 1:
				assert(FindItem());
				
				break;

			case 2:
				assert(ItemList());
				break;

			case 3:
				assert(Add());				
				break;

			default:
			cout << "잘못 입력하셨습니다.\n";
			MainMenu();
		}
}



		
		bool CInventory::Stock(int index)
	{
	int toStock;
	cout << "입고 수량을 입력하세요(수용가능 수량: " << itemInfo[index].capacity - itemInfo[index].Qty << ")\n";
	cin >> toStock;
	cout << endl << endl;

	if(toStock > itemInfo[index].capacity - itemInfo[index].Qty)
	{
		cout << "공간이 초과되었습니다.\n 다시 입력해주세요.\n:";
		cin >> toStock;
	} else {
	
		itemInfo[index].Qty += toStock;
	}
	cout << endl << endl;

	int menu;
	cout << "1.입력한 물품 정보를 확인\n"
		    "2.초기메뉴로 이동\n"
			"3.프로그램 종료\n";
			
	cin >> menu;
	cout << endl << endl;

	switch(menu)
	{
		case 1:
			Info(index);
			break;
		
		case 2:
			MainMenu();
			break;
		
		case 3:
			exit(0);
	}
	return true;
}


bool CInventory::Release(int index)
{

	int toRelease;
	cout << "출고 수량을 입력하세요(출고가능 수량: " << itemInfo[index].Qty << ")\n";
	cin >> toRelease;

	if(toRelease > itemInfo[index].Qty)
	{
		cout << "출고하고자 하는 수량이 재고를 초과하였습니다.\n 다시 입력해주세요.\n:";
		cin >> toRelease;
	} else {
	
		itemInfo[index].Qty -= toRelease;
	}
		
	int menu;
	cout << "1.입력한 물품 정보를 확인\n"
		    "2.초기메뉴로 이동\n"
			"3.프로그램 종료\n";
			
	cin >> menu;
	cout << endl << endl;

	switch(menu)
	{
		case 1:
			Info(index);
			break;
		
		case 2:
			MainMenu();
			break;
		
		case 3:
			exit(0);
	}

	return true;
}


void CInventory::Setting(int index)
{
	int menu;

	cout << "| 물품명: " << itemInfo[index].name << endl
		 << "|-------------------------------------------------------|\n"
		 << "|                   변경 가능한 옵션                    |\n"     
		 << "|-------------------------------------------------------|\n"
	     << "|     1) 가격                           2) 허용수량     |\n"
		 << "|-------------------------------------------------------|\n"
	     << "|-------------------------------------------------------|\n";
		cout << "원하는 메뉴의 번호를 입력하세요\n:";
	cin >> menu;
	cout << endl << endl;

		switch(menu)
		{
			case 1:
				ChangePrice(index);
				
				break;

			case 2:
				ChangeCapacity(index);

				break;

			default:
			cout << "잘못 입력하셨습니다.\n";
			Setting(index);
		}
	
}


void CInventory::Info(int index)
{
	if((double)itemInfo[index].Qty / itemInfo[index].capacity >= sufficientCondition)
	{
		itemInfo[index].status = "충분";
	} else if(lackCondition <= (double)itemInfo[index].Qty / itemInfo[index].capacity && (double)itemInfo[index].Qty / (double)itemInfo[index].capacity < sufficientCondition) {
		itemInfo[index].status = "적정";
	} else if((double)itemInfo[index].Qty / itemInfo[index].capacity < lackCondition) {
		itemInfo[index].status = "부족";
	}
	cout << endl << endl;

	cout << "| 물품명: " << itemInfo[index].name << "          재고상태: " << itemInfo[index].status << endl
		 << "|   가격: "<< itemInfo[index].price << "           수   량:" << itemInfo[index].Qty << " / " << itemInfo[index].capacity << endl
		 << "|----------------------------------------------------------|\n"
		 << "|     1) 입고                           2) 출고            |\n"
		 << "|                                                          |\n"
		 << "|     3) 설정                           4) 초기메뉴        |\n"
		 << "|----------------------------------------------------------|\n";
	
	int menu;
	cout << "원하시는 메뉴를 고르세요(1-4)\n:";
	cin >> menu;
	cout << endl << endl;

	switch(menu)
		{
			case 1:
				assert(Stock(index));
				break;    

			case 2:
				assert(Release(index));
				break;

			case 3:
				Setting(index);				
				break;

			case 4:
				MainMenu();
	
			default:
			cout << "잘못 입력하셨습니다.\n";
			exit(0);
		}
}



void CInventory::ChangePrice(int index)
{
	int nextPrice;
	cout << "변경하고자 하는 가격을 입력하세요.\n:";
	cin >> nextPrice;

	itemInfo[index].price = nextPrice;
	cout << endl << endl;
	cout << itemInfo[index].name << "의 가격이 " << itemInfo[index].price << "로 변경되었습니다." << endl << endl;
	
	int menu;
	cout << "1.입력한 물품 정보를 확인\n"
		    "2.초기메뉴로 이동\n"
			"3.프로그램 종료\n";
			
	cin >> menu;
	cout << endl << endl;

	switch(menu)
	{
		case 1:
			Info(index);
			break;
		
		case 2:
			MainMenu();
			break;
		
		case 3:
			exit(0);
	}
	
	
}


void CInventory::ChangeCapacity(int index)
{
	int nextCapacity;
	cout << "변경하고자 하는 최대 수용량을 입력하세요.\n:";
	cin >> nextCapacity;
	cout << endl << endl;

	while(itemInfo[index].Qty > nextCapacity)
	{
		cout << "현재 재고보다 낮은 숫자로 설정할 수 없습니다. 다시 입력해주세요\n"
			 << "현재 수량: " << itemInfo[index].Qty << "\n:";
			 cin >> nextCapacity;
	}
	cout << endl << endl;

	itemInfo[index].capacity = nextCapacity;
	cout << itemInfo[index].name << "의 최대 수용량이 " << itemInfo[index].capacity << "로 변경되었습니다." << endl << endl;
	
	int menu;
	cout << "1.입력한 물품 정보를 확인\n"
		    "2.초기메뉴로 이동\n"
			"3.프로그램 종료\n";
			
	cin >> menu;
	cout << endl << endl;

	switch(menu)
	{
		case 1:
			Info(index);
			break;
		
		case 2:
			MainMenu();
			break;
		
		case 3:
			exit(0);
	}
}



void CInventory::Initiation(string name, int price, int Qty, int capacity)
{
	numOfItem++;
	itemInfo[numOfItem].name = name;
	itemInfo[numOfItem].price = price;
	itemInfo[numOfItem].Qty = Qty;
	itemInfo[numOfItem].capacity = capacity;
	
	if((double)itemInfo[numOfItem].Qty / itemInfo[numOfItem].capacity >= sufficientCondition)
	{
		itemInfo[numOfItem].status = "충분";
	} else if(lackCondition <= (double)itemInfo[numOfItem].Qty / itemInfo[numOfItem].capacity && (double)itemInfo[numOfItem].Qty / itemInfo[numOfItem].capacity < sufficientCondition) {
		itemInfo[numOfItem].status = "적정";
	} else if((double)itemInfo[numOfItem].Qty / itemInfo[numOfItem].capacity < lackCondition) {
		itemInfo[numOfItem].status = "부족";
	}
}
