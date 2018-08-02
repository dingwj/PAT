/*
	Galleon -- Sickle -- Knut
    big  --------------> small
	
    1 Galleon == 17 Sickle
    1 Sickle == 29 Knut
    
    so, 
    	1 Galleon == 17 * 29 Knut
    	1 Sickle  == 29 Knut
*/

#include<stdio.h>
const int Galleon = 17 * 29;
const int Sickle = 29;
int main()
{
	int a1, b1, c1;
	int a2, b2, c2;
	
	scanf("%d.%d.%d %d.%d.%d", &a1, &b1, &c1, &a2, &b2, &c2);
	int price = a1*Galleon + b1*Sickle + c1;
	int money = a2*Galleon + b2*Sickle + c2;
	int charge = money - price;
	
	if(charge < 0){
		printf("-");
		charge = -charge;
	}
	
	printf("%d.%d.%d\n", charge/Galleon, charge%Galleon/Sickle, charge%Sickle);
	//                        Galleon ------- Sickle -------------- Knut
	return 0;
}
