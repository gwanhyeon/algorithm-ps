//
//  다음순열10972.cpp
//  algorithm-ps
//
//  Created by kgh on 2020/07/25.
//  Copyright © 2020 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;

int main(void){
    
    int n;
    cin >> n;
    vector<int> v(n);
    
    for(int i=0; i<n; i++){
        cin >> v[i];
    }
    // 1234 -> 1243
    if(next_permutation(v.begin(),v.end())){
        for(int i=0; i<n; i++){
            cout << v[i] << ' ';
        }
    }else {
        cout << "-1" << '\n';
    }
    return 0;
}
