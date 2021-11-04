#include<stdio.h>
int Factorial (int y);
void main (){
	int x;
	printf("enter the number :");
	scanf("%d", &x);
	printf("\nthe Factorial equal %d",Factorial(x));
}
int Factorial (int y){  							// funtion get Factorial
	
	if (y!=1)
	{
		y *= Factorial(y-1) ;
	}
	else{
		return y;
	}
}