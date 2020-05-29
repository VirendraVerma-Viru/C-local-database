
#include<stdio.h>
#include<conio.h>
# include <string.h>
#include<windows.h>
#include<stdlib.h>

void Insert_New_Data();
void Reading_Data();
void Delete_All_Data();
void Edit_Student_Detail();
void gotoxy(int x,int y);
void clrscr();
//files variables
FILE *fp ;
char data[10000];
int l,i;
//getting number of insertion in library
int n;int infinite_loop=1;



void main()
{

    int choice;

    while(infinite_loop>0)
    {
      printf("Enter you choice");
    printf("\nPress 1 to Insert Data");
    printf("\nPress 2 to Read Data");
    printf("\nPress 3 to Edit Student Detail");
    printf("\nPress 4 to Delete All Data");
    printf("\nPress 5 to Exit\n");
    scanf("%d",&choice);
    clrscr();
    switch(choice)
    {
        case 1: Insert_New_Data();break;
        case 2: Reading_Data();break;
        case 3: Edit_Student_Detail();break;
        case 4: Delete_All_Data();break;
        case 5: infinite_loop=0;break;
        default : printf("Error");
    }
    clrscr();
    }


}
void Insert_New_Data()
{

    char Pno_Insert[15];
    char Name_Insert[60];
    char Roll_no_Insert[15];
    char atten_Insert[10];
    char data[1000];
    int i,j,count=0;

    printf("\n");
    printf("Insert Number of More Student - ");
    scanf("%d",&n);
    printf("\n \t \t \t\t\t\t\t Use underscore instead of space\n\n");
    //-----------------------getting data from user
  for(i=0;i<n;i++)
    {
        count=0;
        printf("Enter student details of Student %d",i+1);
        printf("\n");

        printf("\n Name - ");
        scanf("%s",Name_Insert);
        printf("\n Roll Number - ");
        scanf("%s",Roll_no_Insert);
        printf("\n Attendence - ");
        scanf("%s",atten_Insert);
        printf("\n Phone Number - ");
        scanf("%s",Pno_Insert);
        printf("\n\n");

        fp = fopen( "att.txt", "a" ) ;
         if ( fp == NULL )
         {
                 printf( "Could not open file att.text\n" ) ;

         }
       //  printf( "Reading the file test.c\n" ) ;
       for(j=0;j<strlen(Pno_Insert);j++)
       {
           data[count]=Pno_Insert[j];
           count++;
       }
       data[count]='<';
       count++;

       for(j=0;j<strlen(Name_Insert);j++)
       {
           if(Name_Insert[j]=='_')
           {
               data[count]=' ';
           }
           else
           data[count]=Name_Insert[j];
           count++;
       }
       data[count]='>';
       count++;

       for(j=0;j<strlen(Roll_no_Insert);j++)
       {
           data[count]=Roll_no_Insert[j];
           count++;
       }
       data[count]=':';
       count++;

       for(j=0;j<strlen(atten_Insert);j++)
       {
           data[count]=atten_Insert[j];
           count++;
       }
       data[count]=';';
       count++;


         fputs ( data, fp );

         fclose(fp);


    }

printf("Data Updated");

}


void Reading_Data()
{

    char Pno[100][15];
    char temp_Pno[15];
    char Name[100][50];
    char temp_name[50];
    char Roll_no[100][15];
    char temp_roll[15];
    char atten_string[100][10];
    char temp_atten[10];
    double atten[100];

    int t_Pno=1,t_name=0,t_roll=0,t_atten=0,count=0,c=0,j;

   fp = fopen( "att.txt", "r" ) ;
         if ( fp == NULL )
         {
                 printf( "Could not open file att.text\n" ) ;

         }
       //  printf( "Reading the file test.c\n" ) ;
         fgets ( data,1000, fp );
         l=strlen(data);//calculation length

        //printf("Pno  Name               Attendence");


        for(i=0;i<l;i++)
        {

            if(data[i]=='<')
            {
                data[i]=' ';
                t_Pno=0;
                t_name=1;
                c=0;
                strcpy(Pno[count],temp_Pno);
                for(j=0;j<strlen(temp_Pno);j++)
                {
                    temp_Pno[j]=' ';
                }
            }
            else if(data[i]=='>')
            {
                data[i]=' ';
                t_name=0;
                t_roll=1;
                c=0;
            strcpy(Name[count],temp_name);
            for(j=0;j<strlen(temp_name);j++)
                {
                    temp_name[j]=' ';
                }
            }
            else if(data[i]==':')
            {
                data[i]=' ';
                t_roll=0;
                t_atten=1;
                c=0;
                strcpy(Roll_no[count],temp_roll);
                for(j=0;j<strlen(temp_roll);j++)
                {
                    temp_roll[j]=' ';
                }
            }
            else if(data[i]==';')
            {
                data[i]=' ';
                t_atten=0;
                t_Pno=1;
                c=0;
            strcpy(atten_string[count],temp_atten);

            atten[count]=atof(temp_atten);
            for(j=0;j<strlen(temp_atten);j++)
                {
                    temp_atten[j]=' ';
                }
                count++;
            }

            if(t_Pno>0)
            {
                temp_Pno[c]=data[i];
                c++;
            }
            else if(t_name>0)
            {
                temp_name[c]=data[i];
                c++;
            }
            else if(t_roll>0)
            {
               temp_roll[c]=data[i];
                c++;
            }
            else if(t_atten>0)
            {
                temp_atten[c]=data[i];
                c++;
            }
        }

        for(i=0;i<count;i++)
        {
            for(j=0;j<count-1-i;j++)
            {
                if(atten[j+1]>atten[j])
                {
                    float temp1=atten[j];
                    atten[j]=atten[j+1];
                    atten[j+1]=temp1;

                    char temp2[100];
                    strcpy(temp2,Pno[j]);
                    strcpy(Pno[j],Pno[j+1]);
                    strcpy(Pno[j+1],temp2);

                    char temp3[100];
                    strcpy(temp3,Name[j]);
                    strcpy(Name[j],Name[j+1]);
                    strcpy(Name[j+1],temp3);

                    char temp4[100];
                    strcpy(temp4,Roll_no[j]);
                    strcpy(Roll_no[j],Roll_no[j+1]);
                    strcpy(Roll_no[j+1],temp4);
                }
            }
        }
        printf("\n\n");

        gotoxy(1,2);printf("Pno");gotoxy(5,2);printf("Name");gotoxy(49,2);printf("Phone No.");gotoxy(60,2);printf("Roll Number");gotoxy(75,2);printf("Attendence");
        //printf("    Pno          Name                                     Roll Number                                   Attendence");
        printf("\n\n");
        for(i=0;i<count;i++)
        {
            gotoxy(2,i+3);printf("%d",i+1);gotoxy(4,i+3);printf("%s",Name[i]);gotoxy(49,i+3);printf("%s",Pno[i]);gotoxy(60,i+3);printf("%s",Roll_no[i]);gotoxy(75,i+3);printf("%f",atten[i]);
            //printf("    %s        %s                            %s                                    %f",Pno[i],Name[i],Roll_no[i],atten[i]);
            //printf("\n");
        }

     fclose(fp) ;
     getch();

}

void Edit_Student_Detail()
{
    char Per_Student_detail[1000][500];
    char temp_Per_Student_detail[500];
    int number_of_students=0;int c=0;
    char rollNo_to_edit[15];int j,i;int trigger=0;int flag=0;int l,k;
    char temp_detail[200];int match_Student=0;int counter=0;


    //editting variables
    char Temp_Name[100];
    char Temp_PhoneNo[15];
    char Temp_RollNo[15];
    char Temp_Attendence[10];

    fp = fopen( "att.txt", "r" ) ;
         if ( fp == NULL )
         {
                 printf( "Could not open file att.text\n" ) ;

         }
       //  printf( "Reading the file att.text\n" ) ;
         fgets ( data,10000, fp );
         l=strlen(data);
        fclose(fp) ;


        fp = fopen( "att.txt", "w" ) ;
         if ( fp == NULL )
         {
                 printf( "Could not open file att.text\n" ) ;

         }
       //  printf( "Writting the file att.text\n" ) ;




         //---------------------storing per student data in an array----------
       for(i=0;i<l;i++)
         {
             if(data[i]!=';')
             {
                 temp_Per_Student_detail[c]=data[i];
                 c++;
             }
             else{
                  strcpy(Per_Student_detail[number_of_students],temp_Per_Student_detail);
                number_of_students++;
                c=0;
                for(j=0;j<strlen(temp_Per_Student_detail);j++)
                {
                    temp_Per_Student_detail[j]=' ';
                }
             }
         }

         //----------------------------getting roll number from user to edit----

         printf("Enter Student Roll Number to Edit\n\n");
         scanf("%s",rollNo_to_edit);
         int temp_len=strlen(rollNo_to_edit);
        rollNo_to_edit[temp_len]=':';
       // puts(rollNo_to_edit);

         //----------------------------cheaking roll number----------

        for(i=0;i<number_of_students;i++)
        {
            counter=0;
            flag=0;
            strcpy(temp_Per_Student_detail,Per_Student_detail[i]);
            for(j=0;j<strlen(temp_Per_Student_detail);j++)
            {
                if(temp_Per_Student_detail[j]=='>')
                {
                    trigger=1;
                }
                else if(temp_Per_Student_detail[j]==':')
                {
                    trigger=0;
                }

                if(trigger>0)
                {
                    if(temp_Per_Student_detail[j+1]==rollNo_to_edit[counter])
                    {

                        flag=1;

                    }
                    else{

                        trigger=0;
                        flag=0;
                    }
                    counter++;
                }
            }
            if(flag==1)
            {
                match_Student++;
                printf("\n Match Found\n");
                printf("Phone No. - ");
                for(j=0;j<strlen(temp_Per_Student_detail);j++)
                {
                    if(temp_Per_Student_detail[j]=='<')
                    {
                        printf("  ");
                        printf("Name - ");
                        temp_Per_Student_detail[j]=' ';
                    }
                   else if(temp_Per_Student_detail[j]=='>')
                    {
                        printf("  ");
                        printf("Roll Number - ");
                        temp_Per_Student_detail[j]=' ';
                    }
                    else if(temp_Per_Student_detail[j]==':')
                    {
                        printf("  ");
                        printf("Attendence - ");
                        temp_Per_Student_detail[j]=' ';
                        printf("\n");
                    }
                    printf("%c",temp_Per_Student_detail[j]);
                }
                printf("\n                               Use Underscore instead of space\n");
                printf("\n Name - > ");
                scanf("%s",Temp_Name);
                printf("\n Roll No - > ");
                scanf("%s",Temp_RollNo);
                printf("\n Phone No - > ");
                scanf("%s",Temp_PhoneNo);
                printf("\n Attendence - > ");
                scanf("%s",Temp_Attendence);

                //----------------filling blank space in temp_Per_Student_detail variable array jisse undesired value na aaye
                for(j=0;j<strlen(temp_Per_Student_detail);j++)
                {
                    temp_Per_Student_detail[j]=' ';
                }
                counter=0;



                for(j=0;j<strlen(Temp_PhoneNo);j++)
                {
                    temp_Per_Student_detail[counter]=Temp_PhoneNo[j];
                    counter++;
                }
                temp_Per_Student_detail[counter]='<';
                counter++;

                for(j=0;j<strlen(Temp_Name);j++)
                {
                    if(Temp_Name[j]=='_')
                    {
                      Temp_Name[j]=' ';
                    }
                    temp_Per_Student_detail[counter]=Temp_Name[j];
                    counter++;
                }
                temp_Per_Student_detail[counter]='>';
                counter++;

                for(j=0;j<strlen(Temp_RollNo);j++)
                {
                    temp_Per_Student_detail[counter]=Temp_RollNo[j];
                    counter++;
                }
                temp_Per_Student_detail[counter]=':';
                counter++;

                for(j=0;j<strlen(Temp_Attendence);j++)
                {
                    temp_Per_Student_detail[counter]=Temp_Attendence[j];
                    counter++;
                }

                strcpy(Per_Student_detail[i],temp_Per_Student_detail);
                counter=0;
                for(j=0;j<strlen(data);j++)
                {
                    data[j]=' ';
                }

                for(j=0;j<number_of_students;j++)
                {
                    strcpy(temp_Per_Student_detail,Per_Student_detail[j]);
                    for(k=0;k<strlen(temp_Per_Student_detail);k++)
                    {
                        data[counter]=temp_Per_Student_detail[k];
                        counter++;
                    }
                    data[counter]=';';
                    counter++;
                }
                //puts(data);
                fputs ( data, fp );
                printf("Data Updated");

            }


                for(j=0;j<strlen(temp_Per_Student_detail);j++)
                {
                    temp_Per_Student_detail[j]=' ';
                }
        }
if(!match_Student)
    printf("\n Roll Number Not Found");



          getch();
         fclose(fp) ;
}

void Delete_All_Data()
{

    fp = fopen( "att.txt", "w" ) ;
         if ( fp == NULL )
         {
                 printf( "Could not open file att.text\n" ) ;

         }
         data[1]=" ";
         fputs ( data, fp );
         fclose(fp) ;
         printf("\n Data Cleared");
         getch();
}


void gotoxy(int b,int v)
{
    COORD c;
    c.X=b;
    c.Y=v;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}

void clrscr()
{
    system("cls");
}
