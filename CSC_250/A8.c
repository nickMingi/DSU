#include <stdio.h>
#include <stdlib.h>

void selectionSort(int arr[], int size);
void bubbleSort(int arr[], int size);
void array_copy(int a[], int b[], int size);

int main(int argc, char *argv[])
{
	FILE* inFile = NULL;
	int num = 0;
	int i = 0;

	if(argc < 1){
		return -1;
	}

	inFile = fopen(argv[1],"r");
	if(inFile == NULL){
		printf("Could not open file.\n");
		return -1;
	}

	fscanf(inFile,"%d",&num);
	int arr[num];
	for(i = 0; i < num; i++){
		fscanf(inFile,"%d",&arr[i]);
	}
	printf("Before:");
		for(i = 0; i < num; i++){
			printf("%4d",arr[i]);
		}
		printf("\n");
		selectionSort(arr,num);
		printf("\n");
		bubbleSort(arr,num);

		printf("\n");
	
	return 0;
}

void array_copy(int a[], int b[], int size){
	int i = 0;
	for(i = 0; i < size; i++){
		b[i] = a[i];
	}
}

void selectionSort(int arr[], int size){
	int i = 0, j = 0, tmp = 0;
	int n = size;
	int selection[size];
	array_copy(arr,selection,size);
	for(i = 0; i < n-1; i++){
		for(j = i+1; j < n; j++){
			if(selection[i] > selection[j]){
				tmp = selection[i];
				selection[i] = selection[j];
				selection[j] = tmp;
			}
		}
	}

	printf("** Selection Sort **\n");
	printf(" After:");
	for(i = 0; i < n; i++){
		printf("%4d",selection[i]);
	}

}

void bubbleSort(int arr[], int size){
	
	int i = 0, j = 0, tmp = 0;
	int n = size;
	int bubble[size];
	array_copy(arr,bubble,size);
	for(i = 0; i < n-1; i++){
		for(j = 0; j < n-1-i; j++){
			if(bubble[j] > bubble[j+1]){
				tmp = bubble[j];
				bubble[j] = bubble[j+1];
				bubble[j+1] = tmp;
			}
		}
	}
	printf("** Bubble Sort **\n");
	printf(" After:");
	for(i =0; i < n; i++){
		printf("%4d",bubble[i]);
	}
	printf("\n");
}