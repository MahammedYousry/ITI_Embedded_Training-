#include<stdio.h>
void main()
{
	
	int arr[10];
	for (int i =0 ; i<10 ; i++)
	{
		printf("enter the number %d\n",i+1);		//enter the numbers in the array
		scanf("%d", &arr[i]);
	}
	printf("The value after sorting:\n");
	
	for (int c=0 ; c<10 ; c++)
	{
		for(int j=0 ; j<10-c-1 ; j++)
		{
			if(arr[j] > arr[j+1])
			{
				int swap;							//sorting numbers
				swap =arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=swap;
			}	
		}
	}
	for (int z=0 ;z<10 ;z++)
	{
		printf("%d \n" ,arr[z]);					//printing the array 
	}
}
