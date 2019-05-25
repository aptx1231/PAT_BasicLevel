#include <stdio.h>

long getgcd(long a, long b);
void printfrac(long a, long b);

int main () {
    long a1;
    long b1;
    long a2;
    long b2;
    char op[4] = {'+', '-', '*', '/'};
    int i;

    scanf("%ld/%ld %ld/%ld", &a1, &b1, &a2, &b2);
    for(i = 0; i < 4; i++) {
        printfrac(a1, b1);
        printf(" %c ", op[i]);
        printfrac(a2, b2);
        printf(" = ");
        // 我们使用的是long, 这里不用同分, 直接计算
        switch (op[i]) {
            case '+':
                printfrac(a1 * b2 + a2 * b1, b1 * b2); 
                break;
            case '-':
                printfrac(a1 * b2 - a2 * b1, b1 * b2);
                break;
            case '*':
                printfrac(a1 * a2, b1 * b2);
                break;
            case '/':
                printfrac(a1 * b2, b1 * a2);
                break;
        }
        printf("\n");
    }

    return 0;
}


long getgcd (long a, long b) {
    // 用其它求gcd的方法, 很可能导致
    // 后两个测试点超时, 原因不明
    long r;
    while ((r = a % b)) {
        a = b;
        b = r;
    }
    
    return b;
}


void printfrac (long a, long b) {
    /*
        这里的a, b有多种情况, 正正, 正负, 负负都有可能
        再下面判断符号时, 充分利用了负负的正的思想
    */
    if (b == 0) {
        printf("Inf");
        return;
    }

    int sign = 1;
    long gcd;
    if (a < 0) {
        a = -a;
        sign = sign * -1;
    }
    if (b < 0) {
        b = -b;
        sign = sign * -1;
    }
    gcd = getgcd(a, b);
    a = a / gcd;
    b = b / gcd;

    if (sign == -1) printf("(-");
    if (b == 1) {
        printf("%ld", a);   // 整数
    } else if (a > b) {
        printf("%ld %ld/%ld", a / b, a % b, b);
    } else {
        printf("%ld/%ld", a, b); // a < b
    }
    if (sign == -1) printf(")");
}
