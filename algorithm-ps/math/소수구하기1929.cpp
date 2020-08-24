//
//  소수구하기1929.cpp
//  algorithm-ps
//
//  Created by kgh on 2020/07/21.
//  Copyright © 2020 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;

int prime[1000001];
bool check[1000001];
int cnt = 0;

void Eratosthenes_Overflow(){
    int n,m;
       cin >> n >> m;
       check[0] = check[1] = true;
       for(int i=2; i<=m; i++){
           if(check[i] == false){
               prime[cnt] = i;
               cnt++;
               for(int j=i*i; j<=m; j+=i){
                   check[j] = true;
               }
           }
       }
       
       for(int i=n; i<=m; i++){
           if(check[i] == false){
               cout << i << '\n';
           }
       }
}

void Eratosthenes_None_Overflow(){
        int n,m;
       cin >> n >> m;
       check[0] = check[1] = true;
        // 오버플로우 방지 i*i
       for(int i=2; i*i<=m; i++){
           if(check[i] == false){
               prime[cnt] = i;
               cnt++;
               // 오버플로우 방지 i+i 이게 무슨뜻인지...오버플로우 방지시켜주는듯.. 전체 for문을 m으로 잡아버리니까 그 이상은 돌일이 없으니 
               for(int j=i+i; j<=m; j+=i){
                   check[j] = true;
               }
           }
       }
       
       for(int i=n; i<=m; i++){
           if(check[i] == false){
               cout << i << '\n';
           }
       }
}
int main(void){
    Eratosthenes_None_Overflow();

    return 0;
    
}
