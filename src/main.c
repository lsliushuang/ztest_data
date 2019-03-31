/*
 * main.c
 *
 *  Created on: Mar 29, 2019
 *  Author: ls
 */


#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>


extern int *find_value(int *begin , int*end, int value);


int main(int argc, char**argv)
{
	int *p = NULL;
	int array[10] = {1,2,3,4,5,6,7,8,9,10};

	p = find_value(array,&array[9],3);
	printf("test = %d \r\n",*p);

	return 0;
}
