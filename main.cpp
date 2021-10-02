#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

struct Node{
        int data;
        Node* next;
    };


class SLL{
    
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

    void printList2(Node* node)
    {
        while (node != NULL) {
            cout << node->data << " ";
            node = node->next;
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

    void push(Node** head_ref, int new_data) // add to beginning of list
    {
        Node* new_node = new Node();
        new_node->data = new_data;
        new_node->next = (*head_ref);
        (*head_ref) = new_node;
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
        for (int i = 0; i < size; i++){
            
            for(int j = countArr[i]; j > 0; j--){
                
                curr->data = i;
                curr = curr->next;
            }
        }
    }

    void quickSort(){

    }

    /* MERGE SORT BEGIN */

    void mergeSort(Node** headRef)
    {
        Node* head = *headRef;
        Node* a;
        Node* b;
    
        if ((head == NULL) || (head->next == NULL)) {
            return;
        }
    
        //Split head into sublists
        split(head, &a, &b);
    
        mergeSort(&a);
        mergeSort(&b);
    
        // merge the two sorted lists together 
        *headRef = mergeSorted(a, b);
    }
    
    Node* mergeSorted(Node* a, Node* b)
    {
        Node* result = NULL;
    
        if (a == NULL)
            return (b);
        else if (b == NULL)
            return (a);
    
        // pick and recur
        if (a->data <= b->data) {
            result = a;
            result->next = mergeSorted(a->next, b);
        }
        else {
            result = b;
            result->next = mergeSorted(a, b->next);
        }
        return (result);
    }
    void split(Node* source,
                    Node** frontRef, Node** backRef)
    {
        Node* fast;
        Node* slow;
        slow = source;
        fast = source->next;
    
        while (fast != NULL) {
            fast = fast->next;
            if (fast != NULL) {
                slow = slow->next;
                fast = fast->next;
            }
        }
    
        //so split it in two at midpoint
        *frontRef = source;
        *backRef = slow->next;
        slow->next = NULL;
    }

    /* MERGE SORT END */
};




int main(){
    
    srand(unsigned(time(NULL)));
    
    //put whatever you want after this, ignore the srand function (i.e. leave it there)
     /* Start with the empty list */

    /* MERGE SORT */

    Node* res = NULL;
    Node* a = NULL;
 
    SLL mergeList;
    mergeList.push(&a, 15);
    mergeList.push(&a, 10);
    mergeList.push(&a, 5);
    mergeList.push(&a, 20);
    mergeList.push(&a, 3);
    mergeList.push(&a, 2);
 
    mergeList.mergeSort(&a);
 
    cout << "Merge sorted Linked List is: \n";
    mergeList.printList2(a);
    cout << " \n " ;

    /* MERGE SORT END */

    /* COUNTING SORT BEGIN */
 
    SLL list;
    list.populateList(10);
    list.printList();
    list.countingSort();
    cout << "Sorted:" << endl;
    list.printList();

    /* COUNTING SORT END */

    return 0;
}