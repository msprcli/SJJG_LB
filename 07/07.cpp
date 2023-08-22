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

/// <summary>
/// 深复制法执行替换
/// </summary>
/// <param name="La">La</param>
/// <param name="Lb">Lb</param>
void replaceNodes(struct Node* La, struct Node* Lb) {
	int num = 0, tmpn = 0;
	// 
	struct Node* Lc = NULL, *newList = NULL;

	while (true){
		num++;
		if (num != j) {
			// 复制j之前和j+len之后的元素给Lc
			insert(Lc, La->data);
		}
		else {
			// 向后跳过len个元素，因为外层还有一个La = La->next所以这里选len-1
			for (int i = 0; i < len - 1; i++)
			{
				insert(newList , La->data);
				La = La->next;
				num++;
			}
			insert(newList, La->data);
		}
		La = La->next;
		if (La == NULL) {
			break;
		}
	}
	struct Node* current = newList;
	while (current->next)
	{
		current = current->next;
	}
	while (Lb->next) {
		insert(current, Lb->data);
		Lb = Lb->next;
	}
	insert(current, Lb->data);
	Lb = newList;
	La = Lc;
	display(La);
	display(Lb);
}

/// <summary>
/// 指针移动法执行替换
/// </summary>
/// <param name="La">La</param>
/// <param name="Lb">Lb</param>
void updateNodeLists(struct Node*& La, struct Node*& Lb) {
	Node* t1 = NULL, * t2 = NULL, * t3 = NULL, * t4 = NULL;
	// t1是La第一段终点，指向j-1
	t1 = La;
	for (int i = 0; i < j - 2; i++)
	{
		t1 = t1->next;
	}
	// t2是La第二段起点，指向j
	t2 = t1->next;
	// t3是La第二段终点，指向j+len
	t3 = t2;
	for (int i = 0; i < len - 1; i++)
	{
		t3 = t3->next;
	}
	// t4是La第三段起点指向j+len+1
	t4 = t3->next;
	// 拼接La的第一三两段
	t1->next = t4;
	int count = 0;

	// 拼接La第二段到Lb前
	t3->next = Lb;
	Lb = t2;
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

	display(La);

	struct Node* Lb = NULL;

	// 设置节点元素
	insert(Lb, 1);
	insert(Lb, 2);
	insert(Lb, 3);
	insert(Lb, 4);
	insert(Lb, 5);
	insert(Lb, 6);

	display(Lb);
	replaceNodes(La, Lb);
	updateNodeLists(La, Lb);
	display(La);
	display(Lb);

	return 0;
}