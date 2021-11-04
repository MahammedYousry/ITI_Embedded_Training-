#include<stdio.h>
int main (){
	int x;
	
	int salary;
	printf("please enter the hours rate\n");
	scanf("%d", &x);
	if(x>40){
		salary =x*50;
		printf("your salary is :%d",salary);
	
	}
	else{
		salary=50 *x;
		salary-=.1*salary;
		printf("your salary is :%d",salary);
	}
	
	
	
	
	
	
}