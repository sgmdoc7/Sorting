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

    
        string first[] = {"Sarah"," Greg"," Hayden"," Brayden"," Emily"," Grace"," Kayden"," Charles"," Ibrahim",               "Neha"," Shruti"," Al"," Chloe"," Blair",
                  " Nick","Eric"," Preston"," Dean"," Shreya"," Ben"," Madilyn"," Trevor"," Kelly"," Ameya"," Joshua"," Nachiket"," Ryan"," Om",
                  " Jimmy"," Trysten"," Isabella","Sunny"," Caleb"," Trey"," Travis"," Jake"," Christian"," Prateek"," Calvin"," Huy"," Nathaniel",
                  " Cat"," Quoc"," Trent"," Parker"," Jack"," Avery","Derrick"," Keein"," Potatoe"," Patty"};
        
        string last[] = {"Murdock"," Thatcher"," Reed"," Wood"," Meyers"," Raymer"," Yaweh"," Adams"," Ahmed"," Ruth",         " Asolkar"," Ayoola"," Belletti",
                " Bowen"," Bryant","Buffing"," Buter"," Cashmere"," Chandra"," Cimini"," Coul"," Darst"," Deal"," Deshmukh"," Dickens"," Dighe",
                " Evans"," Gaikwad"," German"," Giorg"," Hall","He"," Hendrix"," Hicks"," Hurst"," Huseman"," Kahl"," Kharan"," Kinated"," Le",
                " Loud"," Luong"," Lang"," Maas"," Manson"," Margeson"," Mathis"," McHale","Rawr"," Head"," Burger"};
        
        int mnumber[] = {13349332, 56628723, 78383890, 83475939, 47883992, 72583828, 75424551, 75783888, 58362625, 68836653, 76774728, 86736271, 87533944, 86459633,
                         74653883, 25860056, 25254386, 84222485, 75763515, 76736252, 75639593, 85837775, 59499384, 75993455, 85739355, 11245723, 88721174, 29347245,
                         35236682, 23588934, 23958929, 89263865, 90328111, 97297992, 19646736, 83920264, 29774627, 83749626, 76388368, 65763672, 83263239, 36592743,
                         97238422, 88411392, 10907447, 38205723, 48500902, 48500903, 48500904, 48500906, 48500907};

        for (int i = 0; i < sizeof(first)/sizeof(first[0]); i++) { // adding first names

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

    /*ISNERTION SORT BEGIN for First Name*/
    void insertionsort(int key)	//key determines if first name (key = 1), last name (key = 2) or mnumber (key = 3).
    {
    	if (key == 1){ //first name basis
          
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
      
        if (key == 2){
          
          Node* curr = head;
          while(curr->next != NULL){
            Node* temp = curr;
            while (temp->next != NULL and temp->Last.compare(temp->next->Last) == 1){
            	
              	string tempS = temp->next->Last;
              	temp->next->Last = temp->Last;
              	temp->Last = tempS;
              	
              	temp = temp->next;
            }
            curr = curr->next;
          }     
        }
      
        if (key == 3){
              
          Node* curr = head;
          while(curr->next != NULL){
            Node* temp = curr;
            while (temp->next != NULL and temp->Mnumber > temp->next->Mnumber){
            	
              	string tempS = temp->next->Mnumber;
              	temp->next->Mnumber = temp->Mnumber;
              	temp->Mnumber = tempS;
              	
              	temp = temp->next;
            }
            curr = curr->next;
          }
        }
    }
    /*INSERTION SORT END*/
    // ------------------------
    /* MERGE SORT BEGIN for mNumber*/

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
        if (p->data <= r->Mnumber) {
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

int main() {

    srand(unsigned(time(NULL)));

    /* BUBBLE SORT TEST*/
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
    

    /* BUBBLE SORT END*/
    /* MERGE SORT TEST*/

    //Node* res = NULL;
    Node* a = NULL;

    StudentInfo mergeList;
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
    /*INSERTION SORT TEST*/
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
    /*INSERTION SORT END*/

    return 0;
}

