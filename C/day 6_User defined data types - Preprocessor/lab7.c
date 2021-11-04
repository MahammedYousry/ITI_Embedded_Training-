#include <stdio.h>
#define set_bit(var,bit_no) var=1
#define clr_bit(var,bit_no) var=0
#define toggle_bit(var,bit_no) var=(1^bit_no)
int main (){
	int x =set_bit(x ,1);
	
	printf("%d\n",x);
	int z =toggle_bit(z ,0);
	printf("%d\n",z);
	
	int y =clr_bit(y ,1);
	printf("%d\n",y);
	}

