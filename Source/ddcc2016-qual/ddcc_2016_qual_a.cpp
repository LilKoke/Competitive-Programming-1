#include <stdio.h>

int main(){
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    double answer = (double)b * (double)c / (double)a;
    printf("%lf", answer);
    return 0;
}
