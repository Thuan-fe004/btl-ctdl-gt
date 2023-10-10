#include <stdio.h>
#include <stdlib.h>

//định nghĩa 1 nút
typedef struct tagNode {
    int data ;
    
    struct tagNode* pnext;
} Node;

typedef struct tagList {
    Node* pHead; // Lưu địa chỉ Node đầu tiên trong List
    Node* pTail;
} List;

void CreateList(List* l) {
    l->pHead = NULL;
    l->pTail = NULL;
}

//tạo nút mới
Node* CreateNode(int data){
    Node* p;
    p = (Node*)malloc(sizeof(Node));
    p->data = data;
    p->pnext = NULL;
    return p;
}

//chèn nút mới vào cuối danh sách
void insert(List *l, Node *p){
    if (l ->pHead == NULL)
    {
       l ->pHead = p;
       l ->pTail = p;
    }
    else{
        l ->pTail ->pnext = p;
        l -> pTail = p;
    }
    
}
//hiển thị danh sách lk đơn
void displayList(List* l) {
    Node* currentNode = l->pHead;
    while (currentNode != NULL) {
        printf("%d ", currentNode->data);
        currentNode = currentNode->pnext;
    }
}
//giải phóng bộ nhớ
void freeList(List* l) {
    Node* currentNode = l->pHead;
    while (currentNode != NULL) {
        Node* temp = currentNode;
        currentNode = currentNode->pnext;
        free(temp);
    }
    l->pHead = NULL;
    l->pTail = NULL;
}

 // nhập danh sách số kết thúc khi nhập kí tự @




// Sắp xếp danh sách theo thứ tự tăng dần.(sử dụng thuật toán Quick Sort)



//Liệt kê ra màn hình tất cả các phần tử là số chính phương




//Xóa tất cả các số nguyên tố trong danh sách.





//Xóa tất cả các phần tử có giá trị trùng nhau trong danh sách.
void removeDuplicates(List* l) {
    Node* currentNode = l->pHead;
    while (currentNode != NULL) {
        Node* compareNode = currentNode;
        while (compareNode->pnext != NULL) {
            if (compareNode->pnext->data == currentNode->data) {
                Node* temp = compareNode->pnext;
                compareNode->pnext = compareNode->pnext->pnext;
                free(temp);
            } else {
                compareNode = compareNode->pnext;
            }
        }
        currentNode = currentNode->pnext;
    }
}

//Xét dãy 3 số liên có tạo ra một dãy cấp số cộng/ số nhân hay không?, bao nhiêu số tạo ra các cấp đó.





int main() {
  
}
