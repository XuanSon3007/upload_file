#include <iostream>

using namespace std;

#define Max 100  //Số phần tử tối đa của Stack
struct Stack{
    int top;
    int data[Max];
};

//Khởi tạo ngăn xếp
void init(Stack *S){
    S->top = 0;
}

//Kiểm tra ngăn xếp rỗng
int issEmpty(Stack S){
    return (S.top == 0);
}

//Kiểm tra ngăn xếp đầy
int issFull(Stack S){
    return (S.top == Max -1 );
}

//Hàm push thêm phần tử x vào đỉnh ngăn xếp
void push(Stack &S, int x){
    if(issFull(S))
        cout << " Danh sach day! " << endl;
    else{
        S.top++;
        S.data[S.top] = x;
    }
}

//Hàm pop xóa phần tử ở định ra khỏi ngăn xếp
int pop(Stack&S){
    if(issEmpty(S))
        cout<<" Ngan xep rong! ";
    else{
        int x = S.data[S.top];
        S.top--;
        return x;
    }
}

//Hàm nhập ngăn xếp
void input(Stack &S){
    cout<<" Nhap gia tri cho stack: "<< endl;
    int x;
    do{
        cin>>x;
        if(x !=0){
            push(S,x);
        }
    }while(x !=0);
}

//Hàm xuất ngăn xếp
void output(Stack S){
    while(S.top !=0){
        cout<< " "<< pop(S);
    }
}

int main(){
    Stack S;
    init(&S);
    input(S);
    cout<<" Stack vua nhap la: ";
    output(S);
    return 0;
}