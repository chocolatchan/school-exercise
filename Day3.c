#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void LF_trim(char *str) {
    int i = 0;
LOOP:
    if (str[i] != 10 || str[i] == 0) {
        ++i;
        goto LOOP;
    }
    str[i] = 0;
}

void buffer_clear() {
    while (getchar() != '\n');
}

int isLeap(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) return 1;
    return 0;
}

typedef struct {
    int day;
    int month;
    int year;
} Date;

void Date_term_export(Date D) {
    printf("%d/%d/%d", D.day, D.month, D.year);
}

void Date_inp(Date *D, int day, int month, int year) {
    D -> day = day;
    D -> month = month;
    D -> year = year;
}

int Date_valid_check(Date D) {
    int days[] = {31, 28 + isLeap(D.year), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (0 > D.month || D.month > 12)
        return 0;
    else 
        return (0 < D.day) && (D.day < days[D.month]);
}

//[Exercise 1]
typedef struct {
    char *id;
    char *name;
    char *sex;
    Date birthday;
    int salary;

} Employee;

//[Exercise 3]
void Employee_term_export(Employee E) {
    printf("Name: %s\nSex: %s\n", E.name, E.sex);
    printf("Birthday: "); Date_term_export(E.birthday); puts("");
    printf("ID: %s\nSalary: %d\n", E.id, E.salary);
}

void Employee_term_import(Employee *E) {
    // Alloc
    E -> name = (char*) malloc(64 * sizeof(char));
    E -> sex = (char*) malloc(8 * sizeof(char));
    E -> id = (char*) malloc(16 * sizeof(char));

    printf("Enter employee's name\n\t> ");
    fgets(E -> name, 64, stdin);
    printf("Enter employee's gender\n\t> ");
    fgets(E -> sex, 8, stdin);
    printf("Enter employee's birthday[day/month/year]\n\t> ");
LOOP:
    scanf("%d %d %d",
        &E -> birthday.day,
        &E -> birthday.month,
        &E -> birthday.year
    );
    buffer_clear();
    if (!Date_valid_check(E -> birthday)) {
        printf("Invalid date! Enter again!\n\t> ");
        goto LOOP;
    }
    printf("Enter employee's ID\n\t> ");
    fgets(E -> id, 16, stdin);
    printf("Enter employee's salary\n\t> ");
    scanf("%d", &(E -> salary));
    buffer_clear();
    LF_trim(E -> name);
    LF_trim(E -> sex);
    LF_trim(E -> id);
}

//[Exercise 4]
int Array__Employee_searchByID(char *ID, Employee E[], int n) {
    for(int i = 0; i < n; ++i)
        if (strcmp(ID, E[i].id) == 0)
            return i;
    return -1;
}

int main() {
    int n = 2;
    //[Exercise 2]
    Employee employee_1[n];

    for (int i = 0; i < n; ++i) {
        printf("--[Employee %d]--\n", i + 1);
        Employee_term_import(&employee_1[i]);
    }
    puts("-<PRINT EVERY EMPLOYEE INFORMATION>-");
    for (int i = 0; i < n; ++i) {
        printf("--[Employee %d]--\n", i + 1);
        Employee_term_export(employee_1[i]);
    }
    puts("-<SEARCH EMPLOYEE'S ID IN ARRAY>-");
    char *ID = (char*) malloc(16 * sizeof(char));
    printf("Enter an ID to search\n\t> ");
    fgets(ID, 16, stdin);
    LF_trim(ID);
    printf("ID founded at index %d\n", Array__Employee_searchByID(ID, employee_1, n));
    return 0;
}