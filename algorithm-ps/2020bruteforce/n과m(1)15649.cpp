//
//  n과m(1)15649.cpp
//  algorithm-ps
//
//  Created by kgh on 2020/07/22.
//  Copyright © 2020 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
bool check[8];
int arr[8];
vector<int> v;
int n,m;
void dfs(int index){
    
    if(index == m){
        
        
        for(int i=0; i<v.size(); i++){
            cout << v[i] << ' ';
        }
        cout << '\n';
        return;
        
        
    }
    
    for(int i=1; i<=n; i++){
        if(check[i]){
            continue;
        }
        
        check[i] = true;
        v.push_back(i);
        //arr[index] = i;
        dfs(index+1);
        check[i] = false;
        v.pop_back();
    }
    
    
    
}
int main(void){
    
    cin >> n >> m;
    dfs(0);
    return 0;
}
