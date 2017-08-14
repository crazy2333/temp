//
//  Stack.hpp
//  dynconn
//
//  Created by mars on 2017/8/14.
//  Copyright © 2017年 mars. All rights reserved.
//

#ifndef Stack_hpp
#define Stack_hpp

#include <stdio.h>

template<typename T>
class Stack
{
public:
    Stack();
    ~Stack();
    
    void push(T);
    void pop();
    bool empty();
    int size();
    T * top();

    
private:
    T * arr=nullptr;
    int length;
    int maxL;

};

template<typename T>
Stack<T>::Stack()
{
    if(nullptr==arr)
    {
        arr=new T [10];
        length=0;
        maxL=10;
    }


}

template<typename T>
Stack<T>::~Stack()
{
    if(nullptr==arr)
    {
        delete [] arr;
    }



}
template<typename T>
void Stack<T>::push(T t)
{
    if(length==maxL)
    {
        maxL*=2;
        length ++;
        int * temp=new T [maxl];
        int * l=temp;
        int * r=arr;
        while(0!=*l++=*r++);
        *l=t;
        delete [] arr;
        arr=temp;
    }
    else
    {
        arr[length++]=t
    }

}

template<typename T>
void Stack<T>::pop()
{
    
}

template<typename T>
bool Stack<T>::empty()
{
    if(length==0) return true;
    else return false;
}

template<typename T>
int Stack<T>::size()
{
    return length;
}

template<typename T>
T * Stack<T>::top()
{}








#endif /* Stack_hpp */
