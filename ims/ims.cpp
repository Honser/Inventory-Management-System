#include <iostream>
#include <string>
#include "Inventory.h"

using namespace std;



int main()
{
	
	CInventory ourInven;

	ourInven.Initiation("���", 1000, 10, 100);
	ourInven.Initiation("����", 3000, 30, 100);
	ourInven.Initiation("����̹�", 5000, 50, 100);
	ourInven.Initiation("�ѷ�", 7000, 70, 100);
	ourInven.Initiation("��ġ", 9000, 90, 100);

	ourInven.MainMenu();
	
	


	return 0;
}
