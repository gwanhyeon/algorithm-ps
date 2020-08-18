//
//  123더하기15988.cpp
//  algorithm-ps
//
//  Created by kgh on 2020/08/16.
//  Copyright © 2020 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;
long long memo[1000001];
const long long mod = 1000000009LL;
int main(void){
    int t;
    cin >> t;
    memo[0] = 1;
    for(int i=1; i<=1000000; i++){
        if(i-1 >= 0){
            memo[i] += memo[i-1];
        }
        if(i-2 >= 0){
            memo[i] += memo[i-2];
        }
        if(i-3 >= 0){
            memo[i] += memo[i-3];
        }
        memo[i] %= mod;
    }
    while(t--){
        int n=0;
        cin >> n;
        cout << memo[n] << '\n';
    }
    return 0;
}
