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

/**
 * D1 > D2: -> <0
 * D1 < D2: -> >0
 * D1 = D2: -> =0
 */
int Date_cmp(Date D1, Date D2) {
    if (D1.year != D2.year) {
        return D2.year - D1.year;
    } else if (D1.month != D2.month) {
        return D2.month - D1.month;
    } else if (D1.day != D2.day) {
        return D2.day - D1.day;
    } else return 0;
}

void Date_term_export(Date D) {
    printf("%d/%d/%d", D.day, D.month, D.year);
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

void Array__Employee_swap(Employee *E1, Employee *E2) {
    Employee *T = E1;
    E1 = E2;
    E2 = T;
}

//[Exercise 4]
int Array__Employee_searchByID(char *ID, Employee E[], int n) {
    for(int i = 0; i < n; ++i)
        if (strcmp(ID, E[i].id) == 0)
            return i;
    return -1;
}
//[Exercise 6]
int Array__Employee_sortBubble_birthday(Employee *E, int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (Date_cmp(E[i].birthday, E[j].birthday) < 0) {
                Array__Employee_swap(&E[i], &E[j]);
            }
        }
    }
}

int Array__Employee_sortBubble_salary(Employee *E, int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (E[i].salary > E[j].salary) {
                Array__Employee_swap(&E[i], &E[j]);
            }
        }
    }
}

int Array__Employee_findMax_salary_index(Employee *E, int n) {
    int max = 0;
    int max_index = 0;
    for (int i = 0; i < n; ++i) {
        if (E[i].salary > max) {
            max = E[i].salary;
            max_index = i;
        }
    }
    return max_index;
}

void Array__Employee_delete(Employee *E, int *n, char *ID) {
    int pos = -1;
    for (int i = 0; i < *n; ++i)
        if (strcmp(ID, E[i].id) == 0) pos = i;
    for (int i = pos; i < *n - 1; ++i)
        E[i] = E[i + 1];
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
    //[Exercise 5]
    puts("-<COUNTING MALE/FEMALE>-");
    int count[2] = {0};
    for (int i = 0; i < n; ++i) {
        if (!strcmp(employee_1[i].sex, "Male")) ++count[0];
        else ++count[1];
    }
    printf("%d Male, %d Female", count[0], count[1]);
    puts("-<SORT BY BIRTHDAY (ASCENDING)>-");
    Array__Employee_sortBubble_birthday(employee_1, n);
    printf("Employee array after sort by birthday:\n\t");
    for (int i = 0; i < n; ++i) {
        Employee_term_export(employee_1[i]);
    }
    puts("-<SORT BY SALARY (ASCENDING)>-");
    Array__Employee_sortBubble_salary(employee_1, n);
    printf("Employee array after sort by salary:\n\t");
    for (int i = 0; i < n; ++i) {
        Employee_term_export(employee_1[i]);
    }
    puts("-<HIGHEST SALARY>-");
    int k = Array__Employee_findMax_salary_index(employee_1, n);
    printf("Employee have the highest salary is %s!", employee_1[k].name);
    puts("-<YOUNGEST EMPLOYEE>-");
    Array__Employee_sortBubble_birthday(employee_1, n);
    printf("The youngest employee is %s!", employee_1[0].name);
    char *ID = (char*) malloc(16 * sizeof(char));
    printf("Enter employee's ID to delete");
    fgets(ID, 16, stdin);
    LF_trim(ID);
    Array__Employee_delete(&employee_1, &n, ID);
    printf("Employee array after delete %s", ID);
    for (int i = 0; i < n; ++i) {
        Employee_term_export(employee_1[i]);
    }
    return 0;
}
