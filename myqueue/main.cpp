
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
};

MyQueue::MyQueue():length(0){}
MyQueue::~MyQueue(){}

bool MyQueue::empty()
{
    if(length==0) return true;
    else return false;
}
int MyQueue::size(){return length;}
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
    if(length<=0) return;
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
    if(length==0) return 0;
    if(s1.empty()) 
    {
        return s2.top();
    }
    while(s1.size()!=1)
    {
        s2.push(s1.top());
        s1.pop();
    }
    return s1.top();

}
int MyQueue::back()
{
    if(length==0) return 0;
    if(s2.empty()) return s1.top();
    while(s2.size()!=1)
    {
        s1.push(s2.top());
        s2.pop();
    }
    return s2.top();
}



int main()
{
    MyQueue mq;
    
    cout<<"size1():"<<mq.size()<<endl;
    
    mq.push(1);
    mq.push(2);
    mq.push(3);
    mq.push(4);
    mq.push(5);
    mq.push(6);
    mq.push(7);
    mq.push(8);
    
    cout<<"size2():"<<mq.size()<<endl;
    cout<<"front2():"<<mq.front()<<endl;
    cout<<"back2():"<<mq.back()<<endl;

    mq.pop();
    mq.pop();


    cout<<"size3():"<<mq.size()<<endl;
    cout<<"front3():"<<mq.front()<<endl;
    cout<<"back3():"<<mq.back()<<endl;


      
    
    
}

