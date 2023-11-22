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
void update_emp();
void add_emp(char ename[20],int id,char dept[15],int salary,char address[20],char phoneno[10]);
void delete_emp();
void display_emp();
int main()
{
    char ename[20];
    int id;
    char dept[15];
    int salary;
    char address[20];
    char phoneno[10];

    add_emp("Sandesh",11111,"Sales",1000,"Hyderabad","9999999999");
    add_emp("Rahul",22222,"HR",2000,"Delhi","8888877777");
    add_emp("Arjun",33333,"Marketing",3000,"Bengaluru","7776669954");
    add_emp("Surya",44444,"Engineering",4000,"Mumbai","6676221020");
    add_emp("Krishna",55555,"Designing",5000,"Chennai","8885557219");
    int opt;
    while(opt!=9)
        {
            printf("Press 1 to Add a new employee:\n");
            printf("Press 2 to Update an existing employee:\n");
            printf("Press 3 to Delete an employee:\n");
            printf("Press 4 to Display all the employees:\n");
            scanf("%d",&opt);
            if(opt==1)
                {
                    printf("Enter employee name:\n");
                    scanf(" %s",&ename);
                    printf("Enter employee id:\n");
                    scanf("%d",&id);
                    printf("Enter department:\n");
                    scanf(" %s",&dept);
                    printf("Enter salary:\n");
                    scanf("%d",&salary);
                    printf("Enter address:\n");
                    scanf(" %s",&address);
                    printf("Enter phone number:\n");
                    scanf(" %s",&phoneno);
                    add_emp(ename,id,dept,salary,address,phoneno);
                }
            else if(opt==2)
                {
                    update_emp();
                }
            else if(opt==3)
                {
                    delete_emp();
                }
            else if(opt==4)
                {
                    display_emp();
                }
        }
}


void display_emp()
{
    node *temp;
    temp=root;
    printf("Welcome to the Employee Management System!!\n");
    printf("---------------------------------------------------\n");
    printf("Name  ID  Department  Salary  Address  Phonenumber \n");
    printf("---------------------------------------------------\n");
    while(temp!=NULL)
        {
            printf("%s  ",temp->ename);
            printf("%d  ",temp->id);
            printf("%s  ",temp->dept);
            printf("%d  ",temp->salary);
            printf("%s  ",temp->address);
            printf("%s  \n",temp->phoneno);
            temp=temp->next;
        }
    printf("\n");
}

void update_emp()
{
    node *temp;
    temp=root;
    int num_id;
    char ph_n[10];
    printf("Enter id number of the employee to be updated:\n");
    scanf("%d",&num_id);
    printf("Enter the new phone number of employee to be updated:\n");
    scanf(" %s",&ph_n);
    while(temp!=NULL)
        {
            if(temp->id==num_id)
                {
                    strcpy(temp->phoneno,ph_n);
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
}
