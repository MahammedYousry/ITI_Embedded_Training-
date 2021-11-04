
/*written by *********( Mohammed Youssry Mohammed )**********/
/*written in ********* (21\08\2021)  **********/



#include <stdio.h>
#include"lib/STD_TYPES.h"



typedef struct 																												//main struct							
{
	u8 name [20] ;
	u16 age ;
	u8 gender[10];
	u16 id;
	u16 slot;
}patient;

patient patient_list[10] ;
s32 ptnum=0;

u8 slot1=0;u8 slot2=0;u8 slot3=0;u8 slot4=0;u8 slot5=0;													//global variables
			
void addpatient ()	;																											//prototype of functions
void editpnt ();	
void avaliable_slots();	
void Patient_Slot();
void Cancel_reservation();
void viewptrecord();
void Display_reservations();


void main (void)																																	//main
{
	s16 exit =1;
	s32 pass;
	s32 mode;
	u8 cmode=0;
	u8 choice;
	
	while(exit==1)
	{
		printf ("\nTo Admin mode press 1\nTo User mode press 2\n");
		scanf("%d", &mode);
	
		switch (mode)
		{
		case (1) :
					printf("Enter password : ");																			//login admin mode
					 scanf("%d", &pass);
					for(u8 i=0;i<3;i++){
					 
						if(pass ==1234)
						{	
							printf("Correct Password\n You are in admin mode\n");
							cmode=1;
							break;
						}
						else
						{
						
								printf("please try again\n");
								printf("Enter password : ");
								scanf("%d", &pass);
						
	
						}
					}
					break;
		
		case(2) :																				//login User mode
					printf("You are in User mode\n");
					cmode=2;
					break;
		}
	
	
	switch(cmode)
		{
			case(1) :printf ("To Add patient press 1\nTo Edit patient press 2\nTo reserve a slot enter 3 \nTo cancel a reservation enter 4 \nTo exit press 5\n");								//admin mode  fetures						
					scanf("%d", &choice);
						
						if(choice ==1)
						{
						addpatient();
						}
						else if(choice ==2)
						{
					
						editpnt();
						
						}
						else if(choice ==3)
						{
					
						Patient_Slot();
						
						}
						else if(choice ==4)
						{
							
						    Cancel_reservation();
							
						}
						else if(choice ==5 ){
						exit =5;
						}
						
						
						else {
							
							printf("wrong choice");
						}
						break;
	
	
			case(2) :																													          														//in user mode fetures
					printf("To view patient record press 1\nTo view reservation of today press 2\n To exit press 3\n");
					scanf("%d", &choice);
	
					if (choice ==1 )
					{
						
						viewptrecord();
					}
					else if(choice ==2 ){
						
						
						
					Display_reservations();	
					}
					else if(choice ==3 ){
					exit =3;
					}
					else{
						
						printf("wrong choice");
					}
						break;
		}

	}
}

void addpatient ()																																//add Patient function
{	

	u16 reserve =1;
	while(reserve==1)
	{
		reserve =0;
		printf("Please enter the ID of the patient : \n");
		scanf("%d", &patient_list[ptnum].id);
		
		
		for (u8 i=0;i <ptnum;i++)
		{
			if(patient_list[ptnum].id==patient_list[i].id)
			{
				printf("ID is reserved\n");
				reserve =1;
			}
		}
		
	}
	printf("Please enter the name of the patient : \n");
	scanf("%s", &patient_list[ptnum].name);
   
   printf("Please enter the age of the patient : \n");
	
	scanf("%d", &patient_list[ptnum].age);
	
	printf("Please enter the gender of the patient : \n");
	scanf("%s", &patient_list[ptnum].gender);
	
	
	

	ptnum=ptnum+1;	
	printf("succesful add patient");
}
	


void editpnt ()																																							//edit Patient function
{
	u8 exist =0;
	u16 editId ;
	u8 choice;
	s16 z;
	printf("Please enter the ID of the patient : \n");
	scanf("%d", &editId);
	
	
	for ( z=0;z <=ptnum;z++)
	{
		if(editId==patient_list[z].id)
		{
			 exist =1;
			 break;
		}
	}	
	
	if(exist ==1)
	{
			printf("to edit your name enter 1 \n");
			printf("to edit your age enter 2 \n");
			printf("to edit your gender enter 3 \n");
			scanf("%d", &choice);
			if (choice==1)
			{
				printf("\nYour new name : ");
				scanf("%s", &patient_list[z].name);
			}	
			if (choice==2)
			{
				printf("\nYour new age : ");
				scanf("%d", &patient_list[z].age);
			}			
			if (choice==3)
			{
				printf("\nYour new gender : ");
				scanf("%d", &patient_list[z].gender);			
			}
		
	}
	
	if (exist ==0)
	{
		printf("Id doesnot exist");
	}

}

void avaliable_slots()																								//show available slots function
    {
 		if(slot1==0)
		{
				printf("To reserve from 2 To 2:30 enter 1 \n");
		}
		 if(slot2==0)
		{
			printf("To reserve from 2:30 To 3 enter 2 \n");
		}
		 if(slot3==0)
		{
				printf("To reserve from 3 To 3:30 enter 3 \n");
		}
		 if(slot4==0)
		{
			printf("To reserve from 4 To 4:30 enter 4 \n");
		}
	    if(slot5==0)
		{
		printf("To reserve from 4:30 To 5 enter 5 \n\n");
		}
	}




void Patient_Slot(){																																	//to have a slot function
	u16 id;
	u8 choice;
	printf("Please enter the patient ID : \n");
	scanf("%d",&id);
	
	for(u8 i =0 ;i<ptnum;i++)
	{
		if(id ==patient_list[i].id)
		{
			avaliable_slots();
			printf("Please enter the slot you want to reserve : \n");
			scanf("%d", &choice);
			patient_list[i].slot=choice;
			switch(choice)
			{
			case 1 :
							slot1=1;
							break;
			case 2 :
							slot2=2;
							break;
			case 3 :
							slot3=3;
							break;
			case 4 :
							slot4=4;
							break;
			case 5 :
							slot5=5;
							break;
			}
		}
		
		
	}

}

void Cancel_reservation()																											//to cancel a reservation function
{
	
	 u16 id;
	printf("Please enter the Patient ID : \n");
	scanf("%d", &id);
	for(u8 i;i< ptnum;i++)
	{
	    if(id == patient_list[i].id)
		{
				switch(patient_list[i].slot)
					{
						case 1: patient_list[i].slot=0; slot1=0; break;
						case 2: patient_list[i].slot=0; slot2=0; break;
						case 3: patient_list[i].slot=0; slot3=0; break;
						case 4: patient_list[i].slot=0; slot4=0; break;
						case 5: patient_list[i].slot=0; slot5=0; break;
		
					}
		}	
	}	
}

void viewptrecord()																														//view record Patient function
{																	
	u16 id;
	u8 exist =0;
	u8 i=0
	printf("Please enter the patient ID : \n");
	scanf("%d", &id);
	for ( i=0;i <ptnum;i++)
	{
		if(id==patient_list[i].id)
		{
			
			printf("\nPatient name : %s",patient_list[i].name );
			
			printf("\nnPatient age : %d",patient_list[i].age);
			
			printf("\nPatient gender : %s",patient_list[i].gender);
			printf("\nPatient slot number : %d\n",patient_list[i].slot);
			exist = 1;
		}
	}
	
	if (exist ==0)
	{
		printf("id doesnot exist\n");
	}

}
void Display_reservations()																										//showing reservations
{
	u16 x=1;
	for(u8 i=0;i<ptnum;i++)
	{
		if(patient_list[i].slot!=0)
		{
			switch(patient_list[i].slot)
			{
				case 1: 
				printf("Patient ID : %d have reservation : 2 to 2:30\n",patient_list[i].id);break;
			
				case 2: 
				printf("Patient ID : %d have reservation : 2:30 to 3\n",patient_list[i].id);break;
				case 3: 
				printf("Patient ID : %d have reservation : 3 to 3:30\n",patient_list[i].id);break;
				case 4: 
				printf("Patient ID : %d have reservation : 4 to 4:30\n",patient_list[i].id);break;
				case 5: 
				printf("Patient ID : %d have reservation : 4:30 to 5\n",patient_list[i].id);break;
				
			
			
			}
		}
	}

}
						