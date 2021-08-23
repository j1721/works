#include<stdio.h>
#include <math.h>
#include <stdlib.h>
int main(void)
{
    int n;
    int max=0,max2=1;
    int max2i;
    scanf("%d",&n);
    int *a=malloc(sizeof(int)*n);
    for(int i=0;i<n;i++){
        scanf("%d",a+i);
        if(max<*(a+i)){
            max2=max;
            max=*(a+i);
        }
        else if(max>*(a+i)&&max2<*(a+i)){
           max2=*(a+i); 
        }
    }

    for(int i=0;i<n;i++){
        if(max2==*(a+i)){
            printf("%d",i+1);
        }
    }
        
    
}