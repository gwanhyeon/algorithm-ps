//
//  GCD합9613.cpp
//  algorithm-ps
//
//  Created by kgh on 2020/07/20.
//  Copyright © 2020 kgh. All rights reserved.
//
/*
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
*/



// gcd의 합 복습

#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;
/*
 3
 4 10 20 30 40
 3 7 5 12
 3 125 15 25
 */
int arr[1000001];
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
    
    while(t--){
        int n = 0;
        long long sum = 0;
        cin >> n;
        
        for(int i=0; i<n; i++){
            cin >> arr[i];
        }
        
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                sum += gcd(arr[i], arr[j]);
            }
        }
        cout << sum <<'\n';
        memset(arr, 0, sizeof(arr));
    }
    return 0;
}
