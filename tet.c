#include <stdio.h>
#include <stdlib.h>

// Định nghĩa cấu trúc nút cho danh sách liên kết đơn
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Hàm chèn một phần tử vào cuối danh sách liên kết
void insert(Node** head, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Hàm in ra danh sách liên kết
void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    Node* head = NULL;
    int value;
    char input[100];

    printf("Nhập các số nguyên vào danh sách (nhập @ để kết thúc):\n");

    while (1) {
        scanf("%s", input);

        if (input[0] == '@') {
            break;
        }

        value = atoi(input);
        insert(&head, value);
    }

    printf("Danh sách số nguyên:\n");
    printList(head);

    return 0;
}
