#if !defined(MACRO)
#define MACRO

#include <iostream>

struct node{
    int data;
    node* next;
};

class stack{
private:
    node* top_node;
public:
    stack(): top_node(nullptr){}

    void push(int value){
        node* new_node = new node();
        new_node -> data = value;
        new_node -> next = top_node;
        top_node = new_node;
    };

    bool is_empty(){
        return (top_node == nullptr);
    }

    void pop(){
        if(is_empty()){
            std::cout << "stack vacio. " << "\n";
            return;
        }
        node* temp = top_node;
        top_node = temp->next;
        delete temp;
    }

    int top(){
        if(is_empty()){
            std::cout << "stack vacio. " << "\n";
            return 0;
        }
        return top_node -> data;
    }
};

#endif // MACRO