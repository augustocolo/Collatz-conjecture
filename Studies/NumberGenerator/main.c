#include <stdio.h>
#define INF 1000
#define true 1
#define false 0

typedef struct node{
    unsigned int previousOdd;
    unsigned int previousEven;
    unsigned int next;
}node;

node number[INF*5];

int main() {
    FILE *fp;
    fp= fopen("collatzNodes.csv","w");
    unsigned int i;
    for (i=1;i<INF+1;i++) {
        switch (i % 2) {
            case 0:
                number[i].next= i/2;
                if (((i-1) % 3) == 0) {
                    number[i].previousOdd = (i-1)/3;
                }
                number[i].previousEven = i*2;
                break;
            case 1:
                number[i].next=(i*3)+1;
                number[i].previousEven=i*2;
                number[i].previousOdd=false;
                break;
            default:
                break;
        }
        fprintf(fp,"%d;%d;%d;%d\n",i,number[i].next,number[i].previousEven,number[i].previousOdd);
    }
    fclose(fp);
    return 0;
}