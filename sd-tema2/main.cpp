#include <bits/stdc++.h>
using namespace std;


struct Node{

    int key;
    Node *lchild;
    Node *nextsibling;

    Node():
        lchild(NULL), nextsibling(NULL) {}

    //add child and sibling
    void addchild(Node *n){
        if(lchild == NULL)
            lchild = n;
        else{
            n->nextsibling = lchild;
            lchild = n;
            }
        }

    //NOD NOU
    Node(int key0, Node *lchild0, Node *nextsibling0):
       key(key0), lchild(lchild0), nextsibling(nextsibling0) {}


};

bool Empty(Node *n)
{
    return (n == NULL);
}

// merge separat
Node *Merge(Node *a, Node *b)
{
    if (a == NULL) return b;
    if (b == NULL) return a;

    if(a->key < b->key)
    {
        a->addchild(b);
        return a;
    }
    else{
        b->addchild(a);
        return b;
    }

    return NULL;
}

//top for min
int top(Node *n)
{
    return n->key;
}

//insert nod nou
Node *Insert(Node *n, int key)
{
    return Merge(n, new Node(key, NULL, NULL));
}

//DELETE ROOT Node
Node *merge2(Node *n)
{
    if(n == NULL || n->nextsibling == NULL)
        return n;
    else{
        Node *a, *b, *nodnou;
        a = n;
        b = n->nextsibling;

        nodnou = n->nextsibling->nextsibling;

        a->nextsibling = NULL;
        b->nextsibling = NULL;
        return Merge(Merge(a,b), merge2(nodnou));

    }
    return NULL;
}

Node *Delete(Node *n)
{
    return merge2(n->lchild);
}

struct pairing_heap_func{
    Node *root;

    pairing_heap_func():
        root(NULL) {}

    bool Empty(void){
        return ::Empty(root);
    }

    int Top(void){
        return ::top(root);
    }

    void Insert(int key)
    {
        root = ::Insert(root, key);
    }

    void Lazydelete(void)
    {
        root = ::merge2(root);
    }

    void Delete(void)
    {
        root = ::Delete(root);
    }

    void Merge(pairing_heap_func ok)
    {
        root = ::Merge(root, ok.root);
    }
};

int main(void)
{
    pairing_heap_func heap;
    cout<<"give number:";
    int n;
    cin>>n;
    while( n != NULL)
    {
        switch(n)
        {
        case 1:
            cout<<"give insert number: ";
            int p;
            cin>>p;
            heap.Insert(p); //inserare
            break;

        case 2:
            cout<<"delete number: ";
            int p1;
            cin>>p1;
            heap.Lazydelete();
            break;

        case 3:
            cout<<heap.Top();
            cout<<endl; //minim
            break;

        case 4:
            heap.Delete(); //stergem minim
            break;

        }
        cout<<"another number: ";
        cin>>n;
    }
    return 0;
}



