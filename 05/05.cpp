#include <stdio.h>
#include <stdlib.h>
/// <summary>
/// 链表
/// </summary>
struct Node {
	// 数据
	int data;
	// 指向下一个节点的指针
	struct Node* next;
	bool operator==(const Node& other) const
	{
		return data == other.data;
	}
}node;
/// <summary>
/// 使用尾插法向链表中插入元素
/// </summary>
/// <param name="head">链表表头</param>
/// <param name="data">要插入的数据</param>
void insert(struct Node** head, int data) {
	// 创建一个新节点
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->next = NULL;

	if (*head == NULL) {
		// 如果链表为空，将新节点设置为头节点
		*head = newNode;
	}
	else {
		// 遍历至链表末尾
		struct Node* current = *head;
		while (current->next != NULL) {
			current = current->next;
		}
		// 将新节点连接到链表末尾
		current->next = newNode;
	}
}
/// <summary>
/// 显示当前链表内的全部元素
/// </summary>
/// <param name="head">要显示的链表指针</param>
void display(struct Node* head) {
	struct Node* current = head;
	printf_s("data:{");

	while (current != NULL) {
		if (current->next != NULL) {
			printf_s("%d,", current->data);
		}
		else {
			printf_s("%d", current->data);
		}
		current = current->next;
	}

	printf_s("}\n");
}
/// <summary>
/// 在第i个元素前插入元素e
/// </summary>
/// <param name="head">头指针</param>
/// <param name="i">第i个元素</param>
/// <param name="e">要插入的数据</param>
void insertBeforeI(struct Node* head, int i, int e) {
	struct Node* newNode = NULL;
	insert(&newNode, e);
	for (int j = 1; j < i - 1; j++)
	{
		head = head->next;
	}
	newNode->next = head->next;
	head->next = newNode;
}

int main() {
	struct Node* head = NULL;

	insert(&head, 1);
	insert(&head, 2);

	insert(&head, 4);
	insert(&head, 5);
	insert(&head, 6);

	display(head);

	insertBeforeI(head, 3, 3);

	display(head);

	return 0;
}