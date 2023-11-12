/*
考核作业2： 定义数组，做到数组的元素在任意位置增加、删除、修改，三个函数
最后一次修改2023/11/10  21:36
BY:电控组赵英豪
*/

#define _CRT_SECURE_NO_WARNINGS//由于IDE的问题，需要加入此行才可运行，如出现无定义报错请删掉

/*****************************************↓内容↓****************************************************/

#include <stdio.h>
#include <stdlib.h>

int n;

void ADD(int A[], int position, int Newer)
{
    for (int i = n; i >= position; i--)
    {
        A[i] = A[i - 1];
    }
    A[position] = Newer;
    n++;
    printf("添加后的数组为: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
}

void Delete(int A[], int position)
{
    for (int i = position; i < n - 1; i++)
    {
        A[i] = A[i + 1];
    }
    n--;
    printf("删除后的数组为:");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
}

void Switch(int A[], int position, int Newer)
{
    A[position] = Newer;
    printf("修改后的数组为");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
}

int main(void)
{
    int* A = NULL; // 定义一个指针A，初始化为NULL
    n = 0;
    int size = 10; // 初始数组大小为10
    A = (int*)malloc(size * sizeof(int)); // 申请10个int类型大小的内存空间
    if (A == NULL) // 判断是否申请成功
    {
        printf("内存申请失败！\n");
        return 0;
    }
    for (int i = 0; i < size; i++) // 初始化数组为{0，1，2，3，4，5，6，7，8，9}
    {
        A[i] = i;
        n++;
    }
    //数组为{ 0，1，2，3，4，5，6，7，8，9 }
    // 进行添加、删除、修改操作
    Delete(A, 0);//
    printf("\n");
    Switch(A, 1, 8);//
    printf("\n");
    ADD(A, 4, 9);//

    free(A); // 释放内存空间
    A = NULL; // 将指针A赋值为NULL，防止野指针的出现

    return 0;
}