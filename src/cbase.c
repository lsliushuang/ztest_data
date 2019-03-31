/*
 * cbase.c
 *
 *  Created on: Mar 29, 2019
 *      Author: ls
 */



#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>



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
