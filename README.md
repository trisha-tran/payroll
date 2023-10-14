Please solve the following Problem:
You need to store and manage Payroll Records stored as an array of structures of the following form:

struct payroll {
unsigned long long int internal_id; char first_name[50];
char last_name[50];
char department[100];
      unsigned char dob_day;
      unsigned char dob_month;
      unsigned short dob_year;
      double monthly_salary;
};

The array of structures is stored as an external variable
#define MAX_PAY_RECS_NO 10000
struct payroll pay_recs[MAX_PAY_RECS_NO];

The number of actual payroll records is stored in the following external variable: 
size_t pay_recs_no;

Your responsibility is to develop a function that prints out the payroll records of employees of a certain department, 
the number of employees in the department and their aggregated monthly salary (sum of monthly salaries of the department’s employees).
The output should be made in the following format:

Employees of the department_name Department:
Last Name  First Name   Date of Birth   Monthly Salary
---------------------------------------------------------
Smith      John         1997-01-20      5920.00
Gary       Richard      1991-07-03      6530.00
Nataly     Jason        1995-03-05      6200.00

Total Number of Employees in the Department: 3 
Aggregated Salary of the Department: 18650.00
If the department supplied as a parameter of the function has no payroll records, the function shall print the following:
Department department_name has no payroll records. 
This is the function’s signature:

void PrintDeptPayrollRecords(char* dept_name);

In the main() function, please initialize 10 or more payroll records in the payroll records array pay_recs[],
and call the abovementioned function with the name of an existing department,
and then with non-existing one, and check that a correct output is generated.
