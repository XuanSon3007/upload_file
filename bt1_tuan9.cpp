#include <iostream>

using namespace std;


//Cấu trúc Node tương ứng cho các file
struct Node{
    string name;//Tên file
    int size;// Kích thước file
    string creTime;//Thời gian tạo
    Node *next;//Con trỏ tới file tiếp
};

//Danh sách liên kết là 1 thư mục chứa các file
struct Folder{
    Node *first;
    Node *last;
};


//Hàm thêm file vào danh sách theo thứ tự thời gian

void addFile(Folder *f, const string &name, int size, const string &creTime){
    Node *newNode = new Node{name, size, creTime, nullptr};

    //Thêm vào đầu danh sách trống hoặc thời gian tạo file nhỏ nhất
    if(f->first == nullptr || f->first->creTime > creTime){
        newNode->next = f->first;
        f->first = newNode;
        if(f->last == nullptr) f->last = newNode;
        return;
    }
   
   //Duyệt danh sách để tìm vị trí chèn
   Node *current = f->first;//Khởi tạo con trỏ current trỏ đến đầu danh sách
   while( current->next != nullptr && current->next->creTime < creTime){// Duyệt toàn bộ danh sách và theo creTime tăng dần
    current = current->next;// tăng con trỏ current đến node kế tiếp
   }
   //Chèn newNode vào sau current
   newNode -> next = current -> next;
   current -> next = newNode;
   if(newNode -> next != nullptr) f->last = newNode; //Cập nhật last nếu chèn vào cuối danh sách
}


//Hàm tính tổng kích thước các file trong thư mục-danh sách liên kết
int calculateSize(Folder *f){
    int totalSize = 0;
    Node *current = f->first;
    while( current != nullptr){
        totalSize += current->size;
        current = current->next;
    }
    return totalSize;
}





// Hàm loại bỏ file
void removeFile(Folder *f, int maxSize = 32*1024){
    while(calculateSize(f)> maxSize){
        Node *minNode = f->first;
        Node *prev = nullptr;
        Node *current = f->first;
        Node *prevMin = nullptr;


    //Tìm file có kích thước nhỏ nhất
    while(current != nullptr){
        if(current->size< minNode->size){//Khi tìm thấy node có size nhỏ hơn minNode
            minNode = current;//Cập nhật minNode là node mới
            prevMin = prev;//Cập nhật node đứnng trước minNode trỏ đến prev - node đứng trước current trong danh sách
    }
    prev = current; // Cập nhật prev trỏ đến current sau môi lần kiểm tra
    current = current->next;
    }
      cout << " Xoa file: " << minNode->name << ", Size: " << minNode->size << endl;

      //Xóa file có kích thước nhỏ nhất
      if(prevMin == nullptr){
        //Nếu file nhỏ nhất là file đầu tiên
        f->first = minNode->next;
        if(f->first == nullptr) f->last = nullptr;
    } else{
        prevMin->next = minNode->next;
    }
    delete minNode;
    }
}



//Hàm di chuyển file sang USB 
void moveFileToUSB(Folder *f, Folder *USBList, int maxSize = 32*1024){
    int currentSize = 0;//Khởi tạo size =0
    Node *current = f->first;//Con trỏ current trỏ đến đầu danh sách folder

    while(current != nullptr){
        if(current->size <= maxSize - currentSize){// Khi kích thước file được xét chưa vượt quá size max, sẽ thêm file vào USBList
            addFile(USBList, current->name, current->size, current->creTime);
            currentSize +=current->size;//Tính kích thước sau mỗi lần thêm
            cout << " Them file: " << current->name << ", Size: " << current->size << endl;

    }
    current= current->next;// Di chuyển đến node kế tiếp
}

}

int main(){

    Folder folderList = {nullptr, nullptr};
    Folder USBList = {nullptr, nullptr};

    //Thêm các file vào danh sách folderList
    addFile(&folderList, "file1.txt", 1000, "2022-01-01 8:00:00");
    addFile(&folderList, "file2.txt", 8000, "2022-01-02 10:30:00");
    addFile(&folderList, "file3.txt", 12000, "2022-01-03 11:20:34");
    addFile(&folderList, "file4.txt", 15000, "2022-01-04 13:07:26");
    addFile(&folderList, "file5.txt", 500, "2022-01-05 20:11:33");

    //Tính tổng kích thước thư mục
    cout<<" Tong kich thuoc thu muc la: "<< calculateSize(&folderList)<< " KB"<<endl;

    //Loại bỏ các file có kích thước nhỏ để ko vượt quá giới hạn trước khi chuyển sang thư mục
    removeFile(&folderList, 32*1024);

    //Chuyển file sang USB với giới hạn kích thước
    moveFileToUSB(&folderList, &USBList);

    //In danh sách file trong USBList
    Node *current = USBList.first;
    cout<<" Danh sach file trong USB la: "<<endl;
    while(current!= nullptr){
        cout<< "File: "<< current->name<< ", Size: "<< current->size<< " KB, Create Time: "<< current->creTime<<endl;
        current = current->next;
    }
    return 0;
}