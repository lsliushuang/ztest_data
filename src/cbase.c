/*
 * cbase.c
 *
 *  Created on: Mar 29, 2019
 *      Author: ls
 */



#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef int (*PF)(int, int);  //函数指针

/**
 * function: find_value
 * descrption: find a value from a list
 * author: ls
 * input:
 * return:
 * */
int *find_value(int *begin , int*end, int value)
{

	while(begin != end  && (*begin != value))
	{
		++begin;
	}

 	return begin;
}

/**
 * function: test_ptr
 * descrption: 测试指针数组
 * author: ls
 * input:
 * return:
 * */

void test_ptr(void)
{
	char *aa[3] = {"1str1","2str2","3str3"};  //定义一个指针数组

	printf("aa[0] = %s \r\n",aa[1]);
	printf("aa[0] = %c \r\n",*aa[1]);


	 int iNum1 = 9, iNum2 = 10, temp;

	 printf("%d, %d  \n", &iNum1, &iNum2);
	 printf("%x, %x  \n", iNum1, iNum2);
	 temp = iNum1; iNum1 = iNum2; iNum2 = temp;
	 printf("%d, %d\n", &iNum1, &iNum2);
	 printf("%x, %x\n", iNum1, iNum2);
}






