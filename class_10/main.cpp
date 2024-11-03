
#include "include/stack.hpp";

void add_node(node* &head, int value){
    node* new_node = new node();
    new_node -> data = value;
    new_node -> next = nullptr;

    if(head == nullptr){
        head = new_node;
    } else{
        node* temp = head;
        while(temp -> next != nullptr){
            temp=temp->next;
        }
        temp -> next = new_node;
    }
}

void print_linked_list(node* head){
    node* temp = head;
    while(temp != nullptr){
        std::cout << temp -> data << "-> ";
        temp = temp -> next;
    }
}

int main(){
    node* list = nullptr;
    add_node(list, 40);
    add_node(list, 10);
    add_node(list, 890);
    print_linked_list(list);
    return 0;

}