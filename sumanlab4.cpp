#include<iostream>
using namespace std;

class Queue{
    private:
        int front;
        int rear;
        int arr[7];
    public:
        Queue(){
            front = -1;
            rear = -1;
            for(int i = 0; i < 7; i++){
                arr[i] = 0;
            }
        }

        bool isEmpty(){
            return front == -1;
        }

        bool isFull(){
            return rear == 6;
        }

        void Enqueue(int val){
            if(isFull()){
                cout << "The queue is full" << endl;
            }
            else if(isEmpty()){
                front = 0;
                rear = 0;
                arr[rear] = val;
            }
            else{
                rear++;
                arr[rear] = val;
            }
        }

        void Dequeue(){
            if(isEmpty()){
                cout << "The Queue is empty" << endl;
            }
            else{
                cout << "Dequeued value: " << arr[front] << endl;
                arr[front] = 0;
                if(front == rear){
                    front = rear = -1; // Reset the queue when it's empty
                }
                else{
                    front++;
                }
            }
        }

        void Transvers(){
            if(isEmpty()){
                cout << "The Queue is empty" << endl;
            }
            else{
                cout << "All values in the Queue are: ";
                for(int i = front; i <= rear; i++){
                    cout << arr[i] << " ";
                }
                cout << endl;
            }
        }
};

int main(){
    Queue q1;
    int option, value;

    do{
        cout << "Enter your options:" << endl;
        cout << "1. Enqueue operation" << endl;
        cout << "2. isFull operation" << endl;
        cout << "3. isEmpty operation" << endl;
        cout << "4. Dequeue operation" << endl;
        cout << "5. Transverse operation" << endl;
        cout << "6. Stop" << endl;
        cin >> option;

        switch(option){
            case 1:
                cout << "Enter the value you want to enqueue:" << endl;
                cin >> value;
                q1.Enqueue(value);
                break;

            case 2:
                if(q1.isFull()){
                    cout << "Queue is full" << endl;
                }
                else{
                    cout << "Queue is not full" << endl;
                }
                break;

            case 3:
                if(q1.isEmpty()){
                    cout << "Queue is empty" << endl;
                }
                else{
                    cout << "Queue is not empty" << endl;
                }
                break;

            case 4:
                q1.Dequeue();
                break;

            case 5:
                q1.Transvers();
                break;

            case 6:
                cout << "Exiting program..." << endl;
                break;

            default:
                cout << "Enter a valid option!" << endl;
                break;
        }

    } while(option != 6);

    return 0;
}

