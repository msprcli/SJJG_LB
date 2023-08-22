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
/// 访问单链表第i个数据节点（i从1开始）
/// </summary>
/// <param name="head">头节点</param>
/// <param name="i">i</param>
/// <returns>对应的节点</returns>
Node getTargetNode(struct Node* head, int i) {
	struct Node* errorNode = NULL;
	insert(&errorNode, -1);

	if (i < 1) {
		printf_s("Individual num input : %d \n", i);
		return *errorNode;
	}
	else if (i == 1) {
		return *head;
	}
	else {
		for (int j = 0; j < i - 1; j++)
		{
			if (head->next == NULL) {
				printf_s("Individual num input : %d \n", i);
				return *errorNode;
			}
			head = head->next;
		}
		printf_s("Target node data is : %d \n", head->data);
		return *head;
	}
}

int main() {
	struct Node* head = NULL;

	insert(&head, 1);
	insert(&head, 2);
	insert(&head, 3);
	insert(&head, 4);
	insert(&head, 5);

	display(head);
	getTargetNode(head, 0);
	getTargetNode(head, 2);
	getTargetNode(head, 6);

	return 0;
}