#include <iostream>


using namespace std;

struct Node{
    int index;
    Node *next;
};

Node *taovong(int n){
    Node *head= new Node;// tạo node head là 1 node mới
    head->index=1;// gán giá trị vị trị cho node head là 1
    Node *prev=head;// tạo con trỏ prev trỏ đến node head

    for(int i=2;i<=n;i++){
        Node *newNode = new Node;//Tạo node newNode
        newNode->index=i;//newNode trỏ đến phần tử thứ i
        prev->next=newNode;
        prev=newNode;
    }
    prev->next=head;//Tạo vòng tròn
    return head;
}

int josephus(int n, int m){
    Node *head= taovong(n);
    Node *current= head;

    //Lặp đến khi chỉ còn 1 người
    while(current->next != current){
        //Đếm tới người thứ m
        for(int count=1; count <m-1; count++){
            current=current->next;
        }
        //Xóa người thứ m
        Node *temp=current->next;
        cout << "Loai bo: " << temp->index << endl;  // In ra người bị loạ
        current->next=temp->next;
        delete temp;

        //Chuyển tiếp đến người tiếp theo liền kề người bị loại
        current=current->next;
    }
    int nguoi_thang= current->index;
    delete current;//xóa ô nhớ
    return nguoi_thang;
}

int main(){
    int n, m;
    cout << " Nhap so nguoi: ";
    cin >> n;
    cout << " Nhap buoc dem: ";
    cin >>m;
    
    int nguoi_thang=josephus(n, m);
    cout << " Nguoi chien thang la: "<< nguoi_thang<< endl;
    return 0;
}

