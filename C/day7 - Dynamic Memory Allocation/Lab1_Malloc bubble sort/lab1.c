#include <stdio.h>
#include<stdlib.h>
typedef signed     short  int s16;
int main ()
{
	s16 x;
	printf("enter the number of elements :\n");
	scanf("%d", &x);
	s16 *ptr=(s16*)malloc (x*sizeof(s16));
	for (s16 c=0 ; c<x ; c++)
	{
		printf("enter the number %d\n",c+1);
		scanf("%d", &ptr[c]);
	
	}
	for (int c=0 ; c<x-1 ; c++)
	{
		for(int j=0 ; j<x-c-1 ; j++)
		{
			if(ptr[j] > ptr[j+1])
			{
				s16 swap;																	//sorting numbers
				swap =ptr[j];
				ptr[j]=ptr[j+1];
				ptr[j+1]=swap;
			}	
		}
	}
	printf("number after sorting\n");
	for (int z=0 ;z<x ;z++)
	{
		printf("%d \n" ,ptr[z]);														//printing the array 
	}
}