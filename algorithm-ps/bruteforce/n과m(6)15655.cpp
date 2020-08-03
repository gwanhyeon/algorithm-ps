//
//  n과m(6)15655.cpp
//  algorithm-ps
//
//  Created by kgh on 2020/07/23.
//  Copyright © 2020 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n,m;
int arr[10001];
bool check[10001];
vector<int> v;

void dfs(int idx, int cnt){
    if(cnt == m){
        for(int i=0; i<v.size(); i++){
            cout <<v[i] << ' ';
        }
        cout << '\n';
        return;
    }
    
    for(int i=idx; i<n; i++){
        if(check[i] == true){
            continue;
        }
        check[i] = true;
        v.push_back(arr[i]);
        dfs(i, cnt+1);
        check[i] = false;
        v.pop_back();
        
    }
}
int main(void){
    cin >> n >> m;
    
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    sort(arr,arr+n);
    
    dfs(0,0);
}

