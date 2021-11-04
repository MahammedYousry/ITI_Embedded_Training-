#include  <stdio.h>

int main ()
{
	int x =10;
	
	printf("Before change %d\n",x); 			//dscfdsfsf
	
	int *ptr = &x;
	
	*ptr =20;
	
	printf("after change %d \n",x);
}