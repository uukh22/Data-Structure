#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node* next;
};
class linkedlist
{
    Node* head;
public:
    linkedlist()
    {
        head = NULL;
    }

    bool isempty()
    {
        return head == NULL;
    }

    bool isfound(int val)
    {
        Node* temp = head;
        bool found = false;
        while (temp != NULL)
        {
            if (temp->data == val)return true;
            temp = temp->next;
        }
        return false;
    }

    void insert_First(int newValue)
    {
        Node* newNode = new Node;
        newNode->data = newValue;
        if (isempty())
        {
            newNode->next = NULL;
            head = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
    }
    void insert_Before(int element, int newValue)
    {
        if (isempty())
        {
            insert_First(newValue);
        }
        else
        {
            if (isfound(element))
            {
                if (head->data == element)
                {
                    insert_First(newValue);
                }
                else
                {
                    Node* newNode = new Node();
                    newNode->data = newValue;

                    Node* temp = head;
                    while (temp != NULL && temp->next->data != element)temp = temp->next;
                    newNode->next = temp->next;
                    temp->next = newNode;
                }
            }
            else cout << "Element is not found.\n";
        }
    }

    void insert_Last(int newValue)
    {
        if (isempty())
            insert_First(newValue);
        else
        {
            Node* newNode = new Node();
            newNode->data = newValue;

            Node* temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            newNode->next = NULL;
            temp->next = newNode;

        }
    }

    void delete_ele(int val)
    {
        Node* delptr1 = head;
        Node* delptr2 = head;
        if (isempty())
        {
            cout << "List is Empty." << '\n';
            return;
        }
        if (!isfound(val))
        {
            cout << "This element is not found in this list." << '\n';
            return;
        }
        if (head->data == val)head = head->next;
        else
        {
            while (delptr1->data != val)
            {
                delptr2 = delptr1;
                delptr1 = delptr1->next;
            }
            delptr2->next = delptr1->next;
        }
        delete(delptr1);
    }

    int counter()
    {
        Node* temp = head;
        int counter = 0;
        while (temp != NULL)
        {
            counter++;
            temp = temp->next;
        }
        return counter;
    }

    void display()
    {
        if (isempty())
        {
            cout << "List is empty\n";
            return;
        }
        else
        {
            cout << "This is elements in Linkedlist : [ ";
            Node* temp = head;
            while (temp != NULL)
            {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << "].\n";
        }
    }

};
int main()
{
    linkedlist l;
    int val, num, el;
    for (int i = 0; i < 4; i++)
    {
        cout << "Enter number to add in this list " << i + 1 << " : ";
        cin >> val;
        l.insert_First(val);
    }
    cout << "Enter element to be delete : ";
    cin >> num;
    l.delete_ele(num);
    cout << "This is elements after delete : ";
    l.display();
    cout << "Enter element you need insert before his : ";
    cin >> el;
    cout << "Enter value to insert before this element : ";
    cin >> num;
    l.insert_Before(el, num);
    cout << "This is elements after insert : \n";
    l.display();
    cout << "The number of elements = " << l.counter() << '\n';
    return 0;
}
//khaled ibrahem