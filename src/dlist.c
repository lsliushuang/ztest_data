/*
 * dlist.c
 *
 *  Created on: Apr 7, 2019
 *      Author: ls
 */

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct _dlist_node
{
	int data;
	struct _dlist_node* p_prev;
	struct _dlist_node* p_next;

}dlist_node_t;

dlist_node_t head;  //定义一个头结点

//初始化一个双向循环链表，即初始化一个头结点
int init_dlist(dlist_node_t *head)
{
	if(head == NULL)
	{
		return -1;
	}

	head->p_next = head;
	head->p_prev = head;
	return 0;
}

//寻找指定节点的前一个节点
dlist_node_t *prev_get(dlist_node_t *p_head,dlist_node_t *pos)
{
	if((p_head == NULL) || (pos == NULL))
	{
		return -1;
	}

	return pos->p_prev;
}


//寻找指定节点的后一个节点
dlist_node_t *next_get(dlist_node_t *p_head,dlist_node_t *pos)
{
	if((p_head == NULL) || (pos == NULL))
	{
		return -1;
	}

	return pos->p_next;
}


//添加一个节点在链表尾部
int dlist_add_tail(dlist_node_t *p_head,dlist_node_t *node)
{
	if((p_head == NULL) || (node == NULL))
	{
		return -1;
	}

	node->p_prev = p_head->p_prev;
	node->p_next = p_head;
	p_head->p_prev->p_next = node;
	p_head->p_prev = node;
	return 0;
}


//任意位置添加任意节点
int dlist_add_node(dlist_node_t *p_head,dlist_node_t *pos,dlist_node_t *node)
{
	if((p_head == NULL) || (node == NULL) || (pos == NULL))
	{
		return -1;
	}

	node->p_prev = pos;
	node->p_next = pos->p_next;
	pos->p_next->p_prev = node;
	pos->p_next = node;
	return 0;
}

//删除任意节点
int dlist_del_node(dlist_node_t *p_head, dlist_node_t *node)
{
	if((p_head == NULL) || (node == NULL) || (node == p_head))
	{
		return 0;
	}
	dlist_node_t *p_tmp = NULL;
	p_tmp = node->p_prev; //获取被删节点的前节点
	p_tmp->p_next = node->p_next;
	node->p_next->p_prev = p_tmp;
	node->p_next = NULL;
	node->p_prev = NULL;
	return 0;

}
