#include<stdio.h>
int main(){
	int x[3];
	int max;
	for(int i =0 ;i<3;i++){						//enter numbers
		printf("enter number %d\n",i+1);
		scanf("%d", &x[i]);
	}
	max=x[0];
	for(int i=0;i<3;i++){						//finding the maximum number
		if(max<x[i]){
			max= x[i];
		}
	}
	printf("the maximum number is %d",max);			//printing the max
}