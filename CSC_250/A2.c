#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int strLen(char str[]);
void removeN(char str[]);

int main()
{
	char myChar = 'a';
	char yourChar;
	printf("%c\n", myChar);
	printf("%d\n", myChar);
	printf("enter any character");
	scanf("%c",&yourChar);
	if(strcmp(myChar,yourChar)==0){
		printf("same");
	}else{
		printf("different");
	}

	char myStr[500];
	printf("Enter a string: ");
	fgets(myStr, 500, stdin);
	removeN(myStr);
	int length = strlen(myStr);
	printf("Length is: %d\n", length);
	
	return 0;
}

int strLen(char str[]){
	
	int len = 0;
	int i = 0;

	while(str[i] != '\0'){
		len++;
		i++;
	}

	return len;
}

void removeN(char str[]){

	int endLoc = strLen(str);
	if (str[endLoc-1] == '\n')
	{
		str[endLoc-1] = '\0';
	}
	return;
}
