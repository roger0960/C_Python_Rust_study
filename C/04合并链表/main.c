#include <stdio.h>
#include <stdlib.h>

struct list {
	int val;
	struct list *next;
};

typedef struct list* Ptrlist;

Ptrlist create_node(int val)
{
	Ptrlist node = (Ptrlist)malloc(sizeof(struct list));
	if(NULL == node) {
		printf("Fail to malloc.\n");
		exit(1);
	}
	node->val = val;
	node->next = NULL;
}

Ptrlist create_list(int count, int base_val)
{
	int i;
	Ptrlist header_list = create_node(0);
	Ptrlist tail_node = header_list;

	for(i=1;i<count;i++) {
		tail_node->next = create_node(i*base_val);
		tail_node = tail_node->next;
	}
	return header_list;
}

void traver_list(Ptrlist list)
{
	Ptrlist p = list;
	while(p) {
		printf("%d ",p->val);
		p = p->next;
	}
	printf("\n");
}

Ptrlist merge(Ptrlist list1, Ptrlist list2)
{
	if(NULL == list1)
		return list2;
	if(NULL == list2)
		return list1;

	Ptrlist merge_header_list = NULL;
	Ptrlist current = NULL;
	while(list1 && list2) {
		if(list1->val <= list2->val) {
			if(NULL == merge_header_list)
				merge_header_list = current = list1;
			else {
				current->next = list1;
				current = current->next;
			}
			list1 = list1->next;
		} else {
			if(NULL == merge_header_list)
				merge_header_list = current = list2;
			else {
				current->next = list2;
				current = current->next;
			}
			list2 = list2->next;
		}
	}
	if(NULL == list1) {
		current->next = list2;
	}
	if(NULL == list2) {
		current->next = list1;
	}
	return merge_header_list;
}

int main()
{
	Ptrlist list1 = create_list(5,1);
	Ptrlist list2 = create_list(3,2);
	printf("list1\n");
	traver_list(list1);
	printf("list2\n");
	traver_list(list2);

	Ptrlist merge_list = merge(list1, list2);
	traver_list(merge_list);
	return 0;
}
