/*
    Ex1:
        Write a C program to print your name, date of birth and mobile number
    Ex2:
        Write a C program promting user to input two integer numbers, then compute and
        print the results of addition, subtraction, multiplication, division and remainder
    Ex3:
        Write a C program to compute the perimeter and area of a rectangle
    Ex4:
        Write a C program to convert specified days into years, weeks and days (ignore leap year)
    Ex5:
        Write a C program to convert celsius to fahrenheit
    Ex6:
        Write a C program to return an absolut value of a number
    Ex7:
        Write a C program to check whether a year is a leap year or not
    Ex8:
        Write a C program to find maximum between 2 numbers
    Ex9: 
        Write a C program to find maximum between 3 numbers
    Ex10:
        Write a C program to check whether a number is even or odd
    Ex11:
        Write a C program to input a character and check whether it is alphanumeric or not
    Ex12:
        Write a C program to input angle of a triangle and check whether triangle is valid or not
    Ex13:
        Write a C program to input marks of five subjects: Physics, Chemistry, Biology,
        Mathematics, Computer. Calculate percentage and grade according to following:
        Percentage > 90%: Grade A
        Percentage > 80%: Grade B
        Percentage > 70%: Grade C
        Percentage > 60%: Grade D
        Percentage > 40%: Grade E
        Percentage < 40%: Grade F
*/

#include <stdio.h>

void Ex1_introduce() {
    printf("Name: Ho Sy Duy\n");
    printf("Date of birth: 11/04/2006\n");
    printf("Mobile number: 0373850103\n");
}

void Ex2_binaryOperation(int a, int b) {
    if (b != 0) {
        printf("Addition: %d + %d = %d\n", a, b, a + b);
        printf("Subtract: %d - %d = %d\n", a, b, a - b);
        printf("Multiplication: %d * %d = %d\n", a, b, a * b);
        printf("Division: %d / %d = %d\n", a, b, a / b);
        printf("Remainder: %d mod %d = %d\n", a, b, a % b);
    } else printf("Aecond number equal to zero!");
}

void Ex3_rectanglePerimeterArea(int h, int w) {
    printf("Rectangle perimeter: %d\n", (a + b) * 2);
    printf("Rectangle area: %d\n", a * b);
}

void Ex4_dayToYearWeekDay(unsigned int dayAmount) {
    int year = dayAmount / 365;
    dayAmount %= 365;
    int week = dayAmount / 7;
    int day = dayAmount % 7;
    printf("%d year, %d week, %d day.", year, week, day);
}

int Ex5_celsiusToFahrenheit(int celsius) {
    return (celsius * 1.8) + 32;
}

int Ex6_absoluteValue(int a) {
    return (a > 0 ? a : -a);
}

void Ex7_leapYearCheck(unsigned int year) {
    if ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0)) printf("Leap year!");
    else printf("Not a leap year!");
}

void Ex8_twoMax(int a, int b) {
    printf("Maximum is %d", (a > b ? a : b));
}

void Ex9_threeMax(int a, int b, int c) {
    printf("Maximum is %d", ((a > b && a > c) ? a : (b > c ? b : c)));
}

void Ex10_evenOddCheck(int a) {
    if (a % 2 == 0) printf("Even");
    else printf("Odd");
}

void Ex11_alphanumericCheck(char c) {
    if (33 <= c && c <= 126) printf("Alphanumeric!");
    else printf("Non alphanumeric!");
}

void Ex12_triangleValidCheck(unsigned int a, unsigned int b, unsigned int c) {
    if ((a + b + c) == 180) std::cout("Valid triangle!");
    else std::cout("Invalid triangle!")
}

int Ex13_markInput() {
     int mark = 0;
    while (true) {
        scanf("%d", &mark);
        if (mark <= 100 && mark >= 0) {
            break;
        } else {
            printf("Invalid! Enter again: ");
        }
    }
    return mark;
}

char Ex13_gradeCalculate(float percentage) {
    if (60 < percentage && percentage <= 90) {
        if (percentage > 70) {
            return 'C';  
        } else if (percentage > 80) {
            return 'B';
        } else {
            return 'D';
        }
    } else if (percentage <= 60) {
        if (percentage <= 40) {
            return 'F';
        } else {
            return 'E';
        }
    } else {
        return 'A';
    }
}

void Ex13_main() {
    float percentage = 0;
    printf("Enter mark (Physics, Chamistry, Biology, Mathematics, Computer): ");
    for (int i = 0; i < 5; ++i) {
        percentage += Ex13_markInput();
    }
    percentage /= 5;
    printf("Grade: %c", Ex13_gradeCalculate(percentage));
}

int main() {
    return 0;

}

