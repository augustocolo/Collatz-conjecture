#include <stdio.h>
#include <limits.h>

#define INF 1431655764
#define true 1
#define false 0

int numberone;

int evenNumber(int n){
    n=n/2;
    if (n==1){
        numberone=true;
    }
    return n;
}

int oddNumber (int n){
    n=(n*3)+1;
    if (n==1){
        numberone=true;
    }
    return n;
}

int main() {
    unsigned int n,i;
    int div, passage;
    printf("-\n");
    for (n=1;n<INF;n++){
        passage=0;
        i=n;
        numberone=false;
        while (numberone==false) {
            div = i % 2;
            switch (div) {
                case 0:
                    i=evenNumber(i);
                    break;
                case 1:
                    i=oddNumber(i);
                    break;
                default:
                    printf("NOT ODD NOR EVEN???\n");
                    return 1;
            }
            passage++;
        }
        printf("Number %d found in %d passages\n\n", n, passage);
    }
    return 0;

}