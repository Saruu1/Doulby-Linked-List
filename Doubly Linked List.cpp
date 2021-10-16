//This program contains the the solution of problems from 1 to 9.
//p1: Viewing an Even linked list.
//p2: Viewing an Odd linked list.
//p3: Viewing linked list with only prime numbers.
//p4: Finding maximum and minimum values in the list.
//p5: Finding the frequency of an element.
//p6: Sorting the elements of list (both ascending and descending).
//p7: Deleting all instances of an element.
//p8: Modifing insert function such that it can insert before or after a particular element.
//p9: Modifing the create list such that it always creates list in sorted order

#include<iostream>
#include<cmath>
using namespace std;
class Node{
    int val;
    Node *next;
    Node *prev;
public:
    void set_val(int data){ val = data; }
    int get_val(){ return val; }
    void set_next(Node *n){ next = n; }
    Node* get_next(){ return next; }
    void set_prev(Node *p){ prev = p;}
    Node* get_prev(){ return prev; }
};
//This function checks whether a number is prime or not.
bool isprime(int n){
    if(n < 2)
        return false;
    for(int i = 2; i <= sqrt(n); i++)
        if(n % i == 0)
            return false;
    return true;
}
class LinkedList{
    Node *head = NULL;
    Node *tail = NULL;
public:
    void create(){
        int n;      //number of elements
        cout<<"Limit: ";
        cin>>n;
        for(int i = 0; i < n; i++){
            int data;
            cout<<"Data: ";
            cin>>data;
            
            Node *tmp = new Node();
            tmp->set_val(data);
            tmp->set_next(NULL);
            tmp->set_prev(NULL);
            
            if(i == 0){
                head = tmp;
                tail = tmp;
            }
            else{
                tail->set_next(tmp);
                tmp->set_prev(tail);
                tail = tmp;
            }
        }
    }
    void view(){
        Node *trav = head;
        cout<<"List: ";
        while(trav != NULL){
            cout<<trav->get_val()<<" ";
            trav = trav->get_next();
        }
        cout<<endl;
    }
    //This function prints the maximum and minimum values present in the list.
    void view_min_max_val(){
        if(head == NULL){
            cout<<"Empty List.\n";
            return;
        }
        else{
            Node *t = head;

            int min = t->get_val();
            int max = t->get_val();
            
            while(t != NULL){
                
                if(t->get_val() < min){
                    min = t->get_val();
                }
                
                if(t->get_val() > max){
                    max = t->get_val();
                }
                
                t = t->get_next();
            }
        cout<<"Min val: "<<min<<endl;
        cout<<"Max val: "<<max<<endl;
        }
    }
    //This function prints the frequency of a particular element.
    void view_frequency_val(){
        int data;
        cout<<"Enter element for checking its frequency: ";
        cin>>data;

        int count = 0;      //stores the frequency of element
        
        Node *t = head;
        
        while(t != NULL){
            if(t->get_val() == data){
                count++;
            }
            t = t->get_next();
        }
        cout<<"Frequency of "<<data<<" is "<<count<<endl;
    }
    //This function views a linked list with only even numbers.
    void view_even(){
        Node *t = head;
        cout<<"Even List:\n";
        while(t != NULL){
            if(t->get_val() % 2 == 0){
                cout<<t->get_val()<<" ";
            }
            t = t->get_next();
        }
        cout<<endl;
    }
    //This function views a linked list with only odd numbers.
    void view_odd(){
        Node *t = head;
        cout<<"Odd List:\n";
        while(t != NULL){
            if(t->get_val() % 2 != 0){
                cout<<t->get_val()<<" ";
            }
            t = t->get_next();
        }
        cout<<endl;
    }
    //This function views a linked list with only prime numbers.
    void view_prime(){
        Node *t = head;
        cout<<"Prime List:\n";
        while(t != NULL){
            if(isprime(t->get_val())){
                cout<<t->get_val()<<" ";
            }
        t = t->get_next();
        }
        cout<<endl;
    }
    //This function deletes an element from the doubly list.
    void delete_val(){
        int data;
        cout<<"Enter Element to be deleted: ";
        cin>>data;
        
        Node *tmp = head;
        Node *prev = NULL;
        //Checking in the head.
        if(tmp != NULL && tmp->get_val() == data){
            head = tmp->get_next(); 
            head->set_prev(NULL);
            delete tmp;
            return;
        }
        //Checking in the rest of List.
        else {
            while(tmp != NULL && tmp->get_val() != data){
                prev = tmp;
                tmp = tmp->get_next();
            }
            if(tmp == NULL){
                cout<<"Element not present\n";
                return;
            }
            prev->set_next(tmp->get_next());
            tmp->get_next()->set_prev(prev);
            delete tmp;
        }
    }
    //This function views a linked in ascending order.
    void view_sorted_ascending(){
        if(head == NULL){
            return;
        }
        else{
            Node *t = head;
            Node *index = NULL;

            //Sorting in ascending order.
            while (t != NULL){
                index = t->get_next();
                while(index != NULL){
                    if(t->get_val() > index->get_val()){
                        //Swapping the elements of the nodes  
                        int tmp = t->get_val();  
                        t->set_val(index->get_val());  
                        index->set_val(tmp);  
                    }
                    index = index->get_next();
                }
                t = t->get_next();
            }
            cout<<"After sorting in ascending order, ";
            view();
        }
    }
    //This function views a linked in descending order.
    void view_sorted_descending(){
        if(tail == NULL){
            return;
        }
        else{

            Node *t = tail;
            Node *index = NULL;
            
            //Sorting in descending order
            while (t != NULL){
                index = t->get_prev();
                while(index != NULL){
                    if(t->get_val() > index->get_val()){
                        //Swapping the elements of the nodes  
                        int tmp = t->get_val();  
                        t->set_val(index->get_val());  
                        index->set_val(tmp);  
                    }
                    index = index->get_prev();
                }
                t = t->get_prev();
            }
            cout<<"After sorting in descending order, ";
            view();
        }
    }
    //This function creates a doubly linked in ascending order.
    void create_sorted_list(){
        int n;
        cout<<"Enter the number of elements you want to enter: ";
        cin>>n;
        cout<<"Enter data:\n";

        for(int i = 0; i < n; i++){
            Node *tmp = new Node();
            
            int data;
            cin>>data;
            
            tmp->set_val(data);
            tmp->set_next(NULL);
            tmp->set_prev(NULL);
            
            //The first element is both the head and tail.
            if (i == 0){
                head = tmp;
                tail = tmp;
            }
            
            //Arranging the elements in ascending order.
            else{
                Node *t = head, *p = new Node();
                while (t != NULL && t->get_val() < data)
                {
                    p = t;
                    t = t->get_next();
                }
                if (t == head)
                {
                    head->set_prev(tmp);
                    tmp->set_next(head);
                    head = tmp;
                }
                else if (t == NULL)
                {
                    tail->set_next(tmp);
                    tmp->set_prev(tail);
                    tail = tmp;
                }
                else
                {
                    tmp->set_next(t);
                    t->set_prev(tmp);
                    p->set_next(tmp);
                    tmp->set_prev(p);
                }
            }
        }
    }
    //This function inserts an element after a paricular element in the list.
    void insert_after(){

        int i;
        cout<<"Enter the element after which you want to insert: ";
        cin>>i;

        Node *trav = head;

        while (trav->get_val() != i && trav != NULL){
            trav = trav->get_next();
        }

        if (trav != NULL){

            Node *tmp = new Node();
            int data;
            cout << "Enter the new element: ";
            cin >> data;

            tmp->set_val(data);

            if (trav == tail){

                tmp->set_prev(tail);
                tmp->set_next(NULL);
                tail->set_next(tmp);
                tail = tmp;
            }
            else{

                tmp->set_next(trav->get_next());
                tmp->set_prev(trav);
                trav->get_next()->set_prev(tmp);
                trav->set_next(tmp);
            }
        }
        else{
            cout << "Element not found." << endl;
        }
    }
    //This function inserts an element before a paricular element in the list.
    void insert_before(){
        int i;
        cout<<"Enter element before which you want to insert: ";
        cin>>i;
        
        Node *trav = head;
        if (trav != NULL){

            int data;
            cout << "Enter the new element: ";
            cin >> data;
            if (trav->get_val() == i){

                Node *tmp = new Node();
                tmp->set_val(data);
                tmp->set_prev(NULL);
                tmp->set_next(trav);
                trav->set_prev(tmp);
                head = tmp;
            }
            else
            {
                while (trav->get_val() != i && trav != NULL){
                    trav = trav->get_next();
                }
                if (trav == NULL){
                    cout << "Element not found!";
                }
                else{
                    Node *tmp =  new Node;
                    tmp->set_val(data);
                    tmp->set_prev(trav->get_prev());
                    tmp->set_next(trav);
                    trav->get_prev()->set_next(tmp);
                    trav->set_prev(tmp);
                }
            }
        }
        else cout << "Element not found!" << endl;
    }
    //This function deletes all instances of an element from the list.
    void delete_all_val(){
        int i;
        cout<<"Enter the element which you want to delete: ";
        cin>>i;
        Node *tmp = head;
        while (tmp != NULL){

            if (tmp->get_val() == i){
                
                if (tmp == head){

                    head = tmp->get_next();
                    delete tmp;
                    if (head != NULL) head->set_prev(NULL);
                    tmp = head;
                    continue;
                }
                else if (tmp == tail){

                    tail = tmp->get_prev();
                    delete tmp;
                    tail->set_next(NULL);
                }
                else{
                    tmp->get_next()->set_prev(tmp->get_prev());
                    tmp->get_prev()->set_next(tmp->get_next());
                    Node *p2 = tmp->get_next();
                    delete tmp;
                    tmp = p2;
                }
            }
            else{
                tmp = tmp->get_next();
            }

        }
    }
};
int main()
{
    LinkedList list;
    int ch;
    bool flag = false;
    while(1){
        
        cout<<"Enter an option:\n";
        cout<<"1.Create List\n2.View List\n3.View Even List\n4.View Odd List\n5.View Prime List\n6.View Min and Max Values\n7.View Frequency of an Element\n8.View Sorted List (Ascending)\n9.View Sorted List (Descending)\n10.Insert (Before Element)\n11.Insert (After Element)\n12.Create Sorted List\n13.Delete an Element\n14.Delete all instances of Element\n\n";
        cout<<"Enter 0 to exit.\n";
        cin>>ch;

        //Flag checks whether a list has been created.
        //For performing an operation or viewing, a list needs to be created first. 
        if(flag == false){
            if(ch == 1){
                list.create();
                flag = true;
            }
            else if(ch == 12){
                list.create_sorted_list();
                flag = true;
            }
            else cout<<"*** Create a list first. ***\n\n";
        }
        else{
        if(ch == 1){
            list.create();
            flag = true;
        }
        else if(ch == 2){
            list.view();
        }
        else if(ch == 3){
            list.view_even();
        }
        else if(ch == 4){
            list.view_odd();
        }
        else if(ch == 5){
            list.view_prime();
        }
        else if(ch == 6){
            list.view_min_max_val();
        }
        else if(ch == 7){
            list.view_frequency_val();
        }
        else if(ch == 8){
            list.view_sorted_ascending();
        }
        else if(ch == 9){
            list.view_sorted_descending();
        }
        else if(ch == 10){
            list.insert_before();
        }
        else if(ch == 11){
            list.insert_after();
        }
        else if(ch == 12){
            list.create_sorted_list();
            flag = true;
        }
        else if(ch == 13){
            list.delete_val();
        }
        else if(ch == 14){
            list.delete_all_val();
        }
        else if(ch == 0)
            return 0;
        else cout<<"\n*** Please enter a valid choice. ****\n\n";
        }
    }
    return 0;
}