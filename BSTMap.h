#ifndef BST_H
#define BST_H
#include "structures.h"
template <class elemType>
class BST {

    struct node {
        int key;
        elemType value;
        node* left;
        node* right;
    };
    int maxSize;
    elemType* treeNodes;
    node* root;
    int size;


    node* makeEmpty(node* t) {
        if(t == NULL)
            return NULL;
        {
            makeEmpty(t->left);
            makeEmpty(t->right);
            delete t;
        }
        return NULL;
    }

    node* insert(int x, node* t, elemType obj)
    {
        if(t == NULL)
        {
            t = new node;
            t->key = x;
            t->value = obj;
            t->left = t->right = NULL;
        }
        else if(x < t->key)
            t->left = insert(x, t->left, obj);
        else if(x > t->key)
            t->right = insert(x, t->right, obj);
        return t;
    }

    node* findMin(node* t)
    {
        if(t == NULL)
            return NULL;
        else if(t->left == NULL)
            return t;
        else
            return findMin(t->left);
    }

    node* findMax(node* t) {
        if(t == NULL)
            return NULL;
        else if(t->right == NULL)
            return t;
        else
            return findMax(t->right);
    }

    node* remove(int x, node* t) {
        node* temp;
        if(t == NULL)
            return NULL;
        else if(x < t->key)
            t->left = remove(x, t->left);
        else if(x > t->key)
            t->right = remove(x, t->right);
        else if(t->left && t->right)
        {
            temp = findMin(t->right);
            t->key = temp->key;
            t->right = remove(t->key, t->right);
        }
        else
        {
            temp = t;
            if(t->left == NULL)
                t = t->right;
            else if(t->right == NULL)
                t = t->left;
            delete temp;
            size--;
        }

        return t;
    }

    void inorder(node* t) {
        if(t == NULL)
            return;
        inorder(t->left);
        treeNodes[t->key] = t->value;
        //std::cout << t->key << ":"<<t->value<< " ";
        inorder(t->right);
    }



    node* find(node* t, int x) {
        if(t == NULL)
            return NULL;
        else if(x < t->key)
            return find(t->left, x);
        else if(x > t->key)
            return find(t->right, x);
        else
            return t;
    }






public:
    BST() {
        root = NULL;
        maxSize =100;
        treeNodes= new elemType[maxSize]();
        size=0;

    }

    ~BST() {
        if(root !=NULL){
        root = makeEmpty(root);


        }
    }

    void insert(int x, elemType obj) {
        node * temp = find(root, x);
        if(temp != NULL)
        {
            temp->value = obj;
        }
        else
        {
            root = insert(x, root, obj);
            size++;
        }
    }

    void remove(int x) {
        root = remove(x, root);
    }

    void display() {
        inorder(root);
        //std::cout << endl;
    }

    void search(int x) {
        root = find(root, x);
    }

    void destroyTree() {
        makeEmpty(root);
        root = NULL;
        delete [] treeNodes;
        size =0;
    }

    int getBSTSize(){
        return size;
    }

    int getSize(){return size;}

    elemType* getTreeNodes()
    {
        return treeNodes;
    }
};

#endif // BST_H
