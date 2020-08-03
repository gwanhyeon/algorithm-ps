//
//  차이를최대로10819.cpp
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
int main(void){
    int n;
    cin >>n;
    vector<int> v(n);
    int ans = 0;
    for(int i=0; i<n; i++){
        cin >> v[i];
    }
    
    sort(v.begin(), v.end());
    do {
        int res = 0;
        for(int i=0; i<n-1; i++){
            
            res += abs(v[i] - v[i+1]);
        }
        if(ans < res){
            ans = res;
        }
    } while (next_permutation(v.begin(), v.end()));
    
    cout << ans << '\n';
        
}
