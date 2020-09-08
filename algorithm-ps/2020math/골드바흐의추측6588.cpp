//
//  골드바흐의추측6588.cpp
//  algorithm-ps
//
//  Created by kgh on 2020/07/21.
//  Copyright © 2020 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;
const int MAX = 1000000;
bool check[MAX+1];
int cnt = 0;
int prime[MAX+1];
int main(void){
    // 이부분 없어서 시간초과 났음.
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // 에라토스테네체
    for(int i=2; i*i<=MAX; i++){
        if(check[i] == false){
            prime[cnt] = i;
            cnt++;
            for(int j=i+i; j<=MAX; j+=i){
                check[j] = true;
            }
        }
    }
    
    while(true){
        int t;
        cin >> t;
        if(t == 0){
            break;
        }
        
        // 0부터 진행해야 prime[0], [1], [2]순으로 진행된다.
        for(int i=0; i<cnt; i++){
            if(check[t-prime[i]] == false){
                cout << t << " = " << prime[i] << " + " << t-prime[i] << '\n';
                break;
            }
        }
    }
    
    return 0;
}
