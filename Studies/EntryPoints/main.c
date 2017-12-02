#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAXPOW 25

int main() {
    FILE *fp;
    fp=fopen("collatzEntryPoints.csv","w");
    int n=0;
    unsigned int power, div;
    for (n=0; n<MAXPOW; n++){
        power = (unsigned int) pow(2, n);
        switch ((power - 1) % 3) {
            case 0:
                div = (power - 1) / 3;
                fprintf(fp, "%d;%d;%d\n", n, power, div);
                break;
            default:
                fprintf(fp, "%d;%d;%d\n", n, power, 0);
                break;
        }
    }

    fclose(fp);
    return 0;
}