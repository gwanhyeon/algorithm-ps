
//
//  소수만들기.cpp
//  algorithm-ps
//
//  Created by kgh on 2020/09/01.
//  Copyright © 2020 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
vector<bool> check;
bool isPrime(vector<int> v,int n){
   
    if(n < 2){
        return false;
    }
    
    for(int i=2; i*i<=n; i++){
        if(n % i == 0){
            return false;
        }
    }
    return true;
    
}
int main(void){
    vector<int> v{1,2,3,4};
    
    for(int i=0; i<3; i++){
        check.push_back(true);
    }
    for(int i=0; i<v.size()-3; i++){
        check.push_back(false);
    }
    int ans = 0;
    sort(check.begin(), check.end());
    do {
        int sum = 0;
        for(int i=0; i<v.size(); i++){
            if(check[i] == true){
                sum += v[i];
            }
        }
        bool tf = isPrime(v, sum);
        if(tf == true){
            ans+=1;
        }
    } while (next_permutation(check.begin(), check.end()));
    cout << ans << '\n';
    return 0;
}
