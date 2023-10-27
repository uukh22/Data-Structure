#include <iostream>

using namespace std;

struct node
{
    int data;
    node*next;
};

class queuee
{
    node*front;
    node*rear;
public:
    queuee()
    {
        front = NULL;
        rear = NULL;
    }

    bool isempty()
    {
        return front==NULL;
    }

    void enqueue(int val)
    {
        node*newnode = new node;
        newnode->data = val;
        newnode->next = NULL;
        if(isempty())
        {
            front = newnode;
            rear = newnode;
        }
        else
        {
            rear->next = newnode;
            rear = newnode;
        }
    }

    void deqeue()
    {
        node* delptr = front;
        if(isempty())
        {
            cout<<"This queue is empty."<<'\n';
        }
        else if(front == rear)
        {
            delete(front);
            front = rear = NULL;
        }
        else
        {
            front = front->next;
            delete(delptr);
        }
    }

    int deqeue_val()
    {
        int k;
        node* delptr = front;
        k = delptr->data;
        if(isempty())
        {
            cout<<"This queue is empty."<<'\n';
        }
        else if(front == rear)
        {
            delete(front);
            front = rear = NULL;
        }
        else
        {
            front = front->next;
            delete(delptr);
        }
        return k;
    }

    int counter()
    {
        int counter=0;
        node* temp = front;
        while(temp!=NULL)
        {
            counter++;
            temp = temp->next;
        }
        return counter;
    }

    void clearr()
    {
        node* temp = front;
        if (isempty())cout<<"Queue is empty.\n";
        else if(front == rear)
        {
            delete(front);
            front = rear = NULL;
        }
        else
        {
            while(temp!=NULL)
            {
                node* delptr = front;
                front = front->next;
                temp = temp->next;
                delete(delptr);
            }
            front = rear = NULL;
        }
    }

    int get_rear()
    {
        return rear->data;
    }

    int get_front()
    {
        return front->data;
    }

    void display()
    {
        if(isempty())
        {
            cout<<"This queue is empty."<<'\n';
            return;
        }
        else
        {
            cout<<"This is elements in Queue : [ ";
            node* temp = front;
            while(temp!=NULL)
            {
                cout<<temp->data<<" ";
                temp = temp->next;
            }
            cout<<"].\n";
        }
    }
};
int main()
{
    queuee q1;
    int val;
    for(int i=0; i<4; i++)
    {
        cout<<"enter a number "<<i+1<<" : ";
        cin>>val;
        q1.enqueue(val);
    }
    cout<<"the number is delete = "<<q1.deqeue_val()<<'\n';
    cout<< "This is elements after dequeue : ";
    q1.display();
    cout<<"the number of elements = "<<q1.counter()<<'\n';
    q1.clearr();
    cout<< "This is elements in List : ";
    q1.display();
    return 0;
}
//khaled ibrahem