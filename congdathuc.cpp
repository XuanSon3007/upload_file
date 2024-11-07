#include <iostream>
 
 using namespace std;

 struct Node{
    double heso;
    int somu;
    Node *link;
 };

 struct ListDT{
    Node *first, *last;
 };

 //Khởi tạo danh sách đa thức
 void init(ListDT * list){
    list->first= list->last=NULL;
 }

 //Tạo node mới
 Node *createNode(double heso, int somu){
     Node *p;
     p= new Node ;
     if(p ==NULL) return NULL;
     p->heso = heso;
     p->somu = somu;
     p->link = NULL;//p là node cuối danh sách
     return p;
 }

 //Gán node p vào danh sách
 void addNode(ListDT *list, Node *p){
    if( list->first==NULL){ //list rỗng
      list->first=list->last=p;// node đầu = node cuối =p
  } else {
    list->last->link=p; //gán địa chỉ node cuối là p

    list->last=p;//cập nhật p là node cuối
  }
 }

 //Thêm node với hệ số và số mũ cho trước
 void attachNode(ListDT *list, double heso, int somu){
    Node *p = createNode(heso, somu);
    if(p==NULL) return;
    addNode(list, p);
 }

 //Tạo đa thức
 void createDT(ListDT *list){
    double heso;
    int somu;
    Node *tempNode = createNode(0,0);
    int i=0;// đếm số hạng tử trong 1 đa thức
    while(true){
        i++;
        cout<<"Nhap phan tu thu "<<i <<endl;
        cout<<" He so: ";
        cin >>heso;
        if(heso == 0){
            delete tempNode;
            cout<<" Ket thuc nhap da thuc.\n ";
            break;
        }
        cout<<"So mu: ";
        cin >> somu;

        //Cập nhật giá trị của tempNode để thêm vào danh sách
        tempNode->heso = heso;
        tempNode->somu = somu;
        tempNode->link= NULL;

        //Thêm node vào danh sách và cấp phát lại tempNode
        addNode(list, tempNode);
        cout << "Them node dia chi: " << tempNode << ", heso: " << heso << ", somu: " << somu << endl;

        tempNode = createNode(0, 0); // tạo tempNode mới cho lần nhập tiếp theo

    }
    
 }

void inDT(ListDT list) {
    Node* p;
    p = list.first;
    
    while (p != NULL ) {
        if(p->somu ==0){
            cout<<p->heso;
        }else{
        cout << p->heso << " * x^" << p->somu;}
        if (p->link != NULL && p->heso!= 0) cout << " + ";
        p = p->link;
    }
}
// Hàm cộng hai đa thức
ListDT congDaThuc(ListDT list1, ListDT list2) {
    ListDT ketQua;// Tạo list kết quả
    init(&ketQua);//khởi tạo kết quả
    Node* p1 = list1.first;// Khởi tạo node p1 là node đầu tiên của danh sách list1

    Node* p2 = list2.first;// Khởi tạo node p2 là node đầu tiên của danh sách list2

    while (p1 != NULL && p2 != NULL) {// Khi node p1 và p2 khác NULL
        if (p1->somu > p2->somu) {// Nếu số mũ p1 lớn hơn số mũ p2
            attachNode(&ketQua, p1->heso, p1->somu);// Thêm hệ số và số mũ của p1 và danh sách list Kết quả
            p1 = p1->link;// trỏ đến node tiếp theo của list1
        }
        else if (p1->somu < p2->somu) {// Ngược lại cái trên
            attachNode(&ketQua, p2->heso, p2->somu);
            p2 = p2->link;
        }
        else {// số mũ p1= số mũ p2
            double tongHeSo = p1->heso + p2->heso;
            if (tongHeSo != 0) {
                attachNode(&ketQua, tongHeSo, p1->somu);
            }
            p1 = p1->link;
            p2 = p2->link;
        }
    }
// Điền tiếp các node khi 1 danh sách đã kết thúc mà danh sách còn lại vẫn còn
    while (p1 != NULL) {
        attachNode(&ketQua, p1->heso, p1->somu);
        p1 = p1->link;
    }

    while (p2 != NULL) {
        attachNode(&ketQua, p2->heso, p2->somu);
        p2 = p2->link;
    }

    return ketQua;
}


int main(){
    ListDT list1, list2;
    cout<<"Nhap f(x):\n";
    init(&list1);
    createDT(&list1);
    inDT(list1);

    cout<<"\nNhap g(x):\n ";
    init(&list2);
    createDT(&list2);
    inDT(list2);

    
    cout<<"\nDa thuc tong cua f(x) va g(x) la: ";
    ListDT tong = congDaThuc(list1, list2);  
    inDT(tong);
    cout<<endl;
    return 0;
 
}

 