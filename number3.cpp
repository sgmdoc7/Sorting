/* Code for number 3 
3.	Create a linked list class that can store Student information.  
The Student information must include First Name, Last Name, MNumber 
and may include any other additional information you wish.  
In addition to any required members to make the linked list work, 
include 3 of the above sort algorithms to support sorting by First 
Name, Last Name and MNumber (each algorithm sorts by 1 of the 3) 
and includes a parameter for ascending or descending.  Seed your 
linked list with data for 50 students that will result in a different 
order for each of the fields.  Include a menu interface that allows 
the user to select the sort method and direction and will display 
the sorted students on the screen.
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#incku

using namespace std;

struct Node{
        string First;
        string Last;
        int Mnumber;
        Node* next;
    };

class StudentInfo {

    Node* head;
    Node* tail;

public:
    StudentInfo() {
        head = NULL;
        tail = NULL;
    }

    void appendList(string First, string Last, int Mnumber) { //adds at the end of the list

        Node* newNode = new Node;
        newNode->First = First;
      	newNode->Last = Last;
      	newNode->Mnumber = Mnumber;
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

    void printList2(Node* node) // another way to print list
    {
        while (node != NULL) {
            cout << node->First << "\t" << node->Last << "\t" << node-> Mnumber << endl;
            node = node->next;
        }
    }

    void populateList2(Node** head_ref) { //makes list of preferred size

    
        string first[] = {"Sarah","Greg","Hayden","Brayden","Emily","Grace","Kayden","Charles","Ibrahim",               "Neha","Shruti","Al","Chloe","Blair",
                  "Nick","Eric","Preston","Dean","Shreya","Ben","Madilyn","Trevor","Kelly","Ameya","Joshua","Nachiket","Ryan","Om",
                  "Jimmy","Trysten","Isabella","Sunny","Caleb","Trey","Travis","Jake","Christian","Prateek","Calvin","Huy","Nathaniel",
                  "Cat","Quoc","Trent","Parker","Jack","Avery","Derrick","Keein","Potatoe","Patty"};
        
        string last[] = {"Murdock","Thatcher","Reed","Wood","Meyers","Raymer","Yaweh","Adams","Ahmed","Ruth",         "Asolkar","Ayoola","Belletti",
                "Bowen","Bryant","Buffing","Buter","Cashmere","Chandra","Cimini","Coul","Darst","Deal","Deshmukh","Dickens","Dighe",
                "Evans","Gaikwad","German","Giorg","Hall","He","Hendrix","Hicks","Hurst","Huseman","Kahl","Kharan","Kinated","Le",
                "Loud","Luong","Lang","Maas","Manson","Margeson","Mathis","McHale","Rawr","Head","Burger"};
        
        int mnumber[] = {13349332, 56628723, 78383890, 83475939, 47883992, 72583828, 75424551, 75783888, 58362625, 68836653, 76774728, 86736271, 87533944, 86459633,
                         74653883, 25860056, 25254386, 84222485, 75763515, 76736252, 75639593, 85837775, 59499384, 75993455, 85739355, 11245723, 88721174, 29347245,
                         35236682, 23588934, 23958929, 89263865, 90328111, 97297992, 19646736, 83920264, 29774627, 83749626, 76388368, 65763672, 83263239, 36592743,
                         97238422, 88411392, 10907447, 38205723, 48500902, 48500903, 48500904, 48500906, 48500907};

        for (int i = 0; i < sizeof(first)/sizeof(first[0]); i++) { // adding first name, last name, mnumber to a node, then going to next node

          Node* nodeNew = new Node();
          nodeNew->First = first[i];
          nodeNew->Last = last[i];
          nodeNew->Mnumber = mnumber[i];
           nodeNew->next = (*head_ref);
          (*head_ref) = nodeNew;
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

    Node* getTail(Node* current)
    {
        while (current != NULL && current->next != NULL)
            current = current->next;
        return current;
    }
    /* BUBBLE SORT BEGIN */
    void bubbleSort(){
      
      Node* curr = head;
        while(curr->next != NULL){
        	Node* temp = curr;
        	while (temp->next != NULL and temp->First.compare(temp->next->First) == 1){
         	
           		string tempS = temp->next->First;
           		temp->next->First = temp->First;
           		temp->First = tempS;
             	
           		temp = temp->next;
        	}
        	curr = curr->next;
        } 
    }

    /* BUBBLE SORT END */

    /*ISNERTION SORT BEGIN for First Name*/
    void insertionsort()	
    {   
        Node* curr = head, *currPrev = head;
        while(curr->next != NULL){
        	Node* temp = curr, *tempPrev =  currPrev;
        	while (temp->next != NULL and temp->Last.compare(curr->Last) == 1){
              	tempPrev = temp;
           		temp = temp->next;
        	}
          	if (temp->Last.compare(curr->Last) != 1){
            	
              	if (curr == head){
                    
                  	tempPrev->next = temp->next;
                    	temp->next = curr;
                    	head = temp;                    	
                  }
              	else{
                  	tempPrev->next = temp->next;
                    	temp->next = curr;
                    	currPrev->next = temp;
                  }
              	
              	if (temp->next == NULL)
                  	tail = tempPrev;	  	
            }
          	currPrev = curr;
        	curr = curr->next;
        }
    }
    /*INSERTION SORT END*/
    // ------------------------
    /* MERGE SORT BEGIN for mNumber*/

    void mergeSortA(Node** refHead) // merge sort ascending
    {
        Node* head = *refHead;

        Node* p;
        Node* r;

        if ((head->next == NULL) || head == NULL) {
            return;
        }
        //Split into sublists
        splitA(head, &p, &r);
        mergeSortA(&p);
        mergeSortA(&r);

        *refHead = mSortedA(p, r); // two lists come together
    }

    Node* mSortedA(Node* p, Node* r)
    {
        Node* answer = NULL;


        if (p == NULL)
            return r;
        else if (r == NULL)
            return p;

        // pick and use recursion
        if (p->Mnumber <= r->Mnumber) {
            answer = p;
            answer->next = mSortedA(p->next, r);
        }
        else {
            answer = r;
            answer->next = mSortedA(p, r->next);
        }
        return (answer);
    }
    void splitA(Node* origin, Node** fRef, Node** bRef)
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
  
    void mergeSortD(Node** refHead) // merge sort descending 
    {
        Node* head = *refHead;

        Node* p;
        Node* r;

        if ((head->next == NULL) || head == NULL) {
            return;
        }
        //Split into sublists
        splitD(head, &p, &r);
        mergeSortD(&p);
        mergeSortD(&r);

        *refHead = mSortedD(p, r); // two lists come together
    }

    Node* mSortedD(Node* p, Node* r)
    {
        Node* answer = NULL;


        if (p == NULL)
            return r;
        else if (r == NULL)
            return p;

        // pick and use recursion
        if (p->Mnumber >= r->Mnumber) {
            answer = p;
            answer->next = mSortedD(p->next, r);
        }
        else {
            answer = r;
            answer->next = mSortedD(p, r->next);
        }
        return (answer);
    }
    void splitD(Node* origin, Node** fRef, Node** bRef)
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
int main() {

    srand(unsigned(time(NULL)));
    int e;
    int g;
  
    cout << "How would you like the student information to be sorted?" << endl;
    cout << "1. First name (insertion sort)" << endl;
    cout << "2. Last name (bubble sort)" << endl;
    cout << "3. Mnumber (merge sort)" << endl;
    cin >> e;
    cout << "Would you like it to be Ascending or Descending?" << endl;
    cout << "1. Ascending" << endl;
    cout << "2. Descending" << endl;
    cin >> g;
  
    // Last Name Ascending
    if ((e == 2) && (g == 1)){
      /*
        cout<<endl;
        Node* r = NULL;

        StudentInfo bubbleList;
        bubbleList.populateList2(&r,s);
        cout << "Linked List before bubble sort is: " << endl;
        bubbleList.printList2(r);
        cout << endl;

        bubbleList.bubbleSort(r);

        cout << "Bubble sorted Linked List is: " << endl;
        bubbleList.printList2(r);
        cout << endl<<endl;
        */
    }
  
    // Last Name Descending
    if ((e == 2) && (g == 2)){
      /*
        cout<<endl;
        Node* r = NULL;

        StudentInfo bubbleList;
        bubbleList.populateList2(&r,s);
        cout << "Linked List before bubble sort is: " << endl;
        bubbleList.printList2(r);
        cout << endl;

        bubbleList.bubbleSort(r);

        cout << "Bubble sorted Linked List is: " << endl;
        bubbleList.printList2(r);
        cout << endl<<endl;
        */
    }
	
    // Mnumber Ascending
    if ((e == 3) && (g == 1)){
        Node* a = NULL;

        StudentInfo mergeList;
        mergeList.populateList2(&a);

        mergeList.mergeSortA(&a);

        cout << "Student info sorted by Mnumber: " << endl;
        mergeList.printList2(a);
        cout << endl;
        cout << endl;
    }
    
    // Mnumber Descending
    if ((e == 3) && (g == 2)){
        Node* a = NULL;

        StudentInfo mergeList;
        mergeList.populateList2(&a);

        mergeList.mergeSortD(&a);

        cout << "Student info sorted by Mnumber: " << endl;
        mergeList.printList2(a);
        cout << endl;
        cout << endl;
    }
	
    // First Name Ascending
    if ((e == 1) && (g == 1)){
      /*
        Node* k = NULL;

       StudentInfo insertion;
        insertion.populateList2(&k, s);

        cout << "Linked List before insertion sort is: " << endl;
        insertion.printList2(k);
        cout << endl;

        Node* insertionpointer = insertion.insertionsort(k);
        cout << "insertion sorted linked list is: " << endl;
        insertion.printList2(insertionpointer);
        cout << endl;
        */
    }
  
    // First Name Descending
    if ((e == 1) && (g == 2)){
      /*
        Node* k = NULL;

       StudentInfo insertion;
        insertion.populateList2(&k, s);

        cout << "Linked List before insertion sort is: " << endl;
        insertion.printList2(k);
        cout << endl;

        Node* insertionpointer = insertion.insertionsort(k);
        cout << "insertion sorted linked list is: " << endl;
        insertion.printList2(insertionpointer);
        cout << endl;
        */
    }

    return 0;
}

