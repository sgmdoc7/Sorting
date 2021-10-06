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

Student Info:

Sarah,Murdock,M13349332
Greg,Thatcher,M56628723
Hayden, Reed    ,M78383890
Brayden, Wood   ,M83475939
Emily, Meyers   ,M47883992
Grace, Raymer   ,M72583828
Kayden, Yaweh   ,M75424551
Charles, Adams  ,M75783888
Ibrahim, Ahmed	,M36248658
Neha, Ruth      ,M36552268
Shruti, Asolkar	,M65935286
Al, Ayoola	    ,M75738624
Chloe, Belletti	,M58362625
Blair, Bowen	,M68836653
Nick, Bryant	,M76774728
Eric, Buffing   ,M86736271
Preston, Buter  ,M87533944
Dean, Cashmere	,M86459633
Shreya, Chandra	,M74653883
Ben, Cimini	    ,M25860056
Madilyn, Coul	,M25254386
Trevor, Darst	,M84222485
Kelly, Deal	    ,M75763515
Ameya, Deshmukh ,M76736252
Joshua, Dickens	,M75639593
Nachiket, Dighe	,M85837775
Ryan, Evans     ,M59499384
Om, Gaikwad	    ,M75993455
Jimmy, German   ,M85739355
Trysten, Giorg  ,M11245723
Isabella, Hall	,M88721174
Sunny, He	    ,M29347245
Caleb, Hendrix	,M35236682
Trey, Hicks	    ,M23588934
Travis, Hurst   ,M23958929
Jake, Huseman	,M89263865
Christian, Kahl ,M90328111
Prateek, Kharan ,M97297992
Calvin, Kinated	,M19646736
Huy, Le	        ,M83920264
Nathaniel, Loud ,M29774627
Cat, Luong	    ,M83749626
Quoc, Luong	    ,M76388368
Trent, Maas	    ,M65763672
Parker, Manson	,M83263239
Jack, Margeson  ,M36592743
Avery, Mathis	,M97238422
Derrick, McHale ,M88411392
Keein, Rawr     ,M10907447
Potatoe, Head   ,M38205723
Patty, Burger   ,M48500902

students = {Sarah,Murdock,M13349332,Greg,Thatcher,M56628723,Hayden,Reed,M78383890,
    Brayden,Wood,M83475939,Emily,Meyers,M47883992,Grace,Raymer,M72583828,Kayden,Yaweh,
    M75424551,Charles,Adams,M75783888,Ibrahim,Ahmed,M36248658,Neha,Ruth,M36552268,Shruti, 
    Asolkar,M65935286,Al,Ayoola,M75738624,Chloe,Belletti,M58362625,Blair,Bowen,M68836653,
    Nick,Bryant,M76774728,Eric,Buffing,M86736271,Preston,Buter,M87533944,Dean,Cashmere,
    M86459633,Shreya,Chandra,M74653883,Ben,Cimini,M25860056,Madilyn,Coul,M25254386,Trevor,
    Darst,M84222485,Kelly,Deal,M75763515,Ameya,Deshmukh,M76736252,Joshua,Dickens,M75639593,
    Nachiket,Dighe,M85837775,Ryan,Evans,M59499384,Om,Gaikwad,M75993455,Jimmy,German,M85739355,
    Trysten,Giorg,M11245723,Isabella,Hall,M88721174,Sunny,He,M29347245,Caleb,Hendrix,M35236682,
    Trey,Hicks,M23588934,Travis,Hurst,M23958929,Jake,Huseman,M89263865,Christian,Kahl,M90328111,
    Prateek,Kharan,M97297992,Calvin,Kinated,M19646736,Huy,Le,M83920264,Nathaniel,Loud,M29774627,
    Cat,Luong,M83749626,Quoc,Luong,M76388368,Trent,Maas,M65763672,Parker,Manson,M83263239,Jack,
    Margeson,M36592743,Avery,Mathis,M97238422,Derrick,McHale,M88411392,Keein,Rawr,M10907447,
    Potatoe,Head,M38205723,Patty,Burger,M48500902}


change to ascii values
compare

*/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

struct Node{
        string First;
        string Last;
        int Mnumber;
        int listselect; // 1, 2, 3
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

    void printList2(Node* node) // another way to print list
    {
        while (node != NULL) {
            cout << node->data << " ";
            node = node->next;
        }
    }

    AsciiConv(){

    }

    void populateList2(Node** head_ref, int size) { //makes list of preferred size

        students = {Sarah,Murdock,13349332,Greg,Thatcher,56628723,Hayden,Reed,78383890,
        Brayden,Wood,83475939,Emily,Meyers,47883992,Grace,Raymer,72583828,Kayden,Yaweh,
        75424551,Charles,Adams,75783888,Ibrahim,Ahmed,36248658,Neha,Ruth,36552268,Shruti, 
        Asolkar,65935286,Al,Ayoola,75738624,Chloe,Belletti,58362625,Blair,Bowen,68836653,
        Nick,Bryant,76774728,Eric,Buffing,86736271,Preston,Buter,87533944,Dean,Cashmere,
        86459633,Shreya,Chandra,74653883,Ben,Cimini,25860056,Madilyn,Coul,25254386,Trevor,
        Darst,84222485,Kelly,Deal,75763515,Ameya,Deshmukh,76736252,Joshua,Dickens,75639593,
        Nachiket,Dighe,85837775,Ryan,Evans,59499384,Om,Gaikwad,75993455,Jimmy,German,85739355,
        Trysten,Giorg,11245723,Isabella,Hall,88721174,Sunny,He,29347245,Caleb,Hendrix,35236682,
        Trey,Hicks,23588934,Travis,Hurst,23958929,Jake,Huseman,89263865,Christian,Kahl,90328111,
        Prateek,Kharan,97297992,Calvin,Kinated,19646736,Huy,Le,83920264,Nathaniel,Loud,29774627,
        Cat,Luong,83749626,Quoc,Luong,76388368,Trent,Maas,65763672,Parker,Manson,83263239,Jack,
        Margeson,36592743,Avery,Mathis,97238422,Derrick,McHale,88411392,Keein,Rawr,10907447,
        Potatoe,Head,38205723,Patty,Burger,48500902}


        for (int i = 0; i < 150; i++) {

            int dataValue = AsciiConv(students[i]) 
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

    /*ISNERTION SORT BEGIN for First Name*/
    Node* insertionsort(Node* headref, int listselect)
    {
        Node* sorted = NULL;
        Node* key = headref;
        while (key != NULL) {
            Node* next = key->next;

            int length = (len(sorted->First) < len(key->First))? len(sorted->First) : len(key->First), flag = -1;
            for(int i = 0; i <= length; i++){
                if (sorted->First[i] > key->first[i]){
                    flag = 0;
                    break;
                }
                else if (sorted->First[i] < key->first[i]){ 
                    flag = 1;
                    break;
                }
            }

            if (sorted == NULL || flag == 0) {
                key->next = sorted;
                sorted = key;
            }
            else {
                Node* current = sorted;
                while (current->next != NULL
                    && flag == 1) {
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

int main() {

    srand(unsigned(time(NULL)));

   
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
    /*INSERTION SORT TEST*/
    Node* k = NULL;

    SLL insertion;
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

