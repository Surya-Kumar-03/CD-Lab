#include <string.h>
int countbit1(int n)
{
    int bits = 0, i = 0;
    while (n != 0)
    {
        if (n & 1)
            bits++;
        n >>= 1;
        i++;
    }
    printf("\n no of iterations %d", i);
    return bits;
}
int countbit2(int n)
{
    int bits = 0, i = 0;
    while (n != 0)
    {
        if (n & 1)
            bits++;
        if (n & 2)
            bits++;
        if (n & 4)
            bits++;
        if (n & 8)
            bits++;
        n >>= 4;
        i++;
    }
    printf("\n no of iterations %d", i);
    return bits;
}
int main()
{
    unsigned int n;
    int x = 0;
    char ch;
    printf("\nEnter N\n");
    scanf("%u", &n);
    printf("\n1. Loop Roll\n2. Loop UnRoll\n");
    printf("\nEnter your choice\n");
    scanf(" %c", &ch);
    switch (ch)
    {
    case '1':
        x = countbit1(n);
        printf("\nLoop Roll: Count of 1's : %d", x);
        break;
    case '2':
        x = countbit2(n);
        printf("\nLoop UnRoll: Count of 1's : %d", x);
        break;
    default:
        printf("\nWrong Choice\n");
        return 1;
    }
    return 0;
}
