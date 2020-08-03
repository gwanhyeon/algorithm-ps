//
//  모든순열10974.cpp
//  algorithm-ps
//
//  Created by kgh on 2020/07/25.
//  Copyright © 2020 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(void){
    
    int n;
    cin >> n;
    vector<int> v(n);
    
    for(int i=0; i<n; i++){
        v[i] = i+1;
    }
    
    
    do {
        
        for(int i=0; i<n; i++){
            cout << v[i] << ' ';
            
            if(i == v.size()-1){
                cout << '\n';
            }
        }
    }while(next_permutation(v.begin(), v.end()));
    return 0;
}
