//
//  123더하기9095(dfs).cpp
//  algorithm-ps
//
//  Created by kgh on 2020/07/28.
//  Copyright © 2020 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
int cnt = 0;


int dfs(int target, int sum){
    if(sum == target){
        return 1;
    }
    
    if(sum > target){
        return 0;
    }
    
    return dfs(target,sum+1) + dfs(target,sum+2) + dfs(target,sum+3);
        
}
int main(void){
    
    int t;
    cin >> t;
    vector<int> v(t);
    for(int i=0; i<t; i++){
        cin >> v[i];
    }
    
    for(int i=0; i<v.size(); i++){
        cout << dfs(v[i], 0) << '\n';
    }

    return 0;
}
