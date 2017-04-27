#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 50

struct properties_struct
{
	char property[MAX];
	float rental;
	float maintenance;
	int bedrooms;
	int bathrooms;

}typedef properties;

struct owner_struct
{
	int propertiNum;
	properties ps[MAX];
}typedef owner;

int main(int argc, char *argv[])
{
	FILE* infile = NULL;
	int i = 0, j = 0, propertiNum = 0;
	float totalIncome = 0, totalCost = 0, average1 = 0, average2 = 0;
	float totalIncome2 = 0;
	int house1 = 0, house2 = 0;
	int bedroom = 0, bedroom2 = 0;
	int totalProperty = 0;
	float totalRental = 0;
	float averageTotal = 0;

	if(argc<1){
		return -1;
	}
	owner o[2];

	infile = fopen(argv[1],"r");
	if (infile == NULL)
	{
		printf("Could not open file.\n");
		return -1;
	}

	for (j = 0; j < 2; j++ )
	{
		fscanf(infile,"%d",&o[j].propertiNum);
		propertiNum = o[j].propertiNum;
			if (propertiNum <= MAX)
			{
				o[j].ps[propertiNum];
			}else{
				printf("Maximum is 50. Ending the program.\n");
				return -1;
			}
		printf("number of contents = %d\n",o[j].propertiNum);
		totalProperty += o[j].propertiNum;
		for (i = 0; i < o[j].propertiNum; i++ )
		{
			fscanf(infile,"%s",o[j].ps[i].property);
			fscanf(infile,"%f",&o[j].ps[i].rental);
			fscanf(infile,"%f",&o[j].ps[i].maintenance);
			fscanf(infile,"%d",&o[j].ps[i].bedrooms);
			fscanf(infile,"%d",&o[j].ps[i].bathrooms);

			if(j == 0){
				totalIncome += o[j].ps[i].rental;
				bedroom += o[j].ps[i].bedrooms;
				average1 = totalIncome/bedroom;

				if(strcmp(o[j].ps[i].property,"house")==0){
					house1++;
				}
			}else if(j == 1){
				totalIncome2 += o[j].ps[i].rental;
				totalCost += o[j].ps[i].maintenance;
				bedroom2 += o[j].ps[i].bedrooms;
				average2 = totalIncome2/bedroom2;

				if(strcmp(o[j].ps[i].property,"house")==0){
					house2++;
				}
			}

			totalRental += o[j].ps[i].rental;
		}
	}
			averageTotal = totalRental / totalProperty;

				printf("Total income Owner1: $%.2f\n",totalIncome);
				printf("Total cost Owner2: $%.2f\n",totalCost);
				printf("Average price per bedroom Owner1: $%.2f\n",average1);
				printf("Average price per bedroom Owner2: $%.2f\n",average2);
				printf("# of Houses Owner1: $%d\n",house1);
				printf("# of Houses Owner2: $%d\n",house2);
				printf("Average price of all properties: $%.2f\n",averageTotal);


	fclose(infile);

	return 0;
}
