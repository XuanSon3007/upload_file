#include <iostream>

using namespace std;

struct SinhVien{
    char maSV[8];
    char hoTen[50];
    int gioiTinh;
    Ngay ngaySinh;
    char diaChi[100];
    char lop[12];
    char khoa[7];
};

struct Ngay{
    int ngay, thang, nam;
};

struct Node{
    SinhVien data;
    Node *link;
};

// Tạo danh sách ListSV
struct ListSV{
    Node *first;
    Node *last;
};

//Khởi tạo danh sách rỗng

void ListSV_init(struct ListSV *list){
    list->first = list->last = NULL;
}

//Hàm so sánh mã sinh viên 
bool comparemaSV(const char *ma1, const char *ma2){
    int i=0;
     while (ma1[i] != '\0' && ma2[i] != '\0') {
        if (ma1[i] < ma2[i]) return true;
        if (ma1[i] > ma2[i]) return false;
        i++;
    }
    // Kiểm tra độ dài chuỗi
    if (ma1[i] == '\0' && ma2[i] != '\0') return true;
    return false;
}
// Hàm thêm 1 sinh viên mới vào danh sách ListSV
void ListSV_add(ListSV *list, SinhVien *sv){
    Node *newNode = new Node;
    newNode->data = *sv;
    newNode->link = NULL;
//Nếu danh sách rỗng, thêm Node vào đầu
    if(list->first ==NULL){
        list->first = newNode;
        list->last = newNode;
        return;
    } 
    //Nếu mã sinh viên mới nhỏ hơn mã sinh viên đầu tiên
    if(comparemaSV(sv->maSV, list->first->data.maSV)){
       newNode->link= list->first;
       list->first= newNode;
       return;
    }
     // Tìm vị trí chèn phù hợp
    Node *prev = list->first;
    Node *current = list->first->link;
    while (current != NULL && !comparemaSV(sv->maSV, current->data.maSV)) {
        prev = current;
        current = current->link;
    }

    // Chèn node mới vào danh sách
    newNode->link = current;
    prev->link = newNode;

    // Nếu chèn vào cuối, cập nhật last
    if (newNode->link == NULL) {
        list->last = newNode;
    }
}


// Hàm in danh sách sinh viên
void ListSV_out(const ListSV *list) {
    Node *p = list->first;
    while (p != NULL) {
        cout << "Ma SV: " << p->data.maSV << ", Ho Ten: " << p->data.hoTen << endl;
        p = p->link;
    }
}

//Hàm kiểm tra 2 sinh viên có cùng ngày sinh hay không
bool sameNgay(const Ngay &d1, const Ngay &d2){
    return (d1.ngay == d2.ngay ) && (d1.thang == d2.thang) && (d1.nam == d2.nam);
}

//Hàm in ra các sinh viên có cùng ngày sinh , nếu không in ra thông báo "Không có sinh viên sinh cùng ngày

void ListSV_sameNgay(ListSV *list){
    Node *p = list->first;
    while (p != NULL) {
        Node *q = p->link;
        bool same = false;
        while (q != NULL) {
            if (sameNgay(p->data.ngaySinh, q->data.ngaySinh)) {
                cout << "Ma SV: " << p->data.maSV << ", Ho Ten: " << p->data.hoTen << ", Ngay sinh: " << p->data.ngaySinh.ngay << "/" << p->data.ngaySinh.thang << "/" << p->data.ngaySinh.nam << endl;
                cout << "Ma SV: " << q->data.maSV << ", Ho Ten: " << q->data.hoTen << ", Ngay sinh: " << q->data.ngaySinh.ngay << "/" << q->data.ngaySinh.thang <<
}