#include <stdio.h>
#include <stdlib.h>


// Định nghĩa một nút trong danh sách liên kết đơn
struct Node {
    int data;           // Giá trị của nút
    struct Node* next;  // Con trỏ trỏ đến nút tiếp theo trong danh sách
};

typedef struct Node Node;

// Tạo một nút mới với giá trị được cung cấp
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Chèn một nút mới vào cuối danh sách
void insert(Node** head, int value) {
    Node* newNode = createNode(value);
    if (*head == NULL) {
        *head = newNode;  // Nếu danh sách rỗng, nút mới là nút đầu tiên
    } else {
        Node* current = *head;
        while (current->next != NULL) {
            current = current->next;  // Di chuyển đến cuối danh sách
        }
        current->next = newNode;  // Chèn nút mới vào cuối danh sách
    }
}

// Hiển thị danh sách liên kết đơn
void displayList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Giải phóng bộ nhớ của danh sách liên kết đơn
void freeList(Node** head) {
    Node* current = *head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
    *head = NULL;
}

// Xóa các phần tử trùng nhau trong danh sách liên kết đơn
void removeDuplicates(Node* head) {
    if (head == NULL) {
        return;  // Nếu danh sách rỗng, không có gì để xóa
    }

    Node* phead = head;

    while (phead != NULL) {
        Node* runner = phead;

        while (runner->next != NULL) {
            // Nếu phần tử tiếp theo trùng giá trị với phead, xóa nút đó
            if (runner->next->data == phead->data) {
                Node* duplicate = runner->next;
                runner->next = runner->next->next;  // Bỏ qua nút trùng
                free(duplicate);  // Giải phóng bộ nhớ của nút trùng
            } else {
                runner = runner->next;
            }
        }

        phead = phead->next;
    }
}

int main() {
    Node* head = NULL;
    int num;
    char input[100];

    printf("nhap danh sach cac so ket thuc bang nhap ki tu @:");
    while (scanf("%s", input) == 1 && input[0] != '@') {
        num = atoi(input);
        insert(&head, num);
    }

    printf("Danh sach cac so truoc khi xoa cac phan tu trung nhau: ");
    displayList(head);

    removeDuplicates(head);

    printf("Danh sach cac so sau khi xoa phan tu trung nhau: ");
    displayList(head);

    freeList(&head);

    return 0;
}