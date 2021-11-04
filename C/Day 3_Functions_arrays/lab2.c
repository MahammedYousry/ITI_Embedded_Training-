#include<stdio.h>
int x =10;
int y =20;
void swap (void)
{
	int b;
	b=x;
	x=y;
	y =b ;
}	
void main()
{
	printf("x before swap %d\n",x);
	printf("y before swap %d\n",y);
	swap();
	printf("x after swap %d\n",x);
	printf("y after swap %d\n",y);
}
