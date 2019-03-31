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


union test
{
	int aa ;
	char bb;

};
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
	union test test_u;
	test_u.aa = 0x12345678;
	printf("aa[0] = %s \r\n",aa[1]);
	printf("aa[0] = %c \r\n",*aa[1]);


	 int iNum1 = 9, iNum2 = 10, temp;

	 printf("%d, %d  \n", &iNum1, &iNum2);
	 printf("%x, %x  \n", iNum1, iNum2);
	 temp = iNum1; iNum1 = iNum2; iNum2 = temp;
	 printf("%d, %d\n", &iNum1, &iNum2);
	 printf("%x, %x\n", iNum1, iNum2);

	 printf("tets = %x \r\n",test_u.bb);
}



void judge_host_little_big(void)
{
	union{
		short s;
		char c[sizeof(short)];
	}un;

	un.s = 0x0102;

	if(un.c[0] == 0x01 && (un.c[1] == 0x02))
	{
		printf("host is big endian\r\n");
	}
	else if(un.c[0] == 0x02 && (un.c[1] == 0x01))
	{
		printf("host is little endian\r\n");
	}

}




