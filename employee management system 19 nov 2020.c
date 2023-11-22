//Employee Management System using linked list
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node
{
    char ename[20];
    int id;
    char dept[10];
    int salary;
    char address[20];
    char phoneno[10];
    struct node *next;
}node;
node *root=NULL;
node *end=NULL;
void user_access();
void admin_access();
void leave_permission();
void grant_decline_leave();
void update_emp_admin();
void update_emp_user();
void add_emp(char ename[20],int id,char dept[15],int salary,char address[20],char phoneno[10]);
void delete_emp();
void display_all_emp();
void display_one_emp();
void check_leave_status();
void display_options();

// The main program starts here
int main()
{
    char ename[20], address[20],phoneno[10],dept[15];
    int id, salary;
    FILE *fp;

    fp=fopen("C:/Users/balan/Desktop/c programs/cfile.txt","w");
    fclose(fp);

    add_emp("Sahil",11111,"SALES",1000,"Pune    ","9999999999");
    add_emp("Rahul",22222,"HR   ",2000,"Delhi   ","8888877777");
    add_emp("Arjun",33333,"MKTG ",3000,"B'luru","7776669954");
    add_emp("Surya",44444,"ENGG ",4000,"Mumbai   ","6676221020");
    add_emp("Krish",55555,"DSGN ",5000,"Chennai  ","8885557219");
    add_emp("Ramya",66666,"MKTG",5000,"Delhi","7689456796");
    int n;
    printf("Press 1 for admin access:\n");
    printf("Press 2 for user access:\n");
    scanf("%d",&n);
    if(n==1)
        {

            admin_access();
        }
    else if(n==2)
        {

            user_access();
        }
}


void admin_access()
{
    int opt,num,salary,id;
    char ename[20],dept[20],address[20],phoneno[20];
    num=1;
    char admin_username[10],admin_password[10];
    while(num<=3)
        {
            printf("Enter your username:\n");
            scanf(" %s",admin_username);
            printf("Enter your password:\n");
            scanf(" %s",admin_password);
            if((strcmp(admin_username,"admin")==0)&&(strcmp(admin_password,"admin")==0))
                {
                    while(opt!=9)
                        {
                            printf("Press 1 to Add a new employee:\n");
                            printf("Press 2 to Update an existing employee:\n");
                            printf("Press 3 to Delete an employee:\n");
                            printf("Press 4 to Display all the employees:\n");
                            printf("Press 5 to Grant/Decline leave to the employees:\n");
                            printf("Press 9 to Exit:\n");
                            scanf("%d",&opt);
                            if(opt==1)
                                {
                                    printf("Enter employee name:\n");
                                    scanf(" %s",ename);
                                    printf("Enter employee id:\n");
                                    scanf("%d",&id);
                                    printf("Enter department:\n");
                                    scanf(" %s",dept);
                                    printf("Enter salary:\n");
                                    scanf("%d",&salary);
                                    printf("Enter address:\n");
                                    scanf(" %s",address);
                                    printf("Enter phone number:\n");
                                    scanf(" %s",phoneno);
                                    add_emp(ename,id,dept,salary,address,phoneno);
                                }
                            else if(opt==2)
                                {
                                    update_emp_admin();
                                }
                            else if(opt==3)
                                {
                                    delete_emp();
                                }
                            else if(opt==4)
                                {
                                    display_all_emp();
                                }
                            else if(opt==5)
                                {
                                    grant_decline_leave();
                                }
                            else if(opt==9)
                                {
                                   printf("Good Bye!\n");
                                }
                        }
                    break;
                }
                else
                    {
                        printf("Username and Password are invalid. Please try again.\n");
                        num++;
                        if (num==4)
                            {
                              printf("You have exceeded the max number of attempts. Good Bye!\n");
                              exit(1);
                            }
                    }
        }
}

void user_access()
{
   int opt,num,value;
   num=1;
   char username[10],password[10],buf[20];
   FILE *fp;


   while(num<=3)
    {
        printf("Enter your username:\n");
        scanf(" %s",username);
        printf("Enter your password:\n");
        scanf(" %s",password);

        fp=fopen("C:/Users/balan/Desktop/c programs/cfile.txt","r");


        while (fgets(buf,20, fp)!=NULL)
                    {

                        value=(strcmp(buf,username));
                        if(value==1)
                            {
                                display_options();
                                fclose(fp);
                                break;
                            } //This closing bracket for if statement on line 146/147
                    }

                        printf("Username and Password are invalid. Please try again.\n");
                        num++;
                        if (num==4)
                           {
                            printf("You have exceeded the max number of attempts. Good Bye!\n");
                            fclose(fp);
                            exit(1);
                            }


    } // Closing for while loop on 136/137

} //for main function line 127

void display_all_emp()
{
    node *temp;
    temp=root;
    printf("Welcome to the Employee Management System!!\n");
    printf("---------------------------------------------------\n");
    printf("Name       ID      Dept    Salary    Address     Phone \n");
    printf("---------------------------------------------------\n");
    while(temp!=NULL)
        {
            printf("%s    ",temp->ename);
            printf("%d    ",temp->id);
            printf("%s    ",temp->dept);
            printf("%d    ",temp->salary);
            printf("%s    ",temp->address);
            printf("%s   \n",temp->phoneno);
            temp=temp->next;
        }
    printf("\n");
}

void display_one_emp()
{
    node *temp;
    temp=root;
    int num_id;
    printf("Enter your id to display your information:\n");
    scanf("%d",&num_id);
    while(temp!=NULL)
        {
            if(temp->id==num_id)
                {
                    printf("%s  ",temp->ename);
                    printf("%d  ",temp->id);
                    printf("%s  ",temp->dept);
                    printf("%d  ",temp->salary);
                    printf("%s  ",temp->address);
                    printf("%s  \n",temp->phoneno);
                }
            temp=temp->next;
        }
    printf("\n");
}

void update_emp_admin()
{
    node *temp;
    temp=root;
    int num_id;
    char ph_n[10],new_address[20];
    int new_salary;

    printf("Enter id number of the employee to be updated:\n");
    scanf("%d",&num_id);
    printf("Enter the new salary for the employee:\n");
    scanf("%d",&new_salary);
    printf("Enter the new phone number of employee:\n");
    scanf(" %s",&ph_n);
    printf("Enter the new address of employee:\n");
    scanf(" %s",&new_address);
    while(temp!=NULL)
        {
            if(temp->id==num_id)
                {
                    strcpy(temp->phoneno,ph_n);
                    strcpy(temp->address,new_address);
                    temp->salary=new_salary;
                }
            temp=temp->next;
        }
}

void delete_emp()
{
    node *p,*q;
    p=root;
    int num_id;
    printf("Enter id number of the employee to be deleted:\n");
    scanf("%d",&num_id);
    while(num_id!=p->id)
        {
            q=p;
            p=p->next;
        }
    q->next=p->next;
    p->next=NULL;
}

void add_emp(char ename[20],int id,char dept[15],int salary,char address[20],char phoneno[10])
{
    int vac_value=0;
    FILE *fp;
    node *temp;
    temp=(node *)malloc(sizeof(node));

    strcpy(temp->ename,ename);
    temp->id=id;
    strcpy(temp->dept,dept);
    temp->salary=salary;
    strcpy(temp->address,address);
    strcpy(temp->phoneno,phoneno);
    temp->next=NULL;

    if(root==NULL)
        {
            root=temp;
            end=temp;
        }
    else
        {
            end->next=temp;
            end=temp;
        }
//Entering employee name into the file

    fp=fopen("C:/Users/balan/Desktop/c programs/cfile.txt","a");
    fprintf(fp,"\n%s %d",ename,vac_value);
    fclose(fp);
}

void leave_permission()
{
    char ename[20];
    int choice;
    printf("Enter 1 to apply for Casual leave (CL) and 2 to apply for Earned leave (EL)\n");
    scanf("%d",&choice);
    printf("Your leave application has been submitted.\n");
    FILE *ft;
    char ch;
    ft=fopen("C:/Users/balan/Desktop/c programs/cfile_leave.txt","r+");
    if(ft==NULL)
        {
             printf("can not open target file\n");
             exit(1);
        }

    if(choice==1)
        {
            while ((ch = fgetc(ft)) != EOF)
                {
                    if ((ch == '0') || (ch=='2') || (ch =='3') || (ch=='4') || (ch=='5') || (ch=='6'))
                        {
                             fseek(ft, -1, SEEK_CUR);
                             fputc('1',ft);
                             fseek(ft, 0, SEEK_CUR);
                        }
                }
        }

    else if(choice==2)
        {
            while ((ch = fgetc(ft)) != EOF)
                {
                    if ((ch == '0') || (ch=='1') || (ch =='3') || (ch=='4') || (ch=='5') || (ch=='6'))
                        {
                             fseek(ft, -1, SEEK_CUR);
                             fputc('2',ft);
                             fseek(ft, 0, SEEK_CUR);
                        }
                }
        }
    fclose(ft);

} //Main function

void check_leave_status()
{
    int opt,num,value;
    num=1;
    char buf[2];
    FILE *fp;
    char leave_flag[2];
    fp=fopen("C:/Users/balan/Desktop/c programs/cfile_leave.txt","r");
    while (fgets(buf,20, fp)!=NULL)
        {
            strcpy(leave_flag,buf);
            if(leave_flag[0]=='1')
                {
                    printf("Your CL leave application is still pending:\n");
                    break;
                }
            else if(leave_flag[0]=='2')
                {
                    printf("Your EL leave application is still pending:\n");
                    break;
                }
            else if(leave_flag[0]=='3')
                {
                    printf("Your CL leave application has been approved:\n");
                    break;
                }
            else if(leave_flag[0]=='4')
                {
                    printf("Your EL leave application has been approved:\n");
                    break;
                }
            else if(leave_flag[0]=='5')
                {
                    printf("Your CL leave application has been declined:\n");
                    break;
                }
            else if(leave_flag[0]=='6')
                {
                    printf("Your EL leave application has been declined:\n");
                    break;
                }
        }
}

void display_options()
{
    int opt=0;
    while(opt!=9)
        {
            printf("Press 1 to View your employee information:\n");
            printf("Press 2 to Apply for Casual leave (CL) or Earned leave(EL):\n");
            printf("Press 3 to Check the status of leave application:\n");
            printf("Press 4 to Update your profile information:\n");
            printf("Press 9 to Exit:\n");
            scanf("%d",&opt);
            if(opt==1)
                {
                    display_one_emp();
                }
            else if(opt==2)
                {
                    leave_permission();
                }
            else if(opt==3)
                {
                    check_leave_status();
                }
            else if(opt==4)
                {
                    update_emp_user();
                }
            else if(opt==9)
                {
                    printf("Good Bye!\n");
                }

        }

}

void update_emp_user()
{
    node *temp;
    temp=root;
    int num_id;
    char ph_n[10],new_address[20];
    int new_salary;

    printf("Enter your employee id:\n");
    scanf("%d",&num_id);
    printf("Enter your new phone number:\n");
    scanf(" %s",&ph_n);
    printf("Enter your new address:\n");
    scanf(" %s",&new_address);
    while(temp!=NULL)
        {
            if(temp->id==num_id)
                {
                    strcpy(temp->phoneno,ph_n);
                    strcpy(temp->address,new_address);
                }
            temp=temp->next;
        }
}

void grant_decline_leave()
{
   char ename[20];
    int choice;
    printf("Enter 1 to Grant leave and 2 to Decline leave\n");
    scanf("%d",&choice);

    if (choice==1)
    {
        FILE *ft;
        char ch;
        ft=fopen("C:/Users/balan/Desktop/c programs/cfile_leave.txt","r+");
        if(ft==NULL)
            {
                 printf("can not open target file\n");
                 exit(1);
            }
        while ((ch = fgetc(ft)) != EOF)
            {
               if ((ch == '1') || (ch=='5'))
                    {
                        fseek(ft, -1, SEEK_CUR);
                        fputc('3',ft);
                        fseek(ft, 0, SEEK_CUR);
                    }

                 else if ((ch == '2') || (ch=='6'))
                    {
                        fseek(ft, -1, SEEK_CUR);
                        fputc('4',ft);
                        fseek(ft, 0, SEEK_CUR);
                    }
            }
        fclose(ft);
    }

    else if (choice==2)
    {
        FILE *ft;
        char ch;
        ft=fopen("C:/Users/balan/Desktop/c programs/cfile_leave.txt","r+");
        if(ft==NULL)
            {
                 printf("can not open target file\n");
                 exit(1);
            }
        while ((ch = fgetc(ft)) != EOF)
            {
               if ((ch == '1') || (ch=='3'))
                    {
                        fseek(ft, -1, SEEK_CUR);
                        fputc('5',ft);
                        fseek(ft, 0, SEEK_CUR);
                    }
                 else if ((ch == '2') || (ch=='4'))
                    {
                        fseek(ft, -1, SEEK_CUR);
                        fputc('6',ft);
                        fseek(ft, 0, SEEK_CUR);
                    }
            }
        fclose(ft);
    }
}
