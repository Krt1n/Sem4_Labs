#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void fcfs(int requests[], int n, int head){
    int total= 0, current=head;
    printf("\n---FCFS--\n");
    printf("Order of service: %d", head);
    for(int i=0;i<n;i++){
        printf("-> %d", requests[i]);
        total+=abs(requests[i]-current);
        current=requests[i];
    }
    printf("\nTotal Cylinder Movements: %d\n",total);
}

void sstf(int requests[], int n, int head){
    int total=0, current=head;
    int visited[100]={0};
    int req[100];

    for(int i=0;i<n;i++){
        req[i] = requests[i];
    }

    printf("\n--- SSTF ---\n");
    printf("Order of service: %d",head);
    for(int count=0;count<n;count++){
        int minDist=99999, minIdx=-1;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                int dist = abs(req[i]-current);
                if(dist < minDist){
                    minDist = dist;
                    minIdx = i;
                }
            }
        }
        visited[minIdx]=1;
        total+=minDist;
        current = req[minIdx];
        printf("-> %d", req[minIdx]);
    }
    printf("\nTotal Cylinder Movements: %d\n", total);
}

void scan(int requests[], int n, int head, int disk_size){
    int total=0, current=head;
    int req[100],cnt=n;

    for(int i=0;i<n;i++){
        req[i]=requests[i];
    }

    for(int i=0;i<cnt-1;i++){
        for(int j=0;j<cnt-i-1;j++){
            if(req[j]>req[j+1]){
                int t = req[j];
                req[j] = req[j+1];
                req[j+1] = t;
            }
        }
    }

    int pos=0;
    while(pos<cnt && req[pos]<head){
        pos++;
    }

    printf("\n--- SCAN ---\n");
    printf("\nOrder of Service: %d",head);
    // Move right (toward higher cylinders)
    for (int i = pos; i < cnt; i++) {
        printf(" -> %d", req[i]);
        total += abs(req[i] - current);
        current = req[i];
    }
    // Go to end
    total += abs((disk_size - 1) - current);
    current = disk_size - 1;
    // Move left (toward lower cylinders)
    for (int i = pos - 1; i >= 0; i--) {
        printf(" -> %d", req[i]);
        total += abs(req[i] - current);
        current = req[i];
    }
    printf("\nTotal Cylinder Movements: %d\n", total);
}

void cscan(int requests[], int n, int head, int disk_size){
    int total=0,current=head;
    int req[100], cnt=n;

    for(int i=0;i<n;i++){
    req[i]=requests[i];
    }

    for(int i=0;i<cnt-1;i++){
        for(int j=0;j<cnt-i-1;j++){
            if(req[j]>req[j+1]){
                int t = req[j];
                req[j] = req[j+1];
                req[j+1] = t;
            }
        }
    }

    int pos=0;
    while(pos<cnt && req[pos]<head){
        pos++;
    }

    printf("\n--- C-SCAN ---\n");
    printf("\nOrder of Service: %d",head);
    for(int i=pos;i<cnt;i++){
        printf("-> %d", req[i]);
        total+=abs(req[i]-current);
        current=req[i];
    }

    total+=abs((disk_size-1)-current); //goes to last cylin
    total+=(disk_size-1); // end to 0
    printf("->%d->0",disk_size-1);
    current=0;

    for (int i = 0; i < pos; i++)
    {
        printf("->%d", req[i]);
        total+=abs(req[i]-current);
        current=req[i];
    }
    printf("\nTotal Cylinder Movements: %d\n",total);
}

int main(){
    int n, head, disk_size;

    printf("Enter total number of cylinders: ");
    scanf("%d",&disk_size);

    printf("Enter initial head position     :");
    scanf("%d",&head);

    printf("Enter the number of requests    :");
    scanf("%d",&n);

    int requests[100];
    printf("Enter %d disk requests      :",n);
    for(int i = 0; i < n; i++){
        scanf("%d",&requests[i]);
    }
    fcfs(requests,n,head);
    sstf(requests,n,head);
    scan(requests,n,head,disk_size);
    cscan(requests,n,head,disk_size);

    return 0;
}