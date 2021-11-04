#include <stdio.h>

typedef signed     long  int s32;
typedef unsigned     long  int u32;
typedef unsigned     char u16;
typedef struct 
{
	u16 x;
	u32 y;
	u16 z;
	u32 k;
} mystruct;
	
void  main ()
{

	printf("\n the size = %d",sizeof(mystruct));
	
	
}