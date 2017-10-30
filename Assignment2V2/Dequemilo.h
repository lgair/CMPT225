#ifndef DEQUE_H_
#define DEQUE_H_
#include <cstdlib>
struct node
{
    node *left;
    node *right;
    int thisInt;
    node()
    {
        left = NULL;
        right = NULL;
        thisInt = NULL;
    }
    node(const node &inNode) : left(inNode.left), right(inNode.right), thisInt(inNode.thisInt) {}
};

class Deque
{

    //end node struct
private:
    int thisSize;
    node *top;
    node *bottom;

  public:
    Deque();

    Deque(const Deque &inDeque)
    {
        if (inDeque.top == NULL)//copying empty deque
        { 
            top = NULL;
            bottom = NULL;
            thisSize = 0;
        }
        else
        {
            copyDeque(this->top, inDeque.top);
        }
    }

    ~Deque();
    void copyDeque(node *thisTop, node *inTop);
    Deque & operator = (const Deque &obj);

    bool insertFront(int);
    bool insertBack(int);
    int removeFront();
    int removeBack();
    int peekFront();
    int peekBack();
    bool empty();
    int size();

}; //end class Deque

#endif /* DEQUE.H */