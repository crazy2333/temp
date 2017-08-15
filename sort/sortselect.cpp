

#include <iostream>

using namespace std;

void print(int * arr,int length)
{
    for(int i=0;i<length;++i)
    {
        cout<<arr[i]<<":";
    }
    cout<<endl;
}

void select(int * arr,int length)
{
    for(int i=0;i<length-1;++i)
    {
        for(int j=i+1;j<length;++j)
        {
            if(arr[i]>arr[j]) 
            {
                int temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
    print(arr,10);
}

void insert(int * arr,int length)
{

    for(int i=1;i<length;++i)
    {
        int temp=arr[i];
        int j=i-1;
        while(j>=0&&arr[j]>temp)
        {
            arr[j+1]=arr[j];
            --j;
        }
        arr[j+1]=temp;
    }
    print(arr,10);

}

 void shell(int * arr,int length)
 {
    int gap=length;
    
    while(gap>1)
    {
        gap=gap/3+1;
        
        for(int i=gap;i<length;++i)
        {
        int temp=arr[i];
        int j=i-gap;

        while(j>=0&&arr[j]>temp)
        {
            arr[j+gap]=arr[j];
            j-=gap;
        }
        arr[j+gap]=temp;

        }
        break;
    }


    print(arr,10);


 }

 void ShellSort(int * a,size_t n)//希尔排序  
 {  
 
     int gap = n;//gap为所给增量  
     while(gap > 1)  
     {  
         //实验证明，gap=gap/3是比较优的，+1则是为了最后一次对全体数据进行插入排序  
         gap = gap/3 + 1;  
         for (size_t i = gap; i < n; ++i)  
         {  
             int end = i - gap;  
             int tmp = a[i];  
   
             while(end >= 0)  
             {  
                 if (tmp<a[end])  
                 {  
                     a[end+gap] = a[end];  
                     end -= gap;  
                 }  
                 else  
                 {  
                     break;  
                 }  
             }  
             a[end+gap] = tmp;  
         }  
     }  
     print(a,10);
 }  


int main()
{
    int arr[10]={2,5,4,9,3,6,8,7,1,0};

    // select(arr,10);
    // insert(arr,10);
    shell(arr,10);
    // ShellSort(arr,10);
  



}