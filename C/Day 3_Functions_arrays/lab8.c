#include<stdio.h>


void main(){
	int arr[10];
	int x,flag,sum;
	for (int i =0 ; i<10 ; i++)
	{
		printf("enter the number :%d\n",i+1);		//enter the numbers in the array
		scanf("%d", &arr[i]);
	}
	printf("enter value to search :");			//value to search	
	scanf("%d", &x);	
	for(int j=0 ;j<10 ;j++)
	{											//linear search
		if (x==arr[j])
		{
		flag=1;	
		sum+=flag;	
		}
	}
	if(sum==0){
		printf("\nvalue not exist");										//printing time to exist
	}
	else{
		printf("this value exist %d times",sum);
	}
	
	
}