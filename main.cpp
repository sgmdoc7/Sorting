#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;


class SLL{
    
    struct Node{
        int data;
        Node* next;
    };
    
    Node* head;
    Node* tail;
    
    public:
    SLL(){
        head = NULL;
        tail = NULL;
    }
    
    void appendList(int data){ //adds at the end of the list
        
        Node* newNode = new Node;
        newNode->data = data;
        newNode->next = NULL;
        
        if (head == NULL && tail == NULL){
            head = newNode;
            tail = newNode;
        }
        else{
            tail->next = newNode;
            tail = newNode;
        }
    }
    
    void printList(){   //prints list
        
        Node* traverser = head;
        while (traverser != NULL){
            
            cout << traverser->data << endl;
            traverser = traverser->next;
        }
    }
    
    void populateList(int size){ //makes list of preferred size
        
        for (int i = 0; i < size; i++){
            
            int dataValue = rand() % (size * 2);
            this->appendList(dataValue);
        }
    }
};



int main(){
    
    srand(unsigned(time(NULL)));
    
    //put whatever you want after this, ignore the srand function (i.e. leave it there)
    
    return 0;
}



