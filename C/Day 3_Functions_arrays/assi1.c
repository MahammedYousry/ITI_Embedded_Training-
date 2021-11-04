#include  <stdio.h>

int the_max(int array2[4])
{
	int max,min;
	max = array2[0];
	min = array2[0];
	for(int i=1;i<4;i++)
	{
		if(array2[i]>max)
		{
			max=array2[i];
			
		}
		else if(array2[i]<min)
		{
			min=array2[i];
		}
		
	}
	return max;
	
	
}
int the_min(int array2[4])
{
	int min,max;
	max = array2[0];
	min = array2[0];
	for(int i=1;i<4;i++)
	{
		if(array2[i]>max)
		{
			max=array2[i];
			
		}
		else if(array2[i]<min)
		{
			min=array2[i];
		}
		
	}
	return min;
}
void main()
{
	int array1[4];
    for(int i=0;i<4;i++)
	{
		printf("enter the %d number = ",i+1);
		scanf("%d",&array1[i]);
	}
	printf("the maximum number is %d \n",the_max(array1));
	printf("the minimum number is %d ",the_min(array1));	
}