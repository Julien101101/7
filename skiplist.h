// Julien Savary
// 04/10/2023
// Assignment 7 - Skip Lists
// A simple skip list that does insert, delete, and print

#ifndef SKIPLIST_H
#define SKIPLIST_H

#include <string>
#include <vector>
#include <random>
using namespace std;

class SkipList
{
private:
    // create a node struct
    struct Node
    {
        int key;
        string value;
        int height; // new field to track node height
        Node *next;
        Node *down;
        Node *up; // new field to point to node above
        Node *prev;
    };

    // create a new node
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    // create a head node for each level
    vector<Node *> heads;

    // create a tail node for each level
    vector<Node *> tails;

    // create a random number generator for determining node heights
    default_random_engine randGen;

    // create a distribution for the coin flip function
    uniform_real_distribution<double> coinDist;

    // create a function to create a new node
    Node *createNode(int key, string value, int height);

    // create a function to determine the height of a new node
    int getHeight();

public:
    // constructor
    SkipList();

    // destructor
    ~SkipList();

    // create a function to insert a new node
    void insert(int key, string value);

    // create a function to remove a node
    void remove(int);

    // create a function to find a node with a given key
    Node *find(int key);

    // create a function to print the skip list
    void print();

    // Method to get the size of the skip list
    int getSize();

    // Method to get the total number of nodes in the skip list
    int getNumNodes();

    // Method to print the number of nodes at each level of the skip list
    void printLevelCounts();
};

// constructor
SkipList::SkipList()
{
    // initialize the heads and tails for each level
    for (int i = 0; i < 16; i++)
    {
        Node *head = createNode(0, "", i);
        Node *tail = createNode(0, "", i);
        head->next = tail;
        heads.push_back(head);
        tails.push_back(tail);
    }

    // initialize the random number generator and distribution
    randGen = default_random_engine(0);
    coinDist = uniform_real_distribution<double>(0.0, 1.0);
}

// destructor
SkipList::~SkipList()
{
    // remove all nodes from the skip list
    Node *node = heads[0];
    while (node != nullptr)
    {
        Node *next = node->next;
        delete node;
        node = next;
    }
}

// create a function to create a new node
SkipList::Node *SkipList::createNode(int key, string value, int height)
{
    // create a new node with the specified key and value
    Node *node = new Node;
    node->key = key;
    node->value = value;
    node->height = height;
    node->next = nullptr;
    node->down = nullptr;
    node->up = nullptr; // initialize up pointer to null

    // return the new node
    return node;
}

void SkipList::remove(int key)
{
    Node *nodeToRemove = find(key);
    if (nodeToRemove == nullptr)
    {
        return; // key not found, do nothing
    }
    // remove the node from each level that it exists on
    while (nodeToRemove != nullptr)
    {
        Node *prev = nodeToRemove->prev;
        Node *next = nodeToRemove->next;
        prev->next = next;
        if (next != nullptr)
        {
            next->prev = prev;
        }
        Node *temp = nodeToRemove;
        nodeToRemove = nodeToRemove->down;
        delete temp;
    }
}

// create a function to determine the height of a new node
int SkipList::getHeight()
{
    // determine the height of the new node using a coin flip
    int height = 1;
    while (height < 16 && coinDist(randGen) < 0.5)
    {
        height++;
    }
    return height;
}

void SkipList::insert(int key, string value)
{
    // find the node where the new node should be inserted
    Node *curr = find(key);
    // create the new node and insert it at the bottom level
    Node *newNode = createNode(key, value, getHeight());
    newNode->next = curr->next;
    curr->next = newNode;
    newNode->down = curr; // set down pointer to node below

    // insert the new node at higher levels using a coin flip
    Node *prev = newNode;

    while (coinDist(randGen) < 0.5)
    {
        int level = prev->height + 1; // initialize level
        if (level >= heads.size())
        {
            Node *newHead = createNode(0, "", level);
            Node *newTail = createNode(0, "", level);
            newHead->next = newTail;
            newHead->down = heads.back();
            heads.push_back(newHead);
            tails.push_back(newTail);
        }
        while (curr->up == nullptr)
        {
            curr = curr->down;
        }
        curr = curr->up;
        newNode = createNode(key, value, level); // fixed line
        newNode->next = curr->next;
        curr->next = newNode;
        newNode->down = prev;
        prev->up = newNode; // set up pointer to node above
        prev = newNode;
    }
}
// create a function to find a node with a given key
SkipList::Node *SkipList::find(int key)
{
    // start at the top-left node
    Node *curr = heads.back();
    // traverse the skip list until the key is found or the end is reached
    while (true)
    {
        if (curr->next->key == key)
        {
            return curr->next;
        }
        else if (curr->next == tails.back())
        {
            if (curr->down == nullptr)
            {
                return curr;
            }
            else
            {
                curr = curr->down;
            }
        }
        else if (curr->next->key < key)
        {
            curr = curr->next;
        }
        else
        {
            if (curr->down == nullptr)
            {
                return curr;
            }
            else
            {
                curr = curr->down;
            }
        }
    }
}

// create a function to print the skip list
void SkipList::print()
{
    // start at the top-left node
    Node *curr = heads.back();
    // traverse the skip list level by level
    while (curr != nullptr)
    {
        Node *rowStart = curr;
        // print out the nodes in the current level
        while (curr != nullptr)
        {
            if (curr->key != 0)
            {
                printf("(%d, %s, %d) ", curr->key, curr->value.c_str(), curr->height);
            }
            curr = curr->next;
        }
        printf("\n");

        // move down to the next level
        curr = rowStart->down;
    }
}

int SkipList::getSize()
{
    // count the number of nodes at the bottom level
    Node *node = heads[0]->next;
    int size = 0;
    while (node != tails[0])
    {
        size++;
        node = node->next;
    }
    return size;
}

// Method to get the total number of nodes in the skip list
int SkipList::getNumNodes()
{
    int numNodes = 0;
    Node *curr = heads[0]->next;
    while (curr != tails[0])
    {
        numNodes++;
        curr = curr->next;
    }
    return numNodes;
}

#endif // SKIPLIST_H