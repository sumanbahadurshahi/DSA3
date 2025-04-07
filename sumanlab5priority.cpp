#include <iostream>
using namespace std;

class PriorityQueue {
private:
    int front;
    int rear;
    int arr[7];
    int priority[7]; // To store priority values
public:
    PriorityQueue() {
        front = -1;
        rear = -1;
        for (int i = 0; i < 7; i++) {
            arr[i] = 0;
            priority[i] = -1;
        }
    }

    bool isEmpty() {
        return front == -1;
    }

    bool isFull() {
        return rear == 6;
    }

    void Enqueue(int val, int prio) {
        if (isFull()) {
            cout << "The queue is full" << endl;
            return;
        }

        if (isEmpty()) {
            front = rear = 0;
            arr[rear] = val;
            priority[rear] = prio;
        } else {
            int i;
            for (i = rear; i >= front && priority[i] > prio; i--) {
                arr[i + 1] = arr[i];
                priority[i + 1] = priority[i];
            }
            arr[i + 1] = val;
            priority[i + 1] = prio;
            rear++;
        }
    }

    void Dequeue() {
        if (isEmpty()) {
            cout << "The Queue is empty" << endl;
        } else {
            cout << "Dequeued value: " << arr[front] << " with priority: " << priority[front] << endl;
            arr[front] = 0;
            priority[front] = -1;
            if (front == rear) {
                front = rear = -1; // Reset the queue
            } else {
                front++;
            }
        }
    }

    void Traverse() {
        if (isEmpty()) {
            cout << "The Queue is empty" << endl;
        } else {
            cout << "All values in the Priority Queue are: ";
            for (int i = front; i <= rear; i++) {
                cout << "(" << arr[i] << ", P: " << priority[i] << ") ";
            }
            cout << endl;
        }
    }
};

int main() {
    PriorityQueue pq;
    int option, value, prio;

    do {
        cout << "Enter your options:" << endl;
        cout << "1. Enqueue operation" << endl;
        cout << "2. isFull operation" << endl;
        cout << "3. isEmpty operation" << endl;
        cout << "4. Dequeue operation" << endl;
        cout << "5. Traverse operation" << endl;
        cout << "6. Stop" << endl;
        cin >> option;

        switch (option) {
            case 1:
                cout << "Enter the value and priority you want to enqueue:" << endl;
                cin >> value >> prio;
                pq.Enqueue(value, prio);
                break;

            case 2:
                cout << (pq.isFull() ? "Queue is full" : "Queue is not full") << endl;
                break;

            case 3:
                cout << (pq.isEmpty() ? "Queue is empty" : "Queue is not empty") << endl;
                break;

            case 4:
                pq.Dequeue();
                break;

            case 5:
                pq.Traverse();
                break;

            case 6:
                cout << "Exiting program..." << endl;
                break;

            default:
                cout << "Enter a valid option!" << endl;
                break;
        }
    } while (option != 6);

    return 0;
}

