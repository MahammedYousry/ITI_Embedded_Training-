#include<stdio.h>
int main(){
	int y[10];
	for (int x=0;x<10;x++){
		printf("enter number %d\n",x+1);
		scanf("%d", &y[x]);
		
	}
	int a;
	printf("\nenter the value to search :");
	scanf("%d", &a);
	for(int x=0 ;x<10;x++){
		if (a == y[x])
		{
			printf("value is exist at element number %d",x);
			
		}
		
		
		
		
	}
	
	
}