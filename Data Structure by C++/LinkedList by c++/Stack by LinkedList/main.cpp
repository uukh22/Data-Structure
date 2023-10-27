#include <iostream>

using namespace std;

//template<class t>
struct node
{
    int data;
    node* next;
};
class stackk
{
    node* top;
public:

    stackk()
    {
        top = NULL;
    }

    bool isempty()
    {
        return top==NULL;
    }

    void push(int val)
    {
        node* newnode = new node;
        newnode->data = val;
        if(isempty())
        {
            newnode->next = NULL;
            top = newnode;
        }
        else
        {
            newnode->next = top;
            top = newnode;
        }
    }

    void pop()
    {
        if(isempty())
        {
            cout<<"This stack is empty."<<'\n';
            return;
        }
        else
        {
            node* temp = top;
            top = top->next;
            delete(temp);
        }
    }

    int counter()
    {
        int counter=0;
        node* temp = top;
        while(temp!=NULL)
        {
            counter++;
            temp = temp->next;
        }
        return counter;
    }

    int pop_val()
    {
        if(isempty())cout<<"This stack is empty."<<'\n';
        else
        {
            node* temp = top;
            int num;
            num = temp->data;
            top = top->next;
            delete(temp);
            return num;
        }
    }

    void display()
    {
        node* temp = top;
        if(isempty())
        {
            cout<<"This stack is empty."<<'\n';
            return;
        }
        else
        {
            cout<<"This is elements in Stack : [ ";
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
    stackk st;
    int val;
    for(int i=0; i<4; i++)
    {
        cout<<"enter a number "<<i+1<<" : ";
        cin>>val;
        st.push(val);
    }
    cout<<"the number is delete = "<<st.pop_val()<<'\n';
    cout<<"This is elements after pop : ";
    st.display();
    cout<<"the number of elements = "<<st.counter()<<'\n';
    //st.display();
    return 0;
}
//khaled ibrahem