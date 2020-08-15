#include <stdio.h>
#include <math.h>

int main(void)
{
    float change;
    int count = 0;
    int total = 0;
    do {
        change = get_float("How much change?\n");
    }
    while(change <= 0);

    // printf("%f\n",change);
    int cents = round(change*100);
    while(cents>=25){
        cents = cents - 25;
        count= count +1;
    }

    while(cents>=10){
        cents = cents - 10;
        count= count +1;
    }

    while(cents>=5){
        cents = cents - 5;
        count= count +1;
    } 

    while(cents>=1){
        cents = cents - 1;
        count= count +1;
    }
    printf("%d\n",count);
    return 0;
    
 }

