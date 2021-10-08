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
        Node* returnatindex(Node* headref, int index){
    for(int i = 0; i < index; i++){
      headref = headref->next;
    }
    return headref;
  }

    void heapify(int arr[], int size, int i){
      int big = i; 
      int left = 2 * i + 1; //left child
      int right = 2 * i + 2; //right child
  
      if (left < size && arr[left] > arr[big]){
          big = left;
      }
      if (right < size && arr[right] > arr[big]){
          big = right;
      }
      if (big != i) {
          swap(arr[i], arr[big]);
          heapify(arr, size, big);
      }
  }
    void heapsort(Node* headref, int size){
      int arr[size];
      Node* next;
      for(int i = 0; i < size; i++){ //change linked list into array to swap data easier
        arr[i] = returnatindex(headref, i)->data;
      }

      for (int i=size/2-1; i>=0; i--){
          heapify(arr, size, i);
      }
      for (int i=size-1; i>0; i--) {
          swap(arr[0], arr[i]);
          heapify(arr, i, 0);
      }

      for(int i = 0; i < size; i++){
        Node* newNode = new Node;
          newNode->data = arr[i];
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
    }
  };




int main() {

    srand(unsigned(time(NULL)));
    int s;

    //put whatever you want after this, ignore the srand function (i.e. leave it there)
     /* Start with the empty list */
    cout << "What size would you like the arrays? (10,100,500,5000, or 25000)" << endl;
    cin >> s;
	
    /* BUBBLE SORT TEST*/
    Node* r = NULL;

    SLL bubbleList;
    bubbleList.populateList2(&r,s);
    cout << endl;
    auto t1 = Clock::now();
    bubbleList.bubbleSort(r);

    cout << "Bubble sorted Linked List" << endl;
    auto t2 = Clock::now();
    std::cout << "Delta t2-t1: "<< std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count() <<" nanoseconds" << std::endl;

    /* BUBBLE SORT END*/
    //-----------------------
    /* QUICK SORT TEST*/
    Node* f = NULL;

    SLL quickList;

    cout << endl;
    auto t3 = Clock::now();
    quickList.quickSort(&r);

    cout << "Quick sorted Linked List " << endl;
    auto t4 = Clock::now();
    std::cout << "Delta t4-t3: "<< std::chrono::duration_cast<std::chrono::nanoseconds>(t4 - t3).count() << " nanoseconds" << std::endl;
    /* QUICK SORT END*/
    //-----------------------
    /* MERGE SORT TEST*/

    Node* a = NULL;

    SLL mergeList;
    cout << endl;
    auto t5 = Clock::now();
    mergeList.mergeSort(&r);

    cout << "Merge sorted Linked List " << endl;
    auto t6 = Clock::now();
    std::cout << "Delta t6-t5: "<< std::chrono::duration_cast<std::chrono::nanoseconds>(t6 - t5).count() << " nanoseconds" << std::endl;
    cout << endl;


    /* MERGE SORT END */
    //-------------------------
    /* COUNTING SORT TEST */

    SLL list;
    auto t9 = Clock::now();
    list.countingSort();
    cout << "Counting sorted Linked List" << endl;
    auto t10 = Clock::now();
    std::cout << "Delta t10-t9: "<< std::chrono::duration_cast<std::chrono::nanoseconds>(t10 - t9).count() << " nanoseconds" << std::endl;

    /* COUNTING SORT END */

    /*INSERTION SORT TEST*/
    Node* b = NULL;
    SLL insertion;

    cout << endl;
    auto t7 = Clock::now();
    r = insertion.insertionsort(r);
    cout << "Insertion sorted linked list " << endl;
    auto t8 = Clock::now();
    std::cout << "Delta t8-t7: "<< std::chrono::duration_cast<std::chrono::nanoseconds>(t8 - t7).count() << " nanoseconds" << std::endl;
    /*INSERTION SORT END*/
    
    //RADIX SORT TEST
    SLL radix;
    
    cout << endl;
    auto t11 = Clock::now();
    radix.radixSort();
    cout << "Radix sorted linked list " << endl;
    auto t12 = Clock::now();
    std::cout << "Delta t12-t11: "<< std::chrono::duration_cast<std::chrono::nanoseconds>(t12 - t11).count() << " nanoseconds" << std::endl;

    //RADIX SORT TEST END

    /*heap SORT TEST*/
    Node* e = NULL;
    SLL heaps;

    cout << endl;
    auto t13 = Clock::now();
    heaps.heapsort(r,s);
    cout << "Heap sorted linked list" << endl;
    auto t14 = Clock::now();
    std::cout << "Delta t14-t13: "<< std::chrono::duration_cast<std::chrono::nanoseconds>(t14 - t13).count() << " nanoseconds" << std::endl;
    
    /*heap SORT END*/

    return 0;
}
