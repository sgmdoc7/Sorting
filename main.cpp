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
    
    int returnSize(){   //returns size of list
        
        int size = 0;
        Node* curr = head;
        while (curr != NULL){
            
            size++;
            curr = curr->next;
        } 
        
        return size;
    }
    
    void countingSort(){
    
        //counting number of possible numbers
        int size = returnSize();
        size = size * 2;
        int countArr[size];
        
        for (int i = 0; i < size; i++)   //populating array
            countArr[i] = 0;
        
        Node* curr = head;
        while (curr != NULL){       //adding each element
            
            countArr[curr->data]++;
            curr = curr->next;
        }
        
        curr = head;
        for (int i = 0; i < size; i++){		//adding back in sorted order
            
            for(int j = countArr[i]; j > 0; j--){
                
                curr->data = i;
                curr = curr->next;
            }
        }
    }
};




int main(){
    
    srand(unsigned(time(NULL)));
    
    //put whatever you want after this, ignore the srand function (i.e. leave it there)
    SLL list;
    list.populateList(10);
    list.printList();
    list.countingSort();
    cout << "Sorted:" << endl;
    list.printList();

    return 0;
}



