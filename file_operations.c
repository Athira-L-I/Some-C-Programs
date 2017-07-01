#include<stdio.h>
#include<stdlib.h>
struct rec
{	int rno;
	char name[20];
	int marks[3];
}s;
FILE *fp, *fq;
void add(); void search(); void deleterec(); void display();
main()
{
  int i, ch;
  do{
	printf("*****************Student records*******************\n MENU:\n ");
	printf("\t 1. Add record \t 2. Search for a record\n");
	printf("\t 3. Delete a record \t 4. Display all records\n");
	scanf("%d", &i);
	switch(i)
	{	case 1: add(); break;
		case 2: search(); break;
		case 3: deleterec(); break;
		case 4: display(); break;
		default: printf("\n \tWrong input"); break;
	}
    printf("\n Do you want to continue? (1-Yes/2-No)");
    scanf("%d", &ch);
  }while(ch==1);
}

void add()
{ 	fp=fopen("st_recs.txt", "a");
	int i, c;
do
{	printf("\n Enter rollno: "); 	scanf("%d", &s.rno);
	printf("\n Enter name: "); 		scanf("%s", s.name);
	printf("\n Enter marks in 3 subjects: ");
	for(i=0; i<3; i++)
	  scanf("%d", &s.marks[i]);
	  
	fprintf(fp, "\n %d %s %d %d %d", s.rno, s.name, s.marks[0], s.marks[1], s.marks[2]);
	printf("\nDo you want to enter more records? (1-Yes/2-No) ");
	scanf("%d", &c);
}while(c==1);
fclose(fp);
}

void search()
{
	int rn, found=0;
	fp=fopen("st_recs.txt", "r");
	if(fp==NULL)
		printf("\n\tSource file can't be opened"); exit(0);
	
	printf("\nEnter the rollno. to be searched for: ");
	scanf("%d", &rn);
	while(!feof(fp))
	{
		fscanf(fp, "%d %s %d %d %d", &s.rno, s.name, &s.marks[0], &s.marks[1], &s.marks[2]);
		if(rn==s.rno)
		{	printf("\n \t Record found!\n");
			printf("\n %d  %s  %d %d %d", s.rno, s.name, s.marks[0], s.marks[1], s.marks[2]);
			found++;
			break;
		}
	}
	if(!found)
	printf("\n \tFile not found!");
	fclose(fp);
}

void display()
{
	fp=fopen("st_recs.txt", "r");
	int i=0;
	if(fp==NULL)
		printf("\n\t Source file can't be opened"); exit(0);
	
	while(!feof(fp))
	{
		fscanf(fp, "\n %d %s %d %d %d", &s.rno, s.name, &s.marks[0], &s.marks[1], &s.marks[2]);
		printf("\n %d  %s  %d %d %d", s.rno, s.name, s.marks[0], s.marks[1], s.marks[2]);
		i++;
	}
	printf("\n\n\t %d records", i);
	fclose(fp);
}

void deleterec()
{
	int rn, confirm, found=0;
	fp=fopen("st_recs.txt", "r");
	fq=fopen("temp.txt", "w");
	if((fp==NULL)||(fq==NULL))
		{printf("\nSource file(s) can't be opened"); exit(0);}
	
	printf("\nEnter the rollno. whose record is to be deleted: ");
	scanf("%d", &rn);
	
	while(!feof(fp))
	{
		fscanf(fp, "%d %s %d %d %d", &s.rno, s.name, &s.marks[0], &s.marks[1], &s.marks[2]);
		if(rn!=s.rno)
			fprintf(fq, "\n %d %s %d %d %d", s.rno, s.name, s.marks[0], s.marks[1], s.marks[2]);			  
		else
		{
			printf("\n %d  %s  %d %d %d", s.rno, s.name, s.marks[0], s.marks[1], s.marks[2]);
			found++;
			printf("\n\n Enter 1 to confirm deletion, 0 to cancel deletion");
			scanf("%d", &confirm);
			if(confirm==0)
			{
				fprintf(fq, "\n %d %s %d %d %d", s.rno, s.name, s.marks[0], s.marks[1], s.marks[2]);
				printf("\n\t Deletion cancelled!");	
			}
			else
				printf("\n\t Record deleted!"); 
		}			
	}
	
	if(!found)
		printf("\n\t Record not found!");
	fclose(fp);
	fclose(fq);
	remove("st_recs.txt");
	rename("temp.txt", "st_recs.txt");
}
/*OUTPUT:

*****************Student records************************
 MENU:
         1. Add record   		2. Search for a record
         3. Delete a record      4. Display all records
1
 Enter rollno: 1
 Enter name: aatmaj
 Enter marks in 3 subjects: 1
2
3
Do you want to enter more records? (1-Yes/2-No) 1
 Enter rollno: 2
 Enter name: aayina
 Enter marks in 3 subjects: 1
2
3
Do you want to enter more records? (1-Yes/2-No) 1
 Enter rollno: 3
 Enter name: abhishek
 Enter marks in 3 subjects: 1
2
3
Do you want to enter more records? (1-Yes/2-No) 1
 Enter rollno: 4
 Enter name: abin
 Enter marks in 3 subjects: 1
2
3
Do you want to enter more records? (1-Yes/2-No) 2

	Do you want to continue? (1-Yes/2-No)1
*****************Student records************************
 MENU:
         1. Add record   2. Search for a record
         3. Delete a record      4. Display all records
4
 1  aatmaj  1 2 3
 2  aayina  1 2 3
 3  abhishek  1 2 3
 4  abin  1 2 3
         4 records
		 
	Do you want to continue? (1-Yes/2-No)1
*****************Student records************************
 MENU:
         1. Add record   2. Search for a record
         3. Delete a record      4. Display all records
2
Enter the rollno. to be searched for: 4
         Record found!
 4  abin  1 2 3
 Do you want to continue? (1-Yes/2-No)1
 
*****************Student records************************
 MENU:
         1. Add record   2. Search for a record
         3. Delete a record      4. Display all records
3
Enter the rollno. whose record is to be deleted: 3
 3  abhishek  1 2 3
 Enter 1 to confirm deletion, 0 to cancel deletion  1
         Record deleted!
 Do you want to continue? (1-Yes/2-No)1
 
*****************Student records************************
 MENU:
         1. Add record   2. Search for a record
         3. Delete a record      4. Display all records
4
 1  aatmaj  1 2 3
 2  aayina  1 2 3
 4  abin  1 2 3
 
         3 records
 Do you want to continue? (1-Yes/2-No)2

*/
