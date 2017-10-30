// The Deque class should implement the following public methods:

// §  constructor – creates an empty deque

// §  copy constructor – a constructor that creates a deep copy of its constant Deque reference parameter

// §  destructor – deallocates dynamic memory allocated by the deque

// §  operator= – overloads the assignment operator for Deque – (deep) copies its constant Deque reference parameter into the calling object and returns a reference to the calling object after de-allocating any dynamic memory associated with the original contents of the calling object; if the calling object is the same as the parameter the operator should not copy it

// §  insertFront – inserts its parameter at the front of the deque

// §  insertBack – inserts its parameter at the back of the deque

// §  removeFront – removes and returns the value at the front of the deque; if the deque is empty throws a runtime_error (this error class is defined in the stdexcept library file)

// §  removeBack – removes and returns the value at the back of the deque; if the deque is empty throws a runtime_error

// §  peekFront – returns the value at the front of the deque without removing it; if the deque is empty throws a runtime_error

// §  peekBack – returns the value at the back of the deque without removing it; if the deque is empty throws a runtime_error

// §  empty – returns true if the deque is empty, false otherwise

// §  size – returns the number of items stored in the deque
#include "Deque.h"
Deque::Deque()
{
    thisSize = 0;
    top = new node;
    bottom = new node;
    top->thisInt = NULL;
    bottom->thisInt = NULL;
    top->right = bottom;
    bottom->left = top;

}

Deque::~Deque() {}

bool Deque::insertFront(int inInt)
{
    if (top->right == bottom)
    {
        top->thisInt = inInt;
        node *in = new node;
        top->left = in;
        in->right = top;
        thisSize++;
    }
    else
    {
        node *in = new node;
        in->left = NULL;
        in->thisInt = inInt;
        in->right = top;
        top->left = in;
        thisSize++;
    }
    return true;
}
bool Deque::insertBack(int inInt)
{
    if (bottom->left == top)
    {
        bottom->thisInt = inInt;
        node *in = new node;
        bottom->right = in;
        in->left = bottom;
        thisSize++;
    }
    else
    {
        node *in = new node;
        in->right = NULL;
        in->thisInt = inInt;
        in->left = bottom;
        bottom->right = in;
        thisSize++;
    }
}
void Deque::copyDeque(node *thisTop, node *inTop)
{
    if (inTop == NULL)
    {
        thisTop = NULL;
    }
    else
    {
        thisTop = new node;
        thisTop->thisInt = inTop->thisInt;
        copyDeque(thisTop->right, inTop->right);
    }
}
int Deque::removeFront() {}
int Deque::removeBack() {}
int Deque::peekFront() {
    return top->thisInt;
}
int Deque::peekBack() {
    return bottom->thisInt;
}
bool Deque::empty() {}
int Deque::size() { return thisSize; }
