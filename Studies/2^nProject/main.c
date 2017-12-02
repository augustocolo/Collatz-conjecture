#include <stdio.h>
#include <limits.h>

#define INF 65536
#define LEV 53
#define true 1
#define false 0

typedef struct levels{
    unsigned int numbers[INF+1];
    unsigned int n_num;
    unsigned int prev[INF+1];
}levels;
levels leveel[LEV + 1];
//MY_TYPE a = { .flag = true, .value = 123, .stuff = 0.456 };

int main() {
    int l,n,m,i,j,check;
    unsigned int act_num;
    int levelfin;
    leveel[0].numbers[0]=1;
    leveel[0].n_num=1;
    for (l=0;l<LEV;l++){
        leveel[l+1].n_num=0;
        n=0;
        m=0;
        levelfin=false;
        do {
            act_num=leveel[l].numbers[n];
            switch(act_num % 2){
                case 0:
                    check=0;
                    if ((act_num-1)%3==0 && act_num!=1){
                        for (i=0;i<l + 1;i++){
                            for (j=0;j<leveel[i].n_num && check==0;j++){
                               if ((act_num-1)/3==leveel[i].numbers[j]){
                                   check++;
                               }
                            }
                        }
                        if (check==0) {
                            leveel[l + 1].numbers[m] = (act_num - 1) / 3;
                            leveel[l + 1].prev[m] = act_num;
                            leveel[l + 1].n_num++;
                            m++;
                        }
                    }
                default:
                    check=0;
                    for (i=0;i<l + 1;i++){
                        for (j=0;j<leveel[i].n_num && check==0;j++){
                            if ((act_num*2)==leveel[i].numbers[j]){
                                check++;
                            }
                        }
                    }
                    if (check==0) {
                        leveel[l + 1].numbers[m] = act_num * 2;
                        leveel[l + 1].prev[m] = act_num;
                        leveel[l + 1].n_num++;
                        m++;
                    }
                    break;
            }
            n++;
            if (leveel[l].numbers[n]==0){
                levelfin=true;
            }
        }
        while (levelfin==false);
        printf("%d\n", l);

    }
    FILE *fp;
    fp=fopen("collatzTree.csv","w");
    for (l=0;l<LEV+1;l++){
        levelfin=false;
        n=0;
        do{
            fprintf(fp,"%d;%d;%d;%d\n",l,leveel[l].n_num,leveel[l].numbers[n],leveel[l].prev[n]);
            n++;
            if (leveel[l].numbers[n]==0){
                levelfin=true;
            }
        }
        while(levelfin==false);
    }
    fclose(fp);
    return 0;
}