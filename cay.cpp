#include <iostream>
#define MAX_SIZE 100
using namespace std;

// Node của cây biểu thức
struct Node {
    char value;
    Node* left;
    Node* right;

    Node(char val) : value(val), left(nullptr), right(nullptr) {}
};

// Stack để quản lý các Node
struct Stack {
    Node* arr[MAX_SIZE];
    int top;

    Stack() : top(-1) {}

    void push(Node* node) {
        if (top < MAX_SIZE - 1) {
            arr[++top] = node;
        }
    }

    Node* pop() {
        if (top >= 0) {
            return arr[top--];
        }
        return nullptr;
    }

    Node* peek() {
        if (top >= 0) {
            return arr[top];
        }
        return nullptr;
    }

    bool isEmpty() {
        return top == -1;
    }
};

// Hàm kiểm tra ký tự có phải là toán tử không
bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

// Hàm xây dựng cây biểu thức từ biểu thức hậu tố
Node* constructTree(char postfix[], int n) {
    Stack stack;

    for (int i = 0; i < n; ++i) {
        char c = postfix[i];

        if (!isOperator(c)) {
            // Nếu là toán hạng, tạo nút mới và đẩy vào stack
            stack.push(new Node(c));
        } else {
            // Nếu là toán tử, tạo nút mới và gắn các toán hạng từ stack
            Node* node = new Node(c);

            node->right = stack.pop();
            node->left = stack.pop();

            stack.push(node);
        }
    }

    return stack.pop(); // Root của cây
}

// Hàm duyệt trung tố 
void LNR(Node* tree) {
    if (tree == nullptr) return;

    // Thêm ngoặc nếu nút hiện tại là toán tử
    if (isOperator(tree->value)) cout << "(";

    LNR(tree->left);
    cout << tree->value;
    LNR(tree->right);

    if (isOperator(tree->value)) cout << ")";
}

int main() {
    // Biểu thức hậu tố (postfix) đầu vào
    char postfix[] = {'a', '5', 'b', '*', 'c', '/', '+', 'c', '8', '^', '-', 'd', 'e', '1', '2', '/', '^', '*', '+'};
    int n = sizeof(postfix) / sizeof(postfix[0]);

    // Xây dựng cây biểu thức
    Node* tree = constructTree(postfix, n);

    // Duyệt trung tố
    cout << "Infix Expression: ";
    LNR(tree);
    cout << endl;

    return 0;
}
