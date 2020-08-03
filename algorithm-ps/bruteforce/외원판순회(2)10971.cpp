//
//  2외원판순회10971.cpp
//  algorithm-ps
//
//  Created by kgh on 2020/07/26.
//  Copyright © 2020 kgh. All rights reserved.

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int w[20][20];

int main(void){
    int n;
    cin >> n;
    vector<int> v(n);
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> w[i][j];
        }
    }
    
    for(int i=0; i<n; i++){
        v[i] = i;
    }
    int ans = 2147483647;
    do {
        
        bool tf = true;
        int sum = 0;
        
        for(int i=0; i<n-1; i++){
            if(w[v[i]][v[i+1]] == 0){
                tf = false;
            }else {
                sum += w[v[i]][v[i+1]];
            }
        }
        // 모든경로를 돌고 다시 경로로 돌아오는 경우 sum
        
        if(tf && w[v[n-1]][v[0]] != 0){
            sum += w[v[n-1]][v[0]];
            if(ans > sum){
                ans = sum;
            }
        }

    } while(next_permutation(v.begin(), v.end()));

    cout << ans << '\n';
    
    return 0;
}
