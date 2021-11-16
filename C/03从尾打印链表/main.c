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

PtrList create_node(int val)
{
	PtrList node = (PtrList)malloc(LEN);
	if(NULL == node) {
		printf("Fail to malloc.\n");
		exit(1);
	}
	node->data = val;
	node->next = NULL;
	return node;
}

PtrList create_list(int len)
{
	int i;
	PtrList head_list = create_node(0);
	PtrList tail_node = head_list;

	for(i=1; i<len; i++) {
		PtrList new_node = create_node(i);
		tail_node->next = new_node;
		tail_node = tail_node->next;
	}
	return head_list;
}

void traverse_list(PtrList list)
{
	PtrList p = list;
	while(p) {
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}

/*
 * @param listNode ListNode类
 * @return int整型一维数组
 * @return int* returnSize 返回数组行数
 */
int* reverse_traverse_list(PtrList list, int *returnSize)
{
	PtrList p = list;
	int count = 0;
	int *val, i;

	while(p) {
		p = p->next;
		count++;
	}
	*returnSize = count;
	val = (int *)malloc(sizeof(int)*count);
	for(p=list, i=0; p; p=p->next, i++) {
		val[i] = p->data;
	}

	// val 数组首位对调
	int mid = (count)/2;
	int backup;
	for(i=0; i<mid; i++) {
		backup = val[i];
		val[i] = val[count-1-i];
		val[count-1-i] = backup;
	}
	return val;
}

int main()
{
	int returnSize = 0, i;
	PtrList list = create_list(2);
	traverse_list(list);
	int *arr = reverse_traverse_list(list, &returnSize);
	printf("returnSize: %d\n",returnSize);
	for(i=0; i<returnSize; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}
