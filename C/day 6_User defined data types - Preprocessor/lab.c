#include<stdio.h>
typedef unsigned short int u16;
typedef signed     short int s16;
typedef unsigned long  int u32;
typedef signed     long  int s32;
typedef unsigned  char u8;
typedef signed      char s8;
typedef float f32;
typedef double f64;
int main (){
	printf("the size of u16=%d\n",sizeof(u16));
	printf("the size of s16=%d\n",sizeof(s16));
	printf("the size of u32=%d\n",sizeof(u32));
	printf("the size of s32=%d\n",sizeof(s32));
	printf("the size of u8=%d\n",sizeof(u8));
	printf("the size of s8=%d\n",sizeof(s8));
	printf("the size of f32=%d\n",sizeof(f32));
	printf("the size of f64=%d\n",sizeof(f64));
	}