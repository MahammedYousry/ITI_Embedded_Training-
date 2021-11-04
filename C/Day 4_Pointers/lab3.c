#include  <stdio.h>
int b1,b2;
void function (int n1,int n2 )
{	
	
	b1 =n1+n2;
	b2=n1-n2;
}

int main ()
{
	int x ,y;
	int *sum= NULL;
	int *sub= NULL;
	printf("enter number 1 : \n"); 			
	scanf("%d", &x);
	printf("enter number 2 : \n"); 			
	scanf("%d", &y);
	function(x,y);
	sum=&b1;
	sub=&b2;
	printf("Sum Equal: %d \n",*sum);
	printf("Sub Equal: %d \n",*sub);
}