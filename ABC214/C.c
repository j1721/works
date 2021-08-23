#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(void)
{
    int n;
    scanf("%d",&n);
    int *s=malloc(sizeof(int)*n);
    int *t=malloc(sizeof(int)*n);
    int *ans=malloc(sizeof(int)*n);
    int total;
    int tf=0;
    
    for(int i=0;i<n;i++){
        scanf("%d",s+i);
    }
    for(int i=0;i<n;i++){
        scanf("%d",t+i);
    }


    for(int i=0;i<n;i++){
        if(i==0){
            total=*(t+i);
        }
        else{
            total=total+*(s+i-1);
            if(total>*(t+i)){
                total=*(t+i);
            }
        }
        *(ans+i)=total;
    }
    if(*ans>*(ans+n-1)+*(s+n-1)){
        *ans=*(ans+n-1)+*(s+n-1);
        tf=1;
    }
    if(tf==1){
        total=*ans;
        for(int i=1;i<n;i++){
            total=total+*(s+i-1);
            if(total>*(t+i)){
                total=*(t+i);
            }
            if(*(ans+i)>total){
                *(ans+i)=total;
            }
        }
    }
    for(int i=0;i<n;i++){
        printf("%d\n",*(ans+i));
    }
}