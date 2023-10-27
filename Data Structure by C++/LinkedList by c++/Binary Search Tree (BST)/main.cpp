#include <iostream>

using namespace std;

class node
{
public:
    int data;
    node* left, *right;
    node()
    {
        data = 0;
        left = NULL;
        right = NULL;
    }
};

class BST
{
public:
    node* root;
    BST()
    {
        root = NULL;
    }

    node* insert_t(node*ptr, int val)
    {
        node* newnode = new node;
        newnode->data=val;
        if(ptr==NULL) ptr = newnode;
        else if(val<ptr->data)ptr->left = insert_t(ptr->left, val);
        else ptr->right = insert_t(ptr->right, val);
        return ptr;
    }


    void insert_t(int val)
    {
        root = insert_t(root, val);
    }

    void Preorder(node* ptr)
    {
        if(ptr==NULL)return ;
        cout<<ptr->data<<'\t';
        Preorder(ptr->left);
        Preorder(ptr->right);
    }

    void Inorder(node*ptr)
    {
        if(ptr==NULL)return ;
        Inorder(ptr->left);
        cout<<ptr->data<<'\t';
        Inorder(ptr->right);
    }

    void Postorder(node*ptr)
    {
        if(ptr==NULL)return ;
        Postorder(ptr->left);
        Postorder(ptr->right);
        cout<<ptr->data<<'\t';
    }

    node* search_t(node* ptr, int num)
    {
        if(ptr == NULL)return NULL;
        else if(num<ptr->data)return search_t(ptr->left, num);
        else return search_t(ptr->right,num);
    }

    bool search_t(int num)
    {
        node* val = search_t(root, num);
        return val!=NULL;
    }

    node* MIN(node*ptr)
    {
        if(ptr == NULL)return NULL;
        else if(ptr->left==NULL)return ptr;
        else return MIN(ptr->left);
    }

    node* MAX(node*ptr)
    {
        if(ptr == NULL)return NULL;
        else if(ptr->right==NULL)return ptr;
        else return MAX(ptr->right);
    }

    node* DEL(node*ptr, int num)
    {
        if(ptr==NULL)return NULL;
        if(num<ptr->data)ptr->left=DEL(ptr->left, num);
        else if(num>ptr->data)ptr->right = DEL(ptr->right, num);
        else
        {
            if(ptr->left == NULL && ptr->right == NULL)ptr =NULL;
            else if(ptr->left != NULL && ptr->right == NULL)
            {
                ptr->data = ptr->left->data;
                delete ptr->left;
                ptr->left = NULL;
            }
            else if(ptr->left == NULL && ptr->right != NULL)
            {
                ptr->data = ptr->right->data;
                delete ptr->right;
                ptr->right = NULL;
            }
            else
            {
                node* MX =MAX(ptr->left);
                ptr->data = MX->data;
                ptr->left = DEL(ptr->left,MX->data);
            }
        }
        return ptr;
    }
};
BST t;
int n,a,b,c=0;
void insertt()
{

    c++;
    cout<<"Enter element in BST "<<c<<" : ";
    cin>>n;
    t.insert_t(n);
    c++;
    cout<<"Enter element in BST "<<c<<" : ";
    cin>>n;
    t.insert_t(n);
    c++;
    cout<<"Enter element in BST "<<c<<" : ";
    cin>>n;
    t.insert_t(n);
    c++;
    cout<<"Enter element in BST "<<c<<" : ";
    cin>>n;
    t.insert_t(n);
    c++;
    cout<<"Enter element in BST "<<c<<" : ";
    cin>>n;
    t.insert_t(n);
    c++;
    cout<<"Enter element in BST "<<c<<" : ";
    cin>>n;
    t.insert_t(n);
    c++;
    cout<<"Enter element in BST "<<c<<" : ";
    cin>>n;
    t.insert_t(n);
    c++;
    cout<<"Enter element in BST "<<c<<" : ";
    cin>>n;
    t.insert_t(n);
    c++;
    cout<<"Enter element in BST "<<c<<" : ";
    cin>>n;
    t.insert_t(n);
    c++;
    cout<<"Enter element in BST "<<c<<" : ";
    cin>>n;
    t.insert_t(n);
    c++;
    cout<<"Enter element in BST "<<c<<" : ";
    cin>>n;
    t.insert_t(n);
}
void pre()
{
    cout<<'\n'<<"this is items by Preorder : "<<'\n';
    t.Preorder(t.root);
    cout<<"\n------------------------------------------------------------------------------------------------------------------------";
}
void in()
{
    cout<<'\n'<<"this is items by Inorder : "<<'\n';
    t.Inorder(t.root);
    cout<<"\n------------------------------------------------------------------------------------------------------------------------";
}
void post()
{
    cout<<'\n'<<"this is items by Preorder : "<<'\n';
    t.Postorder(t.root);
    cout<<"\n------------------------------------------------------------------------------------------------------------------------";
}
void pre_del(node* ptr)
{
    cout<<'\n'<<"Preorder after delete "<<a<<" : "<<'\n';
    t.Preorder(ptr);
    cout<<"\n------------------------------------------------------------------------------------------------------------------------";

}
void in_del(node* ptr)
{
    cout<<'\n'<<"Inorder after delete "<<a<<" : "<<'\n';
    t.Inorder(ptr);
    cout<<"\n------------------------------------------------------------------------------------------------------------------------";
}
void post_del(node* ptr)
{
    cout<<'\n'<<"Preorder after delete "<<a<<" : "<<'\n';
    t.Postorder(ptr);
    cout<<"\n------------------------------------------------------------------------------------------------------------------------";
}
void mn(node* l)
{
    if(l==NULL)cout<<"Is not exist."<<'\n';
    else cout<<"\nthis is min item in BST : "<<l->data<<'\n';
}
void searchh()
{
    cout<<"\nEnter number to be search in BST : ";
    cin>>b;
    cout<<((!t.search_t(b))?"\nIS FOUND.":"\IS NOT FOUND.")<<'\n';
}
void mx(node* r)
{
    if(r==NULL)cout<<"Is not exist."<<'\n';
    else cout<<"\nthis is max item in BST : "<<r->data<<'\n';
}
int main()
{
    insertt();
    pre();
    in();
    post();
    cout<<"Enter number to be delete from BST : ";
    cin>>a;
    node* ptr = t.DEL(t.root,a);
    pre_del(ptr);
    in_del(ptr);
    post_del(ptr);
    searchh();
    node* r = t.MAX(t.root);
    mx(r);
    node* l = t.MIN(t.root);
    mn(l);
    return 0;
}
//khaled ibrahem