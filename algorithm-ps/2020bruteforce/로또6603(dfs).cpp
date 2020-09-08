//
//  로또6603(dfs).cpp
//  algorithm-ps
//
//  Created by kgh on 2020/07/29.
//  Copyright © 2020 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
bool check[13];
vector<int> res;
void dfs(int cnt, int idx, int n, vector<int> v){
    if(cnt == 6){
        sort(res.begin(), res.end());
        for(int i=0; i<res.size(); i++){
            cout << res[i] << ' ';
        }
        cout << '\n';
        return;
    }
    
    for(int i=idx; i<v.size(); i++){
        if(check[i] == true){
            continue;
        }
        check[i] = true;
        res.push_back(v[i]);
        dfs(cnt+1, i, n, v);
        check[i] = false;
        res.pop_back();
    }
    
}

int main(void){
    while(true){
        int n = 0;
        cin >> n;
        vector<int> v(n);
        
        if(n == 0){
            break;
        }
        for(int i=0; i<v.size(); i++){
            cin >> v[i];
        }
        dfs(0, 0, n, v);
        res.clear();
        v.clear();
        memset(check,0,sizeof(check));
        cout << '\n';
        
        
    }
    
    
    return 0;
}
