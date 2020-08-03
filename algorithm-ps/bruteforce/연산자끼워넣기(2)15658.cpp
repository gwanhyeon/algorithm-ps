//
//  연산자끼워넣기(2)15658.cpp
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
vector<int> res;
void dfs(int idx, vector<int> v, int sum, int plus, int minus, int multi, int div){
    
    if(idx == v.size()){
        res.push_back(sum);
        return;
    }
    if(plus > 0){
        dfs(idx+1, v, sum+v[idx], plus-1, minus, multi, div);
    }
        
    if(minus > 0){
        dfs(idx+1, v, sum-v[idx], plus, minus-1, multi, div);
    }
        
    if(multi > 0){
        dfs(idx+1, v, sum*v[idx], plus, minus ,multi-1, div);
    }
        
    if(div > 0){
        dfs(idx+1, v, sum/v[idx], plus, minus, multi, div-1);
    }
        
}

int main(void){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin >> v[i];
    }
    
    int plus = 0;
    int minus = 0;
    int multi = 0;
    int div = 0;
    
    for(int i=0; i<4; i++){
        int cal;
        cin >> cal;
        if(i==0){
            plus = cal;
        }else if(i==1){
            minus = cal;
        }else if(i==2){
            multi = cal;
        }else {
            div = cal;
        }
    }
    
    dfs(1, v , v[0], plus, minus, multi, div);
    
    int max = *max_element(res.begin(), res.end());
    int min = *min_element(res.begin(), res.end());
    
    cout << max << '\n' << min << '\n';
    
    
}
