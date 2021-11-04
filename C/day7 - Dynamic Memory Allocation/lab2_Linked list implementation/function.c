#include <stdio.h>
#include<stdlib.h>
#include"STD_TYPE.h"

struct node_type{
	
	s32 value;
	struct node_type *next;
	
};
typedef struct node_type node;
s32 listlength=0;
node *head;




void addnode (s32 val)
{	
	if (listlength ==0)
	{
		node *new =(node*)malloc(sizeof (node));
		head =new;
		head->value = val;
		head->next = NULL;
		
	}
	else
	{
		node *last;
		node *new =(node*)malloc(sizeof (node));
		new->value = val;
		new->next = NULL;
		last=head;
		while (last ->next != NULL)
		{
			last = last->next;
		}
		last->next=new;
		
	}
	listlength++;
}





void print (void)
{
	printf("\n\n----------------------\n");
	if(listlength>0)
	{
		node *last=head;
		s32 i=1;
		printf("the value %d = %d\n",i,last->value);
		
		
		while (last->next !=NULL)
		{
			i++;
			last=last->next;
			printf ("the value %d = %d\n",i,last->value);
			
		}
		
	}
	else 
		{
			printf("there is no list to view");
		}
	printf("   ----------------------\n\n");
}

void insert (s32 val,s32 position)
{
	node *before ;
	node *after=head;
	if (position ==1)
	{
			node * new=(node*)malloc(sizeof(node));
			new->value=val;
			new->next=head;
			head=new;
			listlength++;
			
	}
	else if(position<=listlength)
	{
		
		for(s32 i =1 ;i<position;i++)
		{
			before =after;
			after=after->next;
		}
		node*new =(node*)malloc(sizeof(node));
		new ->value=val;
		new ->next =after;
		before->next=new;
		listlength++;
	}
	else 
	{
		printf("wrong position");
	}
	
}

void deletevalue (s32 val)
{
	node*first=head;
	node*last=first->next;
	
	while (last->next!=NULL)
	{
	
	
		if (val==last->value){
			first->next=last->next;
			free(last);
			last=first->next;
			listlength--;
		}
		else{
				first=first->next;
				last=last->next;
		}
	}
	if(head->value ==val){
		first=head->next;
		free(head);
		head=first;
		listlength--;
	}
	
	if (last->value==val){
		free(last);
		first->next=NULL;
		listlength--;
	}
	
}





