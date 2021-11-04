#include <stdio.h>

typedef signed     long  int s32;
typedef struct employees
{
	s32 salary;
	s32 bonus;
	s32 deductions;
} emp;
	emp ahmed;
	emp waleed; 
	emp amr;
void  main (){

	printf("\nplease enter ahmed salary :");
	scanf("%d", &ahmed.salary);
	printf("\nplease enter ahmed bonus :");
	scanf("%d", &ahmed.bonus);
	printf("\nplease enter ahmed deductions :");
	scanf("%d", &ahmed.deductions);
	printf("\nplease enter waleed salary :");
	scanf("%d", &waleed.salary);
	printf("\nplease enter waleed bonus :");
	scanf("%d", &waleed.bonus);
	printf("\nplease enter waleed deductions :");
	scanf("%d", &waleed.deductions);
	printf("\nplease enter amr salary :");
	scanf("%d", &amr.salary);
	printf("\nplease enter amr bonus :");
	scanf("%d", &amr.bonus);
	printf("\nplease enter amr deductions :");
	scanf("%d", &amr.deductions);
	s32 sum =ahmed.salary+ahmed.bonus-ahmed.deductions+waleed.salary+waleed.bonus-waleed.deductions+amr.salary+amr.bonus-amr.deductions;
	printf("\nthe value of sum = %d",sum);
	
	}