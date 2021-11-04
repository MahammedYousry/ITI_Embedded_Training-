#include<stdio.h>
int main ()
{
	int sum =0 ;
	int x,y;
	for( x=1;x<=10;x++){
	printf("please enter the num %d\n",x);
	scanf("%d", &y);
	sum+=y;
	
	
	
	}
	int avg =sum/x;
	printf("the sum is %d\n",sum);
	printf("the average is %d\n",avg);
	
	
}