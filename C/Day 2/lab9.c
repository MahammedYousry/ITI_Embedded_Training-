#include<stdio.h>
int main ()
{
	int x;
	for (int a=0;;a++){
	printf("enter the answer of 3 *4 :");
	scanf("%d", &x);
	if (x==12){
		printf("thank you");
		break;
	}
	else{
		printf("wrong answer please try again\n");
	}
	}
}