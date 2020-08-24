//
//  연산자끼워넣기14888(dfs).cpp
//  algorithm-ps
//
//  Created by kgh on 2020/07/30.
//  Copyright © 2020 kgh. All rights reserved.
//
/*
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
*/

// 8.20일 복습 -> 될것같은 로직인데 안됨.

/*

#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

vector<int> check;
vector<int> res;
int n = 0;
void dfs(int idx,int sum,vector<int> v){
    
    // basement
    if(idx == v.size()){
        res.push_back(sum);
        return;
    }
    if(check[idx] == 1 && idx > 0){
        dfs(idx+1,sum+v[idx], v);
        check[idx] = 0;
    }else if(check[idx] == 2 && idx > 0){
        dfs(idx+1, sum-v[idx], v);
        check[idx] = 0;
    }else if(check[idx] == 3 && idx > 0){
        dfs(idx+1,sum*v[idx], v);
        check[idx] = 0;
    }else {
        dfs(idx+1,sum/v[idx], v);
        check[idx] = 0;
    }
}
int main(void){
    
    cin >> n;
    vector<int> v(n);
    
    for(int i=0; i<n; i++){
        cin >> v[i];
    }
    for(int i=0; i<4; i++){
        int cal;
        cin >> cal;
        // + - * /
        
        if(i == 0){
            for(int j=0; j<cal; j++){
                check.push_back(1);
            }
            
        }else if(i == 1){
            for(int j=0; j<cal; j++){
                check.push_back(2);
            }
            
        }else if(i == 2){
            for(int j=0; j<cal; j++){
                check.push_back(3);
            }
            
        }else if(i == 3){
            for(int j=0; j<cal; j++){
                check.push_back(4);
            }
        }
    }
    
    dfs(1, v[0], v);
    
    
    int max = *max_element(res.begin(), res.end());
    int min = *min_element(res.begin(), res.end());
    cout << max << '\n'<< min;
    return 0;
}
*/

// 8.20 복습 로직(완성)

#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> res;
int n = 0;

void dfs(int sum,int idx, vector<int> v, int plus, int minus, int multi, int div){
    
    if(idx == v.size()){
        res.push_back(sum);
        return;
    }
    if(plus > 0){
        dfs(sum+v[idx], idx+1, v, plus-1, minus, multi, div);
    }
    if(minus > 0){
        dfs(sum-v[idx], idx+1, v, plus, minus-1, multi, div);
    }
    if(multi > 0){
        dfs(sum*v[idx], idx+1, v, plus, minus, multi-1, div);
    }
    if(div > 0){
        dfs(sum/v[idx], idx+1, v, plus, minus, multi, div-1);
    }
}
int main(void){
    
    cin >> n;
    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin >> v[i];
    }
    int plus = 0;
    int minus = 0;
    int multi = 0;
    int div =0;
    
    cin >> plus >> minus >> multi >> div;
    dfs(v[0],1,v,plus,minus,multi,div);
    
    int max = *max_element(res.begin(), res.end());
    int min = *min_element(res.begin(), res.end());
    cout << max << '\n' << min;
}
