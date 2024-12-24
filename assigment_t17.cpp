#include <iostream>
using namespace std;

// Cấu trúc cây AVL
struct Node {
    int data;
    Node* left;
    Node* right;
    int height;
    
    Node(int value) : data(value), left(nullptr), right(nullptr), height(1) {}
};

// Hàm tính chiều cao của cây
int height(Node* node) {
    return (node == nullptr) ? 0 : node->height;
}

// Hàm tính chỉ số cân bằng (Balance Factor) của một node
int getBalance(Node* node) {
    return (node == nullptr) ? 0 : height(node->left) - height(node->right);
}

// Hàm xoay trái (Left Rotation)
Node* rotLeft(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;
    
    // Thực hiện xoay
    y->left = x;
    x->right = T2;

    // Cập nhật chiều cao của các node
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y; // trả về node mới là root
}

// Hàm xoay phải (Right Rotation)
Node* rotRight(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    // Thực hiện xoay
    x->right = y;
    y->left = T2;

    // Cập nhật chiều cao của các node
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x; // trả về node mới là root
}

// Hàm thêm một node mới vào cây AVL
Node* add(Node* node, int key) {
    if (node == nullptr) {
        return new Node(key);
    }

    if (key < node->data) {
        node->left = add(node->left, key);
    } else if (key > node->data) {
        node->right = add(node->right, key);
    }

    node->height = max(height(node->left), height(node->right)) + 1;

    int balance = getBalance(node);

    if (balance > 1 && key < node->left->data) {
        return rotRight(node);
    }

    if (balance < -1 && key > node->right->data) {
        return rotLeft(node);
    }

    if (balance > 1 && key > node->left->data) {
        node->left = rotLeft(node->left);
        return rotRight(node);
    }

    if (balance < -1 && key < node->right->data) {
        node->right = rotRight(node->right);
        return rotLeft(node);
    }

    return node;
}

// Hàm duyệt cây theo thứ tự Pre-order (Root, Left, Right)
void preOrder(Node* root) {
    if (root != nullptr) {
        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

// Hàm duyệt cây theo thứ tự In-order (Left, Root, Right)
void inOrder(Node* root) {
    if (root != nullptr) {
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }
}

// Hàm duyệt cây theo thứ tự Post-order (Left, Right, Root)
void postOrder(Node* root) {
    if (root != nullptr) {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->data << " ";
    }
}

// Hàm xóa cây để giải phóng bộ nhớ
void deleteTree(Node* node) {
    if (node == nullptr) return;
    
    deleteTree(node->left);
    deleteTree(node->right);
    delete node;
}

// Hàm main
int main() {
    int a[] = {240, 73, 101, 21, 13, 25, 11, 37, 89, 30, 15, 51};
    int n = sizeof(a) / sizeof(a[0]);


     cout<<" Cay in theo thu tu pre-order "<<endl;
    // Duyệt qua mảng và chèn vào cây AVL
    for (int i = 0; i < n; ++i) {
        Node* root = nullptr;

        // Chèn các phần tử vào cây
         
        for (int j = 0; j <= i; ++j) {
            root = add(root, a[j]);
        }

        // In cây theo thứ tự Pre-order
       
        cout << "Cay sau khi them node la: " << a[i] << ": ";
        preOrder(root);
        cout << endl;

        // Xóa cây để chuẩn bị cho lần duyệt tiếp theo
        deleteTree(root);

        // Chèn lại cây từ đầu
        root = nullptr;
    }


    

     cout<< "Cay in theo thu tu in-order "<<endl;
    for (int i = 0; i < n; ++i) {
        Node* root = nullptr;

        // Chèn các phần tử vào cây
       
        for (int j = 0; j <= i; ++j) {
            root = add(root, a[j]);
        }

        // In cây theo thứ tự In-order
        
        cout << "Cay sau khi them node la: " << a[i] << ": ";
        inOrder(root);
        cout << endl;

        // Xóa cây để chuẩn bị cho lần duyệt tiếp theo
        deleteTree(root);

        // Chèn lại cây từ đầu
        root = nullptr;
    }



     cout<<"Cay in theo thu tu post-order"<<endl;
    for (int i = 0; i < n; ++i) {
        Node* root = nullptr;

        // Chèn các phần tử vào cây
        
        for (int j = 0; j <= i; ++j) {
            root = add(root, a[j]);
        }

        // In cây theo thứ tự Post-order
       
        cout << "Cay sau khi them node la: " << a[i] << ": ";
        postOrder(root);
        cout << endl;

        // Xóa cây để chuẩn bị cho lần duyệt tiếp theo
        deleteTree(root);

        // Chèn lại cây từ đầu
        root = nullptr;
    }

    return 0;
}
