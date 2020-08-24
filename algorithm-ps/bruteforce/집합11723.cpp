//
//  집합11723.cpp
//  algorithm-ps
//
//  Created by kgh on 2020/07/30.
//  Copyright © 2020 kgh. All rights reserved.
//
/*
#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;
int main(void){
    int n;
    cin >> n;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int S = 0;
    while(n--){
        
        string str = "";
        int cmd = 0;
        cin >> str;
        if(str == "add"){
            cin >> cmd;
            cmd--;
            S = S | (1 << cmd);
        }else if(str == "check"){
            cin >> cmd;
            cmd--;
            if(S & (1<<cmd)){
                cout << "1" << '\n';
            }else {
                cout << "0" << '\n';
            }
        }else if(str == "remove"){
            cin >> cmd;
            cmd--;
            S = S & ~(1 << cmd);
        }else if(str == "all"){
            S = (1<<20)-1;
        }else if(str == "toggle"){
            cin >> cmd;
            cmd--;
            S = (S ^ (1<<cmd));
        }else if(str == "empty"){
            S = 0;
        }
        str.empty();
    }
    return 0;
}
*/

#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;
int main(void){
    int t;
    cin >> t;
    int s = 0;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    while(t--){
        string str = "";
        cin >> str;
        
        
        if(str == "add"){
            int num = 0;
            cin >> num;
            num--;
            s = s | (1 << num);
            
        }else if(str == "check"){
            int num = 0;
            cin >> num;
            num--;
            if(s & (1 << num)){
                cout << "1" << '\n';
            }else {
                cout << "0" << '\n';
            }
            
        }else if(str == "remove"){
            int num = 0;
            cin >> num;
            num--;
            s = s & ~(1 << num);
            
        }else if(str == "toggle"){
            int num = 0;
            cin >> num;
            num--;
            s = s ^ (1 << num);
            
        }else if(str == "all"){
            s = ((1 << 20) - 1);
        }else if(str == "empty"){
            s = 0;
        }
    }
    return 0;
}



