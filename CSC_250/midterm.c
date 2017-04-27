#include <stdio.h>

#define N 10 // Do NOT change this line!

/*
	Structure definition should go here
*/
typedef struct point2d_struct
{
	int x;
	int y;

}point2d;


void fill(char str[], point2d P[])
{
/*
	This function opens and reads from the input file. You
	should close the file when you are done with it. Read
	the points into the array of structures in this function.

	Don't forget to check if the file name is valid.
*/
	FILE* inFile = NULL; // file pointer
	inFile = fopen(str,"r");


}

int getdist(point2d p, point2d q)
{
/*
	This function gets the distance between 2 points and
	returns that value.

	Yes, you need to do some math here...
*/


}

void closest(point2d P[], int G[2*N][2*N])
{
/*
	This function finds the 2 points that are the closest.

	You should call the getdist() function from inside here.
*/

// find the 2 points that are closest

// set values in G to unique values

}

void grid(point2d P[], int G[2*N][2*N])
{
/*
	This function will transfer all the points from your
	structure into a 2D array used as the grid.

	You will call the closest() function from inside here.
*/

// set G for each of the N points


	closest(P, G);
}

void printpoints(char str[], point2d P[])
{
/*
	This function will print off the list of all the
	points you have in the following form:

	num: ( x, y)

	ex.
	0: ( 4, 1)

	** Note the spacing!

	You need to open the output file here and write to it.
*/
	int i = 0;
	for( i = 0; i < 10; i++){
		printf("%d: ( %d, %d)",i,P[i].x,P[i].y)
	}



}

void printgridxy(char str[], int G[2*N][2*N])
{
/*
	This function will print out your 2D array (the grid)

	Use ' ' for spots without a point,
	use '*' for spots with a point,
	use 'X' for the 2 points that are closest.

	Put 1 space between each element, for example you should
	print "* " instead of just "*".


	You should also have a top and bottom made of 50 hyphens (-)

	This should be printed to the same file as the points were.
		Be careful not to overwrite the file!
*/


}


int main(int argc, char *argv[])
{
/*
	Do not change anything in main! Also do not change the #define
	at the top of the program.

	There is one exception to this, you may change the "type" for the
	structure you made if you don't use my naming scheme.
*/
	if (argc != 3)
	{
		printf("Syntax Error: ./a.out <infile> <outfile>\n");
		exit(1);
	}
	
	point2d P[N]; // <-- This is the only line you are allowed to change.
	int G[2*N][2*N] = {0};

	fill(argv[1], P);
	grid(P, G);
	printpoints(argv[2], P);
	printgridxy(argv[2], G);

	
	return 0;
}
