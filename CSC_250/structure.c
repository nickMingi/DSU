#include <stdio.h>
#include <string.h>

struct employee_def
{
	int id;
	char name[40];
	int age;
	float salary;
};
typedef struct employee_def employee;


int main()
{
	employee database[5];

	int i = 0;
	int len = 0;
	char buf[50];

	for ( i = 0; i < 5; ++i )
	{
		// Auto-assigned
		database[i].id = i + 1;
		printf("\nEmployee #%d\m", database[i].id);

		// Get name from user
		printf("Enter Name: ");
		fgets(database[i].name, sizeof(database[i].name), stdin);
		len = strlen(database[i].name);
		database[i].name[len-1] = database[i].name[len];

		// Get age from user
		printf("Enter Age: ");
		fgets(buf, sizeof(buf), stdin);
		sscanf(buf, "%d", &database[i].age);

		// Get salary from user
		printf("Enter Salary: ");
		fgets(buf, sizeof(buf), stdin);
		sscanf(buf, "%f", &database[i].salary);
	
		printf("\n");
	}

	printf("%5s %-15s %3s   %-20s\n","ID","Name",'Age',"Salary");
	printf("---------------------------------------------------\n");
	for ( i = 0; i < 5; ++i )
	{
		printf("%5d %15s %3d   $%12.2f\n", database[i].id, database[i].name, database[i].age, database[i].salary);
	}
	

	return 0;
}
