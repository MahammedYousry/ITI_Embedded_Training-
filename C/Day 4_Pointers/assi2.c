#include  <stdio.h>

int main ()
{
	int x=1;
	int y=2;
	int z=3;
	int *p =&x;
	int *q =&y;
	int *r =&z;
	printf("x =%d\ny=%d\nz=%d\n*p=%d\n*q=%d\n*r=%d\np=%d\nq=%d\nr=%d\n",x,y,z,*p,*q,*r,p,q,r);			// q1
	printf("\nswapping pointers");																		// q2
	int temp =r;
	r=p;																								// q3
	p=q;
	q=temp;
	printf("\nx =%d\ny=%d\nz=%d\n*p=%d\n*q=%d\n*r=%d\np=%d\nq=%d\nr=%d\n",x,y,z,*p,*q,*r,p,q,r);			// q4
}