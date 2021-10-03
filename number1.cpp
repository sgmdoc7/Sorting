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

    void push(Node** ref_head, int new_data) // add to beginning of list
    {
        Node* nodeNew = new Node();
        nodeNew->data = new_data;
        nodeNew->next = (*ref_head);
        (*ref_head) = nodeNew;
    }

    Node* getTail(Node* current)
    {
        while (current != NULL && current->next != NULL)
            current = current->next;
        return current;
    }
    
    /* BUBBLE SORT BEGIN */
    
    /* BUBBLE SORT END */
    // ------------------------
    /* COUNTING SORT BEGIN */
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
    /* COUNTING SORT END */
    // ------------------------
    /* QUICK SORT BEGIN */

    Node* partition(Node** headNew, Node** newEnd, Node* head, Node* end)
    {
        Node* hubpiv = end;
        Node *preced = NULL, *tail = hubpiv, *on = head;
        while (on != hubpiv) {

            if (on->data < hubpiv->data) { 
                if (*headNew == NULL)
                    *headNew = on;
    
                preced = on;
                on = on->next;
            }
            else // if the node if larger than the current node
            {
                // Move current node next after tail and change tail
                if (preced)
                    preced -> next = on -> next;
                Node* temp1 = on->next;
                on -> next = NULL;

                tail -> next = on;
                tail = on;

                on = temp1;
            }
        }
    
        if ((*headNew) == NULL)
            *headNew = hubpiv;
    
        *newEnd = tail;
    
        return hubpiv;
    }
 
    Node* recursionQS(Node* head, Node* end)
    {
        if (head == end || !head)
            return head;
        Node *headNew = NULL, *tailNew = NULL;
    
        // partition list
        Node* pivot = partition(&headNew, &tailNew, head, end);
        if (headNew != pivot) {
          
            Node* tmppig = headNew;
            while (tmppig->next != pivot)
                tmppig = tmppig->next;
            tmppig->next = NULL;
    
            // Recursion for section of list before pivot
            headNew = recursionQS(headNew, tmppig);
            tmppig = getTail(headNew);
            tmppig->next = pivot;
        }
    
        pivot->next = recursionQS(pivot->next, tailNew);
    
        return headNew;
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
    
        if ((head->next == NULL)|| head == NULL) {
            return;
        }
        //Split into sublists
        split(head, &p, &r);
        mergeSort(&p);
        mergeSort(&r);

        *refHead = mSorted(p, r); // two lists come together
    }
    
    Node* mSorted(Node* p, Node* r)
    {
        Node* answer = NULL;


        if (p == NULL)
            return r;
        else if (r == NULL)
            return p;
    
        // pick and use recursion
        if (p->data <= r->data) {
            answer = p;
            answer->next = mSorted(p->next, r);
        }
        else {
            answer = r;
            answer->next = mSorted(p, r->next);
        }
        return (answer);
    }
    void split(Node* origin, Node** fRef, Node** bRef)
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
        *fRef = origin;
        *bRef = turtle->next;
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

    //Node* res = NULL;
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
