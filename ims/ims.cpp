#include <iostream>
#include <string>
#include "Inventory.h"

using namespace std;



int main()
{
	
	CInventory ourInven;

	ourInven.Initiation("°î±ªÀÌ", 1000, 10, 100);
	ourInven.Initiation("´ÏÆÛ", 3000, 30, 100);
	ourInven.Initiation("µå¶óÀÌ¹ö", 5000, 50, 100);
	ourInven.Initiation("·Ñ·¯", 7000, 70, 100);
	ourInven.Initiation("¸ÁÄ¡", 9000, 90, 100);

	ourInven.MainMenu();
	
	


	return 0;
}
