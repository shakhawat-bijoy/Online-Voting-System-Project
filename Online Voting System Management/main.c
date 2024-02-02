#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

typedef struct voter_information
{
    char nid[20];
    char name[50];
    char birth_date[15];
    struct voter_information *next;
} node;

node *head;
node *space,*start=NULL;
node *search(char x[],char y[],char z[],node *,int *);
node *voter_insert(node *);
node *main_logs(node *);
 void admin();
 void winner();
 	void exi();
 	void voting();
 	void not_again();
 	void stop();
 	void show();
 	void showVoterList();


int count=0,R=3,vote=0;
int vote1=0,vote2=0,vote3=0,vote4=0,vote5=0;
int main()
{
	while(1){

    system("cls");
    printf("\n\n\n");
    printf("\t            ****** WELCOME TO THE ONLINE VOTING PORTAL ******        \n\n");

    printf("\t           ***************************************************        \n\n\n\n\n");
    printf("        \t\t *****Please Enter One(1) for logging vote main Logs*****    \n\n\n");
    int BB;

    scanf("%d",&BB);
    if(BB==1)
    {
      start=  main_logs(start);
    }

}
    return 0;
}

node *main_logs(node *start)
{
    system("cls");
    printf("\n\n\n");
    printf("        \t\t\t1. FOR VOTE ENTRY     \n");
    Sleep(300);
     printf("        \t\t\t2. FOR VOTER LIST     \n");
    Sleep(300);
    printf("        \t\t\t3. FOR ADMIN PANEL    \n");
    Sleep(300);
    printf("        \t\t\t4. FOR WINNER         \n");
    printf("    \t IF YOUR CREDENTIALS MATCHES WITH THOSE IN THE VOTER LIST THEN ONLY YOU CAN GIVE YOUR VOTE OTHERWISE YOU CAN NOT    \n\n\n");
    Sleep(500);
    printf("    \t ********So Please Enter********\n\n\n");
    int T;
    scanf("%d",&T);
    if(T==1)
    {
       start= voter_insert(start);
    }
    if(T==2)
    {
      voterlist();
    }
    if(T==3)
    {
      admin();
    }
    if(T==4)
    {
        winner();
    }
    if(T!=1||T!=2||T!=3||T!=4)
    {
    	main_logs(start);
	}


    return start;
}


node *voter_insert(node *start)
{
	int UNIVERSAL=0;
int *z;
 z = &UNIVERSAL;
     node *temp;
     char name[50],birth_date[15],nid[20];
     system("cls");
     printf("\n\n\n\n");
     printf("\t IF NID ID, YOUR NAME AND YOUR DATE OF BIRTH MATCHES THEN YOU CAN GIVE YOUR VOTE OTHERWISE NOT\n\n");
     Sleep(300);
     printf("\t\t\t ID YOU DO WRONG %d TIMES, THE PORTAL WILL BE CLOSED AUTOMATICALLY\n\n\n",R);
     Sleep(300);
     printf("\t\tPlease \n");
     Sleep(300);
     printf("\t\t\tEnter your NID ID number  ");
     gets(nid);
     gets(nid);
     printf("\t\t\tEnter Your NAME   ");
     gets(name);
     printf("\t\t\tEnter Your BIRTH DATE  in dd-mm-yyyy format");
     gets(birth_date);
     temp=(node *)malloc(sizeof(node));
     strcpy(temp->nid,nid);
     strcpy(temp->name,name);
     strcpy(temp->birth_date,birth_date);
     temp->next=NULL;
     head=temp;
     while(temp!=NULL)
     {
         if((strcmp(temp->nid,"10001")==0&& strcmp(temp->name,"Meraj")==0 &&strcmp(temp->birth_date,"01-01-2001")==0) ||
         (strcmp(temp->nid,"10002")==0&& strcmp(temp->name,"Rabbi")==0 &&strcmp(temp->birth_date,"01-01-2001")==0)||
         (strcmp(temp->nid,"10003")==0&& strcmp(temp->name,"Jisan")==0 &&strcmp(temp->birth_date,"01-01-2001")==0)||
         (strcmp(temp->nid,"10004")==0&& strcmp(temp->name,"Sraban")==0 &&strcmp(temp->birth_date,"01-01-2001")==0)||
         (strcmp(temp->nid,"10005")==0&& strcmp(temp->name,"Shafin")==0 &&strcmp(temp->birth_date,"01-01-2001")==0)||
         (strcmp(temp->nid,"10006")==0&& strcmp(temp->name,"Innaya")==0 &&strcmp(temp->birth_date,"01-01-2001")==0)||
         (strcmp(temp->nid,"10007")==0&& strcmp(temp->name,"Anika")==0 &&strcmp(temp->birth_date,"01-01-2001")==0)||
         (strcmp(temp->nid,"10008")==0&& strcmp(temp->name,"Khadiza")==0 &&strcmp(temp->birth_date,"01-01-2001")==0)||
         (strcmp(temp->nid,"10009")==0&& strcmp(temp->name,"Mim")==0 &&strcmp(temp->birth_date,"01-01-2001")==0)||
         (strcmp(temp->nid,"10010")==0&& strcmp(temp->name,"Jerin")==0 &&strcmp(temp->birth_date,"01-01-2001")==0))

         {
         	R=3;
         	start=search(temp->nid,temp->name,temp->birth_date,start,&UNIVERSAL);

         	if(UNIVERSAL==0)
            {
            	 voting();
			}
            else
             {
             	not_again();
			 }
           }
         else
            {
              R--;
         if(R==0)
         {
             stop();
             break;
         }
         printf("\n\n\n\n");
         printf("\tYour National ID or NAME or DATE OF BIRTH is wrong\n\n");
         Sleep(300);
         printf("\t\t\tPlz Re-Enter\n\n");
         Sleep(300);
         system("pause");
        start= main_logs(start);
            }
            temp=temp->next;
     }
     return start;
}


void voting()
{
     system("cls");
    printf("\n\n\n\n");
    printf("\t\t     * * * * * LIST OF CANDIDATES * * * * * \n\n\n");
    Sleep(300);
    printf("\t\t\t NAME     & THEIR RESPECTIVE      SYMBOL\n\n");
    Sleep(300);
    printf("\t\t\t 1.Md Tousif Hasan Lavlu                      1.Fish\n");
    Sleep(300);
    printf("\t\t\t 2.Sazzad Hossain Bhuyan                      2.Car\n");
    Sleep(300);
    printf("\t\t\t 3.Sakhhor Das                                3.Motorcycle\n");
    Sleep(300);
    printf("\t\t\t 4.Ahmed Nokib Mozumder                       4.Broomstick\n");
    Sleep(300);
    printf("\t\t\t 5.Sabrina Mannan                             5.Wheel\n\n\n");



       int B,j;
       printf("\t\t\t Plzz, \n");
       printf("\t\t\t Enter Your Choice \n");
       for(j=1;j<=1;j++)
       {
           scanf("%d",&B);

           if(B==1)
           {
               vote1++;
               printf("\n\n\t\t\t\tYOU HAVE SUCCESSFULLY GIVEN YOUR VOTE TO Md Tousif Hasan Lavlu\n");
               break;

           }
           if(B==2)
           {
               vote2++;
                printf("\n\n\t\t\t\tYOU HAVE SUCCESSFULLY GIVEN YOUR VOTE TO Sazzad Hossain Bhuyan\n");
               break;

           }
           if(B==3)
           {
               vote3++;
                printf("\n\n\t\t\t\tYOU HAVE SUCCESSFULLY GIVEN YOUR VOTE TO Sakhhor Das\n");
               break;

           }
           if(B==4)
           {
               vote4++;
                printf("\n\n\t\t\t\tYOU HAVE SUCCESSFULLY GIVEN YOUR VOTE TO Ahmed Nokib Mozumder\n");
               break;
           }
           if(B==5)
           {
               vote5++;
                printf("\n\n\t\t\t\tYOU HAVE SUCCESSFULLY GIVEN YOUR VOTE TO Sabrina Mannan\n");
               break;
           }
            if(B!=1||B!=2||B!=3||B!=4||B!=5)
           {
           	printf("\n\t\t************* INVALID CHOICE ENTERED**************\t\t\n");
           	printf("\n\t\t\tENTER AGAIN\t\t\t\n");
		   }



       }
	   printf("\n\n**************************THANK YOU***************************\n\n");
	   printf("press any key");
	   getch();
}


void admin() {
    int B;
    printf("\n\n\n\n");
    printf("\t\t\t\t\tEnter Your Password To Unlock The Admin Panel\n\n");
         scanf("%d",&B);
     if(B==3692)
     {
         show();
         //showVoterList();
     }
     else
     {
         printf("Wrong Password\n");
     }

}

void voterlist()
{
       int V;
    printf("\n\n\n\n");
    printf("\t\t\t\t\tEnter Your Password To Show The Voter List \n\n");
         scanf("%d",&V);
     if(V==5656)
     {
         //show();
         showVoterList();
     }
     else
     {
         printf("Wrong Password\n");
     }
}

  void show()
  {
  	int G;
      system("cls");

      printf("\n\n\n\n");
      printf("\t\t\tPresent Vote Count :\n\n");
      Sleep(500);
      printf("\t\t\t  Md Tousif Hasan Lavlu is on       %d Votes\n",vote1);
      Sleep(500);
      printf("\t\t\t  Sazzad Hossain Bhuyan is on       %d Votes\n",vote2);
      Sleep(500);
      printf("\t\t\t  Sakhhor Das is on                 %d Votes\n",vote3);
      Sleep(500);
      printf("\t\t\t  Ahmed Nokib Mozumder  is on       %d Votes\n",vote4);
      Sleep(500);
      printf("\t\t\t  Sabrina Mannan  is on             %d Votes\n\n\n\n",vote5);
      Sleep(500);
	  
        printf("\t\t\t\tEnter Any Key for Main Log\n\n");
        getch();
        main_logs(start);


  }

   void winner()
   {
       system("cls");
       printf("\n\n\n\n");
       if(vote2<vote1 && vote3< vote1 && vote4<vote1 && vote5<vote1)
        printf("\t\t\tThe present Winner is Md Tousif Hasan Lavlu and he has got %d votes\n\n\n\n",vote1);

       if(vote1<vote2 && vote3< vote2 && vote4<vote2 && vote5<vote2)
        printf("\t\t\tThe present Winner is Sazzad Hossain Bhuyan and he has got %d votes\n\n\n\n",vote2);

        if(vote1<vote3 && vote2< vote3 && vote4<vote3 && vote5<vote3)
        printf("\t\t\tThe present Winner is Sakhhor Das and he has got %d votes\n\n\n\n",vote3);

        if(vote1<vote4 && vote2< vote4 && vote3<vote4 && vote5<vote4)
        printf("\t\t\tThe present Winner is Ahmed Nokib Mozumder and he has got %d votes\n\n\n\n",vote4);

        if(vote1<vote5 && vote2< vote5 && vote3<vote5 && vote4<vote5)
        printf("\t\t\tThe present Winner is Sabrina Mannan and she has got %d votes\n\n\n\n",vote5);

    printf("\t\t\t\t\tEnter Any Key For Main Logs\n\n\t\t\t\t\t\t\tOR\n\n\t\t\t\t\tENTER THE SPECIAL PASSWORD TO CLOSING VOTING PORTAL\n ");
    scanf("%d",&G);
    if(G==1234)
    exi();
    else
    main_logs(start);

   }

   void stop()
   {
       system("cls");

       printf("\n\n\n\n");
       printf("\t\t\t (:-SORRY YOU ENTERED WRONG CREDENTIALS FOR THREE(3) TIMES IN A ROW -:) \n\n\n");
       Sleep(500);
       printf("\t\t\t Please try again After A few Moment\n\n\n");
       Sleep(500);
       printf("\t\t\t * * *Thank You* * *  \n\n\n");
       Sleep(500);
       printf("press any key");
       getch();

   }

   void not_again()
   {
        int A;
		system("cls");
        printf("\n\n\n\n");
        printf("\t\t\t        ***YOU HAVE GIVEN YOUR VOTE SUCCESSFULLY***       \n\n\n");
        Sleep(300);
        printf("\t\t\t        ***YOU CANNOT GIVE YOUR VOTE MORE THAN ONCE***     \n\n\n");
        Sleep(300);
        printf("\t\t\t If You want to see present winner Enter One(1) or Enter Any Other Key for Main  Logs\n\n");
        Sleep(300);

        scanf("%d",&A);
        if(A==1)
        {
            winner();
        }
        else
        {
            main_logs(start);
        }

   }

   void exi()
   {
       system("cls");

       printf("\n\n\n\n\n");
       Sleep(500);
       printf("\t\t\t        ***YOU ARE NOW EXITING THE PORTAL***       \n\n\n");
       Sleep(1000);
       printf("\t\t\t * * *Thank You For Using This ONLINE PLATFORM For VOTING* * *  \n\n\n");
       Sleep(1000);
       exit(0);
   }

void showVoterList() {

    system("cls");
    printf("\n\n\n\n");
    printf("\t\t\t\t\t***Voter List***\n\n");
    Sleep(500);
    printf("\t\tName:           NID:              Date of birth:\n");
    Sleep(500);
    printf("\t\tMeraj           10001             01-01-2001\n");
    Sleep(500);
    printf("\t\tRabbi           10002             01-01-2001\n");
    Sleep(500);
    printf("\t\tJisan           10003             01-01-2001\n");
    Sleep(500);
    printf("\t\tSraban          10004             01-01-2001\n");
    Sleep(500);
    printf("\t\tShafin          10005             01-01-2001\n");
    Sleep(500);
    printf("\t\tInnaya          10006             01-01-2001\n");
    Sleep(500);
    printf("\t\tAnika           10007             01-01-2001\n");
    Sleep(500);
    printf("\t\tKhadiza         10008             01-01-2001\n");
    Sleep(500);
    printf("\t\tMim             10009             01-01-2001\n");
    Sleep(500);
    printf("\t\tJerin           10010             01-01-2001\n");
    Sleep(500);

    printf("\n\n\t\t\t\t\tEnter Any Key For Main Logs\n\n");
    getch();
    main_logs(start);
}

node *search(char x[],char y[],char z[],node *start,int *Y)
{
	 *Y=0;
  node *t,*space;
  if(start==NULL)
  {
      space=(node*)malloc(sizeof(node));
     strcpy(space->nid,x);
     strcpy(space->name,y);
     strcpy(space->birth_date,z);

      start=space;
      space->next=NULL;

  }
  else
  {
      t=start;
      while(t!=NULL)
       {
          if((strcmp(t->nid,x)==0&& strcmp(t->name,y)==0 &&strcmp(t->birth_date,z)==0))
          {
          	*Y=1;

          	break;
          }
              t=t->next;
    	}

          if(*Y==0)
          {

          	space=(node*)malloc(sizeof(node));

       		strcpy(space->nid,x);

       		strcpy(space->name,y);

       		strcpy(space->birth_date,z);
	        t=space;
    	    space->next=NULL;

    	}
  }
  return start;
 }
