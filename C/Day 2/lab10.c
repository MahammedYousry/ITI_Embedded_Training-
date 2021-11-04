#include<stdio.h>
int main ()
{
	int x;
	
	printf("enter the number");
	scanf("%d", &x);
	for (int a=1;a<=10;a++){
		int z =a *x;
		printf("%d *%d = %d\n",x ,a ,z);
	}
	
}