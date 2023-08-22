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
void insert(struct Node*& head, int data) {
	// 创建一个新节点
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->next = NULL;

	if (head == NULL) {
		// 如果链表为空，将新节点设置为头节点
		head = newNode;
	}
	else {
		// 遍历至链表末尾
		struct Node* current = head;
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

void analyizeNode(Node* head, int x) {
	int count = 0;
	struct Node* current = head;
	struct Node* nextNode = head->next;

	while (current != NULL) {
		if (current->data != nextNode->data) {
			if (current->data < x) {
				count++;
				current = nextNode;
				if (nextNode->next != NULL) {
					nextNode = nextNode->next;
				}
				else {
					// 说明走到最后了，直接比较最后一个节点和x的大小关系
					if (nextNode->data < x) {
						count++;
					}
				}
			}
			else {
				break;
			}
		}
		else {
			if (nextNode->next != NULL) {
				nextNode = nextNode->next;
			}
			else {
				break;
			}
		}
	}
	printf_s("x = %d\n", count);
}

int main() {
	struct Node* La = NULL;

	// 设置节点元素
	insert(La, 1);
	insert(La, 2);
	insert(La, 3);
	insert(La, 3);
	insert(La, 3);
	insert(La, 3);
	insert(La, 4);
	insert(La, 5);
	insert(La, 5);
	insert(La, 6);

	display(La);

	int x = 3;

	analyizeNode(La, x);

	return 0;
}