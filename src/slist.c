/*
 * slist.c
 *
 *  Created on: Apr 7, 2019
 *      Author: ls
 */



#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

//定义单链表节点类型
typedef struct _slist_node{

	int data;
	struct _slist_node * p_next;

}slist_node_t;

//链表尾部添加一个节点
int slist_add_tail(slist_node_t *p_head, slist_node_t *node)
{

	if(p_head == NULL || (node == NULL))
	{
		return -1;
	}

	slist_node_t *p_tmp = p_head;  //获取头结点指针
	while(p_tmp->p_next != NULL)  //寻找最后一个节点
	{
			p_tmp = p_tmp->p_next;
	}

	p_tmp->p_next = node;  //在末尾加入新节点
	node->p_next = NULL;  //尾节点指针指向NULL

	return 0;
}

//链表头部添加一个节点
int slist_add_head(slist_node_t *p_head, slist_node_t *node)
{
	if((p_head == NULL) || (node == NULL))
	{
		return -1;
	}

	node->p_next = p_head->p_next;
	p_head->p_next = node;
	return 0;
}


//链表任意位置插入一个节点
int slist_add_node(slist_node_t *p_head, slist_node_t *pos, slist_node_t *node)
{
	if((p_head == NULL) || (node == NULL) || (pos == NULL))
	{
		return -1;
	}

	node->p_next = pos->p_next;
	pos->p_next = node;
	return 0;
}

//删除一个节点node
int slist_del_node(slist_node_t *p_head,slist_node_t*node)
{
	if((p_head == NULL) || (node == NULL))
	{
		return -1;
	}
	slist_node_t *p_tmp = p_head;
	slist_node_t *p_pre = NULL;
	while(p_tmp->p_next != node)  //找到被删节点的前一个节点
	{
		p_tmp = p_tmp->p_next;
	}

	p_pre = p_tmp;

	p_pre->p_next = node->p_next;
	node->p_next = NULL;

	return 0;

}

int init_slist(slist_node_t *head)  //初始化一个空链表，本质上就是初始化一个头结点
{
	if(head == NULL)
	{
		return -1;
	}

	head->p_next = NULL;
	return 0;
}

void test_slist(void)
{
	slist_node_t head; //定义一个头结点
	slist_node_t node,node1,node2,node3;  //定义一个节点
	init_slist(&head);
	slist_node_t *p_tmp; //临时变量,用于遍历时不改变头指针的值
	node.data = 89;
	node1.data = 90;
	head.data = 78;
	node2.data = 44;
	node3.data = 77;

	slist_add_tail(&head,&node);
	slist_add_tail(&head,&node1);
	printf("ret = %d \r\n",slist_add_head(&head,&node2));
	slist_add_node(&head,&node,&node3);
	slist_del_node(&head,&node2);
	p_tmp = head.p_next;
	while(p_tmp != NULL)  //遍历链表，找出里面的值
	{
		printf("data = %d \r\n",p_tmp->data);
		p_tmp = p_tmp->p_next;
	}
}
