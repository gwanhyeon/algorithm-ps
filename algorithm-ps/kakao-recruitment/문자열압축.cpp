//
//  문자열압축.cpp
//  algorithm-ps
//
//  Created by kgh on 2020/07/25.
//  Copyright © 2020 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;
int main(void){
    string s = "aabbaccc";
    char first;
    int answer = 0;
    string tmp = "";
    
    for(int i=0; i<s.size(); i++){
        int cnt = 0;
        first = s[i];
        
        for(int j=1; j<s.size(); j++){
            
            //
            if(first == s[j]){
                
            }else {
                tmp += s[j];
                cnt += 1;
            }
        }
        
        
        
        
        cout << s[i];
    }
    
    
    
    cout << answer << '\n';
    
    
    
    return 0;
}

