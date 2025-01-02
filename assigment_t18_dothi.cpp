#include <iostream>
using namespace std;

const int MAX = 8; // Số đỉnh tối đa

// Ma trận kề
int graph[MAX][MAX] = {
    {0, 1, 0, 1, 1, 0, 1},
    {0, 0, 1, 1, 0, 1, 0},
    {0, 1, 0, 1, 0, 1, 1},
    {1, 0, 1, 0, 0, 1, 1},
    {0, 1, 0, 1, 0, 1, 1},
    {1, 1, 1, 0, 1, 0, 1},
    {0, 0, 0, 0, 1, 0, 0}
};

// Tự cài đặt hàng đợi (queue)
struct Queue {
    int items[MAX];
    int front, rear;

    Queue() : front(0), rear(0) {}

    bool isEmpty() {
        return front == rear;
    }

    void enqueue(int value) {
        items[rear++] = value;
    }

    int dequeue() {
        return items[front++];
    }
};

// Tự cài đặt ngăn xếp (stack)
struct Stack {
    int items[MAX];
    int top;

    Stack() : top(-1) {}

    bool isEmpty() {
        return top == -1;
    }

    void push(int value) {
        items[++top] = value;
    }

    int pop() {
        return items[top--];
    }
};

// Duyệt BFS
void BFS(int start) {
    bool visited[MAX] = {false};
    Queue q;

    q.enqueue(start);
    visited[start] = true;

    cout << "BFS Order: ";
    while (!q.isEmpty()) {
        int v = q.dequeue();
        cout << char('a' + v) << " ";

        for (int i = 0; i < MAX; i++) {
            if (graph[v][i] == 1 && !visited[i]) {
                q.enqueue(i);
                visited[i] = true;
            }
        }
    }
    cout << endl;
}

// Duyệt DFS
void DFS(int start) {
    bool visited[MAX] = {false};
    Stack s;

    s.push(start);

    cout << "DFS Order: ";
    while (!s.isEmpty()) {
        int v = s.pop();

        if (!visited[v]) {
            visited[v] = true;
            cout << char('a' + v) << " ";

            // Duyệt các đỉnh kề từ cuối về đầu
            for (int i = MAX - 1; i >= 0; i--) {
                if (graph[v][i] == 1 && !visited[i]) {
                    s.push(i);
                }
            }
        }
    }
    cout << endl;
}

int main() {
    int start;
    cout << "Nhap dinh bat dau (0 - 6, tuong ung a - h): ";
    cin >> start;

    BFS(start);
    DFS(start);

    return 0;
}
