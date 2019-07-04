/*
clean up to do list:
-resort sku after add/delete sub
	
-add verification for all input
	verification for sku adding subs removing subs
	prevent add the same sku or removing a fake one
*/

//Project A.N.I.s(Automatic Newsstand Invoice System)

//Preprocessor Header
#include<stdio.h>
#include<ctype.h>
#include<time.h>

//Constant
#define ROWS 15
#define MAX_CUST 25

//main user defined function
void intro_gui(void);
int Mainmenu(void);
void new_entry(void);
void inv_table(void);
void sub_edit(void);
void cust_invoice(void);
//additional user function
int find_cust(int);
void disp_custdb(void);
int find_custidx(int);
void disp_invoice(int);
//void sort_sku();


//Array(CUSTOMER DATABASE)
int custdb_subscode [MAX_CUST]=	{
								2501,
								4902,
								5103,
								1904
								};
char custdb_name[MAX_CUST][30]=	{
							"Jufri",
							"Ali Baba",
							"Flynn Rider",
							"Fuutaro Usagi"
							};
char custdb_address[MAX_CUST][40]=	{
								"No64,TMN DESA",
								"Lot1,BERJAYA RESIDENCE",
								"Lv20,Menara Kubu",
								"B2.10,Kondominium Kristal"
								};
int custdb_sku[MAX_CUST][10]=	{
							{9006,9008,9009},
							{9001,9002,9008},
							{9004,9005,9007},
							{9003,9006,9007,9009,9010}
							};

//(INTVETORY DATABASE)
int inv_sku[ROWS] = 	{	
						9001,
						9002,
						9003,
						9004,
						9005,
						9006,
						9007,
						9008,
						9009,
						9010,
						9011,
						9012,
						9013,
						9014,
						9015
					};
char inv_prefix[ROWS][7]=	{
						"ISR126",
						"ISR119",
						"SCI307",
						"TCR471",
						"TCR250",
						"DGM874",
						"SCI314",
						"ISR408",
						"JPN490",
						"JPN001",
						"NWS921",
						"NWS238",
						"NWS610",
						"NWS792",
						"NWS873"

						};
char inv_title[ROWS][30]=	{
							"Solusi",
							"Majalah Ana Muslim",
							"National Graphic",
							"Aperture",
							"Tech",
							"Reader's Digest",
							"Knowledge",
							"Asuh",
							"Kreko",
							"Weekly Shounen Magazine",
							"The Star",
							"New Straits Times",
							"Berita Harian",
							"Harian Metro",
							"Kosmo!"
						};
char inv_pub[ROWS][30]=	{
							"Telaga Biru",
							"Ana Muslim",
							"World Marketing Group",
							"Digital Imaging Publication",
							"Reach Publication",
							"Trust Media Brand",
							"BBC Print",
							"Galeri Ilmu",
							"Comic Media",
							"Kodansha",
							"Star Media Group Berhad",
							"Media Prima",
							"Media Prima",
							"Media Prima",
							"Utusan Melayu Bhd"
						};
float inv_price[ROWS] =	{
						10.00,
						5.00,
						19.90,
						8.00,
						8.30,
						15.00,
						8.30,
						6.00,
						4.50,
						32.50,
						48.90,
						40.00,
						40.00,
						40.00,
						40.00
						};

//MAIN MODULE
int main()
{
	//LOCAL VARIABLE
	int submenu;
	
	intro_gui();//INTRO SCREEN FUNCTION CALL
	system("cls");
	
	//MENU SELECTION LOOP(Infinite looping until reach sentinal breakpoint)
	for(submenu=0;submenu!=-1;)
	{
		submenu = Mainmenu();//MAIN MENU FUNCTION CALL
		system("cls");
	if(submenu==-1)
		{
		break;
		}
	}
	
	system("pause");
	return 0;
}

//INTRO SCREEN MODULE
void intro_gui(void)
{
	//LOADING SCREEN
	system("title NEN Automatic Newsstand Invoice System(A.N.I.S) Gambang Sector");
	printf("===\t =====================\t   ===\n==\t=======================\t    ==\n=     ==Welcome to NEN  A.N.I.S==    =");
	printf("\n=\t==An Sect 606 Project==\t     =\n==\t =====================\t    ==\n===\t  ===================\t   ===\n");
	system("color 0A");//CHANGE COLOUR
	printf("\nBrought to you by team Ingenium.....PLUS ULTRA!!\n\n\n\n\n\n\n\n");
	system("pause");
	system("cls");
	
	//PROJECT ANIS BREAKDOWN
	printf("\t\t  NEN A.N.I.S\n\t\t===============\n\n");
	sleep(1);
	printf("NEN.CO - NURUDDIN ENTERTAINMENT NEWSSTAND COPERATION\n\n");
	sleep(1);
	printf("A\t-\tAutomatic\n.\n");
	sleep(1);
	printf("N\t-\tNewsstand\n.\n");
	sleep(1);
	printf("I\t-\tInvoice\n.\n");
	sleep(1);
	printf("S\t-\tSystem\n\n\n\n");
	system("pause");
	
}

//MAIN MENU 
int Mainmenu(void)
{
	int y = 1,x;
	printf("MAIN MENU\n---------\nWelcome to ANIS 1.0! What do you want to do?\n");
	printf("\n1. Add New Customer\n2. Add/Delete Subscription\n3. Print Customer Invoice\n4. Display Customer Database\n5. Display Inventory Database\n6. Exit Program");
	printf("\n\nEnter Option no: ");
	
	//DO WHILE LOOP OF VALIDATING OPTION
	do
	{
		scanf("%d",&x);
	
	//ELSE IF SELECTION(IF OPTION THEN RUN OPTION FUNCTION ELSE 0 ASSIGN TO X)	
		if(x==1)
		{
			printf("You've chose New Customer Entry\n",x);
			system("cls");
			printf("NEW CUSTOMER ENTRY\n---------------\n\n");
			new_entry();//NEW CUSTOMER FUNCTION CALL
		}
		else if(x==2)
		{
			printf("You've chose Subscription\n",x);
			printf("Subscription Menu\n");
			system("cls");
			sub_edit();//SUBSCRIPTION EDIT FUNCTION CALL
		}
		else if(x==3)
		{
			printf("You've chose Invoice\n",x);
			printf("Invoice Menu\n");	
			system("cls");
			cust_invoice();//INVOICE FUNCTION CALL
		}
		else if(x==4)
		{
			printf("%d\nYou've chose Customer Database\n",x);
			printf("CUSTDB Menu\n");	
			system("cls");
			disp_custdb();//CUSTOMER DATABASE FUNCTION CALL
		}
		else if(x==5)
		{
			printf("%d\nYou've chose Inventory Database\n",x);
			printf("INVDB Menu\n");	
			system("cls");
			inv_table();//STOCK FUNCTION CALL
			system("pause");
		}
		else if(x==6)
		{
			printf("You've chose Exit\n",x);
			system("cls");
			printf("Exit\n");
			y = -1;//SENTINEL VALUE TO TERMINATE LOOP IN MAIN FUNCTION
		}
		else if(x<1||x>6)
		{
			printf("%d\nThat's not an option!!\n",x);
			x = 0;
		}
		
		if(x<1||x>6)
		{
			printf("Re-enter:");	
		}		
	}while(x=0);
	sleep(1);
	return y;
}

void new_entry(void)
{
	//LOCAL VARIABLE
	int  i, j, k = 0, l;
	char voice;
	int temp;
	
	//NUMBER RANDOMIZER BASED ON  TIME OF DAY TO CREATE SUBSCRIPTION CODE FOR CUSTOMER
	printf("Generating New Customer Subscription code...\n");
	do
	{	
		j = 0;
		sleep(1);
		srand(time(NULL));
		temp = 1000 + rand()%(9999-1000+1);
		for(i=0;i<MAX_CUST;i++)
			{
				//VALIDATION FOR CODE AVAILABILITY
				if(custdb_subscode[i]==0)
				{
					printf("Code is available!\n\nYour Subscription Code is %d\n\nRegistration proceeding...\n",temp);
					custdb_subscode[i] = temp;
					j = 1;
					break;
				}
				else if(custdb_subscode[i]==temp)
				{
					printf("Code %d already taken\nGenerating new Code ");
					break;
				}
				else if(custdb_subscode[i]!=temp)
				;
		}
	}while(j != 1);
	
	//ASK FOR NAME
	printf("\n");
	printf("Enter Customer's Name: ");
	fflush(stdin);
	gets(custdb_name[i]);
	
	//ASK FOR ADDRESS
	printf("Enter Customer Address(LOT/RESIDENCE/ROAD)[30 char max]: ");
	gets(custdb_address[i]);
	
	//ASK FOR TOTAL OF SUBSCRIPTION TO BE MADE
	printf("\nEnter how many magazine has %s has subscribed to(Max Subscription is 10): ",custdb_name[i]);
	do
	{
		scanf("%d",&k);
		if(k<0||k>10)
		{
			printf("Invalid amount(Overexceeding subscription limit or it is negative value)\nRe-enter:");
		}
	}while(k<0||k>10);
	
	inv_table();//DISPLAY STOCK FUNCTION CALL
	
	//ASK FOR SKU CODE OF SUBSCRIPTION
	printf("Enter the SKU of all subscriptions:\n");
	for(l=0;l<k;l++)
	{
		scanf("%d", &custdb_sku[i][l]);//------------------temporary scanf	
	}
	
	/* LOOP TO VERIFY CODE AND CHECK FOR DOUBLE TAKE
	
	*/
	
	// FINISH MESSAGE
	printf("\n...Processing New Customer Data\nNew Customer Registered!!\n\n");
	
	//ASK IF WANT TO PRINT INVOICE
	fflush(stdin);
	printf("Do you want to print the invoice(Y-Yes/N-No)? ");
	scanf("%c",&voice);
	voice = toupper(voice);
	if(voice == 'Y')
		disp_invoice(i);//INVOICE FUNCTION CALL
	else
		;
	
}

//INVENTORY FUNCTION
void inv_table(void)
{
	//LOCAL VARIABLE(USED AS INDEX)
	int n;
	//TABLE HEADER
	printf("SKU\tPrefix\tTitle\t\t\t\tPublisher\t\t\tPrice(RM)\n---\t------\t-----\t\t\t\t---------\t\t\t-----\n");
	
	//LOOP TO PRINT TABLE CONTENT
	for(n=0;n<ROWS;n++)
	{
		printf("%d\t%s\t%-30s\t%-30s\t%.2f\n",inv_sku[n],inv_prefix[n],inv_title[n],inv_pub[n],inv_price[n]);
	}
	printf("\n");
}

//SUBSCRIPTION EDIT FUNCTION
void sub_edit(void)
{
	//LOCAL VARIABLE
	int addonsubs,selection, i, j, k, l,temp,sub_count=0;
	char voice;
	
	printf("ADD/DELETE SUBCRIPTION\n----------------------\n");
	
	//ASK FOR CUSTOMER SUBSCRIPTION CODE
	printf("ENTER CUSTOMER SUBSCRIPTION CODE: ");
	
	//LOOP TO FIND CODE EXISTANCE IN DATABASE
	do
	{
		j = 0;
		scanf("%d",&temp);
		j=find_cust(temp);
		if(j==1)
		{
			i = find_custidx(temp);
		}
		
	}while(j!=1);
	
	//COUNT THE NUMBER OF SUBSCRIPTION
	for(j=0;j<ROWS;j++)
	{
		if(custdb_sku[i][j]==0)
		;
		else if(custdb_sku[i][j]!=0)
			sub_count++;
	}
	
	//DISPLAY A TABLE OF THE CUSTOMER SUBSCRIPTION
	printf("\nYour Subscription\nSKU\tPrefix\tTitle\t\t\t\tPrice(RM)\n---\t------\t-----\t\t\t\t---------\n");
	for(j=0;j<sub_count;j++)
	{
		for(k=0;k<ROWS;k++)
		{
			if(custdb_sku[i][j]==inv_sku[k])
				break;
			else if(custdb_sku[i][j] != inv_sku[k])
				;
		}
		printf("%d\t%s\t%-30s\t%.2f",inv_sku[k],inv_prefix[k],inv_title[k],inv_price[k]);
		printf("\n");
	}
	
	//STATE THE NUMBER OF SUBSCRIPTION
	printf("\nThere are %d amount of sub\n", sub_count);
	
	//ASK FOR OPTION(ADD, DELETE OR RETURN TO MENU)
	printf("\nOKAY [%s] CHOOSE FROM THE FOLLOWING OPTION:\n 1.ADD SUBCRIPTION\n 2.DELETE SUBCRIPTION\n 3.CANCEL OPERATION\n",strupr(custdb_name[i]));
	printf("\nENTER YOUR SELECTION:");
	scanf("%d",&selection);
	printf("\n");
	
	
	//OPTION 1 - ADD SUBSCRIPTION
	if(selection ==1)
	{
	//ASK HOW MANY SUSCRIPTION TO ADD
	printf("How many subcription do you want to add?:");
	
	j=0;
	
	//CHECKING IF THE VALUE ENTER DOES NOT EXCEED SUBSCRIBING LIMIT
	do
	{
		fflush(stdin);
		scanf("%d",&addonsubs);
		if(addonsubs >= 10-sub_count)
			{
				printf("Reenter: ");
			}	
		else if(addonsubs < 10-sub_count)
			{
				printf("okay\n");
				j =1;
			}
	}while(j!= 1);
	
	//PRINT CATALOF
	printf("\nCatalog\n");
	inv_table();//INVENTORY FUNCTION CALL
	
	//ASK FOR SKU 
	printf("\nEnter the SKU code of your order: \n");
	
	for (j=sub_count;j<sub_count+addonsubs;j++)
	{
		scanf("%d", &custdb_sku[i][j]);
	}
	/*
	CHECK IF INPUT IS A SKU
	CHECK IF INPUT IS NOT ALREADY ORDERED
	*/
	
	//PRINT NEW CUSTOMER SUBSCIPTION LIST
	sub_count+= addonsubs;
	printf("\nYour Subs\n");
	printf("SKU\tPrefix\tTitle\n---\t------\t-----\n");
	for(j=0;j<sub_count;j++)
	{
		for(k=0;k<ROWS;k++)
		{
			if(custdb_sku[i][j]==inv_sku[k])
			{
				break;
			}
			else if(custdb_sku[i][j] != inv_sku[k])
			
			;
		}
		printf("%d\t%s\t%s\n",inv_sku[k],inv_prefix[k],inv_title[k]);
	}
	
	}
	//OPTION 2 - TERMINATE SUBSCRIPTION
	else if(selection ==2)
	{
		//ASK FOR NUMBER OF SUBSCRIPTION TO DELETE
		printf("How many subcription do you want to terminate?: ");		
		j=0;
		do
		{
			fflush(stdin);
			scanf("%d",&addonsubs);
			if(addonsubs > sub_count)
				{
					printf("Reenter: ");
				}	
			else if(addonsubs <= sub_count)
				{
					j =1;
				}
		}while(j!= 1);
		
		//DISPLAY INVENTORY	
		printf("\nCatalog\n");
		inv_table();//INVENTORY FUNCTION CALL
		
		//ENTER SKU TO TERMINATE
		printf("Enter the SKU code of your terminate: \n");
		int temp_del[10]={0};
		for (j=0;j<addonsubs;j++)
		scanf("%d",&temp_del[j]);
		for(j=0;j<addonsubs;j++)
		{
			for(k=0;k<sub_count;k++)
			{
				if(temp_del[j]==custdb_sku[i][k])
				custdb_sku[i][k]=0;
				else if(temp_del[j]!=custdb_sku[i][k])
				;
			}
		}
		/* 
		VALIDATE INPUT
		*/
	
		//SHOW NEW SUBSCRIPTION LIST
		printf("\nYour New Subscription\n");
		//print n update
		printf("SKU\tPrefix\tTitle\n---\t------\t-----\n");
		for(j=0;j<sub_count;j++)
		{
			for(k=0;k<ROWS;k++)
			{
				if(custdb_sku[i][j]==inv_sku[k])
				{
					break;
				}
				else if(custdb_sku[i][j] != inv_sku[k])
				
				;
			}
			printf("%d\t%s\t%s\n",inv_sku[k],inv_prefix[k],inv_title[k]);
		}
	
	}
	//OPTION 3 - NULL
	else if(selection ==3)
	;
	
	//ASK IF WANT TO PRINT INVOICE FOR OPTION 1 OR 2
	if(selection == 1 || selection == 2)
	{
		fflush(stdin);
	printf("Do you want to print the invoice(Y-Yes/N-No)? ");
	scanf("%c",&voice);
	voice = toupper(voice);
	if(voice == 'Y')
		disp_invoice(i);
	else
		;
	
	}
}

//INVOICE FUNCTION
void  cust_invoice(void)
{
    //LOCAL VARIABLE
	int temp, i, j, k, l,ttl_subs=0;
	float ttl_payment=0;
	
	printf("Customer Invoice\n----------------\n");
	
	//ASK FOR CUSTOMER SUBSCRIPTION CODE
	printf("\nEnter Customer SUBSCRIPTION CODE: ");
	
	//VALIDATION LOOP
	do
	{	
		j = 0;
		scanf("%d",&temp);
		j = find_cust(temp);//CUSTOMER EXISTANCE CHECK FUNCTION CALL
		if(j==1)
		{
			i = find_custidx(temp);//FIND CUSTOMER INDEX FUNCTION CALL
		}
	}while(j != 1);
		disp_invoice(i);//INVOICE PRINT FUNCTION CALL
}

//CUSTOMER EXISTANCE CHECK FUNCTION
int find_cust(int x)
{
	//LOCAL VARIABLE
	int valid = -1, i;
	
	//LOOP TO CHECK CUSTOMER EXISTANCE
	printf("Searching Cust..\n");
	for(i=0;i<MAX_CUST;i++)
	{
		
		if(custdb_subscode[i]==0)
		{
			printf("INVALID CODE\n");
			break;
		}
		else if(custdb_subscode[i]==x)
		{
			printf("Code Matched. Proceeding...\n ");
			valid = 1;
			break;
		}
		else if(custdb_subscode[i]!=x)
			;
	}
	if(valid!=1)
	{
		printf("Customer does not exist! Re-enter:");
		return 0;
	}
	else if(valid==1)
		return 1;

}

//CUSTOMER INDEX SEARCH FUNCTION
int find_custidx(int x)
{
	//LOCAL VARIABLE
	int i;
	//LOOP EACH ITEM IN ARRAY TO FIND THE SAME SUBSCRIPTION CODE AND RETURN ITS INDEX
	for(i=0;i<MAX_CUST;i++)
	{
		
		if(custdb_subscode[i]==0)
		{
			break;
		}
		else if(custdb_subscode[i]==x)
		{
			break;
		}
		else if(custdb_subscode[i]!=x)
			;
	}

	return i;

}

//CUSTOMER DATABASE FUNCTION
void disp_custdb(void)
{
	//LOCAL VARIABLE
	int i, j;
	//TABLE OUTER FRAME + HEADER
	printf("============================================================================================================================================\n|Subscription Code\t|Name\t\t\t       |Address\t\t\t        |Subscribed List\t\t\t      \t   |\n|==========================================================================================================================================|\n");
	//INNER CONTENT
	for(i=0;i<MAX_CUST;i++)
	{
		if(custdb_subscode[i] != 0)
		{
			printf("|%d\t\t\t|%-30s|%-30s\t|",custdb_subscode[i],custdb_name[i],custdb_address[i]);
			for(j=0;j<10;j++)
			{
				if(custdb_sku[i][j]!= 0)
				{
					printf("%4d ",custdb_sku[i][j] );
				}
				else if(custdb_sku[i][j]== 0)
					printf("     ");
			}
			printf("|\n");
		}
		else if (custdb_subscode[i] == 0)
		break;
	}
	printf("============================================================================================================================================\n");
	
	system("pause");
}	

//DISPLAY INVOICE FUNCTION
void disp_invoice(int i)
{
	//LOCAL VARIABLE
	int j,k;
	float ttl_payment;
	
	//HEADER
	printf("\t-------------------------\n\t%s'S INVOICE\n\t-------------------------\n\n",custdb_name[i]);
		
		printf("\tNuruddin Entertainment Newsstand\n\tGombak KL 53100\n\t---------------------------------\n");
		printf("\tInvoice Prepared For Customer:\n\t%d - %s\n\t%s\n\n",custdb_subscode[i],custdb_name[i],custdb_address[i]);
	//TABLE HEADER
	printf("\t SKU\tPrefix\t\t Price \n\t-----\t------\t\t-------\n");
	//TABLE CONTENT
	for(k=0;k<ROWS;k++)
	{
		for(j=0;j<ROWS;j++)
			{
				
				if(custdb_sku[i][j]==inv_sku[k])
				{
					printf("\t %d \t%s\t\t%4.2f \n",inv_sku[k],inv_prefix[k],inv_price[k]);
					ttl_payment+=inv_price[k];
				}
				else if(custdb_sku[i][j]!=inv_sku[k])
				{
				;
				}
				
			} 
	}
	//TOTAL PAYMENT
	printf("\t---------------------------------\n\tTotal Payments:\t\t%.2f\n",ttl_payment);

	printf("\n");
	system("pause");
}
