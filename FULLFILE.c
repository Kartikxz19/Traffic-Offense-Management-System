#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//*****FUNCTION TO DISPLAY RECORDS**********
char firstname[20];
char lastname[20];
char vno[12];
char mno[10];
char dlno[20];
char add[50];
char vtype[10];
int date;
int month;
int year;
char stat[9];
int law_viol[10];
int sum;
char year_out[5];
char month_out[3];
char day_out[3];
char sum_out[7];

void DISPLAY_PENALTY()
{

    char temp[50];

    FILE *fe;

    fe=fopen("DATABASE.txt","r");
    if(fe==NULL)
    {
        printf("Cannot Open FIle!");
        exit(1);
    }

    char dID[16];
    char ch,chrec;
    char buff[17];
    int vehicle_type;
    int i=0;
    char s='Y';
    int countDID=0;
    int noc=0;
    int countDolla=0;
    while(s!='N'&&s!='n')
    {
        fseek(fe,0,SEEK_SET);
        printf("Enter The Driving License ID: ");
        fflush(stdin);
        gets(dID);

        //puts(dID);
        while(1)
        {
            fscanf(fe," %s %s %s %s %s %s %s %s %s %s %s %s",dlno,firstname,lastname,vno,vtype,mno,add,year_out,month_out,day_out,sum_out,stat);
            //printf("%s",dlno);

            if(strcmp(dlno,dID)==0)
            {

                countDID=1;
                printf("*************************************************");
                printf("\nName: %s %s",firstname,lastname);
                printf("\t\tDriving License ID: %s",dlno);
                printf("\nVehicle Number: %s",vno);
                printf("\tVehicle Type: %s",vtype);
                printf("\nMobile Number: %s",mno);
                printf("\tAddress: %s",add);
                printf("\nDate: %s/%s/%s",day_out,month_out,year_out);
                printf("\t\t\tTotal Fine: %s\n",sum_out);
                printf("STATUS = %s\n",stat);
                printf("************");
                printf("**********");
                printf("**************");
                printf("************\n");
                fseek(fe,0,SEEK_END);
                ch=fgetc(fe);
                if(ch==EOF)
                    break;
                else if(ch=='\n')
                    break;

            }
            fseek(fe,1,SEEK_CUR);
            ch=fgetc(fe);
            if(ch==EOF)
                break;
            fseek(fe,-1,SEEK_CUR);

        }
        if(countDID==0)
            printf("Driving License ID not found!");
        printf("To print another record,Press Y/N : ");
        countDID=0;
        fflush(stdin);
        scanf("%c",&s);

    }

    fclose(fe);
}
//**************************************************************
//********FUNCTION TO ENTER RECORDS*****************************
void ENTER_PENALTY()
{

    int del=1;
    char temp[10];

    FILE *fe;

    int i=0;
    sum=0;
    fe=fopen("DATABASE.txt","a");
    if(fe==NULL)
    {
        printf("Cannot Open FIle!");
        exit(1);
    }
    int choice;
    int vehicle_type;
    char s='Y';
    while(s!='N'&&s!='n')
    {
        printf("\nEnter 10-digit Mobile Number: ");
        scanf("%s",mno);


        printf("\n%s\n",mno);



        printf("Enter First Name: ");
        fflush(stdin);
        gets(firstname);
        printf("Enter Last Name: ");
        fflush(stdin);
        gets(lastname);
        printf("\nEnter Vehicle No.:   ");

        scanf("%s",vno);

        printf("\nEnter Driving License ID: ");
        fflush(stdin);
        gets(dlno);
        /*PRINTING THE VALUE OF DRIVING LICENSE ID
        printf("%s",dbms.dlno);*/


        printf("\n%s\n",mno);

        vehicle_type=0;

        while(vehicle_type==0)
        {
            printf("\nEnter Vehicle type:\nPress");
            printf("\n1-MC 50cc-Vehicles that have an engine capacity of 50cc or less than that.");
            printf("\n2-LMV-NT-Vehicles like jeep and motor cars fall under the Light Motor Vehicle Category but these are of non-transport class.");
            printf("\n3-FVG-Vehicles without gears fall under this category like scooters and mopeds.");
            printf("\n4-MC EX50CC-Vehicles like motorcycles with gears whose engine capacity is of 50CC or more.");
            printf("\n5-MCWG-Vehicles like motorcycles both with and without gear fall under this category.");
            printf("\n6-HGMV-Vehicles like trailers, larger trucks, and other similar vehicles used for transport of goods fall under the category of HGMV.");
            printf("\n7-HPMV-Vehicles that runs for commercial purpose and has an All India Permit to carry passengers falls under the HPMV category.\n");
            scanf("%d",&choice);
            switch(choice)
            {
            case 1:

                strcpy(vtype,"MC_50CC");
                vehicle_type=1;
                break;

            case 2:

                strcpy(vtype,"LMV-NT");
                vehicle_type=1;
                break;
            case 3:

                strcpy(vtype,"FVG");
                vehicle_type=1;
                break;
            case 4:

                strcpy(vtype,"MC_EX50CC");
                vehicle_type=1;
                break;
            case 5:

                strcpy(vtype,"MCWG");
                vehicle_type=1;
                break;
            case 6:

                strcpy(vtype,"HGMV");
                vehicle_type=1;
                break;
            case 7:

                strcpy(vtype,"HPMV");
                vehicle_type=1;
                break;
            default:
                printf("INVALID INPUT!");
                vehicle_type=0;
                break;
        }
        }

        printf("\n%s\n",mno);


        while(1)
        {
            printf("\nEnter Address using underscore '_' instead of space: ");
            fflush(stdin);
            gets(add);
            int space_counter=0;
            int add_index=0;;
            while(add[add_index]!='\0')
            {
                if(add[add_index]==' ')
                {
                    space_counter++;
                    printf("\n^^OCCURENCE OF SPACE ' ' DETECTED! PLEASE USE UNDERSCORE INSTEAD OF SPACE.^^\n");
                    break;
                }
                add_index++;
            }
            if(space_counter==0)
                break;

        }


        printf("\n%s\n",mno);


        printf("\nEnter Year: ");
        fflush(stdin);
        scanf("%d",&year);


        printf("\nEnter Month: ");
        fflush(stdin);
        scanf("%d",&month);

        printf("\nEnter Day: ");
        fflush(stdin);
        scanf("%d",&date);


        printf("\n%s\n",mno);

        int j=0;
        int counting=0;                           //Will be used to find the length of int law_viol array
        char inner_choice='Y';
        while(inner_choice!='N'&&inner_choice!='n')
        {
            printf("\n*************************************");

            printf("\nENTER 1 FOR NO HELMET               *");
            printf("\nENTER 2 FOR NO LICENSE              *");
            printf("\nENTER 3 FOR UNDERAGE DRIVING        *");
            printf("\nENTER 4 FOR OVERSPEEDING            *");
            printf("\nENTER 5 OVERLOADING                 *");
            printf("\nENTER 6 FOR TRAFFIC SIGNAL VIOLATION*");
            printf("\nENTER 7 FOR DRINK&DRIVE             *");
            printf("\n*************************************\n");
            fflush(stdin);
            scanf("%d",&law_viol[j]);
            switch(law_viol[j])
            {
            case 1:
                sum=sum+1000;
                counting++;
                break;
            case 2:
                sum=sum+5000;
                counting++;
                break;
            case 3:
                sum=sum+25000;
                counting++;
                break;
            case 4:
                sum=sum+5000;
                counting++;
                break;
            case 5:
                sum=sum+2000;
                counting++;
                break;
            case 6:
                sum=sum+1000;
                counting++;
                break;
            case 7:
                sum=sum+2000;
                break;
            default:
                printf("INVALID INPUT !");

            }
            printf("To add another Violation,PRESS Y OR PRESS N: ");
            fflush(stdin);
            scanf("%c",&inner_choice);
            j++;
        }


        printf("\n%s\n",mno);



        strcpy(stat,"Pending");

        fprintf(fe,"%s ",dlno);
        fprintf(fe,"%s ",firstname);
        fprintf(fe,"%s ",lastname);
        fprintf(fe,"%s ",vno);
        fprintf(fe,"%s ",vtype);


        fprintf(fe,"%s ",mno);

        fprintf(fe,"%s ",add);

        fprintf(fe,"%d ",year);

        fprintf(fe,"%d ",month);

        fprintf(fe,"%d ",date);
        fprintf(fe,"%d ",sum);
        fprintf(fe,"%s\n ",stat);

        printf("******************<<<RECORD SUCCESSFULLY STORED>>>*********************");
        printf("\n\nTo add another record,PRESS Y OR PRESS N : ");
        fflush(stdin);
        scanf("%c",&s);
        i++;
        sum=0;
    }
    fclose(fe);
}
//******************************************************************************************
//**********************MODIFY_PENALTY*************************************************
void MODIFY_PENALTY()
{

    char year_out[5];
    char month_out[3];
    char day_out[3];
    char sum_out[7];
    int del;
    int choice;
    int vehicle_type;
    char choice_firstname[20];
    char choice_lastname[20];
    char choice_vno[12];
    char choice_mno[10];
    char choice_dlno[20];
    char choice_add[50];
    char choice_vtype[10];
    int choice_year_out;
    int choice_month_out;
    int choice_day_out;
    int choice_sum_out;
    char choice_stat[8];
    int stat_choicer;

    char temp[50];
    char tempdlno[20];
    int ret;
    int ren;
    int counter=0;
    int counter1=0;
    char yes_no='Y';

    char dID[16];
    char ch,chrec;
    char buff[17];

    int i=0;
    char s='Y';
    int countDID=0;
    int noc=0;
    int countDolla=0;
    while(s!='N'&&s!='n')
    {
        FILE *fe;

        fe=fopen("DATABASE.txt","r");
        if(fe==NULL)
        {
            printf("Cannot Open FIle!");
            exit(1);
        }
        FILE *fr;
        fr=fopen("TEMP.txt","w");
        if(fe==NULL)
        {
            printf("Cannot Open FIle!");
            exit(1);
        }
        while(1)
        {
            fscanf(fe,"%s %s %s %s %s %s %s %s %s %s %s %s",dlno,firstname,lastname,vno,vtype,mno,add,year_out,month_out,day_out,sum_out,stat);
            counter++;
            ch=fgetc(fe);
            if(ch==EOF)
            {
                break;
            }
        }
        //printf("Value of counter=%d",counter);
        counter--;
        fseek(fe,0,SEEK_SET);
        printf("Enter The Driving License ID: ");
        fflush(stdin);
        gets(dID);
        puts(dID);
        while(1)                           //ASKING USER WHAT HE WANTS TO CHANGE
        {
            fscanf(fe,"%s %s %s %s %s %s %s %s %s %s %s %s",dlno,firstname,lastname,vno,vtype,mno,add,year_out,month_out,day_out,sum_out,stat);
            if(strcmp(dlno,dID)==0)
            {
                int j=0;
                int counting=0;
                char inner_choice='Y';
                printf("**Driving License ID Found!**");
                printf("\nTO Change:");
                printf("\nNAME: PRESS 1");
                printf("\nVEHICLE NUMBER: PRESS 2");
                printf("\nVEHICLE TYPE: PRESS 3");
                printf("\nMOBILE NUMBER: PRESS 4");
                printf("\nADDRESS: PRESS 5");
                printf("\nYEAR: PRESS 6");
                printf("\nMONTH: PRESS 7");
                printf("\nDAY: PRESS 8");
                printf("\nVIOLATIONS: PRESS 9");
                printf("\nFINE STATUS: PRESS 0");
                printf("\n************************\n");
                printf("ENTER CHOICE HERE: ");
                scanf("%d",&choice);
                switch(choice)
                {
                case 1:
                    printf("\nNEW NAME ");
                    printf("\nENTER FIRST NAME: ");
                    fflush(stdin);
                    gets(choice_firstname);
                    printf("\nENTER LAST NAME: ");
                    fflush(stdin);
                    gets(choice_lastname);
                    break;
                case 2:
                    printf("\ENTER NEW VEHICLE NUMBER: ");
                    scanf("%s",choice_vno);
                    break;
                case 3:
                    while(vehicle_type==0)
                    {
                        printf("\nEnter Vehicle type:\nPress");
                        printf("\n1-MC 50cc-Vehicles that have an engine capacity of 50cc or less than that.");
                        printf("\n2-LMV-NT-Vehicles like jeep and motor cars fall under the Light Motor Vehicle Category but these are of non-transport class.");
                        printf("\n3-FVG-Vehicles without gears fall under this category like scooters and mopeds.");
                        printf("\n4-MC EX50CC-Vehicles like motorcycles with gears whose engine capacity is of 50CC or more.");
                        printf("\n5-MCWG-Vehicles like motorcycles both with and without gear fall under this category.");
                        printf("\n6-HGMV-Vehicles like trailers, larger trucks, and other similar vehicles used for transport of goods fall under the category of HGMV.");
                        printf("\n7-HPMV-Vehicles that runs for commercial purpose and has an All India Permit to carry passengers falls under the HPMV category.\n");
                        scanf("%d",&choice);
                        switch(choice)
                        {
                        case 1:

                            strcpy(choice_vtype,"MC_50CC");
                            vehicle_type=1;
                            break;

                        case 2:

                            strcpy(choice_vtype,"LMV-NT");
                            vehicle_type=1;
                            break;
                        case 3:

                            strcpy(choice_vtype,"FVG");
                            vehicle_type=1;
                            break;
                        case 4:

                            strcpy(choice_vtype,"MC_EX50CC");
                            vehicle_type=1;
                            break;
                        case 5:

                            strcpy(choice_vtype,"MCWG");
                            vehicle_type=1;
                            break;
                        case 6:

                            strcpy(choice_vtype,"HGMV");
                            vehicle_type=1;
                            break;
                        case 7:

                            strcpy(choice_vtype,"HPMV");
                            vehicle_type=1;
                            break;
                        default:
                            printf("INVALID INPUT!");
                            vehicle_type=0;
                            break;
                        }

                    }
                    break;
                case 4:
                    printf("\nENTER NEW MOBILE NUMBER: ");
                    scanf("%s",choice_mno);
                    break;
                case 5:
                    printf("\nENTER NEW ADDRESS(using underscore '_' instead of space): ");
                    fflush(stdin);
                    gets(choice_add);
                    break;
                case 6:
                    printf("\nENTER NEW YEAR: ");
                    scanf("%d",&choice_year_out);
                    break;
                case 7:
                    printf("\nENTER NEW MONTH: ");
                    scanf("%d",&choice_month_out);
                    break;
                case 8:
                    printf("\nENTER NEW DAY: ");
                    scanf("%d",&choice_day_out);
                    break;
                case 9:


                    while(inner_choice!='N'&&inner_choice!='n')
                    {
                        printf("\n*************************************");

                        printf("\nENTER 1 FOR NO HELMET               *");
                        printf("\nENTER 2 FOR NO LICENSE              *");
                        printf("\nENTER 3 FOR UNDERAGE DRIVING        *");
                        printf("\nENTER 4 FOR OVERSPEEDING            *");
                        printf("\nENTER 5 OVERLOADING                 *");
                        printf("\nENTER 6 FOR TRAFFIC SIGNAL VIOLATION*");
                        printf("\nENTER 7 FOR DRINK&DRIVE             *");
                        printf("\n*************************************\n");
                        fflush(stdin);
                        scanf("%d",&law_viol[j]);
                        switch(law_viol[j])
                        {
                        case 1:
                            choice_sum_out=choice_sum_out+1000;
                            counting++;
                            break;
                        case 2:
                            choice_sum_out=choice_sum_out+5000;
                            counting++;
                            break;
                        case 3:
                            choice_sum_out=choice_sum_out+25000;
                            counting++;
                            break;
                        case 4:
                            choice_sum_out=choice_sum_out+5000;
                            counting++;
                            break;
                        case 5:
                            choice_sum_out=choice_sum_out+2000;
                            counting++;
                            break;
                        case 6:
                            choice_sum_out=choice_sum_out+1000;
                            counting++;
                            break;
                        case 7:
                            choice_sum_out=choice_sum_out+2000;
                            break;
                        default:
                            printf("INVALID INPUT !");

                        }
                        printf("To add another Violation,PRESS Y OR PRESS N: ");
                        fflush(stdin);
                        scanf("%c",&inner_choice);
                        j++;
                    }
                    break;
                case 0:
                    printf("\n****************");
                    printf("\nENTER 1 for PENDING");
                    printf("\nENTER 2 for PAID\n");
                    scanf("%d",&stat_choicer);
                    if(stat_choicer==1)
                        strcpy(choice_stat,"UNPAID");
                    else if(stat_choicer==2)
                        strcpy(choice_stat,"PAID");
                    break;
                default:
                    printf("Invalid CHOICE!!!!\n");
                    break;

                }

                countDID=1;
                strcpy(tempdlno,dlno);
                fseek(fe,0,SEEK_SET);
                while(1)                                    //                    COPY FUNCTIONNNNNNN
                {
                    fscanf(fe,"%s %s %s %s %s %s %s %s %s %s %s %s",dlno,firstname,lastname,vno,vtype,mno,add,year_out,month_out,day_out,sum_out,stat);
                    counter1++;

                    if(strcmp(dlno,tempdlno)!=0)
                    {

                        fprintf(fr, "%s %s %s %s %s %s %s %s %s %s %s %s\n",dlno,firstname,lastname,vno,vtype,mno,add,year_out,month_out,day_out,sum_out,stat);
                    }
                    else if(strcmp(dlno,tempdlno)==0)
                    {
                        switch(choice)
                        {
                        case 1:
                            fprintf(fr, "%s %s %s %s %s %s %s %s %s %s %s %s\n",dlno,choice_firstname,choice_lastname,vno,vtype,mno,add,year_out,month_out,day_out,sum_out,stat);
                            break;
                        case 2:
                            fprintf(fr, "%s %s %s %s %s %s %s %s %s %s %s %s\n",dlno,firstname,lastname,choice_vno,vtype,mno,add,year_out,month_out,day_out,sum_out,stat);
                            break;
                        case 3:
                            fprintf(fr, "%s %s %s %s %s %s %s %s %s %s %s %s\n",dlno,firstname,lastname,vno,choice_vtype,mno,add,year_out,month_out,day_out,sum_out,stat);
                            break;
                        case 4:
                            fprintf(fr, "%s %s %s %s %s %s %s %s %s %s %s %s\n",dlno,firstname,lastname,vno,vtype,choice_mno,add,year_out,month_out,day_out,sum_out,stat);
                            break;
                        case 5:
                            fprintf(fr, "%s %s %s %s %s %s %s %s %s %s %s %s\n",dlno,firstname,lastname,vno,vtype,mno,choice_add,year_out,month_out,day_out,sum_out,stat);
                            break;
                        case 6:
                            fprintf(fr, "%s %s %s %s %s %s %s %d %s %s %s %s\n",dlno,firstname,lastname,vno,vtype,mno,add,choice_year_out,month_out,day_out,sum_out,stat);
                            break;
                        case 7:
                            fprintf(fr, "%s %s %s %s %s %s %s %s %d %s %s %s\n",dlno,firstname,lastname,vno,vtype,mno,add,year_out,choice_month_out,day_out,sum_out,stat);
                            break;
                        case 8:
                            fprintf(fr, "%s %s %s %s %s %s %s %s %s %d %s %s\n",dlno,firstname,lastname,vno,vtype,mno,add,year_out,month_out,choice_day_out,sum_out,stat);
                            break;
                        case 9:
                            fprintf(fr, "%s %s %s %s %s %s %s %s %s %s %d %s\n",dlno,firstname,lastname,vno,vtype,mno,add,year_out,month_out,day_out,choice_sum_out,stat);
                            break;
                        case 0:
                            fprintf(fr, "%s %s %s %s %s %s %s %s %s %s %s %s\n",dlno,firstname,lastname,vno,vtype,mno,add,year_out,month_out,day_out,sum_out,choice_stat);
                            break;

                        }
                    }
                        /*ch=fgetc(fe);
                        if(ch==EOF||counter1==counter)
                        {
                            break;
                        }*/
                    ch=fgetc(fe);
                    if(ch==EOF||counter1==counter)
                        break;

                }
                fclose(fe);
                ret=remove("DATABASE.txt");
                if(ret==0)
                    printf("Deleted SuccessFully");
                else
                    printf("Unable to delete file!");
                fclose(fr);
                ren=rename("TEMP.txt","DATABASE.txt");
                if(ret==0)
                    printf("\nRenamed SuccessFully");
                else
                    printf("Unable to Rename file!");

            }

            fseek(fe,1,SEEK_CUR);
            ch=fgetc(fe);
            if(ch==EOF)
                break;
            fseek(fe,-1,SEEK_CUR);

        }
        if(countDID==0)
            printf("Driving License ID not found!");
        printf("To Modify another record,Press Y, ELSE PRESS N : ");
        fflush(stdin);
        scanf("%c",&s);

    }
}
//**********************************************************************************
//******************DELETE_PENALTY************************************************
void DELETE_PENALTY()
{

    char year_out[5];
    char month_out[3];
    char day_out[3];
    char sum_out[7];
    int del;
    char temp[50];
    char tempdlno[20];
    int ret;
    int ren;
    int counter=0;
    int counter1=0;


    char dID[16];
    char ch,chrec;
    char buff[17];
    int vehicle_type;
    int i=0;
    char s='Y';
    int countDID=0;
    int noc=0;
    int countDolla=0;
    while(s!='N'&&s!='n')
    {
        FILE *fe;

        fe=fopen("DATABASE.txt","r");
        if(fe==NULL)
        {
            printf("Cannot Open FIle!");
            exit(1);
        }
        FILE *fr;
        fr=fopen("TEMP.txt","w");
        if(fe==NULL)
        {
            printf("Cannot Open FIle!");
            exit(1);
        }
        while(1)
        {
            fscanf(fe,"%s %s %s %s %s %s %s %s %s %s %s",dlno,firstname,lastname,vno,vtype,mno,add,year_out,month_out,day_out,sum_out,stat);
            counter++;
            ch=fgetc(fe);
            if(ch==EOF)
            {
                break;
            }
        }
        //printf("Value of counter=%d",counter);
        counter--;
        fseek(fe,0,SEEK_SET);
        printf("Enter The Driving License ID: ");
        fflush(stdin);
        gets(dID);
        puts(dID);
        while(1)
        {
            fscanf(fe,"%s %s %s %s %s %s %s %s %s %s %s %s",dlno,firstname,lastname,vno,vtype,mno,add,year_out,month_out,day_out,sum_out,stat);
            if(strcmp(dlno,dID)==0)
            {
                countDID=1;


                strcpy(tempdlno,dlno);
                fseek(fe,0,SEEK_SET);
                while(1)
                {
                    fscanf(fe,"%s %s %s %s %s %s %s %s %s %s %s %s",dlno,firstname,lastname,vno,vtype,mno,add,year_out,month_out,day_out,sum_out,stat);
                    counter1++;

                    if(strcmp(dlno,tempdlno)!=0)
                    {

                        fprintf(fr, "%s %s %s %s %s %s %s %s %s %s %s %s\n",dlno,firstname,lastname,vno,vtype,mno,add,year_out,month_out,day_out,sum_out,stat);
                    }
                        /*ch=fgetc(fe);
                        if(ch==EOF||counter1==counter)
                        {
                            break;
                        }*/
                    ch=fgetc(fe);
                    if(ch==EOF||counter1==counter)
                        break;
                }


                fclose(fe);
                ret=remove("DATABASE.txt");
                if(ret==0)
                    printf("Deleted SuccessFully");
                else
                    printf("Unable to delete file!");
                fclose(fr);
                ren=rename("TEMP.txt","DATABASE.txt");
                if(ret==0)
                    printf("\nRenamed SuccessFully");
                else
                    printf("Unable to Rename file!");

            }
            fseek(fe,1,SEEK_CUR);
            ch=fgetc(fe);
            if(ch==EOF)
                break;
            fseek(fe,-1,SEEK_CUR);

        }
        if(countDID==0)
            printf("Driving License ID not found!");
        printf("To Delete another record,Press Y, ELSE PRESS N : ");
        fflush(stdin);
        scanf("%c",&s);

    }
}
//*****************************************************************************************
int main()
{
    printf("\t\t\t\tWELCOME TO TRAFFIC OFFENSE MANAGEMENT SYSTEM\n");
    printf("PRESS 1-SIGN UP\n");
    printf("PRESS 2-LOGIN\n");
    printf("PRESS 3-EXIT\n");
    int terms_choice;
    scanf("%d",&terms_choice);
    if(terms_choice==2)
    {
        FILE *fp;
        char user[20];
        char pass[20];
        struct sign
        {
            char username[20];
            char password[20];
        };
        struct sign s;
        fp=fopen("signin.txt","r");
        if(fp==NULL)
        {
            printf("Cannot open file!");
            exit(0);
        }


        //Logining in

        ;
        fscanf(fp,"%s %s",s.username,s.password);
        //*******************************************************************************************
        while(1)
        {
            printf("\nEnter Username : ");
            scanf("%s",&user);

            printf("\nEnter Password : ");
            scanf("%s",&pass);
        if(strcmp(user,s.username)==0 && strcmp(pass,s.password)==0)
        {

            printf("LOGIN COMPLETE!");
            fclose(fp);
            printf("\n-------------\n");
              printf("|   MENU    |");
            printf("\n-------------\n");
            //*****************************STARTING MENU***********************
            char menu_asking='Y';
            while(menu_asking!='N')
            {
                int menu_choice;
                printf("ENTER NEW PENALTY     PRESS 1\n");
                printf("DISPLAY PENALTY       PRESS 2\n");
                printf("DELETE PENALTY        PRESS 3\n");
                printf("MODIFY PENALTY        PRESS 4\n");
                printf("HELP                  PRESS 5\n");
                printf("TRAFFIC RULES         PRESS 6\n");
                printf("EXIT                  PRESS 7\n");
                scanf("%d",&menu_choice);
                int z_help;
                switch(menu_choice)
                {
                case 1:
                    ENTER_PENALTY();
                    break;
                case 2:
                    DISPLAY_PENALTY();
                    break;
                case 3:
                    DELETE_PENALTY();
                    break;
                case 4:
                    MODIFY_PENALTY();
                    break;
                case 5:
                    printf("__________\nHELP SECTION\n____________\n");
                    printf("PRESS: 1.How this program works\n2.Rules for entering details\n3.How fine calculating work\n4.Support\n");
                    scanf("%d",&z_help);
                    if(z_help==1)
                    {
                        printf("\n+Open the application\n");
                        printf("+Enter login id and password\n");
                        printf("+SIgn up if using program for the first time\n");
                        printf("+Choose desired option\n");
                        printf("+Carry out the task\n");
                        printf("+Close the application\n");
                    }
                    else if(z_help==2)
                    {
                        printf("*No number while writing name\n*vehicle number should have all letters in uppercase\n*mobile.no must be entered correctly\n*While writing address,use underscore '_' instead of space' '\n*Try not to enter any digit other than what is described in the menu.");
                    }
                    else if(z_help==3)
                    {
                        printf("\nNO HELMET                 Rs.1000");
                        printf("\nNO LICENSE                Rs.5000");
                        printf("\nUNDERAGE DRIVING          Rs.25000");
                        printf("\nDRINK & DRIVE             Rs.2000");
                        printf("\nOVERLOADING               Rs.2000");
                        printf("\nTRAFFIC SIGNAL VIOLATION  Rs.1000");
                        printf("\nOVERSPEEDING              Rs.5000");
                    }
                    else if(z_help==4)
                            {
                                printf("For any other problem,Contact on this number-1234567890-Steel Tech,Gurgaon");
                            }
                    else
                        printf("INVALID CHOICE!");
                    break;
                case 6:
                    //Following are the Traffic Rules for the chalan cutting program.
                    //These are printf commands to display various traffic rules.
                    //The goal here is to keep the traffic rules easy to follow and readable by the user.
                    printf("\t******************************");
                    printf("\t");
                    printf("\t");
                    printf("TRAFFIC RULES");
                    printf("\t\t******************************");
                    printf("\n");
                    printf("\n");
                    printf("\n");
                    printf("Below are the traffic rules which must be followed :");
                    printf("\n");
                    printf("\n");
                    printf("1. Do not drink and drive");
                    printf("\n");
                    printf("    As per the current law, the blood alcohol limit permisible for driving is upto 0.03%");
                    printf("\n");
                    printf("\n");
                    printf("2. Always own valid car insurance policy");
                    printf("\n");
                    printf("    According to the \b Motor Vehicles Act of 1988, ");
                    printf("all motor vehicles in India need to possess valid third-party insurance coverage at all times.");
                    printf("\n");
                    printf("\n");
                    printf("3. Wear your seatbelt while Driving a Car");
                    printf("\n");
                    printf("    If you are new to driving, get in the habit of securing the seat belt as the first thing you do upon entering your vehicle.");
                    printf("\n");
                    printf("\n");
                    printf("4. Riding a Two-Wheeler without a Helmet On");
                    printf("\n");
                    printf("    One must wear a helmet at all times while riding a two-wheeler. One distinction to notice here is that the law states that");
                    printf("all individuals on a two-wheeler must put on helmets and not just the driver.");
                    printf("\n");
                    printf("\n");
                    printf("5. Using a Mobile Phone while Riding");
                    printf("\n");
                    printf("    As per the new Motor Vehicle rules in effect from Oct 1, 2020, drivers can only use their phones as a navigational tool while on the wheel.");
                    printf("\n");
                    printf("\n");
                    printf("6. Over Speeding");
                    printf("\n");
                    printf("    Drivers should never exceed the recommended speed guidelines on roads, as doing so will draw the ire of traffic cops.");
                    printf("\n");
                    printf("\n");
                    printf("7. Jumping the Red Light");
                    printf("\n");
                    printf(" If you do not intend to bear penalties of up to Rs.5000 and a one-year prison sentence,");
                    printf("ensure you stick to the various traffic signals during a drive, even if you are in a hurry.");
                    printf("\n");
                    printf("\n");
                    printf("8. Do not drive on wrong lane");
                    printf("\n");
                    printf("In india, there is left side driving ,");
                    printf("so the person should follow according to the country you are in.");
                    printf("\n");
                    printf("\n");
                    printf("9. Turning without giving indicator,");
                    printf("\n");
                    printf("Giving the indicator on the direction which the vehicle is moving");
                    printf("\n");
                    printf("\n");
                    printf("10. Do not overtake from wrong side,");
                    printf("\n");
                    printf("Slow doen the speed of vehicle when another vehicle is about to overtake");
                    printf("\n");
                    printf("\n");
                    printf("11.Do not drive tired");
                    printf("\n");
                    printf("A person may get asleep while driving in exhausted state which can lead to accident.So he must be in fresh state.");
                    printf("\n");
                    printf("\n");
                    printf("12.Keep distance from ther vehicles while driving");
                    printf("\n");
                    printf("As some vehicles have power brake so keeping a certain distance is safe.");
                    printf("\n");
                    printf("\n");
                    printf("13. Adjust the mirror in correct position");
                    printf("\n");
                    printf("a.)Position the Interior mirror so that the centre of the mirror shows the centre of the rear window.So you would be able to see directly behing your vehicle");
                    printf("b.)The exterior(wing) mirror adjustment should be made while seated normally for driving.Do not adjust the left-hand exterior mirror by leaning to the centre of the vehicle ");
                    printf("\n");
                    printf("\n");
                    printf("14.Turn on headlights at night and in poor light conditions(fog)");
                    printf("\n");
                    printf("Use dipper at night so that you have an idea of the vehicle surpassing and the distance you need to maintain from it");
                    printf("\n");
                    printf("\n");
                    printf("15.You must have good knowledge of traffic signs.");
                    printf("\n");
                    printf("Traffic signs helps in guiding the path to the vehicle.");
                    printf("\n");
                    printf("\n");
                    printf("16.You should always carry a driving licence with you while driving wither in soft copy or hard copy.");
                    printf("\n");
                    printf("\n");
                    printf("17.Do not use horn in the no honking zone");
                    printf("\n");
                    printf("\n");
                    printf("18.Do not triple drive on a two wheeler vehicle");
                    printf("\n");
                    printf("\n");
                    printf("19.Do not allow an unauthorized person to drive your vehicle");
                    printf("\n");
                    printf("\n");
                    printf("20.Your vehicle must not create air or noise pollution");
                    printf("\n");
                    printf("\n");
                    printf("21.Do not drive without RUPD and LUPD");
                    printf("\n");
                    printf("\n");
                    printf("22.Do not drive the vehicle after consuming intoxicants substances");
                    printf("\n");
                    printf("Inoxicants such as narco-drugs,alcohol,violation of blood alcohol concentration over 3mg/100ml");
                    printf("\n");
                    printf("\n");
                    printf("23.A vehicle must have atleast two aibags");
                    printf("\n");
                    printf("An airbag is fitted in a four wheeler vehicle to protect the driver and the passenger during an accident");
                    printf("\n");
                    printf("\n");
                    printf("Keeping our road safe is not difficult task.");
                    printf("Imagine if everyone follows simple safety measures and traffic rules,there will be no accident.");

                    break;
                case 7:
                    printf("\n********************************************************************\n");
                    printf("**************THANKYOU FOR USING THE PROGRAM!***********************\n");
                    printf("********************************************************************");
                    return 7;
                default:
                    printf("\nINVALID INPPUT!");
                    break;
                }
                printf("\nDISPLAY THE MENU AGAIN? Y/N: ");
                fflush(stdin);
                scanf("%c",&menu_asking);
            }
            //***************************************************************


            break;
        }
        else
        {
            printf("\nINVALID USERNAME OR PASSWORD!");

        }
        }
        //********************************************************************************************
    }
    else if(terms_choice==1)
    {
        printf("Firstly, ACCEPT THE TERMS AND CONDITIONS.\n ");
        printf("****************************************************************************************************************************");
        //Following are the terms and conditions for the chalan cutting program.
        //These are printf commands to display aforementioned T and C.
        //The goal here is to keep the T and C easy and readable by the user.
        //At End they must accept these to use the program.


        printf("\t******************************");
        printf("\t\t");
        printf("TERMS & CONDITIONS");
        printf("\t\t******************************");
        printf("\n\n\n");
        printf("The below Terms and Conditions govern ");
        printf("your acqusition and use of the ");
        printf("services.");
        printf("\n\n");
        printf("By accepting this agreement, ");
        printf("by executing an order form that references this agreement, ");
        printf("you agree to the terms of this agreement.");
        printf("\n\n");
        printf("If you are entering on behalf ");
        printf("of a company/legal entity, you represent ");
        printf("that you have the authority to bind such entity ");
        printf("\n");
        printf("and its affiliates to these terms, ");
        printf("in which case the terms ");
        printf("you shall refer to such entity and its affiliates.");
        printf("\n\n");
        printf("IF YOU DO NOT HAVE SUCH AUTHORITY, ");
        printf("OR IF YOU DO NOT AGREE WITH THESE ");
        printf("TERMS : ");
        printf("\n\t");
        printf("||YOU MUST NOT ACCEPT THIS AGREEMENT AND ITS SERVICES.||");
        printf("\n\n");
        printf("System reserves the right to change ");
        printf("these terms at any time, effective ");
        printf("upon the posting of modified ");
        printf("Terms & Services through email.");
        printf("\n");
        printf("It is your obligations to ensure ");
        printf("to that you have read, ");
        printf("understood and agree ");
        printf("to the most recent Terms.");
        printf("\n\n");
        printf("\n");
        printf("END USER LICENSE AGREEMENT:");
        printf("\n");
        printf("SteelTech grants you the right to ");
        printf("access and use these services ");
        printf("with the particular invited ");
        printf("with the particular invited\n");
        printf("as per your subscription type.\n");
        printf("This right is non-exclusive, ");
        printf("and limited by and subject to ");
        printf("this agreement.\n");
        printf("*All the invoices will be sent to you, ");
        printf("or to a billing contact whose ");
        printf("details are provided by you, through email.\n");
        printf("\n");
        printf("\t");
        printf("||YOU ARE RESPONSIBLE FOR PAYMENT OF ALL ");
        printf("THE TAXES AND DUTIES IN ADDITION");
        printf("THE ACCESS FEES.||");
        printf("\n\n");
        printf("*Without prejudice to any other rights ");
        printf("that SteelTech may have under these ");
        printf("terms or at law, ");
        printf("Steel tech reserves the right\n");
        printf(" to render invoices for the full ");
        printf("access fees due ");
        printf("or suspend or terminate ");
        printf("your use of services, in the event that,\n");
        printf(" any invoices for those ");
        printf("access fees are not paid in ");
        printf("full by the due date ");
        printf("for payment.");
        printf("\n\n\n");
        printf("GENRAL OBLIGATIONS:");
        printf("\n");
        printf("*You must only use the services ");
        printf("for your own Lawful internal ");
        printf("purposes, in accordance ");
        printf("with the terms and ");
        printf("conditions posted by SteelTech.\n");
        printf("*You may use the services on ");
        printf("behalf of others but if ");
        printf("you do so you must ");
        printf("ensure that you are ");
        printf("authorised to do so and that\n");
        printf(" all persons for whom or to ");
        printf("whom services are provided ");
        printf("comply with and accept all ");
        printf("terms of this agreement\n");
        printf(" that apply to you.");
        printf("\n\n\n");
        printf("ACCESS CONDITIONS:");
        printf("\n");
        printf("*You must ensure that all ");
        printf("the usernames and ");
        printf("passwords required to access ");
        printf("the services are kept confidential.\n");
        printf("*You must immediately notify ");
        printf("SteelTech of any ");
        printf("unauthorised use of your passwords ");
        printf("and you must take all ");
        printf("other actions \n");
        printf(" that SteelTech reasonably ");
        printf("deems necessary to maintain ");
        printf("or enhance the security.");
        printf("\n\n\n");
        printf("INTELLECTUAL PROPERTY:");
        printf("\n");
        printf("Ownership of Data:\n");
        printf("Title to, and all intellectual ");
        printf("property rights in, ");
        printf("the DATA remain your property.\n");
        printf("However, your access to ");
        printf("the data is contingent ");
        printf("on full payment of the ");
        printf("SteelTech access fees when ");
        printf("due and any re-establishment\n");
        printf("fee due and payable.");
        printf("\n\n");
        printf("You grant SteelTech a ");
        printf("licence to use, copy, ");
        printf("transmit, store and back up ");
        printf("your information and data ");
        printf("for the purpose related\n");
        printf("to provision of services to you.");
        printf("\n\n");
        printf("FOR THE AVOIDANCE OF DOUBT, ");
        printf("THIS LICENSE IS WITHOUT ");
        printf("LIMITATION TO SteelTech's ");
        printf("RIGHT TO CREATE ANONYMISED ");
        printf("\n");
        printf("DATA COMPILATIONS OR SIMILAR WORKS.\n");
        printf("\n");
        printf("\n");
        printf("\n");
        printf("DO YOU ACCEPT THE ABOVE TERMS AND CONDITIONS? PRESS Y/N: \n");
        char tnc;
        fflush(stdin);
        scanf("%c",&tnc);
        if(tnc!='Y')
        {
            printf("TERMS AND CONDITIONS NOT ACCEPTED!\n**PROGRAM TERMINATED**");
            return -10;
        }
        //SIGNUP STARTS****************
        else
        {
            FILE *fp;
            char user[20];
            char pass[20];
            struct sign
            {
                char username[20];
                char password[20];
            };
            struct sign s;
            fp=fopen("signin.txt","w");
            if(fp==NULL)
            {
                printf("Cannot open file!");
                exit(0);
            }
            printf("Enter USername : ");
            scanf("%s",&s.username);
            printf("\nEnter Password : ");
            scanf("%s",&s.password);
            fprintf(fp,"%s %s",s.username,s.password);
            printf("\nSIGNUP COMPLETE!");
            //*********************Logining in

            rewind(fp);
            while(1)
            {
                //**************************************************************
                printf("\nEnter Username : ");
                scanf("%s",&user);

                printf("\nEnter Password : ");
                scanf("%s",&pass);
                fscanf(fp,"%s %s",s.username,s.password);
                if(strcmp(user,s.username)==0 && strcmp(pass,s.password)==0)
                {

                    printf("LOGIN COMPLETE!");
                    fclose(fp);
                    printf("\n-------------\n");
                    printf("|   MENU    |");
                    printf("\n-------------\n");
                //*****************************STARTING MENU***********************
                    char menu_asking='Y';
                    while(menu_asking!='N')
                    {
                        int menu_choice;
                        printf("ENTER NEW PENALTY     PRESS 1\n");
                        printf("DISPLAY PENALTY       PRESS 2\n");
                        printf("DELETE PENALTY        PRESS 3\n");
                        printf("MODIFY PENALTY        PRESS 4\n");
                        printf("HELP                  PRESS 5\n");
                        printf("TRAFFIC RULES         PRESS 6\n");
                        printf("EXIT                  PRESS 7\n");
                        scanf("%d",&menu_choice);
                        int z_help;
                        switch(menu_choice)
                        {
                        case 1:
                            ENTER_PENALTY();
                            break;
                        case 2:
                            DISPLAY_PENALTY();
                            break;
                        case 3:
                            DELETE_PENALTY();
                            break;
                        case 4:
                            MODIFY_PENALTY();
                            break;
                        case 5:
                            printf("__________\nHELP SECTION\n____________\n");
                            printf("PRESS: 1.How this progrm works\n2.Rules for entering details\n3.How fine calculating work\4.Support\n");
                            scanf("%d",&z_help);
                            if(z_help==1)
                            {
                                printf("\n+Open the application\n");
                                printf("+Enter login id and password\n");
                                printf("+SIgn up if using program for the first time\n");
                                printf("+Choose desired option\n");
                                printf("+Carry out the task\n");
                                printf("+Close the application\n");
                            }
                            else if(z_help==2)
                            {
                                printf("*No number while writing name\n*vehicle number should have all letters in uppercase\n*mobile.no must be entered correctly\n*While writing address,use underscore '_' instead of space' '\n*Try not to enter any digit other than what is described in the menu.");
                            }
                            else if(z_help==3)
                            {
                                printf("\nNO HELMET                 Rs.1000");
                                printf("\nNO LICENSE                Rs.5000");
                                printf("\nUNDERAGE DRIVING          Rs.25000");
                                printf("\nDRINK & DRIVE             Rs.2000");
                                printf("\nOVERLOADING               Rs.2000");
                                printf("\nTRAFFIC SIGNAL VIOLATION  Rs.1000");
                                printf("\nOVERSPEEDING              Rs.5000");
                            }
                            else if(z_help==4)
                            {
                                printf("For any other problem,Contact on this number-1234567890-Steel Tech,Gurgaon");
                            }
                            else
                                printf("INVALID CHOICE!");
                            break;
                        case 6:
                            //Following are the Traffic Rules for the chalan cutting program.
                            //These are printf commands to display various traffic rules.
                            //The goal here is to keep the traffic rules easy to follow and readable by the user.


                            printf("\t******************************");
                            printf("\t");
                            printf("\t");
                            printf("TRAFFIC RULES");
                            printf("\t\t******************************");
                            printf("\n");
                            printf("\n");
                            printf("\n");
                            printf("Below are the traffic rules which must be followed :");
                            printf("\n");
                            printf("\n");
                            printf("1. Do not drink and drive");
                            printf("\n");
                            printf("    As per the current law, the blood alcohol limit permisible for driving is upto 0.03%");
                            printf("\n");
                            printf("\n");
                            printf("2. Always own valid car insurance policy");
                            printf("\n");
                            printf("    According to the \b Motor Vehicles Act of 1988, ");
                            printf("all motor vehicles in India need to possess valid third-party insurance coverage at all times.");
                            printf("\n");
                            printf("\n");
                            printf("3. Wear your seatbelt while Driving a Car");
                            printf("\n");
                            printf("    If you are new to driving, get in the habit of securing the seat belt as the first thing you do upon entering your vehicle.");
                            printf("\n");
                            printf("\n");
                            printf("4. Riding a Two-Wheeler without a Helmet On");
                            printf("\n");
                            printf("    One must wear a helmet at all times while riding a two-wheeler. One distinction to notice here is that the law states that");
                            printf("all individuals on a two-wheeler must put on helmets and not just the driver.");
                            printf("\n");
                            printf("\n");
                            printf("5. Using a Mobile Phone while Riding");
                            printf("\n");
                            printf("    As per the new Motor Vehicle rules in effect from Oct 1, 2020, drivers can only use their phones as a navigational tool while on the wheel.");
                            printf("\n");
                            printf("\n");
                            printf("6. Over Speeding");
                            printf("\n");
                            printf("    Drivers should never exceed the recommended speed guidelines on roads, as doing so will draw the ire of traffic cops.");
                            printf("\n");
                            printf("\n");
                            printf("7. Jumping the Red Light");
                            printf("\n");
                            printf(" If you do not intend to bear penalties of up to Rs.5000 and a one-year prison sentence,");
                            printf("ensure you stick to the various traffic signals during a drive, even if you are in a hurry.");
                            printf("\n");
                            printf("\n");
                            printf("8. Do not drive on wrong lane");
                            printf("\n");
                            printf("In india, there is left side driving ,");
                            printf("so the person should follow according to the country you are in.");
                            printf("\n");
                            printf("\n");
                            printf("9. Turning without giving indicator,");
                            printf("\n");
                            printf("Giving the indicator on the direction which the vehicle is moving");
                            printf("\n");
                            printf("\n");
                            printf("10. Do not overtake from wrong side,");
                            printf("\n");
                            printf("Slow doen the speed of vehicle when another vehicle is about to overtake");
                            printf("\n");
                            printf("\n");
                            printf("11.Do not drive tired");
                            printf("\n");
                            printf("A person may get asleep while driving in exhausted state which can lead to accident.So he must be in fresh state.");
                            printf("\n");
                            printf("\n");
                            printf("12.Keep distance from ther vehicles while driving");
                            printf("\n");
                            printf("As some vehicles have power brake so keeping a certain distance is safe.");
                            printf("\n");
                            printf("\n");
                            printf("13. Adjust the mirror in correct position");
                            printf("\n");
                            printf("a.)Position the Interior mirror so that the centre of the mirror shows the centre of the rear window.So you would be able to see directly behing your vehicle");
                            printf("b.)The exterior(wing) mirror adjustment should be made while seated normally for driving.Do not adjust the left-hand exterior mirror by leaning to the centre of the vehicle ");
                            printf("\n");
                            printf("\n");
                            printf("14.Turn on headlights at night and in poor light conditions(fog)");
                            printf("\n");
                            printf("Use dipper at night so that you have an idea of the vehicle surpassing and the distance you need to maintain from it");
                            printf("\n");
                            printf("\n");
                            printf("15.You must have good knowledge of traffic signs.");
                            printf("\n");
                            printf("Traffic signs helps in guiding the path to the vehicle.");
                            printf("\n");
                            printf("\n");
                            printf("16.You should always carry a driving licence with you while driving wither in soft copy or hard copy.");
                            printf("\n");
                            printf("\n");
                            printf("17.Do not use horn in the no honking zone");
                            printf("\n");
                            printf("\n");
                            printf("18.Do not triple drive on a two wheeler vehicle");
                            printf("\n");
                            printf("\n");
                            printf("19.Do not allow an unauthorized person to drive your vehicle");
                            printf("\n");
                            printf("\n");
                            printf("20.Your vehicle must not create air or noise pollution");
                            printf("\n");
                            printf("\n");
                            printf("21.Do not drive without RUPD and LUPD");
                            printf("\n");
                            printf("\n");
                            printf("22.Do not drive the vehicle after consuming intoxicants substances");
                            printf("\n");
                            printf("Inoxicants such as narco-drugs,alcohol,violation of blood alcohol concentration over 3mg/100ml");
                            printf("\n");
                            printf("\n");
                            printf("23.A vehicle must have atleast two aibags");
                            printf("\n");
                            printf("An airbag is fitted in a four wheeler vehicle to protect the driver and the passenger during an accident");
                            printf("\n");
                            printf("\n");
                            printf("Keeping our road safe is not difficult task.");
                            printf("Imagine if everyone follows simple safety measures and traffic rules,there will be no accident.");
                            break;
                        case 7:
                            printf("\n********************************************************************\n");
                            printf("**************THANKYOU FOR USING THE PROGRAM!***********************\n");
                            printf("********************************************************************");
                            return 7;
                        default:
                            printf("\nINVALID INPUT!");
                            break;
                        }
                        printf("\nDISPLAY THE MENU AGAIN? Y/N: ");
                        fflush(stdin);
                        scanf("%c",&menu_asking);
                    }
                //***************************************************************


                    break;
                }
                else
                {
                    printf("\nINVALID USERNAME OR PASSWORD!");

                }
            }
        }
        //********************************************************************************************

    }
    else if(terms_choice==3)
    {
        printf("\n********************************************************************\n");
        printf("**************THANKYOU FOR USING THE PROGRAM!***********************\n");
        printf("********************************************************************");
        return 5;
    }
    printf("\n********************************************************************\n");
    printf("**************THANKYOU FOR USING THE PROGRAM!***********************\n");
    printf("********************************************************************");

    return 0;
}
