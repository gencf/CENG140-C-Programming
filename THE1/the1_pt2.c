#include <stdio.h>

int optimal(int* cost, int* gain, float* ratio, int budget, int power);

int max(float* l, int index, int temp, float biggest);

int main()
{
    int cost[6], gain[6], budget, total_gained, power = 0;
    float ratio[6];

    scanf("%d", &budget);
    scanf(" %d %d", &cost[0], &gain[0]);
    scanf(" %d %d", &cost[1], &gain[1]);
    scanf(" %d %d", &cost[2], &gain[2]);
    scanf(" %d %d", &cost[3], &gain[3]);
    scanf(" %d %d", &cost[4], &gain[4]);
    scanf(" %d %d", &cost[5], &gain[5]);

    ratio[0] = (float) gain[0] / cost[0];
    ratio[1] = (float) gain[1] / cost[1];
    ratio[2] = (float) gain[2] / cost[2];
    ratio[3] = (float) gain[3] / cost[3];
    ratio[4] = (float) gain[4] / cost[4];
    ratio[5] = (float) gain[5] / cost[5];
   
    total_gained = optimal(cost, gain, ratio, budget, power);
    printf("%d\n", total_gained);

    return 0;
}

int optimal(int* cost, int* gain, float* ratio, int budget, int power){
    int index = 0, temp = 0; 
    float best = 0;
    int choice = max(ratio, index, temp, best);
    ratio[choice] = 0;
    budget -=  cost[choice]; 
    if (budget < 0)
        return power;
    power += gain[choice];
    return optimal(cost, gain, ratio, budget, power);
}

int max(float* l, int index, int temp, float biggest){
    if(temp == 6)
        return index;

    if(l[temp] > biggest){    
        index = temp;
        biggest = l[temp];
    } 

    temp++;
    return max(l, index, temp, biggest);      
}
