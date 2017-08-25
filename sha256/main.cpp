//
//  main.cpp
//  sha256version2
//
//  Created by mars on 2017/8/21.
//  Copyright © 2017年 mars. All rights reserved.
//

#include <iostream>
#include <string>
#include "sha256.h"

using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    
    
    cout<<"wellcome!\n"<<"输入加密字符："<<endl;
    string input;
    
    while(getline(cin,input))
    {
        
    
        unsigned char* temp=(unsigned char*)&(*input.begin());

        SHA256 sha(temp,input.size());
        
        uint32_t result[8];
        sha.get_hash(result);
        
        
        cout<<"\n\n得到hash值:\n";

        for(int i=0;i<8;++i)
        {
            printf("%x ",result[i]);
        }
        cout<<endl;
        cout<<"\n\n再输入加密字符："<<endl;
    }

    return 0;
}
