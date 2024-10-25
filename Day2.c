/*
    1. Input a string and return string's length
    2. Input a string and print it in reverse order
    3. Input a string represent a full name, split and print the first name and the last name.  
    4. Input a string and normalize it (trim the space before, inside, and after; to lower each token except the first). For example, with the input "  PrOgRaMmIng   MeThOd  ", the output will be "Programming Method".  
    5. Input two string s1 and s2, concatenating s2 to s1. (Note: don’t use string.h library).  
    6. Input a string and check whether a character appears or not. If yes, return the first position.  
    7. Input a string and check whether a character appears or not. If yes, return all appearing positions.  
    8. Input a string and check whether a word appears or not. If yes, return the first position.  
    9. Input two string s1 and s2, return the first position where s2 appears in s1.  
    10. Input two string s1, s2, and position. Then insert s2 to s1 from this position.  
    11. Input a string and two integer numbers, named n and position. Then delete n characters from position of input string.  
*/

#include <stdio.h>

void Ex1() {
    char a[100] = {0};
// <=>
    printf("Enter any string: ");
    fgets(a, 100, stdin);
// <=> <=>
    {
        int c = -1;
        for (int i = 0; a[i] != '\0'; ++i) {
            ++c;
        }
        printf("String length: %d", c);
    }
}

void Ex2() {
    char c[100] = {0};
// <=>
    printf("Enter anything: ");
    fgets(c, 100, stdin);
// <=> <=>
    {
        int k = 0;
        for (int i = 0; c[i] != '\0'; ++i) {
            
        }
    }
}

void Ex3() {
    char c[100] = {0};
    char d[10][100] = {0};
// <=>
    printf("Enter anything: ");
    fgets(c, 100, stdin);
// <=> <=>
    {
        int f1 = 0;
        int f2 = 0;
        for (int i = 0; c[i] != '\n'; ++i) {
            if (c[i] == ' ') {
                ++f1;
                f2 = 0;
                continue;
            }
            d[f1][f2] = c[i];
            ++f2;
        }

        printf("First name: %s, Last name: %s\n", d[f1], d[0]);
    }
}

void Ex4() {
    char c[100] = {0};
    char z[100] = {0};
// <=>
    printf("Enter anything: ");
    fgets(c, 100, stdin);
// <=> <=>
    {
        int m = 0;
        for (int i = 0; c[i] != '\n'; ++i) {
            if (c[i] != ' ' || c[i] == ' ' && c[i - 1] != ' ') {
                z[m] = c[i];
                ++m;
            }
        }
        for (int i = 0; z[i] != '\n'; ++i) {
            if (i == 0 || z[i - 1] == ' ') {
                if ('a' <= z[i] &&  z[i] <= 'z') {
                    z[i] -= 32;
                }
            } else if ('A' <= z[i] &&  z[i] <= 'Z') {
                    z[i] += 32;
            }
        }
        printf("%s", z);
    }
}

void Ex5() {
    char a[100] = {0};
    char b[100] = {0};
// <=>
    printf("Enter first string: ");
    fgets(a, 100, stdin);
// <=>
    printf("Enter second string: ");
    fgets(b, 100, stdin);
// <=> <=>
    {
        char c[200] = {0};
        int k = 0;
        while (a[k] != '\n') {
            c[k] = a[k];
            ++k;
        }
        int f = 0;
        while (b[f] != '\n') {
            c[k] = b[f];
            ++f;
            ++k;
        }
        puts(c);
    }   
}

void Ex6() {
    char a[100] = {0};
    int f = -1;
// <=>
    printf("Enter any string: ");
    fgets(a, 100, stdin);
// <=>
    printf("Enter any character: ");
    char c = getchar();
// <=> <=>
    {
        for (int i = 0; a[i] != '\n'; ++i) {
            if (a[i] == c) {
                f = i; 
                break;
            }
        }
        if (f == -1) {
            printf("The character isn't appear in this string\n");
        } else {
            printf("%d", f);
        }

    }
}

void Ex7() {
    char a[100] = {0};
    int s[100] = {0}; s[0] = 0;
// <=>
    printf("Enter any string: ");
    fgets(a, 100, stdin);
// <=>
    printf("Enter any character: ");
    char c = getchar();
// <=> <=>
    {
        for (int i = 0; a[i] != '\n'; ++i) {
            if (a[i] == c) {
                s[++s[0]] = i;
            }
        }
        if (s[0] == -1) {
            printf("The character isn't appear in this string\n");
        } else {
            for (int i = 1; i <= s[0]; ++i) {
                printf("%d ", s[i]);
            }
        }

    }
}

void Ex8() {
    int havingSpace(char c[]) {
        for (int i = 0; c[i] != '\n'; ++i) {
            if (c[i] == ' ') return 0;
        }
        return 1;
    };
    char a[100] = {0};
    char c[100] = {0};
    printf("Enter any string: ");
    fgets(a, 100, stdin);
// <=>    
    do {
        printf("Enter any word: ");
        fgets(c, 100, stdin);
    } while (!havingSpace(c));
// <=> <=>
    {
        int res = -1;
        int _t = 0;
        for (int i = 0; a[i] != '\n'; ++i) {
            if (a[i] == c[_t] && a[i - _t - 1] == ' ') {
                res = (res == -1 ? i : res);
                if (a[i + 1] == ' ') break;
                ++_t;
            } else {
                _t = 0;
                res = -1;
            }
        }
        printf("%d\n", res);
    }
}

void Ex9() {
    char a[100] = {0};
    char c[100] = {0};
    printf("Enter first string: ");
    fgets(a, 100, stdin);
// <=>    
    printf("Enter second string: ");
    fgets(c, 100, stdin);
// <=> <=>
    {
        int res = -1;
        int _t = 0;
        for (int i = 0; a[i] != '\n'; ++i) {
            if (a[i] == c[_t]) {
                res = (res == -1 ? i : res);
                if (c[_t + 1] == '\n') break; 
                ++_t;
            } else {
                _t = 0;
                res = -1;
            }
        }
        printf("%d\n", res);
    }
}

void Ex10() {
    char c[100] = {0};
    char p[100] = {0};
    char w[100] = {0};
// <=>
    printf("Enter first string: ");
    fgets(c, 100, stdin);
// <=>
    printf("Enter second string: ");
    fgets(p, 100, stdin);
// <=>
    int pos = 0;
    printf("Enter inserting position: ");
    scanf("%d", &pos);
// <=> <=>
    {
        int _c = 0;
        int _p = 0;
        for (int i = 0; c[_c] != '\n'; ++i) {
            if (_c < pos || pos < _c) {
                w[i] = c[_c];
                ++_c;
            } else if (_c == pos) {
                if (p[_p] == '\n') {
                    w[i] = c[_c];
                    ++_c;
                    continue;
                }
                w[i] = p[_p++];
            }
        }
    }
    printf("%s", w);
}

void Ex11() {
    char c[100] = {0};
    char p[100] = {0};
// <=>
    printf("Enter first string: ");
    fgets(c, 100, stdin);
// <=>
    int d = 0;
    int a = 0;
    printf("Enter deleting position and amount of character to delete: ");
    scanf("%d", &d);
    scanf("%d", &a);
// <=> <=>
    {   
        int _c = 0;
        for (int i = 0; p[i] != '\n'; ++i) {
            if (_c < d || d + a - 1 <= _c) {
                p[i] = c[_c];
                ++_c;
            } else {
                _c += a;
                --i;
            }
        }
    }
    printf("%s", p);   
}

int main() {
    // call any function above
    Ex8();
}