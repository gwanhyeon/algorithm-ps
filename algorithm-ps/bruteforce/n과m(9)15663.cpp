//
//  n과m(9)15663.cpp
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
vector<int> v;
vector<vector<int>> res;
int arr[10001];
bool check[10001];

void dfs(int idx, int cnt){
    if(cnt == m){
        vector<int> tmp;
        for(int i=0; i<v.size(); i++){
            tmp.push_back(v[i]);
        }
        res.push_back(tmp);
        return;
    }
    
    for(int i=0; i<n; i++){
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
int main(void)
{
    cin >> n >> m;
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    sort(arr,arr+n);
    dfs(0,0);
    sort(res.begin(), res.end());
    res.erase(unique(res.begin(),res.end()),res.end());
    for(auto &a : res){
        for(int i=0; i<a.size(); i++){
            cout << a[i];
            if(i != m-1){
                cout << ' ';
            }
        }
        cout << '\n';
    }

    return 0;
}
