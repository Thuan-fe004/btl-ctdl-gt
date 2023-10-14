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
    char input[100];
    int b;

    printf("Nhap danh sach (nhap '@' de ket thuc):\n");
    while (1) {
        scanf(" %s", input);

        if (input[0] == '@') {
            break;
        }

        b = atoi( input);
        Node* p = CreateNode(b);
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
    int c = sqrt(n);
    return (c * c == n);
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
// Hàm kiểm tra xem một dãy 3 số có tạo ra cấp số cộng hay số nhân không
int kiemtraday3so(int a, int b, int c) {
    int d1 = b - a;
    int d2 = c - b;
    if (d1 == d2)
        return 1;
    else if (a != 0 && b != 0 && c != 0 && b % a == 0 && c % b == 0 && c / b == b / a)
        return 2;
    else
        return 0;
}

// Hàm xét dãy 3 số liên tiếp có tạo ra cấp số cộng/số nhân hay không, và số lượng cấp đó
void checkSequences(List* l) {
    Node* current = l->pHead;
    int x = 0;
    int z = 0;
    while (current != NULL && current->pNext != NULL && current->pNext->pNext != NULL) {
        int y = kiemtraday3so(current->data, current->pNext->data, current->pNext->pNext->data);
        if (y == 1) {
            printf("%d, %d, %d tao danh sach so cong.\n", current->data, current->pNext->data, current->pNext->pNext->data);
            x++;
        } else if (y == 2) {
            printf("%d, %d, %d tao danh sach so nhan.\n", current->data, current->pNext->data, current->pNext->pNext->data);
            z++;
        }
        current = current->pNext;
    }
    if (x == 0)
        printf("khong co day so cong.\n");
    if (z ==0)
        printf("khong co day so nhan.\n");
    else
        printf("Tong cong co %d day so cong.\n", x);
        printf("Tong cong co %d day so nhan.\n", z);

}




int main() {
    List l;
    CreateList(&l);
    int choice;
    do {
        printf("\n||----------------------------------------------MENU-------------------------------------------------||\n");
        printf("  1.Tao danh sach so (nhap @ de ket thuc).                 ");
        printf("  2.Sap xep danh sach theo thu tu tang dan.\n\n");
        printf("  3.Liet ke cac so chinh phuong.                           ");
        printf("  4.Xoa so nguyen to.\n\n");
        printf("  5.Xoa cac phan tu trung nhau.                            ");
        printf("  6.Kiem tra cac day so lien tiep.\n\n");
        printf("  0.Thoat chuong trinh.\n----------------\n\n");
        
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
                printf("Cac so chinh phuong trong danh sach la: ");
                ListPerfectSquares(&l);
                break;
            }
            case 4: {
                RemovePrimes(&l);
                printf("Danh sach sau khi xoa so nguyen to la: ");
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
                checkSequences(&l);
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
