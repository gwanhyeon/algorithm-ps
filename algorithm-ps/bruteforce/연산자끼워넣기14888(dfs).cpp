//
//  연산자끼워넣기14888(dfs).cpp
//  algorithm-ps
//
//  Created by kgh on 2020/07/30.
//  Copyright © 2020 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
vector<int> res;
void dfs(vector<int> v, int idx, int sum, int plus, int minus, int multi, int div){
    
    
    if(idx == v.size()){
        res.push_back(sum);
        return;
    }
  
    if(plus > 0){
        dfs(v, idx+1, sum+v[idx], plus-1, minus, multi,div);
    }
    if(minus > 0){
        dfs(v, idx+1, sum-v[idx], plus,minus-1,multi, div);
    }
    if(multi > 0){
        dfs(v, idx+1, sum*v[idx], plus, minus, multi-1, div);
    }
    if(div > 0){
        dfs(v, idx+1, sum/v[idx], plus, minus, multi, div-1);
    }
    
    
    
    
}
int main(void){
    
    cin >> n;
    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin >> v[i];
    }
    
    int plus, minus, multi, div;
    cin >> plus >> minus >> multi >> div;
    
    dfs(v, 1, v[0], plus,minus, multi, div);
    
    
    int max = *max_element(res.begin(), res.end());
    int min = *min_element(res.begin(), res.end());
    
    cout << max << '\n' << min << '\n';
    
    
    
    return 0;
}
