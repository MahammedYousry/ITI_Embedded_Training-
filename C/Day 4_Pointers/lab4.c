#include  <stdio.h>
int sum;
void function (int *array2 )
{	
	
	for(int i=0;i<10 ;i++)
	{
		sum += array2[i];
	}
}

int main ()
{
	int array[10];
    for(int i=0;i<10;i++)
	{
		printf("enter the %d number = ",i+1);
		scanf("%d",&array[i]);
	}
	function(& array[0]);
	printf("The sum equal %d",sum);
	
}