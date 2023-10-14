#include <stdio.h>
#include <string.h>
#define MAX_PAY_RECS_NO 10000
 
void PrintDeptPayrollRecords(char* dept_name); //Prototype

//Structure for payroll
struct payroll {
  unsigned long long int internal_id; 
  char first_name[50];
  char last_name[50];
  char department[100];
  unsigned char dob_day;
  unsigned char dob_month;
  unsigned short dob_year;
  double monthly_salary;
};

size_t pay_recs_no = 0;
struct payroll pay_recs[MAX_PAY_RECS_NO];
 
int main(void)
{
  //Pay records
  struct payroll pay_recs[10] = {
		{235, "John", "Smith", "R&D", 19, 03, 1982, 7350.00},
		{251, "Peter", "Jacobs", "IT", 29, 01, 1983, 7000.00},
		{190, "Johnny", "Smith", "IT", 01, 03, 1972, 5320.00},
		{210, "James", "Rivera", "Sales", 19, 03, 1982, 7350.00},
		{205, "Pedro", "Adriano", "R&D", 19, 03, 1982, 7350.00},
		{17, "Luke", "Skywalker", "Accounting", 19, 03, 1982, 7350.00},
		{29, "Obi-One", "Kenobi", "Engineering", 19, 03, 1982, 7350.00},
		{35, "Leslie", "Montgomery", "Engineering", 19, 03, 1982, 7350.00},
		{11, "Peter", "Sanders", "HR", 19, 03, 1982, 7350.00},
		{1025, "Barbara", "Williams", "Accounting", 19, 03, 1982, 7350.00}
	};

  char departmentName[100]; 
  int i, totalEmployees;
  double salary;

  printf("Enter department name: ");
  scanf(" %s", departmentName);
  
  for(i = 0; i < 10; i++) //Compares department entered with existing department in struct
  {
   if(strcmp(departmentName, pay_recs[i].department) == 0) //Condition if there is an existing department
    {

     pay_recs_no++; //Adds total number of records
     totalEmployees++; //Adds total employees in department
    }  
  }

  PrintDeptPayrollRecords(departmentName); //Function call

  //Iterates through arrays in pay_recs and prints employee info if department is found
 for(i = 0; i <= 10; i++){
  if(strcmp(departmentName, pay_recs[i].department) == 0)
    {
      printf("\n%s\t\t\t%s\t\t\t%u-%u-%u\t\t\t%.2f",
      pay_recs[i].last_name,
      pay_recs[i].first_name,
      pay_recs[i].dob_year, 
      pay_recs[i].dob_month, 
      pay_recs[i].dob_day,
      pay_recs[i].monthly_salary);

      salary += pay_recs[i].monthly_salary; //Adds up salary from specific department
    }
 }

  
 if(totalEmployees > 0) //Condition if employees are found in department and prints total employees and aggregated salary
 {
    printf("\n\nTotal Number of Employees in the Department: %d", totalEmployees);
    printf("\nAggregated Salary of the Department: %.2f", salary);
 }
}

void PrintDeptPayrollRecords(char* dept_name)
{
  if(pay_recs_no > 0) //Condition if pay recs are found in a specific department
  {
    printf("\nEmployees of %s Department\n", dept_name);
    printf("Last Name \t\tFirst Name\t\t Date of Birth\t\t Monthy Salary ");
    printf("\n------------------------------------------------------------");
  }

  else if(pay_recs_no == 0) //Condition if no pay recs are found
  {
    printf("\nDepartment %s has no payroll records.",dept_name);
  }
  
}
