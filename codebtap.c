#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Định nghĩa 1 nút
typedef struct tagNode {
    int data;
    struct tagNode* pNext;
} Node;

typedef struct tagList {
    Node* pHead; // Lưu địa chỉ Node đầu tiên trong List
    Node* pTail;
} List;

// Hàm tạo danh sách rỗng
void CreateList(List* l) {
    l->pHead = NULL;
    l->pTail = NULL;
}

// Hàm tạo nút mới
Node* CreateNode(int x) {
    Node* p;
    p = (Node*)malloc(sizeof(Node));
    p->data = x;
    p->pNext = NULL;
    return p;
}

// Hàm chèn nút mới vào cuối danh sách
void Insert(List* l, Node* p) {
    if (l->pHead == NULL) {
        l->pHead = p;
        l->pTail = p;
    }
    else {
        l->pTail->pNext = p;
        l->pTail = p;
    }
}

// Hàm hiển thị danh sách liên kết đơn
void DisplayList(List* l) {
    Node* current = l->pHead;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->pNext;
    }
    printf("\n");
}

// Hàm giải phóng bộ nhớ
void FreeList(List* l) {
    Node* current = l->pHead;
    while (current != NULL) {
        Node* temp = current;
        current = current->pNext;
        free(temp);
    }
    l->pHead = NULL;
    l->pTail = NULL;
}

// Hàm nhập danh sách kết thúc khi nhập kí tự '@'
void InputList(List* l) {
    char ch;
    int x;

    printf("Nhap danh sach (nhap '@' de ket thuc):\n");
    while (1) {
        scanf(" %c", &ch);

        if (ch == '@') {
            break;
        }

        x = atoi(&ch);
        Node* p = CreateNode(x);
        Insert(l, p);
    }
}


// Hàm sắp xếp danh sách theo thứ tự tăng dần sử dụng thuật toán Quick Sort
void QuickSort(List* l, Node* left, Node* right) {
    if (left == right || right == NULL || left == NULL) {
        return;
    }
    int pivot = left->data;
    Node* i = left;
    Node* j = left->pNext;
    while (j != right->pNext) {
        if (j->data < pivot) {
            i = i->pNext;
            int temp = i->data;
            i->data = j->data;
            j->data = temp;
        }
        j = j->pNext;
    }
    int temp = i->data;
    i->data = left->data;
    left->data = temp;

    QuickSort(l, left, i);
    QuickSort(l, i->pNext, right);
}

// Hàm kiểm tra xem một số có phải là số chính phương hay không
int IsPerfectSquare(int n) {
    int root = sqrt(n);
    return (root * root == n);
}

// Hàm liệt kê tất cả các phần tử là số chính phương trong danh sách
void ListPerfectSquares(List* l) {
    Node* current = l->pHead;
    while (current != NULL) {
        if (IsPerfectSquare(current->data)) {
            printf("%d ", current->data);
        }
        current = current->pNext;
    }
    printf("\n");
}

// Hàm kiểm tra xem một số có phải là số nguyên tố hay không
int IsPrime(int n) {
    if (n <= 1) {
        return 0;
    }
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

// Hàm xóa tất cả các số nguyên tố trong danh sách
void RemovePrimes(List* l) {
    Node* current = l->pHead;
    Node* previous = NULL;
    while (current != NULL) {
        if (IsPrime(current->data)) {
            Node* temp = current;
            if (previous == NULL) {
                l->pHead = current->pNext;
            }
            else {
                previous->pNext = current->pNext;
            }
            current = current->pNext;
            free(temp);
        }
        else {
            previous = current;
            current = current->pNext;
        }
    }
    if (previous != NULL) {
        l->pTail = previous;
    }
}

// Hàm xóa tất cả các phần tử có giá trị trùng nhau trong danh sách
void RemoveDuplicates(List* l) {
    Node* current = l->pHead;
    while (current != NULL) {
        Node* runner = current;
        while (runner->pNext != NULL) {
            if (runner->pNext->data == current->data) {
                Node* temp = runner->pNext;
                runner->pNext = runner->pNext->pNext;
                free(temp);
            }
            else {
                runner = runner->pNext;
            }
        }
        current = current->pNext;
    }
    l->pTail = current;
}

// Hàm kiểm tra xem 3 số có tạo thành dãy số cấp số cộng không
int IsArithmeticSequence(int a, int b, int c) {
    return (b - a == c - b);
}

// Hàm kiểm tra xem 3 số có tạo thành dãy số cấp số nhân không
int IsGeometricSequence(int a, int b, int c) {
    return (b * b == a * c);
}

// Hàm kiểm tra xem danh sách có chứa dãy số cấp số cộng hoặc cấp số nhân không
void CheckSequences(List* l) {
    int countArithmetic = 0;
    int countGeometric = 0;
    Node* current = l->pHead;
    while (current != NULL && current->pNext != NULL && current->pNext->pNext != NULL) {
        if (IsArithmeticSequence(current->data, current->pNext->data, current->pNext->pNext->data)) {
            countArithmetic++;
        }
        if (IsGeometricSequence(current->data, current->pNext->data, current->pNext->pNext->data)) {
            countGeometric++;
        }
        current = current->pNext;
    }

    if (countArithmetic > 0) {
        printf("Danh sach chua day so cap so cong.\n");
    }
    else {
        printf("Danh sach khong chua day so cap so cong.\n");
    }

    if (countGeometric > 0) {
        printf("Danh sach chua day so cap so nhan.\n");
    }
    else {
        printf("Danh sach khong chua day so cap so nhan.\n");
    }
}


// Định nghĩa các hàm và struct đã được cung cấp


int main() {
    List l;
    CreateList(&l);
    int choice;
    do {
        printf("\nMENU:\n");
        printf("1. Tao danh sach so (nhap @ de ket thuc)\n");
        printf("2. Sap xep danh sach\n");
        printf("3. Liet ke so chinh phuong\n");
        printf("4. Xoa so nguyen to\n");
        printf("5. Xoa cac phan tu trung nhau\n");
        printf("6. Kiem tra cac day so lien tiep\n");
        printf("0. Thoat\n");
        printf("Nhap lua chon cua ban: ");
        scanf(" %d", &choice);

        switch (choice) {
            case 1: {
                InputList(&l);

                printf("Danh sach vua nhap: ");
                DisplayList(&l);
                break;

            }
            case 2: {
                QuickSort(&l, l.pHead, l.pTail);
                printf("Danh sach sau khi sap xep: ");
                DisplayList(&l);
                break;
            }
            case 3: {
                printf("Cac so chinh phuong trong danh sach: ");
                ListPerfectSquares(&l);
                break;
            }
            case 4: {
                RemovePrimes(&l);
                printf("Danh sach sau khi xoa so nguyen to: ");
                DisplayList(&l);
                break;
            }
            case 5: {
                RemoveDuplicates(&l);
                printf("Danh sach sau khi xoa cac phan tu trung nhau: ");
                DisplayList(&l);
                break;
            }
            case 6: {
                CheckSequences(&l);
                break;
            }
            case 0: {
                FreeList(&l);
                printf("Thoat chuong trinh.\n");
                break;
            }
            default: {
                printf("Lua chon khong hop le. Vui long nhap lai.\n");
                break;
            }
        }
    } while (choice != 0);

    return 0;
}
