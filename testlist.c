#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Định nghĩa cấu trúc nút trong danh sách liên kết đơn
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Hàm tạo một nút mới chứa giá trị x
Node* createNode(int x) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = x;
    newNode->next = NULL;
    return newNode;
}

// Hàm chèn một nút mới vào đầu danh sách
void insertNode(Node** head, int x) {
    Node* newNode = createNode(x);
    if (*head == NULL) {
        *head = newNode;
    } else {
        newNode->next = *head;
        *head = newNode;
    }
}

// Hàm nhập danh sách số nguyên từ người dùng
void inputList(Node** head) {
    int x;
    printf("Nhap cac so nguyen (Dung khi nhap ki tu @):\n");
    while (1) {
        scanf("%d", &x);
        if (x == '@')
            break;
        insertNode(head, x);
    }
}

// Hàm in danh sách
void printList(Node* head) {
    Node* current = head;
    printf("Danh sach cac so nguyen: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("%d\n");
}

// Hàm hoán đổi giá trị của hai nút
void swap(Node* a, Node* b) {
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}

// Hàm sắp xếp danh sách theo thứ tự tăng dần
void sortList(Node* head) {
    Node* current;
    Node* index;
    if (head == NULL)
        return;
    else {
        for (current = head; current->next != NULL; current = current->next) {
            for (index = current->next; index != NULL; index = index->next) {
                if (current->data > index->data)
                    swap(current, index);
            }
        }
    }
}

// Hàm kiểm tra xem một số có phải là số chính phương hay không
int isPerfectSquare(int x) {
    int sqrtX = sqrt(x);
    return sqrtX * sqrtX == x;
}

// Hàm liệt kê các số chính phương trong danh sách
void listPerfectSquares(Node* head) {
    Node* current = head;
    printf("Cac so chinh phuong trong danh sach: ");
    while (current != NULL) {
        if (isPerfectSquare(current->data))
            printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Hàm kiểm tra xem một số có phải là số nguyên tố hay không
int isPrime(int x) {
    if (x <= 1)
        return 0;
    for (int i = 2; i <= sqrt(x); i++) {
        if (x % i == 0)
            return 0;
    }

    return 1;
}

// Hàm xóa tất cả các số nguyên tố trong danh sách
void removePrimes(Node** head) {
    Node* current = *head;
    Node* prev = NULL;
    while (current != NULL) {
        if (isPrime(current->data)) {
            if (prev == NULL) {
                *head = current->next;
                free(current);
                current = *head;
            } else {
                prev->next = current->next;
                free(current);
                current = prev->next;
            }
        } else {
            prev = current;
            current = current->next;
        }
    }
}

// Hàm xóa tất cả các phần tử trùng nhau trong danh sách
void removeDuplicates(Node* head) {
    Node* current = head;
    Node* nextNext;
    if (current == NULL)
        return;
    while (current->next != NULL) {

        if (current->data == current->next->data) {
            nextNext = current->next->next;
            free(current->next);
            current->next = nextNext;
        } else {
            current = current->next;
        }
    }
}

// Hàm kiểm tra xem một dãy 3 số có tạo ra cấp số cộng hay số nhân không
int isArithmeticOrGeometric(int a, int b, int c) {
    int diff1 = b - a;
    int diff2 = c - b;
    if (diff1 == diff2)
        return 1;
    else if (a != 0 && b != 0 && c != 0 && b % a == 0 && c % b == 0 && c / b == b / a)
        return 2;
    else
        return 0;
}

// Hàm xét dãy 3 số liên tiếp có tạo ra cấp số cộng/số nhân hay không, và số lượng cấp đó
void checkSequences(Node* head) {
    Node* current = head;
    int count = 0;
    while (current != NULL && current->next != NULL && current->next->next != NULL) {
        int result = isArithmeticOrGeometric(current->data, current->next->data, current->next->next->data);
        if (result == 1) {
            printf("%d, %d, %d tao danh sach so cong.\n", current->data, current->next->data, current->next->next->data);
            count++;
        } else if (result == 2) {
            printf("%d, %d, %d tao danh sach so nguyen.\n", current->data, current->next->data, current->next->next->data);
            count++;
        }
        current = current->next;
    }
    if (count == 0)
        printf("khong co day so cong hay day so nguyen.\n");
    else
        printf("Tong cong co %d day so cong hoac day so nguyen trong danh sach.\n", count);
}

// Hàm giải phóng bộ nhớ của danh sách
void freeList(Node* head) {
    Node* current = head;
    Node* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}

int main() {
    Node* head = NULL;
    int choice;

    do {
        printf("\n----- Menu -----\n");
        printf("1. Tao danh sach\n");
        printf("2. Sap xep danh sach\n");
        printf("3. Liet ke so chinh phuong\n");
        printf("4. Xa so nguyen to\n");
        printf("5. xoa phan tu trung nhau\n");
        printf("6. kiem tra day so\n");
        printf("0. thoat\n");

        printf("nhap lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 0:
                printf("Ket thuc chuong trinh.\n");
                break;
            case 1:
                freeList(head);
                head = NULL;
                inputList(&head);
                break;
            case 2:
                sortList(head);
                printf("Danh sach da dc sap xep\n");
                break;
            case 3:
                listPerfectSquares(head);
                break;
            case 4:
                removePrimes(&head);
                printf("Da xoa tat ca so nguyen trong danh  sach.\n");
                break;
            case 5:
                removeDuplicates(head);
                printf("da xoa tat ca phan tu trung nhau trong danh sach\n");
                break;
            case 6:
                checkSequences(head);
                break;
            default:
                printf("Lua chon khon hop le. Vui long nhap lai.\n");
                break;
        }
    } while (choice != 0);

    freeList(head);
    return 0;
}