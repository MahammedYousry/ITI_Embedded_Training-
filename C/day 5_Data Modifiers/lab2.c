#include  <stdio.h>

int main ()
{
	printf("\nsigned char %d ",sizeof(signed char));
	printf("\nunsigned char %d ",sizeof(unsigned char));
	printf("\nunsigned short %d ",sizeof(unsigned short));
	printf("\nsigned short %d ",sizeof(signed short));
	printf("\nsigned int %d ",sizeof(signed int));
	printf("\nsigned long int %d ",sizeof(signed long int));
	printf("\nunsigned long int %d ",sizeof(unsigned long int));
	printf("\nfloat %d ",sizeof(float));
	printf("\ndouble  %d ",sizeof(double));
	printf("\nlong double %d ",sizeof(long double));
}