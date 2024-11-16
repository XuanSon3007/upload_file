#include <iostream>

using namespace std;

struct Node{
    int data;
    Node *next;
};

struct List{
    Node *first;
    Node *last;
};

//Khởi tạo danh sách rỗng
void init(List &list){
    list.first = NULL;
    list.last = NULL;
}

//Thêm node vào cuối danh sách
void addNode(List &list, int data){
    Node *newNode = new Node;
    newNode->data = data;
    newNode->next = NULL;
    if(list.first == nullptr) {
        list.first = list.last= newNode;
}else {
    list.last->next = newNode;
    list.last = newNode;
}
}


//Hiên thị danh sách
void display(List list){
    Node *current = list.first;
    while(current != nullptr){
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}


//Xóa node đầu danh sách
void deleteFirstNode(List *list){
    if(list->first == NULL) return;//Nếu danh sách rỗng ->return
    Node *temp = list->first;// Khởi tạo con trỏ temp trỏ tới node đầu
    list->first = list->first->next;//Cập nhật lại node đầu tiên danh sách 
    delete temp;//Xóa temp
}

//Xóa node cuối danh sách
void deleteLastNode(List *list){
    if(list->first == NULL) return;//Nếu danh sách trống ->return
    if(list->first->next == NULL){//Nếu danh sách chỉ có 1 node
        delete list->first;//Xóa node duy nhất đó
        //=>Danh sách rỗng
        list->first = NULL;
        list->last = NULL;
        return;
    }
    Node *current = list->first;//Khởi tạo con trỏ current trỏ đến node đầu tiên danh sách
    while(current->next!= list->last){//Cho con trỏ current chạy cho tới khi node tiếp theo của nó là node cuối
        current = current->next;
    }
    delete list->last;//Nếu node tiếp theo của current là node cuối thì xóa node cuối đó
    list->last = current;//Cập nhật node cuối là currrent
    list->last->next = NULL;
}

//Xóa 1 node trong 1 danh sách sau 1 node cho trước
void deleteAnotherNode(List *list, Node *T){
    if(list->first == NULL || T ==nullptr ) return;
     
     Node *current = list->first;//Con trỏ current trỏ đến node đầu tiên danh sách
     while(current->next!= T){//Khi node tiếp theo của current chưa phải là T
         current = current->next;//Tăng con trỏ current lên để duyệt   
     } 
     if(T->next == nullptr){//Nếu T là node cuối
        cout<< " T la node cuoi nen khong co node sau de xoa! "<<endl;
     } else{
        Node *temp = T->next;//Khởi tạo con trỏ tem là node sau T
        T->next = temp->next;
        if(temp= list->last) list->last=T;//Nếu node cần xóa là node cuối thì cập nhật T là node cuối
        delete temp;
     }
}

void resetList(List &list) {
    list.first = NULL;
    list.last = NULL;
    addNode(list, 1);
    addNode(list, 2);
    addNode(list, 3);
    addNode(list, 4);
    addNode(list, 5);
}

int main(){
    List list;
    init(list);
    

    addNode(list, 1);
    addNode(list, 2);
    addNode(list, 3);
    addNode(list, 4);
    addNode(list, 5);

    resetList(list);
    cout<<" Danh sach ban dau: ";
    display(list);

    //Xóa node đầu
    resetList(list);
    deleteFirstNode(&list);
    cout<<" Danh sach sau khi xoa node dau: ";
    display(list);

    //Xóa node cuối
    resetList(list);
    deleteLastNode(&list);
    cout<<" Danh sach sau khi xoa node cuoi: ";
    display(list);

    //Xóa node sau node T bất kì
    resetList(list);
    Node *T = list.first->next->next; // node thứ 3
    cout<<" Danh sach sau khi xoa node sau node T: ";
    deleteAnotherNode(&list, T);
    display(list);

    return 0;

}
