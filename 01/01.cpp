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
	/* 关于为什么不能修改为 Node* head
	* 在函数`insert`的参数中使用`Node** head`是为了能够修改指向头节点的指针。
	* 当我们在函数内部插入一个新节点时，需要修改指向头节点的指针，将其指向新插入的节点。
	*
	* 如果使用`Node* head`作为参数，那么在函数内部修改`head`的值，
	* 实际上只是修改了传入参数的副本，并不会影响到原始的头节点。
	*
	* 通过使用`Node** head`，我们可以通过解引用一级指针来修改指向头节点的指针，
	* 确保插入新节点后的链表能够正确地反映在调用函数之后。
	* 这样可以确保我们可以在函数内部修改指向头节点的指针，从而确保链表操作的正确性。
	*
	* 如果尝试修改为`Node* head`，则无法正确修改原始的头指针，从而导致出现错误和不一致的结果。
	* 所以，正确的做法是使用`Node** head`参数来允许在函数内部修改指向头节点的指针。
	*/
	// 创建一个新节点，头插法插入
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->next = *head;
	// 反向赋值，传回去
	*head = newNode;
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

int main() {
	struct Node* head = NULL;

	insert(&head, 1);
	insert(&head, 2);
	insert(&head, 3);

	display(head);

	return 0;
}