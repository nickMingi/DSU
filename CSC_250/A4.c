#include <stdio.h>
#include <string.h>

struct store_def
{
	int id;
	char name[40];
	int quantity;
	float price;
	char date[10];
};
typedef struct store_def store;


int main()
{
	const int MAX_SIZE = 500;
	FILE* inFile = NULL; // File pointer

	int i = 0;
	int len = 0;
	char buf[50];
	int inventoryNum = 0;

	inFile = fopen("infile.txt","r");
	if (inFile == NULL)
	{
		printf("Could not open file inFile.txt.\n");
		return -1; // -1 indicates error
	}

	fscanf(inFile,"%d",&inventoryNum); // getting number of inventory items
	store database[inventoryNum];
	
	for (i = 0; i < inventoryNum; ++i )
	{

		// Get name from user
		fscanf(inFile,"%s",database[i].name);

		// Get quantity from user
		fscanf(inFile,"%d",&database[i].quantity);

		// Get salary from user
		fscanf(inFile,"%f",&database[i].price);

		// Get ID from user
		fscanf(inFile,"%d",&database[i].id);

		// Get date from user
		fscanf(inFile,"%s",database[i].date);

		prinf("\n");
	}
	
	printf("%-15s %5s   %-10s  %-8s  %-5s\n","NAME","QUANTITY","PRICE","ID","DATE");
	printf("---------------------------------------------------------------------\n");
	for (i = 0; i < inventoryNum; ++i )
	{
		printf("%15s %5d   $%12.2f  %-8d  %-10s\n",database[i].name,database[i].quantity,database[i].price,database[i].id,database[i].date);
	}

	fclose(inFile);

	return 0;
}
