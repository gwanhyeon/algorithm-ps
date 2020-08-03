//
//  GCD합9613.cpp
//  algorithm-ps
//
//  Created by kgh on 2020/07/20.
//  Copyright © 2020 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;
int arr[101];
int gcd(int a,int b){
    
    if(b == 0){
        return a;
    }else {
        return gcd(b, a % b);
    }
}

int main(void){
    int t;
    cin >> t;
    for(int i=0; i<t; i++){
        int n;
        cin >> n;
        
        for(int j=0; j<n; j++){
            cin >> arr[j];
        }
        long long sum = 0;
        for(int z=0; z<n; z++){
            for(int q=z+1; q<n; q++){
                sum += gcd(arr[z], arr[q]);
            }
        }
        cout << sum << '\n';
    }
}
