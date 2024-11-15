#include <iostream>

using namespace std;



// Định nghĩa cấu trúc cho một node trong Stack
struct Node {
    int data;
    Node *next;
};

// Định nghĩa cấu trúc cho Stack sử dụng danh sách liên kết
struct Stack {
    Node *top;
};

// Khởi tạo ngăn xếp
void init(Stack &S) {
    S.top = nullptr;
}

// Kiểm tra ngăn xếp rỗng
bool isEmpty(Stack S) {
    return (S.top == nullptr);
}



// Hàm push thêm phần tử x vào đỉnh ngăn xếp
void push(Stack &S, int x) {
    Node *newNode = new Node;
    newNode->data = x;
    newNode->next = S.top;
    S.top = newNode;
    
}

// Hàm pop xóa phần tử ở đỉnh ra khỏi ngăn xếp
int pop(Stack &S) {
    if (isEmpty(S)) {
        cout << "Ngan xep rong! " << endl;
        return -1; // Giá trị lỗi để báo ngăn xếp rỗng
    } else {
        Node *temp = S.top;
        int x = temp->data;
        S.top = S.top->next;
        delete temp;
        return x;
    }
}

// Hàm nhập ngăn xếp
void input(Stack &S) {
    cout << "Nhap gia tri cho stack : " << endl;
    int x;
    do {
        cin >> x;
        if (x != 0) {
            push(S, x);
        }
    } while (x != 0);
}

// Hàm xuất ngăn xếp
void output(Stack S) {
    cout << "Cac phan tu trong stack: ";
    while (!isEmpty(S)) {
        cout << pop(S) << " ";
    }
    cout << endl;
}

int main() {
    Stack S;
    init(S);

    
    input(S);

    
    output(S);

    return 0;
}
