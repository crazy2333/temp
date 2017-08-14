
/*
	coursera
	algorithms-part1
 */

#include <iostream>
#include <vector>


using namespace std;




class dynamic_conn
{
public:
    dynamic_conn();
    ~dynamic_conn();
    
    
    
    
    void insert(int, int);
    bool check(int, int);
    bool check2(int, int);
    
    
    void u1(int,int);
    void u2(int,int);
    
    
    void printf();
    
    
private:
    vector<int> * v_data=NULL;
    
};

dynamic_conn::dynamic_conn()
{
    
    if (NULL==v_data)
    {
        v_data = new vector<int>;
        cout << "构造" << endl;
    }
}

dynamic_conn::~dynamic_conn()
{
    
    if (NULL != v_data)
    {
        delete v_data;
        cout << "析构" << endl;
    }
    
}


void dynamic_conn::insert(int l, int r)
{
    
    int min, max;
    if (l < r)
    {
        max = r;
        min = l;
    }
    else
    {
        max = l;
        min = r;
    }
    
    if (max + 1 > v_data->size())
    {
        for (max -= v_data->size(); max > -1; --max)
        {
            v_data->push_back(-1);
        }
    }
    
    u2(l,r);
    
    
    
}

bool dynamic_conn :: check(int l, int r)
{
    if ((*v_data)[l] == (*v_data)[r])
        return true;
    else
        return false;
}

bool dynamic_conn :: check2(int l, int r)
{
    while((*v_data)[l]!=l) l=(*v_data)[l];
    while((*v_data)[r]!=r) r=(*v_data)[r];
    if(l==r) return true;
    else return false;
}

void dynamic_conn::u1(int l,int r)
{
    
    if ((*v_data)[l] == -1 && (*v_data)[r] == -1)
    {
        (*v_data)[l] = (*v_data)[r] = l;
    }
    
    else if ((*v_data)[l] != -1 && (*v_data)[r] == -1)
    {
        (*v_data)[r] = (*v_data)[l];
    }
    
    else if ((*v_data)[l] == -1 && (*v_data)[r] != -1)
    {
        (*v_data)[l] = (*v_data)[r];
    }
    
    else if ((*v_data)[l] != -1 && (*v_data)[r] != -1)
    {
        
        if (count(v_data->begin(), v_data->end(), (*v_data)[l]) < count(v_data->begin(), v_data->end(), (*v_data)[r]))
        {
            int temp = (*v_data)[l];
            for (auto it=v_data->begin();it!=v_data->end();++it)
            {
                if (*it == temp) *it = (*v_data)[r];
            }
        }
        else
        {
            int temp = (*v_data)[r];
            for (auto & a:*v_data)
            {
                if (a == temp)
                {
                    a = (*v_data)[l];
                }
            }
        }
        
    }
    
}	

void dynamic_conn::u2(int l,int r)
{
    if ((*v_data)[l] == -1 && (*v_data)[r] == -1)
    {
        (*v_data)[l] = (*v_data)[r] = l;
    }
    
    else if ((*v_data)[l] != -1 && (*v_data)[r] == -1)
    {
        (*v_data)[r] = (*v_data)[l];
    }
    
    else if ((*v_data)[l] == -1 && (*v_data)[r] != -1)
    {
        (*v_data)[l] = (*v_data)[r];
    }
    
    else if ((*v_data)[l] != -1 && (*v_data)[r] != -1)
    {
        while((*v_data)[l]!=l) l=(*v_data)[l];
        while((*v_data)[r]!=r) r=(*v_data)[r];
        (*v_data)[r]=l;
    }

}


void dynamic_conn::printf()
{
    cout << "输出数组" << endl;
    for (auto a : *v_data)
    {		
        cout << a << endl;	
    }
    cout << "输出结束" << endl;
}



int main()
{
    dynamic_conn dc;
    
    dc.insert(0, 3);
    dc.insert(1, 7);
    dc.insert(1, 13);
    dc.insert(3, 5);
    dc.insert(2, 8);
    dc.insert(9, 11);
    dc.insert(2, 6);
    dc.insert(7, 9);
    dc.insert(6, 10);
    
    
    
    
    dc.printf();
    
    cout<<"check0,5:"<<dc.check2(0, 5)<<endl;
    
    cout << "check0,8:" << dc.check2(0, 8) << endl;
    
    cout << "check1,11:" << dc.check2(1, 11) << endl;
    
    
    
}

