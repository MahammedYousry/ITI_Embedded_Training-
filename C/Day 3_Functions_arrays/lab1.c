#include<stdio.h>
int Get_Max (int num1,int num2){
	int max;
	if (num1 >num2){
		max = num1;
	}
	if (num1 <num2){
		max = num2;
	}
	return max;
}
	
int main()
{
	int x,y;
	printf("enter the number 1 : ");
	scanf("%d", &x);
	printf("\nenter the number 2 :");
	scanf("%d", &y);
	printf("\nthe maximum is %d",Get_Max( x, y));
}
	