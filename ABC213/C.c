#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int compareInt(const void* a, const void* b)
{
    int aNum = *(int*)a;
    int bNum = *(int*)b;

    return aNum - bNum;
}

int array_unuque(int* array, size_t size)
{
    int end = 0;  // 現在の末尾要素の位置
                     // array[0] は必ずそのまま使うので、0 で開始

    for (int i = 1; i < size; ++i) {
        if (array[i] != array[end]) {
            // 重複していない

            ++end;
            array[end] = array[i];
        }
    }
    //printf("%d\n",end+1);
    return end + 1;  // end は末尾要素の添字なので、要素数は +1 したもの
}

void print_array(const int* array, size_t size)
{
    for (int i = 0; i < size; ++i) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main(void)
{
    int h,w;
    int n;
    scanf("%d %d %d",&h,&w,&n);
    int *a=malloc(sizeof(int)*n);
    int *b=malloc(sizeof(int)*n);
    int *a_ex=malloc(sizeof(int)*n);
    int *b_ex=malloc(sizeof(int)*n);
    for(int i=0;i<n;i++){
        scanf("%d %d",a+i,b+i);
        *(a_ex+i)=*(a+i);
        *(b_ex+i)=*(b+i);
    }

    qsort(a,n,sizeof(int),compareInt);
    qsort(b,n,sizeof(int),compareInt);

    int size1 = array_unuque(a, n);
    int size2 = array_unuque(b, n);

    //print_array(a, size1);
    //print_array(b, size2);

    for(int i=0;i<n;i++){
        for(int j=0;j<size1;j++){
            if(*(a_ex+i)==*(a+j)&&j<size1){
                printf("%d ",j+1);
            }
        }
        for(int j=0;j<size2;j++){
            if(*(b_ex+i)==*(b+j)&&j<size2){
                printf("%d ",j+1);
            }
        }
        printf("\n");
    }
    
}