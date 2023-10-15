#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Định nghĩa 1 nút
typedef struct tagNode {
    int data;
    struct tagNode* pNext;
    struct tagNode* pPrev;
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
//hàm tạo 1 ds liên kết mới từ mảng arr và n phần tử
void createCircularList(List* l) {
    CreateList(l);

     int n, data;
        printf("Nhap so luong phan tu: ");
        scanf("%d", &n);
    for (int i = 0; i < n; i++) {
         printf("Nhap phan tu thu %d: ", i+1);
        scanf("%d", &data);
        Node* newNode = CreateNode(data);
        insert(l, newNode);
    }
}
//hàm kiểm tra snt
int isPrime(int x) {
    if (x < 2) {
        return 0;
    }
    for (int i = 2; i <= sqrt(x); i++) {
        if (x % i == 0) {
            return 0;
        }
    }
    return 1;
}
// hàm duyệt ds và in ra snt
void findPrimeNumbers(List* l) {
    if (l->pHead == NULL) {
        printf("Danh sach rong.\n");
        return;
    }
    
    Node* current = l->pHead;
    int i = 1;
    int primeFound = 0;
    printf("Cac so nguyen to trong danh sach:\n");
    do {
        if (isPrime(current->data)) {
            printf("Vi tri %d: %d\n", i, current->data);
        }
        current = current->pNext;
        i++;
    } while (current != l->pHead);
    
}

void checkAndRemoveZero(List* l ) {
    if (l->pHead == NULL) {
        printf("Danh sach rong.\n");
        return;
    }
    
    Node* current = l->pHead;
    Node* prev = NULL;
    int position = 1;


    // struct Node* current = *head; // Con trỏ hiện tại
    // struct Node* prev = NULL; // Con trỏ trỏ tới node trước node hiện tại
    // int position = 1; // Vị trí hiện tại

    while (position < 5 && current->pNext != l ->pHead) {
        prev = current;
        current = current->pNext;
        position++;
    }

    if (position == 5 && current->data == 0) { // Nếu vị trí là 5 và giá trị là 0
        if (prev == NULL) { // Nếu không có node trước đầu danh sách (đây là node đầu tiên)
            
            while (l->pTail->pNext != l->pHead) {
                l->pTail= l->pTail->pNext;
            }
             l->pHead = current->pNext;
             l->pTail->pNext = l->pHead;
             // Đặt đầu danh sách là node tiếp theo
             // Cập nhật con trỏ next của node cuối cùng
        } else {
           prev->pNext = current->pNext; // Kết nối node trước node hiện tại với node sau node hiện tại
            free(current); // Giải phóng bộ nhớ của node hiện tại
        }
        printf("Da xoa so 0 o vi tri 5.\n");
    } else {
        printf("Khong tim thay so 0 o vi tri 5.\n");
    }
}
void removeNegativeNumbers(List* l) {
    if (l->pHead == NULL) {
        return;
    }

    Node* current = l->pHead;
    Node* previous = l->pTail;

    do {
        if (current->data < 0) {
            // Xóa nút hiện tại
            if (current == l->pHead) {
                l->pHead = current->pNext;
                l->pTail->pNext = l->pHead;
            } else if (current == l->pTail) {
                l->pTail = previous;
                previous->pNext = l->pHead;
            } else {
                previous->pNext = current->pNext;
            }

            Node* temp = current;
            current = current->pNext;
            free(temp);
        } else {
            previous = current;
            current = current->pNext;
        }
    } while (current != l->pHead);
}


int main() {
    List list;
    CreateList(&list);

    int choice;
    do {
        printf("\nMenu:\n");
        printf("1. Tao danh sach\n");
        printf("2. tim va in ra so nguyen to trong danh sach\n");
        printf("3. kiem tra va xoa so 0 o vi tri 5\n");
        printf("4. Xoa cac so am trong danh sach\n");
  
        printf("0. Thoat\n");
        printf("nhap lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1: {
            createCircularList(&list);
            printf("Danh sach vua nhap: ");
            displayList(&list);
            break;
        }
        case 2: {
                findPrimeNumbers(&list);
                printf("Danh sach ban dau:");
                displayList(&list);
                break;
        }
        case 3: {
            checkAndRemoveZero(&list);
            printf("Danh sach sau khi xoa vi tri thu 5: ");
            displayList(&list);
            break;
        }
        case 4: {
            removeNegativeNumbers(&list);
            printf("danh sach sau khi xoa so am: ");
            displayList(&list);
            break;

        }
        
        case 0:{
            freeList(&list);
            printf("Thoat chuong trinh.");
            break;

        }
            
            
        
        default:{
            printf("Lua chon khong hop le. Vui long nhap lai.\n");
                break;
        }
            
        }
    }while (choice != 0);
     return 0;
}