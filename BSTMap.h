#ifndef BST_H
#define BST_H
#include "structures.h"
template <class elemType>
class BST {

    /**
     * @brief The TeamType struct represents the trip information
     * stored for fan
     *
     * TeamType_ containing the teamID, and team name,
     */
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

public:

    /**
     * @brief Default constructor
     */
    BST() {
        root = NULL;
        maxSize =100;
        treeNodes= new elemType[maxSize]();
        size=0;

    }

    /**
     * @brief Destructor
     */
    ~BST() {
        if(root !=NULL){
        root = makeEmpty(root);


        }
    }

    /**
     * @brief Function to insert new object into tree
     * @param key: integer key of node
     * @param obj: object to be inserted
     *
     */

    void insert(int key, elemType obj) {
        node * temp = find(root, key);
        if(temp != NULL)
        {
            temp->value = obj;
        }
        else
        {
            root = insert(key, root, obj);
            size++;
        }
    }

    /**
     * @brief Function to remove object from tree
     * @param key: integer key of node
     *
     */

    void remove(int key) {
        root = remove(key, root);
    }


    /**
     * @brief Function to display object from tree
     */

    void display() {
        inorder(root);
        //std::cout << endl;
    }


    /**
     * @brief Function to search object
     * @param key: integer key of node
     *
     */

    void search(int key) {
        root = find(root, key);
    }


    /**
     * @brief Function to destroy tree
     *
     */

    void destroyTree() {
        makeEmpty(root);
        root = NULL;
        delete [] treeNodes;
        size =0;
    }

    /**
     * @brief Function to get tree size
     * @return size
     */

    int getBSTSize(){
        return size;
    }

    /**
     * @brief Function to get tree size
     * @return size
     */
    int getSize(){return size;}

    /**
     * @brief Function get tree nodes
     * @return pointer to first node
     */

    elemType* getTreeNodes()
    {
        return treeNodes;
    }

private:

    /**
     * @brief Function empty tree
     * @param node: pointer to node to be deleted
     *
     */

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


    /**
     * @brief Function to insert new object into tree
     * @param key: integer key of node
     * @param node: pointer to position that will be used to insert new object
     * @param obj: object to be inserted
     * @return pointer to new element
     */

    node* insert(int key, node* t, elemType obj)
    {
        if(t == NULL)
        {
            t = new node;
            t->key = key;
            t->value = obj;
            t->left = t->right = NULL;
        }
        else if(key < t->key)
            t->left = insert(key, t->left, obj);
        else if(key > t->key)
            t->right = insert(key, t->right, obj);
        return t;
    }


    /**
     * @brief Function to insert new object into tree
     * @param key: integer key of node
     * @param node: pointer to position that will be used to insert new object
     * @param obj: object to be inserted
     * @return pointer to new element
     */

    node* findMin(node* t)
    {
        if(t == NULL)
            return NULL;
        else if(t->left == NULL)
            return t;
        else
            return findMin(t->left);
    }


    /**
     * @brief Function to find maximum node
     * @param ptr: integer key of node
     * @return pointer to max element
     */

    node* findMax(node* ptr) {
        if(ptr == NULL)
            return NULL;
        else if(ptr->right == NULL)
            return ptr;
        else
            return findMax(ptr->right);
    }

    /**
     * @brief Function to remove node
     * @param ptr: integer key of node
     * @param key: element key
     * @return pointer to max element
     */

    node* remove(int key, node* ptr) {
        node* temp;
        if(ptr == NULL)
            return NULL;
        else if(key < ptr->key)
            ptr->left = remove(key, ptr->left);
        else if(key > ptr->key)
            ptr->right = remove(key, ptr->right);
        else if(ptr->left && ptr->right)
        {
            temp = findMin(ptr->right);
            ptr->key = temp->key;
            ptr->right = remove(ptr->key, ptr->right);
        }
        else
        {
            temp = ptr;
            if(ptr->left == NULL)
                ptr = ptr->right;
            else if(ptr->right == NULL)
                ptr = ptr->left;
            delete temp;
            size--;
        }

        return ptr;
    }


    /**
     * @brief Function to display inorder traversal
     * @param ptr: integer key of node
     */

    void inorder(node* ptr) {
        if(ptr == NULL)
            return;
        inorder(ptr->left);
        treeNodes[ptr->key] = ptr->value;
        //std::cout << t->key << ":"<<t->value<< " ";
        inorder(ptr->right);
    }



    /**
     * @brief Function to find node
     * @param ptr: integer key of node
     * @param key: element key
     * @return pointer to element
     */
    node* find(node* ptr, int key) {
        if(ptr == NULL)
            return NULL;
        else if(key < ptr->key)
            return find(ptr->left, key);
        else if(key > ptr->key)
            return find(ptr->right, key);
        else
            return ptr;
    }







};

#endif // BST_H
