#include<stdio.h>
int main ()
{
	int x;
	
	printf("enter the number\n");
	scanf("%d", &x);
	int fac =1;
	
	for (x;x>0;x--){
		
		fac *=x;
		
	}
	
	
	printf("the factorial is :%d\n",fac);
}