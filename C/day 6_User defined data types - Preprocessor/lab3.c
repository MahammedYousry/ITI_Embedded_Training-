#include <stdio.h>

typedef signed     long  int s32;
typedef struct 
{
	s32 math;
	s32 Language;
	s32 Physics ;
	s32 Chemistry;
} std;
	std arr[10];
void  main ()
{
	arr[0].math=30;
	arr[0].Language=40;
	arr[0].Physics=50;
	arr[0].Chemistry=60;
	arr[1].math=30;
	arr[1].Language=40;
	arr[1].Physics=50;
	arr[1].Chemistry=60;			
	arr[2].math=30;
	arr[2].Language=40;
	arr[2].Physics=50;
	arr[2].Chemistry=60;
	arr[3].math=30;
	arr[3].Language=40;
	arr[3].Physics=50;
	arr[3].Chemistry=60;
	arr[4].math=30;
	arr[4].Language=40;
	arr[4].Physics=50;
	arr[4].Chemistry=60;
	arr[5].math=30;
	arr[5].Language=40;
	arr[5].Physics=50;
	arr[5].Chemistry=60;
	arr[6].math=30;
	arr[6].Language=40;
	arr[6].Physics=50;
	arr[6].Chemistry=60;
	arr[7].math=30;
	arr[7].Language=40;
	arr[7].Physics=50;
	arr[7].Chemistry=60;
	arr[8].math=30;
	arr[8].Language=40;
	arr[8].Physics=50;
	arr[8].Chemistry=60;
	arr[9].math=30;
	arr[9].Language=40;
	arr[9].Physics=50;
	arr[9].Chemistry=60;

	s32 x;
	printf("enter the ID : ");
	scanf("%d", &x);
	if(x<10){
		printf("\nthe degree in math = %d",arr[x].math);
		printf("\nthe degree in math = %d",arr[x].Language);
		printf("\nthe degree in math = %d",arr[x].Physics);
		printf("\nthe degree in math = %d",arr[x].Chemistry);
	}
	else{
		printf("wrong ID");
	}
	}