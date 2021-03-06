//
//  암호만들기1759.cpp
//  algorithm-ps
//
//  Created by kgh on 2020/07/29.
//  Copyright © 2020 kgh. All rights reserved.
//
/*
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int l,c;
bool check[15];
vector<char> res;
void dfs(int cnt,int idx, vector<char> v){
    
    if(l == cnt){
        int ja=0;
        int mo=0;
        for(int i=0; i<res.size(); i++){
            if(res[i] == 'a' || res[i] == 'e' || res[i] == 'i' || res[i] == 'o' || res[i] == 'u'){
                mo +=1;
            }else {
                ja +=1;
            }
        }
        
        if(mo >=1 && ja >=2){
            for(int i=0; i<res.size(); i++){
                cout << res[i];
            }
            cout << '\n';
        }
        
        return;
    }
    
    for(int i=idx; i<v.size(); i++){
        if(check[i] == true){
            continue;
        }
        check[i] = true;
        res.push_back(v[i]);
        dfs(cnt+1,i, v);
        check[i] = false;
        res.pop_back();
    }
    
    
    
}
int main(void){
    
    cin >> l >> c;
    vector<char> v(c);
    
    for(int i=0; i<c; i++){
        cin >> v[i];
    }
    
    sort(v.begin(), v.end());
    dfs(0, 0, v);
    
     
    
    return 0;
}
*/


// 8.20 복습
#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;
int check[15];
vector<char> res;
int n,m = 0;
void dfs(vector<char> v,int idx,int cnt){
    
    if(n == cnt){
        // 값 출력
        int ja = 0;
        int mo = 0;
        
        for(int i=0; i<res.size(); i++){
            // (a, e, i, o, u)
            if(res[i] == 'a' || res[i] == 'e' || res[i] == 'i' || res[i] == 'o' || res[i] == 'u'){
                mo +=1;
            }else {
                ja +=1;
                
            }
        }
        
        if(ja >= 2 && mo >= 1){
            for(int i=0; i<res.size(); i++){
                cout << res[i];
            }
            cout << '\n';
        }
        
        return;
    }
    for(int i=idx; i<m; i++){
        if(check[i] == true){
            continue;
        }
        check[i] = true;
        res.push_back(v[i]);
        dfs(v, i, cnt+1);
        check[i] = false;
        res.pop_back();
    }
}
int main(void){
    
    cin >> n >> m;      // 4 , 6
    vector<char> v(m);
    
    for(int i=0; i<m; i++){
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    dfs(v,0,0);
    return 0;
    
}
