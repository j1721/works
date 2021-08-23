#include<stdio.h>
#include <math.h>
 
int main(void)
{
  /* 変数の宣言 */
  int s,t;
  int count=0;
  scanf("%d %d",&s,&t);
  for(int a=0;a<101;a++){
    for(int b=0;b<101;b++){
      for(int c=0;c<101;c++){
        if(a+b+c<=s&&a*b*c<=t){
          count++;
        }
      }
    }
  }
  printf("%d\n",count);
}