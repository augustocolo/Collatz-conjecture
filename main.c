#include <stdio.h>
#include <limits.h>

#define INF (((UINT_MAX/1000)-1)/3)
#define true 1
#define false 0

int numberone;

unsigned int evenNumber(unsigned int n){
    n=n/2;
    if (n==1){
        numberone=true;
    }
    return n;
}

unsigned int oddNumber (unsigned int n){
    n=(n*3)+1;
    if (n==1){
        numberone=true;
    }
    return n;
}

void collatzGeneralN(){
    FILE *fp;
    fp = fopen("collatzGeneralMove.csv","w");
    FILE *sp;
    sp= fopen("collatzGeneralPrev.csv","w");
    unsigned int n,i,l;
    int div, passage;
    printf("-\n");
    for (n=1;n<INF;n++){
        passage=0;
        i=n;
        l=0;
        numberone=false;
        while (numberone==false) {
            div = i % 2;
            switch (div) {
                case 0:
                    i=evenNumber(i);
                    break;
                case 1:
                    l=i;
                    i=oddNumber(i);

                    break;
                default:
                    printf("NOT ODD NOR EVEN???\n");
            }
            passage++;
        }
        printf("Number %d found in %d passages - last odd was %d\n\n", n, passage,l);
        fprintf(fp,"%d;%d\n",n,passage);
        fprintf(sp,"%d;%d\n",n, l);
    }
    fclose(fp);
    fclose(sp);
}

void collatzOddN(){
    FILE *fp_odd;
    fp_odd= fopen("collatzOddN.csv", "w");
    FILE *sp_odd;
    sp_odd= fopen("collatzOddPrev.csv","w");
    unsigned int n,i,l;
    int div, passage;
    printf("-\n");
    for (n=1;n<INF;n+=2){
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
                    l=i;
                    i=oddNumber(i);

                    break;
                default:
                    printf("NOT ODD NOR EVEN???\n");
            }
            passage++;
        }
        printf("Number %d found in %d passages. last odd was %d\n\n", n, passage,l);
        fprintf(fp_odd,"%d;%d\n",n,passage);
        fprintf(sp_odd,"%d;%d\n",n, l);
    }
    fclose(fp_odd);
    fclose(sp_odd);

}

void collatzEvenN(){
    FILE *fp_even;
    fp_even = fopen("collatzEvenMove.csv","w");
    FILE *sp_even;
    sp_even= fopen("collatzEvenPrev.csv","w");
    unsigned int n,i,l;
    int div, passage;
    printf("-\n");
    for (n=2;n<INF;n+=2){
        passage=0;
        i=n;
        l=0;
        numberone=false;
        while (numberone==false) {
            div = i % 2;
            switch (div) {
                case 0:
                    i=evenNumber(i);
                    break;
                case 1:
                    l=i;
                    i=oddNumber(i);

                    break;
                default:
                    printf("NOT ODD NOR EVEN???\n");
            }
            passage++;
        }
        printf("Number %d found in %d passages - last odd was %d\n\n", n, passage,l);
        fprintf(fp_even,"%d;%d\n",n,passage);
        fprintf(sp_even,"%d;%d\n",n, l);
    }
    fclose(fp_even);
    fclose(sp_even);
}

int main() {

    collatzGeneralN();
    collatzOddN();
    collatzEvenN();
    return 0;
}