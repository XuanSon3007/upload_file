#include <iostream>
#include <cstring>


using namespace std;

// Cấu trúc Node
struct Node{
    char chapter[100];// tên chương
    int page; // số trang
    Node *sub[20]; // danh sách các mục con
    int sub_count; // số mục con

    //Hàm khởi tạo Node
    Node(const char* c, int p){
        strcpy(chapter, c);
        page = p;
        sub_count = 0;
        for(int i = 0; i < 10; i++){
            sub[i] = nullptr;
    }
    }
};

//Định nghĩa cấu trúc của cây

struct Tree{
    Node *root;

    //Hàm khởi tạo cây
    Tree(){
        root = new Node("DSABook", 0); // khởi tạo node gốc với tên sách là DSA và trang 0
    }

    // Đếm số chương của sách
    int countChapters(){
        return root->sub_count;
}
    //Tìm chương dài nhất
    Node *findLongestChapter(){
        if(root->sub_count==0) return nullptr;

        Node *longest = root->sub[0];
        for(int i=0; i< root->sub_count; i++){
            if(root->sub[i]->page > longest->page){
                longest = root->sub[i];
        }
    }
    return longest;
    }

    // Tìm và xóa 1 mục ra khỏi cây
    bool deleteNode(Node *parent, const char* delNode){
        for(int i = 0 ; i< parent->sub_count; i++){
            if(strcmp(parent->sub[i]->chapter, delNode)==0){
                //thực hiện xóa node
                delete parent->sub[i];
                //Cập nhật lại các mục còn lại
                for(int j =i; j<parent->sub_count-1; j++){
                    parent->sub[j] = parent->sub[j+1];
            }
            parent->sub_count--;
            return true;
        }
        // Tìm trong các mục con
        if(deleteNode(parent->sub[i], delNode)){
            return true;
        }
    }
    return false;
    }

    //Xóa mục đó ra khỏi cây
    void deleteNode(const char *delNode){
        if(!deleteNode(root, delNode)){
            cout<<" Node da xoa! ";
    }
    }

    //Hàm thêm các chương vào sách
    void addChapter(Node *parent, const char* chapter, int page){
      if(parent->sub_count<20){
        parent->sub[parent->sub_count] = new Node(chapter, page);
        parent->sub_count++;
      } else{
        cout<<"Sach da day chuong ! ";
      }
}
};

int main(){

    Tree DSABook;


    //Thêm các chương vào sách
    DSABook.addChapter(DSABook.root, "Chapter 1", 10);
    DSABook.addChapter(DSABook.root, "Chapter 2", 20);
    DSABook.addChapter(DSABook.root, "Chapter 3", 30);
    DSABook.addChapter(DSABook.root, "Chapter 4", 40);
    DSABook.addChapter(DSABook.root, "Chapter 5", 50);
    DSABook.addChapter(DSABook.root, "Chapter 6", 60);
    DSABook.addChapter(DSABook.root, "Chapter 7", 70);
    DSABook.addChapter(DSABook.root, "Chapter 8", 80);

    //Thêm các mục con vào chapter 1
    DSABook.addChapter(DSABook.root->sub[0], "ARRAY", 11);
    DSABook.addChapter(DSABook.root->sub[0], "LinkList", 12);
    DSABook.addChapter(DSABook.root->sub[0], "Stack", 13);

    //Xác định số chương của sách
    int countChapter = DSABook.countChapters();
    cout<<"So chuong cua sach: "<<countChapter<<endl;


    //Tìm chương dài nhất
    Node *longestChapter = DSABook.findLongestChapter();
    if(longestChapter!= nullptr){
        cout<<"Chuong dai nhat: "<<longestChapter->chapter<<" co "<<longestChapter->page<< " trang "<<endl;
    } else{
        cout<<"Khong tim thay chuong nao dai nhat!"<<endl;
    }

    //Xóa 1 mục 
    DSABook.deleteNode("Chapter 3");

    //Đếm lại số chương
    cout<< "So chuong sau khi xoa la: "<< DSABook.countChapters()<<endl;

}





