#include<stdio.h>

void main()
{
	int x[10];
	for (int i =0;i<10;i++){
		printf("enter the value %d\n",i+1);
		scanf("%d", &x[i]);
	}
	printf("\nthe value after reverse ");
	for( int i=0;i<10 ;i++){
		printf("\n%d",x[9-i]);
	}
}
