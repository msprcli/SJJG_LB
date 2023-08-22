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
/// 求链表中的最大整数
/// </summary>
/// <param name="head">链表头指针</param>
/// <returns>最大的整数</returns>
int maxIntInNodeList(struct Node* head) {
	int Max = head->data;
	while (head->next) {
		head = head->next;
		if (head->data > Max) {
			Max = head->data;
		}
	}
	printf_s("The max number in Node List is : %d \n", Max);
	return Max;
}

/// <summary>
/// 统计当前链表中元素的个数
/// </summary>
/// <param name="head">链表头节点</param>
/// <returns>链表元素个数</returns>
int countNodes(struct Node* head) {
	int count = 1;
	if (head == NULL) {
		printf_s("NodesCount = 0 \n");
		return 0;
	}
	else
	{
		while (head->next) {
			head = head->next;
			count++;
		}
	}
	printf_s("NodesCount = %d \n", count);
	return count;
}
/// <summary>
/// 求链表中所有元素的平均值
/// </summary>
/// <param name="head">链表的头节点</param>
/// <returns>元素平均值</returns>
double averageOfNodeList(struct Node* head) {
	double avg = 0.00, count = 1.00;
	avg += head->data;
	while (head->next) {
		head = head->next;
		if (head->data != NULL) {
			avg += head->data;
			count++;
		}
	}
	avg /= count;
	printf_s("The average of Node List is :%.3f", avg);
	return avg;
}

int main() {
	struct Node* head = NULL;

	insert(&head, 1);
	insert(&head, 2);
	insert(&head, 3);

	display(head);

	maxIntInNodeList(head);

	countNodes(head);
	
	averageOfNodeList(head);

	return 0;
}