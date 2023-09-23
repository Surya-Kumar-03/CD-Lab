#include <stdio.h>
#include <string.h>
void pm();
void plus();
void div();
int i, ch, j, l, addr = 100;
char ex[10], exp0[10], exp1[10], exp3[10], id1[5], op[5], id2[5];

void strrev(char *str)
{
    if (!str)
    {
        return;
    }

    int i = 0;
    int j = strlen(str) - 1;

    while (i < j)
    {
        char c = str[i];
        str[i] = str[j];
        str[j] = c;
        i++;
        j--;
    }
}

int main()
{
    // clrscr();
    printf("\nEnter the expression with arithmetic operator:");
    scanf("%s", ex);
    strcpy(exp0, ex);
    l = strlen(exp0);
    exp1[0] = '\0';

    for (i = 0; i < l; i++)
    {
        if (exp0[i] == '+' || exp0[i] == '-')
        {
            if (exp0[i + 2] == '/' || exp0[i + 2] == '*')
            {
                pm();
                break;
            }
            else
            {
                plus();
                break;
            }
        }
        else if (exp0[i] == '/' || exp0[i] == '*')
        {
            div();
            break;
        }
    }
    // getch();
}

void pm()
{
    strrev(exp0);
    j = l - i - 1;
    strncat(exp1, exp0, j);
    strrev(exp1);
    printf("Three address code:\ntemp=%s\ntemp1=%c%ctemp\n", exp1, exp0[j + 1], exp0[j]);
}

void div()
{
    strncat(exp1, exp0, i + 2);
    printf("Three address code:\ntemp=%s\ntemp1=temp%c%c\n", exp1, exp0[i + 2], exp0[i + 3]);
}

void plus()
{
    strncat(exp1, exp0, i + 2);
    printf("Three address code:\ntemp=%s\ntemp1=temp%c%c\n", exp1, exp0[i + 2], exp0[i + 3]);
}

/*Sample Output:

Enter the expression with arithmetic operator:
a+b-c
Three address code:
temp=a+b
temp1=temp-c

*/