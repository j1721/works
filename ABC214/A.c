#include<stdio.h>
#include <math.h>
 
int main(void)
{
  /* 変数の宣言 */
  int n;
  scanf("%d",&n);

  if(n<126){
    printf("4\n");
  }
  else if(n<212){
    printf("6\n");
  }
  else{
    printf("8\n");
  }
  
}

/*解答
#include<stdio.h>
int main(){
	int a,b;
	scanf("%d%d",&a,&b);
	printf("%d\n",a^b);
}
*/