#include<stdio.h>
int main ()
{
	int x;
	printf("please enter the grade\n");
	scanf("%d", &x);
	if(0<=x && x<50)
	{
		printf("failed\n");
	}
	else if(50<=x && x<65)
	{
		printf("normal\n");
	}
	else if(65<=x && x<75)
	{
		printf("Good\n");
	}
	else if(75<=x && x<85)
	{
		printf("Very Good\n");
	}
	else 
	{
		printf("excellent\n");
	}
	
}