/*
 * program.c
 *
 *  Created on: Apr 6, 2019
 *  Author: ls
 */


#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int (*pf)(int);  //声明一个函数指针
void *pf3;
typedef int (*PF)(int);  //定义一种函数指针类型，类型名为PF
//测试内存对齐
struct data_test
{
	char a;
	char e;
	char g;
	char c[2];
	short b;
	int f;
	double d;
	int (*pf)(int);  //声明一个函数指针即方法


}data;
int print(int a);

//测试结构体传参
void print_struct(struct data_test* data)
{
	data->a = 23;
	data->pf = print;
	data->pf(45);
	printf("data = %d \r\n",data->a);
}

int print(int a)
{
	printf("a = %d \r\n",sizeof(data));
}
 //测试函数指针
void test_funptr(void)
{
	//pf3 = print; //
//	PF pf2[3];  //函数指针数组
//	pf2[1] = print;
//	pf2[1](12); //把pf3强转成int(*)(int)函数指针类型

	print_struct(&data);
}


int *max(int *a, int* b)
{
	return ((*a) > (*b) ? a : b);
}

//测试指针函数--返回值为指针的函数
void test_ptrfun(void)
{

	int a = 9;
	int b = 8;

	printf("tt = %x",*max(&a,&b));

}





