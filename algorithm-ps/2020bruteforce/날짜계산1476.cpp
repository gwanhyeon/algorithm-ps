//
//  날짜계산1476.cpp
//  algorithm-ps
//
//  Created by kgh on 2020/07/21.
//  Copyright © 2020 kgh. All rights reserved.
//
/*
#include <stdio.h>
#include <iostream>
using namespace std;
int main(void){
    
    int e = 1;
    int s = 1;
    int m = 1;
    
    int res_e, res_s, res_m;
    cin >> res_e >> res_s >> res_m;
    
    int year = 1;
    
    while(true){
        
     
        
        if(e > 15){
            e = 1;
        }
        if(s > 28){
            s = 1;
        }
        
        if(m > 19){
            m = 1;
        }
        if(e == res_e && s == res_s && m == res_m){
                 cout << year << '\n';
                 break;
             }
        year += 1;
        e +=1;
        s +=1;
        m +=1;
    }

    return 0;
}



*/

#include <iostream>
#include <stdio.h>
using namespace std;
int main(void){
    int a=0;
    int b=0;
    int c=0;
    int e = 1;
    int s = 1;
    int m = 1;
    cin >> a >> b >> c;
    int cnt = 1;
    
    while(true){
        
        if(a == e && b == s && c == m){
            break;
        }
        e +=1;
        s +=1;
        m +=1;
        if(e > 15){
            e = 1;
        }
        if(s > 28){
            s = 1;
        }
        if(m > 19){
            m = 1;
        }
        
      
        cnt +=1;
    }
    cout << cnt << '\n';
    
    return 0;
    
}
