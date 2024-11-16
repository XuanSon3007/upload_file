#include <iostream>
#include <string>

using namespace std;




// Tạo node là mỗi từ trong 1 câu
struct Node{
    string data;
    Node *next;
};

//Tạo danh sách là 1 câu Tiếng việt
struct List{
    Node *first;
    Node *last;
};

// Hàm so sánh 2 node có giống nhau không
bool compareNodes(Node* node1, Node* node2){
    return node1->data == node2->data;
}



// Hàm xác định từ xuất hiện nhiều nhất trong câu
    Node* findMostFrequentWord(List list){
        if(list.first == nullptr) return nullptr;//Kiểm tra danh sách trống

    Node* maxNode = nullptr;// Tạo node maxNode là con trỏ rác
    int maxCount = 0;// Khởi tạo giá trị maxCount = 0

    Node* current = list.first;// Con trỏ current trỏ đến node đầu tiên của danh sách
    while(current!= nullptr){// Khởi tạo vòng lặp
        int count = 1;// Khởi tạo biến đếm = 1
        Node* temp = current->next;// Con trỏ temp trỏ đến node tiếp theo của current

        while(temp!= nullptr){// Vòng lặp con
            if(compareNodes(current, temp)){//Nếu như current giống với temp
                count++;// Tăng count lên 1
                
            }
            temp = temp->next;// Duyệt temp tới node tiếp theo
           
        }

        if(count > maxCount){
            maxCount = count;
            maxNode = current;
        }

        current = current->next;
    }
    return maxNode;
}


// Hàm xóa node nếu xuất hiện giống nhau- xuất hiện từ láy-> loại bỏ 1 từ

void removeNode(List *list){
    if(list->first == nullptr) return;// Kiểm tra danh sách trống
    
    Node *current = list->first;// Khởi tạo con trỏ current trỏ đến node đầu tiên danh sách
    while( current != NULL ){// Duyệt tất cả các node trong danh sách
        Node *prev = current;// Con trỏ prev bắt đầu từ current
        Node *temp = current->next;//Con trỏ temp trỏ đến node tiếp theo của current
        while( temp != NULL){//Duyệt tất cả các node sau current
            if(compareNodes( current, temp)){
               prev->next = temp->next;//Bỏ qua temp và nối prev với node liền sau temp
               delete temp;//Xóa temp, giải phóng bộ nhớ
               temp = prev->next;//cập nhật temp mới
            } else{
                //Nếu không trùng, di chuyển prev và temp lên
                prev = temp;
                temp = temp->next;
            }
        }
        current = current->next;
}
}


//Hàm đếm số node xuất hiện trong List- Đếm số từ xuất hiện trong câu
int countNode(List *list){
    int count = 0;
    Node *current = list->first;
    while(current!= nullptr){
        count++;
        current = current->next;
    }
    return count;
}

//Hàm thêm từ vào danh sách
    void addWord(List *list, const string &word){
        Node *newNode = new Node();
        newNode->data = word;
        newNode->next = nullptr;

        if(list->first ==nullptr){
            list->first = newNode;
            list->last = newNode;
        } else{
            list->last->next = newNode;
            list->last = newNode;
        }
    }

 // Hàm in danh sách từ ra màn hình
    void printList(List *list){
        Node *current = list->first;
        while(current!= nullptr){
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }   

int main(){

    List list;
    list.first = nullptr;
    list.last = nullptr;

   

    cout<<" Nhap cau: ";
    string input;
    getline(cin, input);//Đọc câu

    string word = "";
    for(char ch:input){
        if(ch == ' '){
            if(!word.empty()){
                addWord(&list, word);//Thêm từ vào danh sách
                word = "";//reset word để bắt đầu từ mới
            }
        } else{
            word += ch;// Thêm ký tự vào từ hiện tại
        }
    }

    //Thêm từ cuối cùng nếu có
    if(!word.empty()){
        addWord(&list, word);
    }


    cout<<" Danh sach tu ban dau la: ";
    printList(&list);


    //Xác định từ xuất hiện nhiều nhất
    Node* mostFrequentWordNode = findMostFrequentWord(list);
    if(mostFrequentWordNode){
    cout<<"Tu xuat hien nhieu nhat la: "<<mostFrequentWordNode->data<<endl;
    } else{
        cout<<" Danh sach rong "<<endl;
    }

    //Loại bỏ từ trùng lặp
    removeNode(&list);
    cout<<" Danh sach sau khi loai bo tu trung lap la: ";
    printList(&list);

    //Đếm số từ xuất hiện trong câu
    int count = countNode(&list);
    cout<<"So tu xuat hien trong cau la: "<<count<<endl;

    return 0;

}

