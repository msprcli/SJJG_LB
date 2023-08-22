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
/// 高效查找带头单链表倒数第m个位置的节点
/// </summary>
/// <param name="head">链表头节点</param>
/// <param name="m">倒数第m个元素</param>
/// <returns>查找到的节点</returns>
Node getBackM(Node* head, int m) {
	struct Node* targetNode = head;
	int count = 1;
	while (head->next)
	{
		if (count < m) {
			count++;
		}
		else {
			targetNode = targetNode->next;
		}
		head = head->next;
	}
	if (count < m) {
		printf_s("Individual input m : %d \n", m);
	}
	else {
		printf_s("Target number is : %d \n", targetNode->data);
	}
	return *targetNode;
}

int main() {
	struct Node* head = NULL;
	// 设置头节点
	insert(&head, NULL);
	// 设置节点元素
	insert(&head, 1);
	insert(&head, 2);
	insert(&head, 3);
	insert(&head, 4);
	insert(&head, 5);
	insert(&head, 6);

	display(head);

	getBackM(head, 3);

	return 0;
}