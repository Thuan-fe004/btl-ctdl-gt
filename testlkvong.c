#include <stdio.h>
#include <stdlib.h>

// Định nghĩa 1 nút
typedef struct tagNode {
    int data;
    struct tagNode* pNext;
} Node;

typedef struct tagList {
    Node* pHead; // Lưu địa chỉ Node đầu tiên trong List
    Node* pTail;
} List;

void CreateList(List* l) {
    l->pHead = NULL;
    l->pTail = NULL;
}

// Tạo nút mới
Node* CreateNode(int x) {
    Node* p;
    p = (Node*)malloc(sizeof(Node));
    p->data = x;
    p->pNext = NULL;
    return p;
}

// Chèn nút mới vào cuối danh sách
void insert(List* l, Node* p) {
    if (l->pHead == NULL) {
        l->pHead = p;
        l->pTail = p;
        p->pNext = l->pHead; // Đặt pNext của p trỏ đến pHead để tạo danh sách liên kết vòng
    }
    else {
        l->pTail->pNext = p;
        l->pTail = p;
        p->pNext = l->pHead; // Đặt pNext của p trỏ đến pHead để tạo danh sách liên kết vòng
    }
}

// Hiển thị danh sách liên kết vòng
void displayList(List* l) {
    if (l->pHead == NULL) {
        printf("Danh sach rong.\n");
        return;
    }
    
    Node* current = l->pHead;
    printf("Cac phan tu trong danh sach: ");
    do {
        printf("%d ", current->data);
        current = current->pNext;
    } while (current != l->pHead);
    printf("\n");
}

// Giải phóng bộ nhớ
void freeList(List* l) {
    if (l->pHead == NULL) {
        return;
    }
    
    Node* current = l->pHead;
    Node* next;
    
    do {
        next = current->pNext;
        free(current);
        current = next;
    } while (current != l->pHead);
    
    l->pHead = NULL;
    l->pTail = NULL;
}

int main() {
    List myList;
    CreateList(&myList);
    
    int n, i, data;
    
    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);
    
    printf("Nhap cac phan tu:\n");
    for (i = 0; i < n; i++) {
        printf("Nhap phan tu thu %d: ", i+1);
        scanf("%d", &data);
        Node* newNode = CreateNode(data);
        insert(&myList, newNode);
    }
    
    printf("Danh sach sau khi them:\n");
    displayList(&myList);
    
    freeList(&myList);
    
    return 0;
}