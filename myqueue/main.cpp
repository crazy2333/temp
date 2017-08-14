
/*
	coursera
	algorithms-part1
 */

#include <iostream>
#include <stack>


using namespace std;


class MyQueue
{
public:

    MyQueue();
    ~MyQueue();

    bool empty();
    int size();
    void push(int);
    void pop();

    int front();
    int back();

private:
    stack<int> s1;
    stack<int> s2;

    int length;
    int * f;
    int * b;
};

    MyQueue::MyQueue():length(0){}
    MyQueue::~MyQueue(){}

    bool MyQueue::empty()
    {
        if(length==0) return true;
        else return false;
    }
    int MyQueue::size(){return length};
    void MyQueue::push(int i)
    {
        ++length; 
        while(!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
        s2.push(i);
    }
    void MyQueue::pop()
    {
        --length;
        if(s1.empty()) 
        {
            s2.pop();
            return;
        }
        while(s1.size()!=1)
        {
            s2.push(s1.top());
            s1.pop();
        }
        s1.pop();
    }

    int MyQueue::front()
    {


    }
    int MyQueue::back();



int main()
{

    

      
    
    
}

