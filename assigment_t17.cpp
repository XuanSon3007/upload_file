#include <iostream>

using namespace std;

// Cấu trúc cây AVL
struct Node{
    int data;
    Node *left;
    Node *right;
    int height;

     Node(int value) : data(value), left(nullptr), right(nullptr), height(1) {}// khởi tạo node ban đầu
};

// Hàm tính chiều cao của cây
int height(Node *node){
    if(node == nullptr) return 0;
    return node->height;
}

//Tính chỉ số cân bằng của 1 node

int getBalanceFactor(Node *node){
    if(node == nullptr) return 0;
    return height(node->left) - height(node->right);
}

//Hàm xoay trái
Node * rotLeft(Node *x){
    Node *y = x->right;
    Node *T2 = y->left;

    //Thực hiện xoay
    y->left = x;
    x->right = T2;

    //Cập nhật chiều cao của các node
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;//trả về node mới là node root
}

//Hàm xoay phải
Node *rotRight(Node *y){
    Node *x = y->left;
    Node *T2 = x->right;

    //Thực hiện xoay
    x->right = y;
    y->left = T2;

    //Cập nhật chiều cao của các node
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x; //trả về node mới là node root
}

//Hàm xoay kép phải - trái
Node *rotRightLeft(Node *node){
    node->right = rotRight(node->right);
    return rotLeft(node);
}

//Hàm xoay kép trái - phải
Node *rotLeftRight(Node *node){
    node->left = rotLeft(node->left);
    return rotRight(node);
}

//Hàm thêm 1 node mới vào cây AVL
Node *add(Node *node, int val){
    // thực hiện chèn node mới
    if(node == nullptr){
        return new Node(val);
    }

    if(val < node ->data){
        node->left = add(node->left, val);
    } else if(val > node ->data || val == node ->data){
        node->right = add(node->right, val);
    } 

    // Cập nhật chiều cao node cha
    node -> height = max(height(node->left), height(node->right))+1;

    //Kiểm tra và cân bằng cây
    int balance = getBalanceFactor(node);

    // Thực hiện xoay khi cây mất cân bằng

    //TH1: Trái-Trái
    if(balance > 1 && val < node->left->data){
        return rotRight(node);
    }

    //TH2: Phải-Phải
    if(balance < -1 && val > node->right->data){
        return rotLeft(node);
    }

    //TH3: Phải-Trái
    if(balance < -1 && val < node->right->data){
        return rotRightLeft(node);
    }

    //TH4: Trái-Phải
    if(balance > 1 && val > node->left->data){
        return rotLeftRight(node);
    }

    return node;
}

// Hàm duyệt cây theo thứ tự trước(preOrder)
void preOrder(Node *root){
    if(root != nullptr){
        cout<< root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

//Hàm duyệt cây theo thứ tự giữa
void inOrder(Node *root){
    if(root != nullptr){
        inOrder(root->left);
        cout<< root->data << " ";
        inOrder(root->right);
    }
}

// Hàm duyệt cây theo thứ tự sau
void postOrder(Node *root){
    if(root != nullptr){
        postOrder(root->left);
        postOrder(root->right);
        cout<< root->data << " ";
    }
}

int main(){
    Node *root = nullptr;
    
    int a[] ={ 240, 73,101,21,13,25,11,37,89,30,15,51};

for (int i = 0; i < 12; ++i) {
        root = add(root, a[i]);  // Chèn phần tử vào cây
        cout << "Cay sau khi them node la: " << a[i] << ": ";
        preOrder(root);  // In cây theo thứ tự Pre-order
        cout << endl;
    }
}


