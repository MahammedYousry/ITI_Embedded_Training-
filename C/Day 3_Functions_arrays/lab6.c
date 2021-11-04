#include<stdio.h>

void main()
{	
	int sum ;
	int x[10];
	for (int i =0;i<10;i++){
		printf("enter the value %d :\n",i+1);
		scanf("%d", &x[i]);
		sum +=x[i];
	}
	
	float avg;
	avg =sum /10.0;
	printf("\nthe sum is %d",sum);
	printf("\nthe average is %f",avg);
}