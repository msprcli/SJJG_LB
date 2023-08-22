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
	bool operator<(const Node& other) const {
		return data < other.data;
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

/// <summary>
/// 仅保留Lb中与Lc重复的元素
/// </summary>
/// <param name="La">La</param>
/// <param name="Lb">Lb</param>
void remainListLb(Node*& Lb, Node* Lc) {
	Node* Lbp = (Node*)malloc(sizeof(Node)), * Lbc = Lb, * Lbf = NULL;
	Node* Lcp = Lc, * Lcc = Lc;
	Lbp->data = 0;
	Lbp->next = Lbc;
	Lbf = Lbp;
	while (Lbc) {
		while (Lcc->data < Lbc->data) {
			Lcc = Lcc->next;
		}
		// 这里换成“==”可以删除重复的元素
		if (Lcc->data != Lbc->data) {
			Lbp->next = Lbc->next;
		}
		else {
			Lbp = Lbp->next;
		}
		Lbc = Lbc->next;
	}
	Lb = Lbf->next;
}

/// <summary>
/// 删除La中与Lb重复的元素
/// </summary>
/// <param name="La">La</param>
/// <param name="Lb">Lb</param>
void cutListLa(Node*& La, Node* Lb) {
	Node* Lap = (Node*)malloc(sizeof(Node)), * Lac = La, * Laf = NULL;
	Node* Lbp = Lb, * Lbc = Lb;
	Lap->data = 0;
	Lap->next = Lac;
	Laf = Lap;
	while (Lac) {
		while (Lbc->data < Lac->data) {
			Lbc = Lbc->next;
		}
		if (Lbc->data == Lac->data) {
			Lap->next = Lac->next;
		}
		else {
			Lap = Lap->next;
		}
		Lac = Lac->next;
	}
	La = Laf->next;
}

void analysize(Node* La, Node* Lb, Node* Lc) {
	remainListLb(Lb, Lc);
	cutListLa(La,Lb);
}

int main() {
	struct Node* La = NULL;

	// 设置节点元素
	insert(La, 1);
	insert(La, 2);
	insert(La, 3);
	insert(La, 4);
	insert(La, 5);
	insert(La, 6);
	printf_s("La: ");
	display(La);

	struct Node* Lb = NULL;

	// 设置节点元素
	insert(Lb, 1);
	insert(Lb, 2);
	insert(Lb, 5);
	insert(Lb, 6);
	printf_s("Lb: ");
	display(Lb);

	struct Node* Lc = NULL;

	// 设置节点元素
	insert(Lc, 1);
	insert(Lc, 4);
	insert(Lc, 5);
	insert(Lc, 6);
	printf_s("Lc: ");
	display(Lc);

	analysize(La, Lb, Lc);

	printf_s("La: ");
	display(La);
	printf_s("Lb: ");
	display(Lb);
	printf_s("Lc: ");
	display(Lc);

	return 0;
}