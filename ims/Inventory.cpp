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
		cout << "��ϵ� ��ǰ�� �����ϴ�.\n";

		return false;
	} else {
	cout  << "��ǰ���� �Է��ϼ���\n:";
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
				 << "| " << i << ": " << itemInfo[i].name << "   ����: " << itemInfo[i].Qty << "/" << itemInfo[i].capacity
				 << "    ������: " << itemInfo[i].status << endl
				 << "|----------------------------------------------------------\n";
		}
		
		int menu;
		cout << "�ʱ�޴��� ���ư����� 1, ���α׷��� �����Ϸ��� 0�� �Է����ּ���.\n:";
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
	cout << "�߰��ϰ��� �ϴ� ��ǰ�� ������ �Է��ϼ���\n";
	cout << "��ǰ��: ";
	cin >> name;
	cout << "����: ";
	cin >> Qty;
	cout << "����: ";
	cin >> price;
	cout << "�ִ� ���뷮: ";
	cin >> capacity;
	
	while (capacity < Qty) {
		cout << "�Է��Ͻ� �ִ� ���뷮�� �������� �۽��ϴ�. �ٽ� �Է��ϼ���." << endl;
		cin >> capacity; 
		}
	

	cout << endl << endl;

	itemInfo[numOfItem].name = name;
	itemInfo[numOfItem].Qty = Qty;
	itemInfo[numOfItem].price = price;
	itemInfo[numOfItem].capacity = capacity;
	
	if(Qty / capacity >= sufficientCondition)
	{
		itemInfo[numOfItem].status = "���";
	} else if(lackCondition <= Qty / capacity && Qty / capacity < sufficientCondition) {
		itemInfo[numOfItem].status = "����";
	} else if(Qty / capacity < lackCondition) {
		itemInfo[numOfItem].status = "����";
	}

	int menu;
	cout << "1.�Է��� ��ǰ ������ Ȯ��\n"
		    "2.�ٸ� ��ǰ �߰�\n"
			"3.�ʱ�޴�\n"
			"4.���α׷� ����\n";
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
		 << "|---------------------������ �ý���----------------------|\n"
		 << "|----------------------------------------------------------|\n"
		 << "|     1) ��ǰ�˻�                       2) �����Ȳ        |\n"
		 << "|                                                          |\n"
		 << "|     3) ��ǰ�߰�                                          |\n"
		 << "|----------------------------------------------------------|\n"
		 << "|----------------------------------------------------------|\n"
		 << "|----------------------------------------------------------|\n";
	
	cout << "���ϴ� �޴��� ��ȣ�� �Է��ϼ���\n:";
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
			cout << "�߸� �Է��ϼ̽��ϴ�.\n";
			MainMenu();
		}
}



		
		bool CInventory::Stock(int index)
	{
	int toStock;
	cout << "�԰� ������ �Է��ϼ���(���밡�� ����: " << itemInfo[index].capacity - itemInfo[index].Qty << ")\n";
	cin >> toStock;
	cout << endl << endl;

	if(toStock > itemInfo[index].capacity - itemInfo[index].Qty)
	{
		cout << "������ �ʰ��Ǿ����ϴ�.\n �ٽ� �Է����ּ���.\n:";
		cin >> toStock;
	} else {
	
		itemInfo[index].Qty += toStock;
	}
	cout << endl << endl;

	int menu;
	cout << "1.�Է��� ��ǰ ������ Ȯ��\n"
		    "2.�ʱ�޴��� �̵�\n"
			"3.���α׷� ����\n";
			
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
	cout << "��� ������ �Է��ϼ���(����� ����: " << itemInfo[index].Qty << ")\n";
	cin >> toRelease;

	if(toRelease > itemInfo[index].Qty)
	{
		cout << "����ϰ��� �ϴ� ������ ��� �ʰ��Ͽ����ϴ�.\n �ٽ� �Է����ּ���.\n:";
		cin >> toRelease;
	} else {
	
		itemInfo[index].Qty -= toRelease;
	}
		
	int menu;
	cout << "1.�Է��� ��ǰ ������ Ȯ��\n"
		    "2.�ʱ�޴��� �̵�\n"
			"3.���α׷� ����\n";
			
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

	cout << "| ��ǰ��: " << itemInfo[index].name << endl
		 << "|-------------------------------------------------------|\n"
		 << "|                   ���� ������ �ɼ�                    |\n"     
		 << "|-------------------------------------------------------|\n"
	     << "|     1) ����                           2) ������     |\n"
		 << "|-------------------------------------------------------|\n"
	     << "|-------------------------------------------------------|\n";
		cout << "���ϴ� �޴��� ��ȣ�� �Է��ϼ���\n:";
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
			cout << "�߸� �Է��ϼ̽��ϴ�.\n";
			Setting(index);
		}
	
}


void CInventory::Info(int index)
{
	if((double)itemInfo[index].Qty / itemInfo[index].capacity >= sufficientCondition)
	{
		itemInfo[index].status = "���";
	} else if(lackCondition <= (double)itemInfo[index].Qty / itemInfo[index].capacity && (double)itemInfo[index].Qty / (double)itemInfo[index].capacity < sufficientCondition) {
		itemInfo[index].status = "����";
	} else if((double)itemInfo[index].Qty / itemInfo[index].capacity < lackCondition) {
		itemInfo[index].status = "����";
	}
	cout << endl << endl;

	cout << "| ��ǰ��: " << itemInfo[index].name << "          ������: " << itemInfo[index].status << endl
		 << "|   ����: "<< itemInfo[index].price << "           ��   ��:" << itemInfo[index].Qty << " / " << itemInfo[index].capacity << endl
		 << "|----------------------------------------------------------|\n"
		 << "|     1) �԰�                           2) ���            |\n"
		 << "|                                                          |\n"
		 << "|     3) ����                           4) �ʱ�޴�        |\n"
		 << "|----------------------------------------------------------|\n";
	
	int menu;
	cout << "���Ͻô� �޴��� ������(1-4)\n:";
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
			cout << "�߸� �Է��ϼ̽��ϴ�.\n";
			exit(0);
		}
}



void CInventory::ChangePrice(int index)
{
	int nextPrice;
	cout << "�����ϰ��� �ϴ� ������ �Է��ϼ���.\n:";
	cin >> nextPrice;

	itemInfo[index].price = nextPrice;
	cout << endl << endl;
	cout << itemInfo[index].name << "�� ������ " << itemInfo[index].price << "�� ����Ǿ����ϴ�." << endl << endl;
	
	int menu;
	cout << "1.�Է��� ��ǰ ������ Ȯ��\n"
		    "2.�ʱ�޴��� �̵�\n"
			"3.���α׷� ����\n";
			
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
	cout << "�����ϰ��� �ϴ� �ִ� ���뷮�� �Է��ϼ���.\n:";
	cin >> nextCapacity;
	cout << endl << endl;

	while(itemInfo[index].Qty > nextCapacity)
	{
		cout << "���� ����� ���� ���ڷ� ������ �� �����ϴ�. �ٽ� �Է����ּ���\n"
			 << "���� ����: " << itemInfo[index].Qty << "\n:";
			 cin >> nextCapacity;
	}
	cout << endl << endl;

	itemInfo[index].capacity = nextCapacity;
	cout << itemInfo[index].name << "�� �ִ� ���뷮�� " << itemInfo[index].capacity << "�� ����Ǿ����ϴ�." << endl << endl;
	
	int menu;
	cout << "1.�Է��� ��ǰ ������ Ȯ��\n"
		    "2.�ʱ�޴��� �̵�\n"
			"3.���α׷� ����\n";
			
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
		itemInfo[numOfItem].status = "���";
	} else if(lackCondition <= (double)itemInfo[numOfItem].Qty / itemInfo[numOfItem].capacity && (double)itemInfo[numOfItem].Qty / itemInfo[numOfItem].capacity < sufficientCondition) {
		itemInfo[numOfItem].status = "����";
	} else if((double)itemInfo[numOfItem].Qty / itemInfo[numOfItem].capacity < lackCondition) {
		itemInfo[numOfItem].status = "����";
	}
}
