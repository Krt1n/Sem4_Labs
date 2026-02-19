/*
Menu driven program to simulate:
1) FCFS
2) SRTF
3) Round Robin (Q = 10)
4) Non-preemptive Priority
Calculate WT, TAT and averages.
*/

#include <stdio.h>
#include <limits.h>

#define N 4

int main() {

    int pid[N] = {1,2,3,4};
    int at[N]  = {0,3,4,9};
    int bt[N]  = {60,30,40,10};
    int pr[N]  = {3,2,1,4};

    int ct[N], wt[N], tat[N], rt[N];
    int i, choice;

    printf("1.FCFS\n2.SRTF\n3.Round Robin(Q=10)\n4.Priority\nEnter choice: ");
    scanf("%d",&choice);

    //FCFS
    if(choice==1) {
        int time=0;

        for(i=0;i<N;i++) {
            if(time < at[i])
                time = at[i];

            time += bt[i];
            ct[i] = time;
        }
    }

    //SRTF
    else if(choice==2) {
        int time=0, complete=0, min, shortest;

        for(i=0;i<N;i++)
            rt[i]=bt[i];

        while(complete!=N) {
            min = INT_MAX;
            shortest=-1;

            for(i=0;i<N;i++)
                if(at[i]<=time && rt[i]>0 && rt[i]<min){
                    min=rt[i];
                    shortest=i;
                }

            if(shortest==-1){
                time++;
                continue;
            }

            rt[shortest]--;
            time++;

            if(rt[shortest]==0){
                complete++;
                ct[shortest]=time;
            }
        }
    }

    //ROUND ROBIN
    else if(choice==3) {
        int time=0, done;

        for(i=0;i<N;i++)
            rt[i]=bt[i];

        do{
            done=1;
            for(i=0;i<N;i++){
                if(at[i]<=time && rt[i]>0){
                    done=0;

                    if(rt[i]>10){
                        time+=10;
                        rt[i]-=10;
                    }
                    else{
                        time+=rt[i];
                        ct[i]=time;
                        rt[i]=0;
                    }
                }
            }
        }while(!done);
    }

    // PRIORITY 
    else if(choice==4) {
        int time=0, complete=0;

        while(complete<N){
            int high=-1, max=-1;

            for(i=0;i<N;i++)
                if(at[i]<=time && ct[i]==0)
                    if(pr[i]>max){
                        max=pr[i];
                        high=i;
                    }

            if(high==-1){
                time++;
            }
            else{
                time+=bt[high];
                ct[high]=time;
                complete++;
            }
        }
    }

    else {
        printf("Invalid choice");
        return 0;
    }
    float avg_wt=0, avg_tat=0;

    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");

    for(i=0;i<N;i++){
        tat[i]=ct[i]-at[i];
        wt[i]=tat[i]-bt[i];

        avg_wt+=wt[i];
        avg_tat+=tat[i];

        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               pid[i],at[i],bt[i],ct[i],tat[i],wt[i]);
    }

    printf("\nAverage Waiting Time = %.2f",avg_wt/N);
    printf("\nAverage Turnaround Time = %.2f\n",avg_tat/N);

    return 0;
}
