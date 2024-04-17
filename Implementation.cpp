#include <iostream>
#include <cstdlib>

using namespace std;

//class for each Node
class Node{
public:
    Node *next;                                                                                         //Pointer to next node
    int numElements;                                                                                    //Number of elements in each node
    int *array;                                                                                         //Array to store elements
    
    //Constructor
    Node(int n){
        next = nullptr;                                                                                 //Initialize to null
        numElements = 0;                                                                                //Initialize to 0
        array = new int[n];                                                                             //Dynamic array of n elements
    }
};

class UnrolledLinkedList{
    
    private:
        Node *head;                                                                                     //Creates a head pointer
        Node *tail;                                                                                     //Creates a tail pointer

        int totalElements;                                                                              //Maximum number of elements in a node
        int numNodes;                                                                                   //Total number of nodes in list
    
    public:
        UnrolledLinkedList(int capacity){
            head = nullptr;                                                                             //Setting the head pointer to null
            tail = nullptr;                                                                             //Setting tail pointer to null
            numNodes = 0;                                                                               //Starting number of Nodes is 0
            totalElements = capacity +1;                                                                //Total elements in each node is capacity + 1
        }

        void Insert(int num){
            numNodes++;                                                                                 //Increment number of nodes

            // Check if the list is empty / create new list
            if (head == nullptr) {
                head = new Node(totalElements);                                                         //Create a new node at the head, taking in the total number of elements it can hold
                head->array[0] = num;                                                                   //Set the [0] array element to num
                head->numElements++;                                                                    //Increment the number of elements
                tail = head;                                                                            //It is the only node in the list
                return;
            }

            // Insert element into array
            if (tail->numElements + 1 < totalElements) {                                                //Check if there is enough space to insert a new element
                tail->array[tail->numElements] = num;                                                   //If there is enough space, insert the new element (num) into the array
                tail->numElements++;
            }
            else {
                // Creation of a new Node
                Node *newNode = new Node(totalElements);                                                //Creates a new node with totalElements capacity
                int j = 0;                                                                              //Initialize j to 0 for a counter later

                for (int i = tail->numElements / 2 + 1; i < tail->numElements; i++) {                   //For loop to iterate through elements
                    newNode->array[j++] = tail->array[i];                                               //Copies each element (up to numElements / 2 + 1) from the old array into the new one
                }

                newNode->array[j++] = num;                                                              //Insert the new element into the new node
                newNode->numElements = j;                                                               //Set the number of elements in the new node
                tail->numElements = tail->numElements / 2 + 1;                                          //Update the number of elements in the current node
                tail->next = newNode;                                                                   //Set the next pointer of the current node to the new node
                tail = newNode;                                                                         //Update the tail to the new node
            }
        }


        void Print(){

            cout << "Unrolled Linked List = " << endl;                                                  //Display message
            
            Node *walker = head;                                                                        //Ceates a walker starting at the head

            while (walker != nullptr){                                                                  //While we are not at the end of the list
                for(int i = 0; i < walker->numElements; i++){                                           //Walk down the list of elements
                    cout << walker->array[i] << " ";                                                    //Output the data at that index of the array
                }
                cout << endl;                                                                           //New line
                walker = walker->next;                                                                  //Move the walker down
            }
        }

        void Search(int n){
            if (head == nullptr){                                                                       //If the head points to null
                cout << "The list is empty" << endl;                                                    //The list is empty
            }

            Node *walker = head;                                                                        //Creates a walker starting at the head

            while(walker != nullptr){                                                                   //While the walker doesnt point to null (at the end of the list)
                for(int i = 0; i < totalElements; i++){                                                 //Iterate through the array
                    if(walker->array[i] == n){                                                          //If the data in the array at the point the walker is at = n
                        cout << "The input " << n << " was found." << endl;                             //Print the statement
                        return;                                                                         //Return
                    }
                    
                }
                walker = walker->next;                                                                  //The walker has not found the element yet, so it will go to the next element
               
            }
            cout << "The input " << n << " was not found." << endl;                                     //The walker made it to the end of the list, and did not find the element

        }

        void DeleteElement(int n){
            if (head == nullptr){                                                                       //If the head points to null
                cout << "The list is empty" << endl;                                                    //Print the statement
            } else {

                Node *walker = head;                                                                    //Make a walker pointer that will point to current position

                while(walker != nullptr){                                                               //While the walker is not null
                    for(int i = 0; i < walker->numElements; i++){                                       //Iterate through the elements of the array
                        if(walker->array[i] == n){                                                      //If the walker array data matches the taken in value
                            for(int j = 0; j < walker->numElements; j++){                               //Iterate through the array
                                walker->array[j] = walker->array[j+1];                                  //Shift all elements one index to the left
                            }
                        walker->numElements--;                                                          //Decrement total number of elements in the array
                        cout << "The input " << n << " has been deleted from the node." << endl;        //Print the statement
                        return;                                                                         //Return
                        }
                    }
                    walker = walker->next;                                                              //move walker down the array
                }
            }
        }

        void DeleteNode(int n){
            if (head == nullptr){                                                                       //If the head points to null
                cout << "The list is empty" << endl;                                                    //Print the statement
            } else {

            Node *prev = nullptr;                                                                       //Make a pointer to trail behind Walker
            Node *walker = head;                                                                        //Make a walker pointer that will point to current position

            while(walker != nullptr){                                                                   //While the walker is not null
                for(int i = 0; i < walker->numElements; i++){                                           //Iterate through the elements of the array
                    if(walker->array[i] == n){                                                          //If the walker array data matches the taken in value
                        if (prev == nullptr) {                                                          //If prev is pointing to null
                            head = walker->next;                                                        //Update head if deleting the first node
                        } else {
                            prev->next = walker->next;                                                  //Update prev->next to skip over the node to be deleted
                        }
                        delete walker;                                                                  //Delete the node containing the target element
                        cout << "Node " << n << " has been deleted." << endl;                       //Print the statement
                        return;                                                                         //Exit the function after deleting the node
                    }
                }
                prev = walker;                                                                          //Update prev only if the target element is not found in the current node
                walker = walker->next;                                                                  //Move walker down the array
            }
        }
    }
};






int main(){

    UnrolledLinkedList ull(3);

    for (int i = 0; i < 37; i++){
        cout << "Entered element is : " << i << endl;
        ull.Insert(i);
        ull.Print();
        cout << endl;
    }

    ull.Search(3);
    ull.Search(30);

    ull.DeleteNode(2);
    ull.DeleteElement(5);

    cout << endl;

    ull.Print();

    return 0;
}