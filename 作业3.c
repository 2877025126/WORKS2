/*
考核作业3： 定义两个数组，在第一个数组后面添加第二个数组
最后一次修改2023/11/11  14:36
BY:电控组赵英豪
*/

#define _CRT_SECURE_NO_WARNINGS//由于IDE的问题，需要加入此行才可运行，如出现无定义报错请删掉
#include <stdio.h>
#include <stdlib.h>

int size_a, size_b;
int* A;
int* B;

void GETSIZE(void)
{
    printf("请输入A数组的元素个数：");    // 输入A数组的元素个数            
    scanf("%d", &size_a);

    printf("请输入B数组的元素个数：");    // 输入B数组的元素个数          
    scanf("%d", &size_b);
}

void GETINFORM(void)
{
    A = (int*)malloc(size_a * sizeof(int));    // 动态分配内存，创建A数组和B数组            
    if (A == NULL) {
        printf("分配内存失败\n");
        exit(1);
    }
    B = (int*)malloc(size_b * sizeof(int));
    if (B == NULL) {
        printf("分配内存失败\n");
        free(A); // 释放A数组的内存            
        exit(1);
    }

    printf("请输入A数组的%d个元素：\n", size_a);   // 输入A数组的内容            
    for (int i = 0; i < size_a; i++)
    {
        scanf("%d", &A[i]);
    }

    printf("请输入B数组的%d个元素：\n", size_b);    // 输入B数组的内容            
    for (int i = 0; i < size_b; i++)
    {
        scanf("%d", &B[i]);
    }
}

void EXCHANGE(int** A, int** B)
{
    *A = (int*)realloc(*A, (size_a + size_b) * sizeof(int)); // 重分配A数组的大小以便在后面添加B数组的内容           
    if (*A == NULL)
    {
        printf("重新分配内存失败");
        free(*A); // 释放A数组的内存            
        free(*B); // 释放B数组的内存            
        exit(1);
    }
    for (int i = 0; i < size_b; i++)    // 将B数组的内容复制到A数组后面            
    {
        (*A)[i + size_a] = (*B)[i];
    }
    printf("合并后的数组：\n");
    for (int i = 0; i < size_a + size_b; i++)
    {
        printf("%d ", (*A)[i]);
    }
}

int main()
{
    GETSIZE();
    GETINFORM();
    EXCHANGE(&A, &B);
    free(A);    // 释放A数组的内存          
    free(B);    // 释放B数组的内存          
    return 0;
}