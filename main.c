#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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



















// git remote add origin https://github.com/luciiifeer/Online-Voting-System-Data-Structure-Project.git
// git branch -M main
// git push -u origin main
