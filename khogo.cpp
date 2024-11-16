#include <iostream>
#include <string>

using namespace std;

// Định nghĩa cấu trúc cho một loại gỗ
struct Wood {
    string type;  // Loại gỗ
    int size;     // Kích thước gỗ
    int age;      // Tuổi của gỗ
    Wood *next;   // Con trỏ đến loại gỗ tiếp theo trong stack
};

// Định nghĩa cấu trúc kho chứa gỗ theo kiểu stack
struct Kho {
    Wood *top;  // Con trỏ đến loại gỗ trên cùng của stack
};

// Khởi tạo kho rỗng
void init(Kho &kho) {
    kho.top = nullptr;
}

// Kiểm tra kho có rỗng không
bool isEmpty(Kho kho) {
    return kho.top == nullptr;
}

// Hàm push thêm một loại gỗ vào kho
void push(Kho &kho, string type, int size, int age) {
    Wood *newWood = new Wood;
    newWood->type = type;
    newWood->size = size;
    newWood->age = age;
    newWood->next = kho.top;
    kho.top = newWood;
    
}

// Hàm pop lấy một loại gỗ ra khỏi kho
void pop(Kho &kho) {
    if (isEmpty(kho)) {
        cout << "Kho rong" << endl;
    } else {
        Wood *temp = kho.top;
        kho.top = kho.top->next;
        delete temp;
    }
}

// Hàm hiển thị các loại gỗ trong kho
void display(Kho kho) {
    if (isEmpty(kho)) {
        cout << "Kho rong." << endl;
    } else {
        Wood *current = kho.top;
        while (current != nullptr) {
            cout << "Loai go: " << current->type << ", size: " << current->size << ", age: " << current->age << endl;
            current = current->next;
        }
    }
}

// Hàm đếm số lượng thanh gỗ có cùng tuổi gỗ
int countWoodByAge(Kho kho, int age) {
    int count = 0;
    Wood *current = kho.top;
    while (current != nullptr) {
        if (current->age == age) {
            count++;
        }
        current = current->next;
    }
    return count;
}

int main() {
    Kho kho;
    init(kho);

    // Thêm một số loại gỗ vào kho
    push(kho, "Lim", 5, 10);
    push(kho, "Xoan", 3, 7);
    push(kho, "Trắc", 8, 10);
    push(kho, "Keo", 6, 7);

    display(kho);

    // Đếm số lượng thanh gỗ có tuổi là 7
    int ageToCount = 7;
    int count = countWoodByAge(kho, ageToCount);
    cout << "So luong thanh go co tuoi  " << ageToCount << ": " << count << endl;

    
    pop(kho);

   
    display(kho);

    return 0;
}
