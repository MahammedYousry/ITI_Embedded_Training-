#include <stdio.h>
#include<stdlib.h>
#include"STD_TYPE.h"
struct node_type;
typedef struct node_type node;
void addnode (s32 val);
void print (void);
void insert (s32 val,s32 position);

void deletevalue (s32 val);
int main ()
{
	s16 x ,y;
	s32 newvalue;
	s32 pos;
	while (y!=5)
	{
		
	
		printf("to add a node enter 1\nTo print a linked list enter 2 \nto insert press 3\nto delete a node press 4\nto exit press 5\n your choice is :");
		scanf("%d", &x);
		switch(x)
		{	
			case 1 : printf("enter the node value : ");
				scanf("%d", &y);
				addnode(y);
				printf("node added thank you \n\n");
				break;
			case 2 :
				print();
				
				break;
				
				
			case 3 :
				printf("Please Enter Node Value: ");
			    scanf("%d",&newvalue);
				printf("Please Enter the position: ");
			    scanf("%d",&pos);
				insert(newvalue , pos);
				
				
				break;
				
				
			case 4 :
				printf("Please Enter Node Value: ");
			    scanf("%d",&newvalue);
				deletevalue (newvalue);
				break;
	
			case 5 :
					printf("Thank You\nGood Bye");
					y = 5;
	
				break;
	
			default:
				printf("Invalid Choice please try again\n"); 
				break;
	

		}
	}
}