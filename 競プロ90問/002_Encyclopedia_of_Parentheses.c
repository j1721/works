#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main(void)
{
    int n,n2;
    int cnt=0;
    int right=0,left=0;
    char b[20];
    int check=1;
    scanf("%d",&n);

    for(int i=0;i<pow(2,n);i++){
        itoa(i,b,2);
        cnt=0;
        while(b[cnt]!='\0'){
            cnt++;
        }
        for(int j=cnt-1;j>=0;j--){
            b[n-cnt+j] = b[j];
        }
        for(int j=0;j<n-cnt;j++){
            b[j]='0';
        }

        
        //printf("%s\n",b);
        left=0;right=0;check=1;
        for(int s=0;s<n;s++){
            if(b[s]=='0'){
                left++;
            }
            if(b[s]=='1'){
                right++;
            }
            if(right>left){
                check=0;
            }
        }
        if(left!=right){
            check=0;
        }
        if(check==1){
            for(int s=0;s<n;s++){
                if(b[s]=='0'){
                    printf("(");
                }
                if(b[s]=='1'){
                    printf(")");
                }
            }
            printf("\n");
        }
    }
    
    return 0;
}