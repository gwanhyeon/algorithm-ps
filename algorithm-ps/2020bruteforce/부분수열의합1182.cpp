//
//  부분집합의합1182.cpp
//  algorithm-ps
//
//  Created by kgh on 2020/07/29.
//  Copyright © 2020 kgh. All rights reserved.
//
/*
#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
int n = 0;
int m = 0;
int ans = 0;
vector<int> res;
bool check[21];

void dfs(int sum,int idx, vector<int> v){
    
    if(res.size() > 0){
        
        int s = 0;
        
        for(int i=0; i<res.size(); i++){
            s += res[i];
        }
        if(s == m){
            ans +=1;
        }
    
    }
    
    for(int i=idx; i<n; i++){
        if(check[i] == true){
            continue;
        }
        check[i] = true;
        res.push_back(v[i]);
        dfs(sum,i, v);
        res.pop_back();
        check[i] = false;
    }
    
}
int main(void){
    
    
    cin >> n >> m;
    vector<int> v(n);
    
    for(int i=0; i<n; i++){
        cin >> v[i];
    }
    
    dfs(0,0,v);
    
    cout << ans;
    
    return 0;
}

 */

#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

int n,m = 0;
int cnt = 0;
int check[100001];
vector<int> res;

void dfs(vector<int> v, int sum, int idx){
    
    if(res.size() > 0){
        int ans = 0;
        for(int i=0; i<res.size(); i++){
            ans += res[i];
        }
        if(ans == m){
            cnt+=1;
        }
    }
    
    for(int i=idx; i<n; i++){
        if(check[i] == true){
            continue;
        }
        check[i] = true;
        res.push_back(v[i]);
        dfs(v,sum,i);
        check[i] = false;
        res.pop_back();
    }
}
int main(void){
    
    cin >> n >> m;
    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin >> v[i];
    }
    dfs(v,0,0);
    
    cout << cnt;
    return 0;
}


