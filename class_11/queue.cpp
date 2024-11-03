#include <iostream>

class class_queue{
public:
    class_queue(int capacity);
    bool is_empty();
    bool is_full();
    void en_queue(int value);
    void de_queue();
    ~class_queue();
private:
    int front;
    int rear;
    int size;
    int* queue;
};

class_queue::class_queue(int capacity){
    front = -1;
    rear = -1;
    size = capacity;
    queue = new int[capacity];
}

bool class_queue::is_empty(){
    return front == -1;
}


bool class_queue::is_full(){
    return rear == size - 1;
}

void class_queue::en_queue(int value){
    if (is_full()) {
        std::cout << "full " << value << "\n";
        return;
    }
    if (is_empty()) {
        front = 0;
    }
    rear++;
    queue[rear] = value;
}


void class_queue::de_queue(){
    if(is_empty()){
        std::cout << "empty" << "\n";
        return;
    }
    std::cout << queue[front] << " dequeued" << "\n";
    front++;

    if(front > rear){
        front = -1;
        rear = -1;
    }
}

class_queue::~class_queue(){
    delete[] queue;
}

int main() {
    class_queue q(5);
    q.en_queue(10);
    q.en_queue(20);
    q.en_queue(30);
    q.de_queue();
    q.de_queue();
    q.en_queue(40);
    q.de_queue();
    q.de_queue();
    return 0;
}