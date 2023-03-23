#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void mainmenu(void);
void ekit(void);
void ShowAllRecords(void);
void SearchPatient(void);
void NewPatient(void);                              // functions 
void deleterecord(void);
void updaterecord(void);
void searchid(void);
void searchname(void);
void searchsurname(void);

 struct patient{
	int id;
	char name[30];
	char surname[30];
    char birhday[30];
    char email[30];
    char departmant[30];
    }patient;



int main()
{
	printf("\t\t Welcome to the Hospital Management System\n\n\n ");
	
mainmenu();
	
	

	return 0;
}
void mainmenu()
{
	int islem;
	

	
	printf("\t\t\t\t0= exit\n");
	printf("\t\t\t\t1= show all records\n");
	printf("\t\t\t\t2= search patient\n");
	printf("\t\t\t\t3= new patient\n");
	printf("Please selecet an option:");
	scanf("%d",&islem);
	
	
	
	switch(islem){                               //option of the action we want to do
	
	  case 0: ekit();break;
	  case 1: ShowAllRecords();break;
	  case 2: SearchPatient();break;
	  case 3: NewPatient(); break;
	  default: printf("Please make right select\n"); mainmenu();
	}
	
}
void ekit(void)  // exit function
{
	printf("GOOD BYE");
}
 
 
void ShowAllRecords(void)
{ 
	int sec;	
	
	printf("\nPatient Records:\n\n");

	FILE*hasta;
hasta=fopen("hasta.txt","r");

	
	while(!feof(hasta))  //reads all patient information from the file
	{
		


		fscanf(hasta,"%d %s %s %s %s %s \n",&patient.id, patient.name, patient.surname, patient.birhday, patient.email, patient.departmant);
	printf("%d: %s || %s || %s || %s || %s",patient.id,patient.name,patient.surname, patient.birhday,patient.email,patient.departmant);
	printf("\n\n");
	
	}
	fclose(hasta);
printf("0: return to main menu | 1: delete record | 2: update record\n");
printf("Please selecet an option:");                 //option of the action we want to do
scanf("%d",&sec);
if(sec==0){
	mainmenu();
}
else if	(sec==1)
{
	deleterecord();
}
else if(sec==2)
{
	updaterecord();
}
else 
{
	printf("\nPlease make right select\n");
	ShowAllRecords();
}
}





void SearchPatient(void)   // patient search 
{
	
	int sec;
printf("0: return to main menu | 1: search by id | 2: search by name | 3: search by surname\n");
printf("Please selecet an option:   ");
scanf("%d",&sec);
if(sec==0){
	mainmenu();
}
else if	(sec==1)  
{
	searchid();
}
else if(sec==2)
{
  searchname();
}
else if(sec==3)
{
 searchsurname();
}
else 
{ 
printf(" Please selecet an option:\n");
SearchPatient();
}
}




void NewPatient(void)
{
	int a;
	FILE*hasta;
hasta=fopen("hasta.txt","r");
	
	while(!feof(hasta))
	{
		if(hasta==NULL)
		
		{
			a=0;
		
		break;
		}
		else 
		{
		
		fscanf(hasta,"  %d %s %s %s %s %s \n",&patient.id, patient.name, patient.surname, patient.birhday, patient.email, patient.departmant);
		
	
		
			a=patient.id;
		
	}
	
}
  
// this part is for id. 	firstly it read in text to the last person.  The id of the last person is equal to 'a'.  
  
fclose(hasta);
patient.id=a+1; // id 1 is increased. id of the next patient

char devam;

hasta=fopen("hasta.txt","a");  //file opens to add patients

patient.id;
printf(" Enter Name:");
scanf("%s",patient.name);
printf(" Entr Surname: ");
scanf("%s",patient.surname);
printf(" Enter Birthday: ");
scanf("%s",patient.birhday);
printf(" Enter Email: ");
scanf("%s",patient.email);
printf(" Enter Department: ");
scanf("%s",patient.departmant);

fprintf(hasta," %d %s %s %s %s %s \n", patient.id, patient.name, patient.surname, patient.birhday, patient.email, patient.departmant);

    
printf("\n New patient has been recorded...\n\n\n");
fclose(hasta);


printf("press to add 'Y'  ");     // for new patient
printf("press to main menu 'M' "); // for main menu
scanf("%s",&devam);

if(devam=='Y' || devam=='y')
{
	NewPatient();
}
else if(devam=='M'||devam=='m')
{
	printf("\n");
	mainmenu();
}
    
}


void deleterecord(void)   // for delete 
{
	int sil;
	printf("Select patient id to delete:\n");
	scanf("%d",&sil);
	
FILE*hasta;
FILE*hasta1;

hasta=fopen("hasta.txt","r");
hasta1=fopen("hasta1.txt","w");   // new file opens (hasta1)


while(!feof(hasta))
	{
			fscanf(hasta,"  %d %s %s %s %s %s \n",&patient.id, patient.name, patient.surname, patient.birhday, patient.email, patient.departmant);
	//patient information read
		if(sil!=patient.id){
		
	
    fprintf(hasta1," %d %s %s %s %s %s \n", patient.id, patient.name, patient.surname, patient.birhday, patient.email, patient.departmant);
         //Patient information other than the patient to be deleted is saved in the new file.
		 
		 }
         
    }


fclose(hasta);
fclose(hasta1);


hasta=fopen("hasta.txt","w");
hasta1=fopen("hasta1.txt","r");
while(!feof(hasta1))
		{
		
		fscanf(hasta1,"  %d %s %s %s %s %s \n",&patient.id, patient.name, patient.surname, patient.birhday, patient.email, patient.departmant);
       
	    fprintf(hasta," %d %s %s %s %s %s \n", patient.id, patient.name, patient.surname, patient.birhday, patient.email, patient.departmant);
 //saving to file hasta again
    }
fclose(hasta);
fclose(hasta1);
printf("\n\n");
printf ("Patient record is deleted...	\n");
printf("\n\n");
mainmenu();	
	
}


void updaterecord(void)
{
 
 int degis;
	printf("Select patient id to update:\n");
	scanf("%d",&degis);
	
FILE*hasta;
FILE*hasta2;

hasta=fopen("hasta.txt","r");
hasta2=fopen("hasta2.txt","w");  // new file opens (hasta2)

while(!feof(hasta))
	{
			fscanf(hasta,"  %d %s %s %s %s %s \n",&patient.id, patient.name, patient.surname, patient.birhday, patient.email, patient.departmant);
	//patient information read
		if(degis!=patient.id){
		
             fprintf(hasta2," %d %s %s %s %s %s \n", patient.id, patient.name, patient.surname, patient.birhday, patient.email, patient.departmant);
		//Patient information other than the patient to be deleted is saved in the new file (hasta2).
		
		}
		else if(degis==patient.id)
		{
			printf("Enter Name:(old name %s): ",patient.name);
			scanf("%s",patient.name);
			printf("Enter Surname:(old surname %s):  ",patient.surname);
            scanf("%s",patient.surname);
            printf("Enter Birthday:(old birthday %s):  ",patient.birhday);
            scanf("%s",patient.birhday);
            printf("Enter Email:(old email %s):  ",patient.email);
            scanf("%s",patient.email);
            printf("Enter Department:(old department %s): ",patient.departmant);
            scanf("%s",patient.departmant);
            
            fprintf(hasta2," %d %s %s %s %s %s \n", patient.id, patient.name, patient.surname, patient.birhday, patient.email, patient.departmant);
		
		//Patient information other than the patient to be deleted is saved in the new file.
		
		}
         
         
         
    }
fclose(hasta);
fclose(hasta2);

hasta=fopen("hasta.txt","w");
hasta2=fopen("hasta2.txt","r");
while(!feof(hasta2))
		{
		
		fscanf(hasta2,"  %d %s %s %s %s %s \n",&patient.id, patient.name, patient.surname, patient.birhday, patient.email, patient.departmant);
       
	    fprintf(hasta," %d %s %s %s %s %s \n", patient.id, patient.name, patient.surname, patient.birhday, patient.email, patient.departmant);
 //saving to file hasta again
    }
fclose(hasta);
fclose(hasta2);

printf("Patient record is update...\n");
	printf("\n");
	mainmenu();
	
	
	
	
}



void searchid(void)
{
	int sayi;
	FILE*hasta;
	hasta=fopen("hasta.txt","r"); 
	printf("Enter id:\n");
	scanf("%d",&sayi);
	while(!feof(hasta))
	{
		fscanf(hasta,"  %d %s %s %s %s %s \n",&patient.id, patient.name, patient.surname, patient.birhday, patient.email, patient.departmant);
	 // //patient information read
		if(patient.id==sayi) //if id is equal to what is called
		{
			printf(" %d %s || %s || %s || %s || %s",patient.id,patient.name,patient.surname, patient.birhday,patient.email,patient.departmant);
	        printf("\n");
			
		}
		
	
}
   
printf("\n");
fclose(hasta);
printf("\n");
mainmenu();
}



void searchname(void)
{
	int toplam,kimlik;
	char ad[30];
	FILE*hasta;
hasta=fopen("hasta.txt","r");
	
	printf(" Enter name:\n");
	scanf("%s",ad);
	while(!feof(hasta))
	{
		fscanf(hasta,"  %d %s %s %s %s %s \n",&patient.id, patient.name, patient.surname, patient.birhday, patient.email, patient.departmant);
		 //patient information read
		if(strcmp(patient.name,ad)==0) //if name is equal to what is called
		{
			printf(" %d %s || %s || %s || %s || %s",patient.id,patient.name,patient.surname, patient.birhday,patient.email,patient.departmant);
	        printf("\n");
	    
	kimlik=patient.id/patient.id;  // aranan isimde hasta varsa id/id yaparak o isimde 1 kiþi olduðunu tutarýz.
	toplam+=kimlik;                // total number of patients
		}
		
	
	}
	printf("\n");
printf(" %d Patient(s) are found...\n ",toplam);	
fclose(hasta);
printf("\n");	
mainmenu();	
}



void searchsurname(void)
{
	int kimlik,toplam;
		char soyad[30];
	FILE*hasta;
hasta=fopen("hasta.txt","r");
	
	printf(" Enter surname\n");
	scanf("%s",soyad);
	while(!feof(hasta))
	{
		fscanf(hasta,"%d  %s %s %s %s %s \n",&patient.id, patient.name, patient.surname, patient.birhday, patient.email, patient.departmant);
		//patient information read
		if(strcmp(patient.surname,soyad)==0)  //if surname is equal to what is called
		{
			printf(" %d %s || %s || %s || %s || %s", patient.id, patient.name,patient.surname, patient.birhday,patient.email,patient.departmant);
	        printf("\n");
	        
	        kimlik=patient.id/patient.id;
	        toplam+=kimlik;
		}
		
		

}
printf("\n");
printf(" %d Patient(s) are found... ",toplam);
fclose(hasta);
printf("\n");
mainmenu();


}

