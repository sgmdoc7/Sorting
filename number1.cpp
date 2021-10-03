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
            
            cout << traverser->data; 
            cout << " ";
            traverser = traverser->next;
        }
    }

    void printList2(Node* node) // another way to print list
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

    void populateList2(Node** head_ref,int size){ //makes list of preferred size
        
        for (int i = 0; i < size; i++){
            
            int dataValue = rand() % (size * 2);
            this->push(head_ref,dataValue);
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

    Node* getTail(Node* cur)
    {
        while (cur != NULL && cur->next != NULL)
            cur = cur->next;
        return cur;
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
    /* QUICK SORT BEGIN */

    Node* partition(Node** newHead, Node** newEnd, Node* head, Node* end)
    {
        Node* pivot = end;
        Node *previous = NULL, *tail = pivot, *current = head;
        while (current != pivot) {
            if (current->data < pivot->data) { 
                if ((*newHead) == NULL)
                    *newHead = current;
    
                previous = current;
                current = current->next;
            }
            else // If current node is greater than pivot
            {
                // Move current node next after tail and change tail
                if (previous)
                    previous->next = current->next;
                Node* temp1 = current->next;
                current->next = NULL;
                tail->next = current;
                tail = current;
                current = temp1;
            }
        }
    
        if ((*newHead) == NULL)
            *newHead = pivot;
    
        *newEnd = tail;
    
        return pivot;
    }
 
    Node* recursionQS(Node* head, Node* end)
    {
        if (!head || head == end)
            return head;
        Node *newHead = NULL, *newTail = NULL;
    
        // partition list
        Node* pivot = partition(&newHead, &newTail, head, end);
        if (newHead != pivot) {
          
            Node* tmp = newHead;
            while (tmp->next != pivot)
                tmp = tmp->next;
            tmp->next = NULL;
    
            // Recursion for section of list before pivot
            newHead = recursionQS(newHead, tmp);
            tmp = getTail(newHead);
            tmp->next = pivot;
        }
    
        pivot->next = recursionQS(pivot->next, newTail);
    
        return newHead;
    }
    
    void quickSort(Node** refHead)
    {
        (*refHead) = recursionQS(*refHead, getTail(*refHead));
        return;
    }

    /* QUICK SORT END */
    // ------------------------
    /* MERGE SORT BEGIN */

    void mergeSort(Node** refHead)
    {
        Node* head = *refHead;
        Node* p; 
        Node* r; 
    
        if ((head == NULL) || (head->next == NULL)) {
            return;
        }
        //Split head into sublists
        split(head, &p, &r);
        mergeSort(&p);
        mergeSort(&r);
        // merge the two sorted lists together 
        *refHead = mergeSorted(p, r);
    }
    
    Node* mergeSorted(Node* p, Node* r)
    {
        Node* result = NULL;
        if (p == NULL)
            return (r);
        else if (r == NULL)
            return (p);
    
        // pick and recur
        if (p->data <= r->data) {
            result = p;
            result->next = mergeSorted(p->next, r);
        }
        else {
            result = r;
            result->next = mergeSorted(p, r->next);
        }
        return (result);
    }
    void split(Node* origin, Node** frontRef, Node** backRef)
    {
        Node* rabbit;
        Node* turtle;
        turtle = origin;
        rabbit = origin->next;
    
        while (rabbit != NULL) {
            rabbit = rabbit->next;
            if (rabbit != NULL) {
                turtle = turtle->next;
                rabbit = rabbit->next;
            }
        }
        //so split it in two at midpoint
        *frontRef = origin;
        *backRef = turtle->next;
        turtle->next = NULL;
    }

    /* MERGE SORT END */
};




int main(){
    
    srand(unsigned(time(NULL)));
    int s;
    
    //put whatever you want after this, ignore the srand function (i.e. leave it there)
     /* Start with the empty list */
    cout << "What size would you like the arrays? (10,100,500,5000, or 25000)" << endl;
    cin >> s;

    /* QUICK SORT TEST*/
    cout << endl;
    Node* f = NULL;

    SLL quickList;
    quickList.populateList2(&f, s);
    
    cout << "Linked List before quick sort is: " << endl;
    quickList.printList2(f);
    cout << endl;
 
    quickList.quickSort(&f);
 
    cout << "Quick sorted Linked List is: " << endl;
    quickList.printList2(f);
    cout << endl;
    cout << endl;

    /* QUICK SORT END*/
    //-----------------------
    /* MERGE SORT TEST*/

    Node* res = NULL;
    Node* a = NULL;
 
    SLL mergeList;
    mergeList.populateList2(&a, s);

    cout << "Linked List before merge sort is: " << endl;
    mergeList.printList2(a);
    cout << endl;
 
    mergeList.mergeSort(&a);
 
    cout << "Merge sorted Linked List is: " << endl;
    mergeList.printList2(a);
    cout << endl;
    cout << endl;
  

    /* MERGE SORT END */
    //-------------------------
    /* COUNTING SORT TEST */
 
    SLL list;
    list.populateList(s);
    cout << "Linked List before counting sort is: " << endl;
    list.printList();
    cout << endl;
    list.countingSort();
    cout << "Counting sorted Linked List is: " << endl;
    list.printList();
    cout << endl;
    cout << endl;

    /* COUNTING SORT END */

    return 0;
}