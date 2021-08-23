#include<stdio.h>
#include <math.h>
 
int main(void)
{
  /* 変数の宣言 */
  int a,b;
  int c=0;
  scanf("%d %d",&a,&b);
  int i, decimal;
  int a2[8]={0};
  int b2[8]={0};
  int c2[8]={0};
  int count;
  /* 10進数→2進数の変換 */
  for(i=0;a>0;i++){
    a2[i] = a % 2;
    a = a / 2;
  }
  count=i;
 
  for(i=0;b>0;i++){
    b2[i] = b % 2;
    b = b / 2;
  }
 
  for(i=0;i<8;i++){
      if(a2[i]==b2[i]){
          c2[i]=0;
      }
      else{
          c+=pow(2,i);
      }
  }
   printf("%d",c);
 
 
}

/*解答
#include<stdio.h>
int main(){
	int a,b;
	scanf("%d%d",&a,&b);
	printf("%d\n",a^b);
}
*/