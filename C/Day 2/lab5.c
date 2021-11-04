#include<stdio.h>
int main ()
{
	int x;
	printf("please enter the ID\n");
	scanf("%d", &x);
	switch(x){
		case(1234):printf("welcome Ahmed");
		break;
		case(5678):printf("welcome Youssef");
		break;
		case(1145):printf("welcome Mina");
		break;
		default:printf("wrong ID");
		break;
		
	}
	
}