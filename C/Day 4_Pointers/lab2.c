#include  <stdio.h>
int sum (int *n1,int *n2)
{
	int summ;
	summ =(*n1+*n2);
	return summ;
}
int main ()
{
	int x ,y;
	
	printf("enter number 1 : \n"); 			
	scanf("%d", &x);
	printf("enter number 2 : \n"); 			
	scanf("%d", &y);
	
	int result=sum(&x,&y);
	
	printf("Sum Equal: %d \n",result);
}