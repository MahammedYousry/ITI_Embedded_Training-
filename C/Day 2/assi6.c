#include<stdio.h>
//use library
int main (){
int row,i,x;
printf("please enter the number of rows");
scanf("%d", &x);					//number of rows
for(row = 1; row<=x ; row++)
{								// Loop to print rows
	for(i = 1;i <=x-row;i++)
	{								// Loop to print spaces in a row
		printf(" ");
	}
	for(i =1;i<=2*row-1;i++)
	{								// Loop to print stars in a row
		printf("*");
	}
	printf("\n");
	
	
	
}	
	