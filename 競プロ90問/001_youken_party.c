#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int n,l,k;
    int ans;
    int value=0;
    int min,max;
    int count=0;
    scanf("%d",&n);
    scanf("%d",&l);
    scanf("%d",&k);

    int *a=malloc(sizeof(int)*n);
    for(int i=0;i<n;i++){
        scanf("%d",a+i);
    }
    
    int left = 1, right = l;

	while (right > left)
	{
		int mid = (left + right) / 2.0+0.5;
        //printf("mid:%d\n",mid);
        count=0;
        value=0;
        for(int i=0;i<=n;i++){
            if(i==0){
                value+=*(a+i);
            }
            else if(i==n){
                value+=(l-*(a+i-1));
            }
            else{
                value+=(*(a+i)-*(a+i-1));
            }

            if(value>=mid){
                count++;
                value=0;
            }
        }
        
        if(count>=k+1){
            left=mid;
        }
        else {
            right=mid-1;
        }
        //printf("left:%d,right:%d,count:%d\n",left,right,count);
	}

    //printf("%d %d\n",left,right);
    printf("%d\n",(left + right) / 2);
    return 0;
}