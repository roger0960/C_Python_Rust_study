#include <stdio.h>
#include <stdlib.h>

#define LIST_SIZE 10
#define LEN sizeof(struct list)

struct list {
	struct list *next;
	int data;
};
typedef struct list List;
typedef struct list* PtrList;

// 创建一个节点
PtrList create_node(int val)
{
	PtrList node = (PtrList)malloc(LEN);
	if(NULL == node) {
		printf("Fail to malloc PtrList.\n");
	}
	node->data = val;
	node->next = NULL;
	return node;
}

// 创建 len 长度的链表
PtrList create_list(int len)
{
	int i;
	PtrList head_list = create_node(0);
	PtrList tail_node = head_list;

	for(i = 1; i < len; i++) {
		PtrList new_node = create_node(i);
		tail_node->next = new_node;
		tail_node = new_node; // 将当前结点赋给 tail_node. tail_node 起着一个临时结点的作用. 即 tail_node = tail_node->next;
	}
	return head_list;
}

// 遍历链表
void traverse_list(PtrList list)
{
	PtrList p = list;
	if(NULL == list) {
		printf("List is NULL.\n");
	}

	while(NULL != p) {
		printf("%d\n", p->data);
		p = p->next;
	}
}

// 反转链表
PtrList reverse_list(PtrList list)
{
	PtrList now = list, next = NULL;
	PtrList pre_list = NULL;
	while(now) {
		next = now->next;
		now->next = pre_list;
		pre_list = now;
		now = next;
	}
	return pre_list;
}

int main(void)
{
	PtrList list = create_list(10);
	traverse_list(list);
	printf("反转链表\n");
	PtrList pre_list = reverse_list(list);
	traverse_list(pre_list);
	return 0;
}
