#include  <stdio.h>
void sort (int *ptr1)
{
	for (int c=0 ; c<10 ; c++)
	{
		for(int j=0 ; j<10-c-1 ; j++)
		{
			if(ptr1[j] > ptr1[j+1])
			{
				int swap;							//sorting numbers
				swap =ptr1[j];
				ptr1[j]=ptr1[j+1];
				ptr1[j+1]=swap;
			}	
		}
	}
}
void main ()
{
	int array1[10];
	for(int i =0;i<10;i++)
	{
		printf("\nenter the number %d = ",i+1);
		scanf("%d",&array1[i]);
	}
	int *ptr= array1;
	sort(ptr);
	for (int z=0 ;z<10 ;z++)
	{
		printf("%d \n" ,ptr[z]);					//printing the array 
	}
	
	
}