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

union test {
	int aa;
	char bb;

};

/**
 * function: find_value
 * descrption: find a value from a list
 * author: ls
 * input:
 * return:
 * */
int *find_value(int *begin, int*end, int value) {

	while (begin != end && (*begin != value)) {
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
void test_ptr(void) {
	char *aa[3] = { "1str1", "2str2", "3str3" };  //定义一个指针数组
	union test test_u;
	test_u.aa = 0x12345678;
	printf("aa[0] = %s \r\n", aa[1]);
	printf("aa[0] = %c \r\n", *aa[1]);

	int iNum1 = 9, iNum2 = 10, temp;

	printf("%d, %d  \n", &iNum1, &iNum2);
	printf("%x, %x  \n", iNum1, iNum2);
	temp = iNum1;
	iNum1 = iNum2;
	iNum2 = temp;
	printf("%d, %d\n", &iNum1, &iNum2);
	printf("%x, %x\n", iNum1, iNum2);

	printf("tets = %x \r\n", test_u.bb);

	/***测试隐式转换**********/
	unsigned char a = 0;
	unsigned char b = 0xFF;

	if (a == ~b) {
		printf("a == ~b");

	} else {
		printf("a != ~b");
		printf("~b = %x \r\n", ~b);
	}

	/****测试二级指针**********/
	int num = 32;
	int *ptr = &num;
	int **pptr = &ptr;
	printf("ptr = %d \r\n", **pptr);

	char str1[5] = "welco";
	char *str2 = "hello";
	strncpy(str1, str2, 5);
	printf(" %s \r\n", str1);
}

int lookup(char*word, char*keyword[]) {
	int i = 0;
	for (i = 0; keyword[i] != NULL; i++) {
		if (strcmp(word, keyword[i]) == 0) {
			printf("find a str!\r\n");
			return i;
		}
	}
	return -1;
}

//测试Ｃ语言基础语法
void test_cbase(void)
{
	const char*keyword[5] = { "pig", "eagl", "read", "write", "NULL" };
	char **ptr;  //10*20
	int *p = NULL;
	int array[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	//int aa[3][2] = {{1,2},{3,4},{5,6}};

	p = find_value(array, &array[9], 3);
	printf("test \r\n", __FUNCTION__);
	test_ptr();
	lookup("read", keyword);

	//二级指针实现一个二维数组
	ptr = (char **) malloc(10 * sizeof(char*));  //申请行指针
	for (int i = 0; i < 20; i++) {
		ptr[i] = (char*) malloc(20 * sizeof(char)); //申请列指针
	}

	ptr[5][15] = 90;
	printf("ptr = %d \r\n", ptr[5][15]);

	int *pp;
	pp = calloc(5, sizeof(int));
	if (pp != NULL) {
		pp[3] = 90;
	}

	realloc(pp, 10);
	pp[8] = 30;
	printf("pp = %d \r\n", pp[8]);
}

