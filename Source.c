#include<stdio.h>
#include<stdlib.h>

void totalseats(void);
void slots(void);
void slection(void);
void menu(void);
void business(void);
void economy(void);
void invoice(void);





char arry[100];

int seat_num;

int main() {




	printf("\n\t\t\t\t\tAir management system.\n\n\t\t\t\t----------------------------------------------------\n");
	totalseats();

	menu();



}

void totalseats(void) {



	for (size_t i = 0; i < 100; i++)
	{
		arry[i] = '0';
	}
}


void slots(void) {
	printf("\n\t\t\t\t\tSlots Available.\n\n\t\t\t\t----------------------------------------------------\n");
	int number[10] = { 0,1,2,3,4,5,6,7,8,9 };
	printf("\t\t\t\t");
	printf("BUSINESS SEATS\n");
	printf("\t\t\t\t");
	for (size_t i = 0; i < 10; i++)
	{
		printf("%d ", number[i]);
	}
	printf("\n");
	int array_num = 0;

	for (int i = 0; i < 10; i++)
	{
		printf("\t\t\t");
		int k = i + 1;
		printf("Row %d", k);
		if (k < 10)
		{
			printf("   ");
		}
		else if (k >= 10) {
			printf("  ");

		}
		for (size_t j = 0; j < 10; j++)
		{
			printf("%c ", arry[array_num]);
			if (array_num==29)
			{
				printf("\n\n\t\t\t\tECONOMY SEATS\n");
			}
			array_num++;
		}
		printf("\n");
	}
	printf("Reserved seats are: ");
	int k = 0;
	for (size_t i = 0; i < 100; i++)
	{
		int j = i;
		if (arry[i] != '0') {
			printf("%d ",j+1);
			k = 1;
		}
		
	}if (k == 0)
	{
		printf("None");
	}



	int men = 0;
	printf("\nPress'0' for main menu,\n"); scanf_s("%d", &men);
	if (men == 0)
	{
		menu();
	}
}


void slection(void) {


	printf("\n\t\t\t\t\tSeat Selection.\n\n\t\t\t\t----------------------------------------------------\n");
	printf("Type '1' for 'Business class'.\nType '2' for 'Economy class'.\nSelect a number : ");

	int class;
	scanf_s("%d", &class);
	if (class ==1)
	{
		printf("Business class\n");
		
		printf("Going to Business seat reservation.....");
		Sleep(1800);
		system("cls");
		printf("\n\t\t\t\t\tBusiness class.\n\n\t\t\t\t----------------------------------------------------\n");
		printf("\n\t\t\t\tSelect seat '31 -100' ");
		business();
		printf("Generating boarding pass.....");
		Sleep(1800);
		system("cls");
		invoice();
	}
	else if (class == 2)
	{
		printf("Economy class\n");

		printf("Going to Economy seat reservation.....");
		Sleep(1800);
		system("cls");
		printf("\n\t\t\t\t\tEconomy class.\n\n\t\t\t\t----------------------------------------------------\n");
		printf("\n\t\t\t\tSelect seat '1 -30' ");
		economy();
		printf("Generating boarding pass.....");
		Sleep(1800);
		system("cls");
		invoice();

	}
	else 
	{
		printf("Enter a valid class\n");
		slection();

	}


	
	int men;


	printf("\nPress'0' for main menu,\n"); scanf_s("%d", &men);
	if (men == 0)
	{
		menu();
	}
}



void menu(void)
{


	printf("Going to menu.....");
	Sleep(1800);
	system("cls");
	printf("\n\t\t\t\t\t\tMenu.\n\n\t\t\t----------------------------------------------------\n");
	int meu;
	printf("Type '1' for 'Chart display'.\nType '2' for 'seat selection '.\nType '3' for 'Exit '.\nSelect a number : ");
	scanf_s("%d", &meu);

	 if (meu == 1) {
		slots();


	}
	
	else if (meu == 2) {
		 printf("Seat selection.....");
		 Sleep(1800);
		 system("cls");
		slection();

	
	}
	

	else if (meu == 3) {

		printf("Thanks for using\n");
		exit(65);

	}
	else
	{
		printf("\nNot operation selected. please select an operation \n");
		menu();
	}
}


void business(void){
	
	printf("\nEnter a seat number: ");
	
	scanf_s("%d", &seat_num);
	if (seat_num>=31 && seat_num<=100)
	{
		if (arry[seat_num - 1] == '1') {
			printf("Seat reserved. Please select oter  seat between 31-100\n");
			business();
		}
		else {
			arry[seat_num - 1] = '1';
			printf("Thanks.Seat reserved.\n");
		}
	}
	else
	{
		printf("\n\t\t\t\t Please Select seat '31 -100'.This is not valid seat ");
		business();

	}
	
	

}
void economy(void){

	printf("\nEnter a seat number: ");

	scanf_s("%d", &seat_num);
	if (seat_num >= 1 && seat_num <= 30)
	{
		if (arry[seat_num - 1] == '1') {
			printf("Seat reserved. Please select other  seat between 1-30\n");
			economy();
		}
		else {
			arry[seat_num - 1] = '1';
			printf(" Thanks.Seat reserved.\n");
		}
	}
	else
	{
		printf("\n\t\t\t\t Please Select seat '31 -100'.This is not valid seat ");
		economy();

	}



}

void invoice(void) {
	printf("\n\t\t\t\t\tBoarding Pass.\n\n\t\t\t\t----------------------------------------------------\n");
	printf("Selected  seat number is '%d'\n ", seat_num);
	if (seat_num >= 1 && seat_num <= 30)
	{
		printf("Selected class is 'Economy Class'\n");
	}
	else if (seat_num >= 31 && seat_num <= 100) {
		printf("Selected class is 'Business Class'\n");
	}
	int men;


	printf("\nPress'0' for main menu,\n"); scanf_s("%d", &men);
	if (men == 0)
	{
		menu();
	}
}








