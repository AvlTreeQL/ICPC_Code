#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
	ElementType Data;
	PtrToNode   Next;
};
typedef PtrToNode List;

List Read(); /* 细节在此不表 */
void Print(List L); /* 细节在此不表；空链表将输出NULL */

List Merge(List L1, List L2);

int main()
{
//	freopen("input.txt", "r", stdin);
	List L1, L2, L;
	L1 = Read();
	Print(L1);
	L2 = Read();
	L = Merge(L1, L2);
	Print(L);
	Print(L1);
	Print(L2);
	return 0;
}
List Read() {
	int n;
	List L = (List)malloc(sizeof(struct Node));
	List tail = L;
	L->Next = NULL;
	scanf("%d", &n);
	while (n--) {
		int temp;
		scanf("%d", &temp);
		List x = (List)malloc(sizeof(struct Node));
		x->Data = temp;
		x->Next = tail->Next;
		tail->Next = x;
		tail = tail->Next;
	}
	return L;
}
void Print(List L) {
	List now = L->Next;
	if (!now) printf("NULL");
	while (now) {
		printf("%d ", now->Data);
		now = now->Next;
	}
	printf("\n");
}
List Merge(List L1, List L2) {
	List L = (List)malloc(sizeof(struct Node));
	List tail = L;
	List a = L1->Next;
	List b = L2->Next;
	while (a&&b) {
		List x = (List)malloc(sizeof(struct Node));
		if (a->Data < b->Data) {
			x->Data = a->Data;
			x->Next = tail->Next;
			tail->Next = x;
			tail = tail->Next;
			a = a->Next;
		} else {
			x->Data = b->Data;
			x->Next = tail->Next;
			tail->Next = x;
			tail = tail->Next;
			b = b->Next;
		}
	}
	tail->Next = a ? a : b;
	L1->Next = NULL;
	L2->Next = NULL;
	return L;
}