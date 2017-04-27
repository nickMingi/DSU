#include <stdio.h>
#include <stdlib.h>

void getGrades(int assNum,int stuNum,int assignment[],char stuName[stuNum][50],int grade[assNum][stuNum],FILE* inFile);
void printGrades(int assNum,int stuNum,int grade[assNum][stuNum]);
void printStudents(int stuNum,const int SIZE,char stuName[stuNum][SIZE]);
void calcGrades(int assNum,int stuNum,int assignment[],int grade[assNum][stuNum],int finalGrade[stuNum]);
void printFinalGrades(int assNum,int stuNum,int finalGrade[stuNum]);

int main()
{
	const int SIZE = 50;
	FILE* inFile = NULL; // FIle pointer
	int stuNum = 0;
	int assNum = 0;
	int i = 0 , j = 0;
	int assignment[assNum];
	char stuName[stuNum][SIZE];
	int grade[assNum][stuNum];
	int finalGrade[stuNum];

	inFile = fopen("infile.txt","r");
	if (inFile == NULL)
	{
		printf("Could not open file infile.txt.\n");
		return -1; // -1 indicates error
	}

	fscanf(inFile,"%d",&stuNum); // getting student's number
	fscanf(inFile,"%d",&assNum); // getting assignment's number

	for(i = 0; i < stuNum; i++){
		fscanf(inFile,"%s",stuName[i]);
		printf(" Student : %s\n",stuName[i]);
	}

	getGrades(assNum,stuNum,assignment,stuName,grade,inFile);

	calcGrades(assNum,stuNum,assignment,grade,finalGrade);

	//printf("Finalgrade is = %c\n",finalGrade[0]);

	printf("\n\n");

	printStudents(stuNum,SIZE,stuName);
	printGrades(assNum,stuNum,grade);
	printFinalGrades(assNum,stuNum,finalGrade);
	printf("It's the end of the program\n");

	fclose(inFile);

	return 0;
}

void getGrades(int assNum,int stuNum,int assignment[],char stuName[stuName][50],int grade[assNum][stuNum],FILE* inFile){
	int i = 0, j = 0;

	for(i = 0; i < assNum; i++){
		for(j = 0; j < stuNum; j++){
		
			fscanf(inFile,"%d",&grade[i][j]);
		}
	}
	return;
}

void calcGrades(int assNum,int stuNum,int assignment[],int grade[assNum][stuNum],int finalGrade[stuNum]){
	int i = 0, j = 0;
	int totalGrade[stuNum];
	totalGrade[0] = 0;
	
	for(i = 0; i < stuNum; i++){
	
		for(j = 0; j < assNum; j++){
		
			totalGrade[i] = totalGrade[i] + grade[j][i];
		}
	// printf("totalGrade : %d\n",totalGrade[i]);
		totalGrade[i] = totalGrade[i]/assNum;
	// printf("finalGrade : %d\n",totalGrade[i]);
		if(totalGrade[i] >= 90){
			finalGrade[i] = 65;
		}else if(totalGrade[i] >= 80){
			finalGrade[i] = 66;
		}else if(totalGrade[i] >= 70){
			finalGrade[i] = 67;
		}else if(totalGrade[i] >= 60){
			finalGrade[i] = 68;
		}else{
			finalGrade[i] = 69;
		}

	}

	return;
}

void printStudents(int stuNum,const int SIZE,char stuName[stuNum][SIZE]){
	int i = 0;
	for(i = 0; i < stuNum; i++){
		printf("%12s",stuName[i]);
	}
	printf("\n");
	return;
}

void printGrades(int assNum,int stuNum,int grade[assNum][stuNum]){
	int i = 0, j = 0;
	for(i = 0; i < assNum; i++){
		for(j = 0; j < stuNum; j++){
			printf("%12d",grade[i][j]);
		}
		printf("\n");
	}
	return;
}

void printFinalGrades(int assNum,int stuNum,int finalGrade[stuNum]){
	int j = 0;

		for(j = 0; j < stuNum; j++){
			printf("%12c",finalGrade[j]);
		}
		printf("\n");

	return;
}