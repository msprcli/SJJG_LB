#include <stdio.h>
#include <stdlib.h>

// 从第j个开始
constexpr int j = 3;
// 移动len个元素
constexpr int len = 2;

/// <summary>
/// 链表
/// </summary>
struct Node {
	// 数据
	char data;
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
void insert(struct Node*& head, char data) {
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
			printf_s("%c,", current->data);
		}
		else {
			printf_s("%c", current->data);
		}
		current = current->next;
	}

	printf_s("}\n");
}

void cmpList(Node* list) {
	// 链表总长度
	int length = 0;
	bool flag = true;
	Node *current = NULL;
	current = list;
	char chars[1000]{'\0'};
	while (current) {
		chars[length] = current->data;
		length++;
		current = current->next;
	}
	// 前一半的下标界限，向下取整
	int preHalf = length / 2;
	// 后一半的下标界限，向上取整
	int lasHalf = (length + 1) / 2;

	for (int i = 0; i < preHalf; i++)
	{
		if (chars[i] != chars[lasHalf + i]) {
			flag = false;
			break;
		}
	}
	if (flag) {
		printf_s("相同\n");
	}else{
		printf_s("不同\n");
	}
}

int main() {
	struct Node* La = NULL;

	// 设置节点元素
	insert(La, 'a');
	insert(La, 'b');
	insert(La, 'c');
	insert(La, 'a');
	insert(La, 'b');
	insert(La, 'c');

	display(La);

	struct Node* Lb = NULL;

	// 设置节点元素
	insert(Lb, 'a');
	insert(Lb, 'a');
	insert(Lb, 'a');
	insert(Lb, 'a');
	insert(Lb, 'c');
	insert(Lb, 'a');

	display(Lb);

	cmpList(La);
	cmpList(Lb);

	return 0;
}