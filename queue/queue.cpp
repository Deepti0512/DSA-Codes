#include <iostream>
using namespace std;

class queue
{
private:
    int size;
    int *arr;
    int front;
    int rear;

public:
    queue(int size)
    {
        this->size = size;
        arr = new int[size];
        front = 0;
        rear = 0;
    }
    bool isEmpty()
    {
        if (front == rear)
        {
            return true;
        }
        else
            return false;
    }
    void enqueue(int data)
    {
        if (rear == size)
        {
            cout << "Queue is full\n";
            return;
        }
        else
        {
            arr[rear] = data;
            rear++;
        }
    }
    int dequeue()
    {
        if (front == rear)
        {
            return -1;
        }
        else
        {
            int curr_val = arr[front];
            arr[front] = -1;
            front++;
            if (front == rear)
            {
                front = 0;
                rear = 0;
            }
            return curr_val;
        }
    }
    int front_value()
    {
        if (front == rear)
        {
            return -1;
        }
        else
            return arr[front];
    }
};
class CircularQueue
{
    int *arr;
    int size;
    int front;
    int rear;

public:
    CircularQueue(int size)
    {
        this->size = size;
        arr = new int[size];
        front = -1;
        rear = -1;
    }
    void enqueue(int data)
    {
        if ((front == 0 && rear == size - 1) || (rear = (front - 1) % (size - 1)))
        {
            cout << "Queue is full\n";
            return;
        }
        else if (front == -1)
        {
            // first element to be inserted
            front = rear = 0;
            arr[rear] = data;
        }
        else if (rear == size - 1 && front != 0)
        {
            rear = 0;
            arr[rear] = data;
        }
        else
        {
            rear++;
            arr[rear] = data;
        }
    }
    int dequeue()
    {
        if (front == -1)
        {
            cout << "Queue is empty\n";
            return -1;
        }
        int ans = arr[front];
        arr[front] = -1;
        if (front == rear)
        {
            front = rear - 1;
        }
        else if (front == size - 1)
        {
            front = 0;
        }
        else
        {
            front++;
        }
        return ans;
    }
};
class Dequeue
{
    // Doubly ended queue
    int *arr;
    int size;
    int front;
    int rear;
    Dequeue(int size)
    {
        this->size = size;
        arr = new int[size];
        front = rear = -1;
    }
    void push_front(int data)
    {   
        //check full
        if ((front == 0 && rear == size - 1) || (front == (rear - 1) % (size - 1)))
        {
            cout << "Queue is full\n";
            return;
        }
        else if (front == -1)
        {
            front = rear = 0;
        }
        else if (front == 0 && rear != size - 1)
        {
            front = size - 1;
        }
        else
        {
            front--;
        }
        arr[front] = data;
    }
    void push_back(int data)
    {
        if ((front == 0 && rear == size - 1) || (rear = (front - 1) % (size - 1)))
        {
            cout << "Queue is full\n";
            return;
        }
        else if (front == -1)
        {
            // first element is to be inserted
            front = rear = 0;
            arr[rear] = data;
        }
        else if (rear == size - 1 && front != 0)
        {
            // to maintain cyclic nature
            rear = 0;
            arr[rear] = data;
        }
        else
        {
            rear++;
            arr[rear] = data;
        }
    }
    void pop_front()
    {
        if (front == -1)
        {
            cout << "Queue is empty\n";
        }
        int ans = arr[front];
        if (front == rear)
        {
            arr[front] = -1;
            front = rear - 1;
        }
        else if (front == size - 1)
        {
            arr[front] = -1;
            front = 0;
        }
        else
        {
            front++;
        }
    }
    void pop_back()
    {
        if (front == -1)
        {
            cout << "Queue is empty\n";
            return;
        }
        int ans = arr[rear];
        if (front == rear)
        {
            // case of single element in queue
            arr[rear] = -1;
            rear--;
        }
        else if (rear == 0)
        {
            arr[rear] = -1;
            rear = size - 1;
        }
        else
        {
            rear--;
        }
    }
    int getFront(){
        if(front == -1){
            return -1;
        }
        return arr[front];
    }
    int getRear(){
        if(front == -1){
            return -1;
        }
        return arr[rear];
    }
    
};

int main()
{   
    return 0;
}