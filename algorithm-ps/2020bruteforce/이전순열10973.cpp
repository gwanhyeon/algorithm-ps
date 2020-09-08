//
//  이전순열10937.cpp
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
        cin >> v[i];
    }
    
    if(prev_permutation(v.begin(), v.end())){
        for(int i=0; i<n; i++){
            cout << v[i] << ' ';
        }
        
    }else {
        cout << "-1" << '\n';
    }
    
    return 0;
}
