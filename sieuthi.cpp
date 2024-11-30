#include <iostream>
#include <string>

using namespace std;

struct Node{
    string date;
    string tenSanPham;
    int soLuong;
    int donGia;
    Node *next;
};

struct Queue{
    Node* front;
    Node *rear;
    int totalMoney;//Tổng tiền thu được tại quầy thu ngân
};


//Hàm khởi tạo hàng đợi
void Queue_init( Queue* queue){   
    queue->front = nullptr;
    queue->rear = nullptr;
    queue->totalMoney = 0;
}

//Hàm kiểm tra hàng đợi rỗng
bool isEmptyQueue(Queue* queue){
    return (queue->front == nullptr);
}

//Hàm thêm phần tử vào cuối hàng đợi

void enqueue(Queue* queue, Node value){
    Node* newNode = new Node();
    newNode->date = value.date;
    newNode->tenSanPham = value.tenSanPham;
    newNode->soLuong = value.soLuong;
    newNode->donGia = value.donGia;

    if(isEmptyQueue(queue)){
        queue->front = newNode;
        queue->rear = newNode;
    }else{
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

//Hàm xóa phần từ khỏi hàng đợi sau khi đã thanh toán xong
void dequeue(Queue* queue, const string&productName, int &count){
    if(isEmptyQueue(queue)){
        cout<<" Hang doi rong!"<<endl;
        return;
    }else{
        Node* temp = queue->front;
        int thanhTien = temp->soLuong * temp->donGia;
        queue->totalMoney += thanhTien;//Cộng tiền thanh toán vào tổng
        cout<< " Thanh toan: Ngay: "<<temp->date<< ", Ten san pham: "<< temp->tenSanPham<< ", So luong: "<< temp->soLuong<< ", Don gia :"<<temp->donGia<< ", Thanh tien: "<< thanhTien<<endl;

    //Kiểm tra nếu là sản phẩm cần tìm
    if(temp->tenSanPham == productName){
       count += temp->soLuong;
    }
        queue->front= queue->front->next;
        delete temp;
    }
} 


//Hàm giải phóng hàng đợi
void deleteQueue(Queue* queue){
    Node* temp = queue->front;
    while(temp!= nullptr){
        Node* next = temp->next;
        delete temp;
        temp = next;
    }
    queue->front = nullptr;
    queue->rear = nullptr;
    queue->totalMoney = 0;
} 


//In danh sách sản phẩm
void display(Queue *queue){
    Node* temp = queue->front;
    while(temp!= nullptr){
        cout<<"Ngay: "<<temp->date<<", Ten san pham: "<<temp->tenSanPham<<", So luong: "<<temp->soLuong<<", Don gia: "<<temp->donGia<<endl;
        temp = temp->next;
    }
    cout<<endl;
}


//Hàm tính số lượng  sản phẩm A đã bán
   int countProduct(Queue *queue, const string& productName){
    int count = 0;
    Node *temp = queue->front;
    while(temp != nullptr) {
        if(temp->tenSanPham == productName){
            count += temp->soLuong;
        }
        temp = temp->next;
   }
   return count;
   }

int main(){
    Queue* queue = new Queue();
    Queue_init(queue);

    //Thêm node vào hàng đợi
    enqueue(queue, {"29/11/2024", "rau_cai", 2, 20000});
    enqueue(queue, {"30/11/2024", "chanh", 1, 15000});
    enqueue(queue, {"01/12/2024", "ca", 3, 50000});
    enqueue(queue, {"02/12/2024", "thit", 2, 40000});
    display(queue);

    //Loại bỏ từng người sau khi thanh toán
    cout<<" Xu li thanh toan:"<<endl;
    int count =0;
    string productName ="thit";
    while(!isEmptyQueue(queue)){
        dequeue(queue, productName, count);
    }

    //Tính tổng doanh thu
    cout<<" Tong doanh thu la: "<< queue->totalMoney<<endl;

    //Tìm số lượng sản phẩm A đã bán
   
    cout<< " So luong san pham "<< productName<<" da ban: "<<count<<endl;

    //Giải phóng bộ nhớ
    deleteQueue(queue);
    delete queue;
    

    return 0;
}

