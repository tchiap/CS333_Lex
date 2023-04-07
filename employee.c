/**************************************************************


***************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max_emp 200
#define max_dept 5

void menu(void);
void add_e(void);
void delete_e(void);
void update_e(void);
int get_index(char id[6]);
void list_employee_info(int index);
void employee_by_dept(void);

struct sname{
  char lastn[20];
  char middlen[20];
  char firstn[20];};
  
struct saddress{
    char street[30];
    char city[20];
    char state[3];
    char zipcode[6];};
    
typedef struct{
    char id[6];
    struct sname name;
    struct saddress address;
    char department[20];
    float salary;} employee;
    

typedef struct{
    char *dname;
    char *location;
    char manager[6];
    float budget;}dept;
    
employee e[max_emp];
dept d[max_dept];
int current_num_e=0;



int main()
{
   menu();

   return 0;

}


void menu(void)
{
         int opt;
     
     
         
     do{  
     
     puts("Select an option");
     puts("1.- Insert new employee");
     puts("2.- Delete employee");
     
     puts("8.- Exit");
     scanf("%d",&opt);
     
     if(opt == 1) add_e();
     if(opt == 2) add_e();
     if(opt == 3) update_e();
     if (opt== 7) employee_by_dept();
      }while(opt!=8);
 
}


void add_e(void)
{
     puts("Enter id");
     gets(e[current_num_e].id);
     puts("Enter last name");
     gets(e[current_num_e].name.lastn);
     puts("Enter first name");
     gets(e[current_num_e].name.firstn);
     puts("Enter middle name");
     gets(e[current_num_e].name.middlen);
     puts("Enter department");
     gets(e[current_num_e].department);
     puts("Enter salary");
     scanf("%f",&e[current_num_e].salary);
     
     current_num_e++;
}

void list_employee_info(int index)
{    
     printf("Id: %s\n",e[index].id );
     printf("Last name: %s\n",e[index].name.lastn);
}

int get_index(char id[6])
{
    int index;
    for(index=0; index<max_emp; index++)
        if(strcmp(id,e[index].id)==0) return index;
    return -1;
}


void update_e(void)
{
   int i;
   float sal;
   char id[6];
   puts("Enter Employee ID");
   gets(id);
   i=get_index(id);
   


void delete_e(void)
{

}

}
void employee_by_dept(void)
{
   
}  

         
