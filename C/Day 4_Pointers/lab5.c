#include  <stdio.h>

int function (int *p1,int *p2)
{
	int s;
	for(int a=0;a<5;a++)
	{
		s+=(p1[a]*p2[a]);
	}
	return s;
}

void main ()
{
	int arr1[5];
	int arr2[5];
	
	for(int i =0;i<5;i++)
	{
		printf("\nenter the number %d in array1 = ",i+1);
		scanf("%d",&arr1[i]);
	}
	
	for(int j =0;j<5;j++)
	{
		printf("\nenter the number %d in array2 = ",j+1);
		scanf("%d",&arr1[j]);
	}
	
	int res =function(arr1,arr2);
	
	printf("\nthe multiplication of the two arrays equal : %d",res);
}