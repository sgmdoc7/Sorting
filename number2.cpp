#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;
typedef std::chrono::high_resolution_clock Clock;
struct Node {
    int data;
    Node* next;
};

class SLL {

    Node* head;
    Node* tail;

public:
    SLL() {
        head = NULL;
        tail = NULL;
    }

    void appendList(int data) { //adds at the end of the list

        Node* newNode = new Node;
        newNode->data = data;
        newNode->next = NULL;

        if (head == NULL && tail == NULL) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void printList() {   //prints list

        Node* traverser = head;
        while (traverser != NULL) {

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


    void populateList(int size) { //makes list of preferred size

        for (int i = 0; i < size; i++) {

            int dataValue = rand() % (size * 2);
            this->appendList(dataValue);
        }
    }

    void populateList2(Node** head_ref, int size) { //makes list of preferred size

        for (int i = 0; i < size; i++) {

            int dataValue = rand() % (size * 2);
            this->push(head_ref, dataValue);
        }
    }

    int returnSize() {   //returns size of list

        int size = 0;
        Node* curr = head;
        while (curr != NULL) {

            size++;
            curr = curr->next;
        }

        return size;
    }
    
    Node* getHead(){    //returns head of list
      return head;
    }
  
    Node* getTail(){    //returns tail of list
      return tail;
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
    void mySwap (Node *node_1, Node *node_2){
	    int temp = node_1->data;
	    node_1->data = node_2 -> data;
	    node_2 -> data = temp;
    }

    void bubbleSort(Node *head){
	    int swap;
	    Node *lPtr; // left pointer will point to the start of the list
	    Node *rPtr = NULL; // right pointer will point to the end of the list
	    do{
		    swap = 0;
		    lPtr = head;
		    while(lPtr->next != rPtr){
			    if (lPtr->data > lPtr->next->data) {
				    mySwap(lPtr, lPtr->next); //Swapping data
				    swap = 1; 
			    }
			    lPtr = lPtr->next;
		    }
		    rPtr = lPtr;
	    }while(swap);
    }

    /* BUBBLE SORT END */
    // ------------------------
    /* COUNTING SORT BEGIN */
    void countingSort() {

        //counting number of possible numbers
        int size = returnSize();
        size = size * 2;
        int countArr[size];

        for (int i = 0; i < size; i++)   //populating array
            countArr[i] = 0;

        Node* curr = head;
        while (curr != NULL) {       //adding each element

            countArr[curr->data]++;
            curr = curr->next;
        }

        curr = head;
        for (int i = 0; i < size; i++) {

            for (int j = countArr[i]; j > 0; j--) {

                curr->data = i;
                curr = curr->next;
            }
        }
    }
    //COUNTING SORT END
    // ------------------------
    //RADIX SORT BEGINNING
    void countingSort(int factor){ //overloaded countingSort for radixSort
    
    int countArr[10] = {0};
    
    Node *curr = head;      //adding each element
    while (curr != NULL)
      {				

	    countArr[(curr->data / factor) % 10]++;
    	curr = curr->next;
      }

    curr = head;
    SLL tempList;
    while(curr != NULL){
        
        tempList.appendList(curr->data);
        curr = curr->next;
    }
    
    curr = head;
    for (int i = 0; i < 10; i++)  //copying back each element
      {
        Node* tempCurr = tempList.getHead();
        while (countArr[i] > 0){
            while((tempCurr->data / factor) % 10 != i)
                tempCurr = tempCurr->next;
            
            curr->data = tempCurr->data;
	          curr = curr->next;
            tempCurr = tempCurr->next;
            countArr[i]--;
        }
      }
  }
    
  void radixSort ()
  {

    int factor = 1;
    int size = returnSize ();

    while (factor <= size * 2)
      {
	//uses modified counting sort
	//sorting elements
	    countingSort(factor);
	    factor *= 10;
      }
    }
    /* RADIX SORT END */
    // ------------------------
    /* QUICK SORT BEGIN */

    Node* partition(Node** headNew, Node** newEnd, Node* head, Node* end)
    {
        Node* hubpiv = end;
        Node* preced = NULL, * tail = hubpiv, * on = head;
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
                    preced->next = on->next;
                Node* temp1 = on->next;
                on->next = NULL;

                tail->next = on;
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
        Node* headNew = NULL, * tailNew = NULL;

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

        if ((head->next == NULL) || head == NULL) {
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
    // ------------------------
    /*INSERTION SORT BEGIN*/
    Node* insertionsort(Node* headref)
    {
        Node* sorted = NULL;
        Node* key = headref;
        while (key != NULL) {
            Node* next = key->next;
            if (sorted == NULL || sorted->data >= key->data) {
                key->next = sorted;
                sorted = key;
            }
            else {
                Node* current = sorted;
                while (current->next != NULL
                    && current->next->data < key->data) {
                    current = current->next;
                }
                key->next = current->next;
                current->next = key;
            }
            key = next;
        }
        head = sorted;
        return head;
    }
    /*INSERTION SORT END*/
};




int main() {

    srand(unsigned(time(NULL)));
    int s;

    //put whatever you want after this, ignore the srand function (i.e. leave it there)
     /* Start with the empty list */
    cout << "What size would you like the arrays? (10,100,500,5000, or 25000)" << endl;
    cin >> s;
	
    /* BUBBLE SORT TEST*/
    cout<<endl;
    Node* r = NULL;

    SLL bubbleList;
    bubbleList.populateList2(&r,s);
    cout << "Linked List before bubble sort is: " << endl;
    bubbleList.printList2(r);
    cout << endl;

    bubbleList.bubbleSort(r);

    cout << "Bubble sorted Linked List is: " << endl;
    bubbleList.printList2(r);
    cout << endl;
    auto t1 = Clock::now();
    auto t2 = Clock::now();
    std::cout << "Delta t2-t1: "<< std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count() <<" nanoseconds" << std::endl;
    cout << endl<<endl;


    /* BUBBLE SORT END*/
    //-----------------------
    /* QUICK SORT TEST*/
    Node* f = NULL;

    SLL quickList;

    cout << "Linked List before quick sort is: " << endl;
    quickList.printList2(r);
    cout << endl;

    quickList.quickSort(&r);

    cout << "Quick sorted Linked List is: " << endl;
    quickList.printList2(r);
    cout << endl;
    auto t3 = Clock::now();
    auto t4 = Clock::now();
    std::cout << "Delta t4-t3: "<< std::chrono::duration_cast<std::chrono::nanoseconds>(t4 - t3).count() << " nanoseconds" << std::endl;
    cout << endl;
    cout << endl;
    /* QUICK SORT END*/
    //-----------------------
    /* MERGE SORT TEST*/

    //Node* res = NULL;
    Node* a = NULL;

    SLL mergeList;

    cout << "Linked List before merge sort is: " << endl;
    mergeList.printList2(r);
    cout << endl;

    mergeList.mergeSort(&r);

    cout << "Merge sorted Linked List is: " << endl;
    mergeList.printList2(r);
    cout << endl;
    auto t5 = Clock::now();
    auto t6 = Clock::now();
    std::cout << "Delta t6-t5: "<< std::chrono::duration_cast<std::chrono::nanoseconds>(t6 - t5).count() << " nanoseconds" << std::endl;
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

    /*INSERTION SORT TEST*/
    Node* b = NULL;
    SLL insertion;

    cout << "Linked List before insertion sort is: " << endl;
    insertion.printList2(r);
    cout << endl;

    r = insertion.insertionsort(r);
    cout << "insertion sorted linked list is: " << endl;
    insertion.printList2(r);
    cout << endl;
    auto t7 = Clock::now();
    auto t8 = Clock::now();
    std::cout << "Delta t8-t7: "<< std::chrono::duration_cast<std::chrono::nanoseconds>(t8 - t7).count() << " nanoseconds" << std::endl;
    cout << endl;
    cout << endl;
    /*INSERTION SORT END*/
    
    //RADIX SORT TEST
    SLL radix;
    radix.populateList(s);
    
    cout << "Linked List before radix sort is: " << endl;
    radix.printList();
    cout << endl;
    
    radix.radixSort();
    cout << "Radix sorted linked list is: " << endl;
    radix.printList();
    cout << endl;
    
    //RADIX SORT TEST END

    return 0;
}