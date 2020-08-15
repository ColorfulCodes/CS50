#include <stdio.h>

int main(void)
{
    int howBig;
    do{
        printf("How big do you want the pyramid?\n");
        scanf("%d",&howBig);
    } while(howBig < 1 || howBig > 8);
    for (int i=0; i< howBig; i=i+1){
        for (int j=0; j< howBig; j=j+1){
            if(i+j < howBig-1){
                printf(" ");
            }else{
                printf("#");
            }
        } 
        printf("\n");   
    }
}

    
