#include <iostream>
#include <string>

using namespace std;

struct File {
    string name;
    int size;
    string creTime;
    File *link;
};

struct Folder {
    File *first;
    File *last;
};

// Hàm thêm file vào cuối danh sách
void addFile(Folder *f, const string &name, int size, const string &creTime) {
    File *newFile = new File{name, size, creTime, nullptr};
    if (f->first == nullptr) {//nếu danh sách rỗng
        f->first = newFile;
        f->last = newFile;
    } else {//còn ko sẽ chèn file mới vào cuối danh sách
        f->last->link = newFile;
        f->last = newFile;
    }
}

// Hàm hiển thị danh sách các file trong folder
void displayFiles(Folder *f) {
    File *current = f->first;
    while (current != nullptr) {
        cout << "File: " << current->name << ", Size: " << current->size << ", Created Time: " << current->creTime << endl;
        current = current->link;
    }
}

//Hàm so sánh thời gian lưu trữ
bool compareCreTime(const string &time1, const string &time2){
    return time1 < time2;//Trả về file được tạo sớm hơn- thời gian lưu trữ lâu hơn
}


// Hàm sắp xếp các file theo thứ tự tăng dần về dung lượng(Ưu tiên file có thời gian lưu trữ lâu hơn xếp trước nếu 2 file có cùng dung lượng)
void sortFile(Folder *f) {
    if (f->first == nullptr) return;

    bool swapped;
    do {
        swapped = false;
        File *current = f->first;//khởi tạo con trỏ current trỏ đến đâu danh sách
        

        while (current != nullptr && current->link != nullptr) {
     //Nếu kích thước file hiện tại > minFile hoặc kích thước 2 file bằng nhau nhưng file hiên tại đc tạo trước thì hoán đổi 2 file       
    if (current->size > current->link->size ||current->size == current->link->size && compareCreTime(current->link->creTime, current->creTime)) {
                // Hoán đổi kích thước file
                int tempSize = current->size;
                string tempName = current->name;
                string tempCreTime = current->creTime;
             
             // Cập nhật data cho file hiện tại
                current->size = current->link->size;
                current->name = current->link->name;
                current->creTime = current->link->creTime;
            
            //Cập nhật data cho file kế tiếp file hiện tại
                current->link->size = tempSize;
                current->link->name = tempName;
                current->link->creTime = tempCreTime;

                swapped = true;
            }
           
            current = current->link;
        }
    } while (swapped);// lặp lại vòng lặp cho tới lúc ko còn file nào để hoán đổi nữa
}

// Hàm xóa file có kích thước nhỏ nhất
void deleteFile(Folder *f) {
    if (f->first == nullptr) return; // Nếu thư mục trống

    File *current = f->first;
    File *prev = nullptr;
    File *minFile = f->first;
    File *prevMinFile = nullptr;

    // Tìm file có kích thước nhỏ nhất và thời gian lưu lâu nhất(ưu tiên xóa trước)
    while (current != nullptr) {
  // Nếu file hiện tại có kích thước nhỏ hơn hoặc 2 file có kt bằng nhau nhưng file htai có thời gian tạo lâu hơn      
        if (current->size < minFile->size || current->size == minFile->size && compareCreTime(current->creTime, minFile->creTime)) {
            minFile = current;// cập nhật minFile = file hiện tại
            prevMinFile = prev;// cập nhật con trỏ prevminFile đến con trỏ prev
        }
        prev = current;
        current = current->link;
    }

    cout << "Xoa file: " << minFile->name << ", Size: " << minFile->size << " CreTime: "<< minFile->creTime<< endl;

    // Xóa file tìm được
    if (prevMinFile == nullptr) {//File cần xóa là file đầu tiên
        f->first = minFile->link;
        if (f->first == nullptr) f->last = nullptr;
    } else {
        prevMinFile->link = minFile->link;
        if (minFile == f->last) f->last = prevMinFile;//Nếu file cần xóa là file cuối thì cập nhật file cuối là file trc minFile
    }
    delete minFile;
}

int main() {
    Folder folder = {nullptr, nullptr};

    // Thêm các file vào thư mục
    addFile(&folder, "file1.txt", 100, "2024-11-01");
    addFile(&folder, "file2.txt", 200, "2024-12-02");
    addFile(&folder, "file3.txt", 50, "2024-12-24");
    addFile(&folder, "file4.txt", 50, "2024-10-18");

    cout << " Cac file la:" << endl;
    displayFiles(&folder);

    // Sắp xếp file theo kích thước tăng dần
    sortFile(&folder);
    cout << "\nFile sau khi duoc sap xep la:" << endl;
    displayFiles(&folder);

    // Xóa file có kích thước nhỏ nhất
    deleteFile(&folder);
    cout << "\nFile sau khi xoa la:" << endl;
    displayFiles(&folder);

    return 0;
}
