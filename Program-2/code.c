#include<stdio.h>

struct node{
        unsigned front[20];
        unsigned dist[20];
}t[20];

int main(){
        int costmat[20][20];
        int nodes,i,j,k,count=0;

        printf("Enter the No. of Nodes: \n");
        scanf("%d",&nodes);

        printf("Enter the Matrix: \n");
        for(i=0; i<nodes; i++){
                for(j=0; j<nodes; j++){
                        scanf("%d",&costmat[i][j]);
                        t[i].dist[j] = costmat[i][j];
                        t[i].front[j] = j;
                }
        }

        do{
                count = 0;
                for(i=0; i<nodes; i++){
                        for(j=0; j<nodes; j++){
                                for(k=0; k<nodes; k++){
                                        if(t[i].dist[j] > costmat[i][k]+t[k].dist[j]){
                                                t[i].dist[j] = t[i].dist[k] + t[k].dist[j];
                                                t[i].front[j] = k;
                                                count++;
                                        }
                                }
                        }
                }
        }while(count != 0);

        for(i=0; i<nodes; i++){
                printf("\n For Router %d\n", i+1);
                for(j=0; j<nodes; j++){
                        printf("\n For node %d via %d,  distance is %d\n",j+1, t[i].front[j+1],t[i].dist[j]);
                }
        }

        printf("\n");
}
