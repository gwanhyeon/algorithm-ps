//
//  123더하기9095.cpp
//  algorithm-ps
//
//  Created by kgh on 2020/07/24.
//  Copyright © 2020 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;
int main(void){
    int t;
    int num;
    cin >> t;
    
    
    
    while(t--){
        int cnt = 0;
        cin >> num;
        
        for(int l1=1; l1<=3; l1++){
            if(l1 == num){
                cnt +=1;
            }
            for(int l2=1; l2<=3; l2++){
                if(l1 + l2 == num){
                    cnt +=1;
                }
                for(int l3=1; l3<=3; l3++){
                    if(l1 + l2 + l3 == num){
                        cnt +=1;
                    }
                    
                    for(int l4=1; l4<=3; l4++){
                        if(l1 + l2 + l3 + l4 == num){
                            cnt +=1;
                        }
                        
                        for(int l5=1; l5<=3; l5++){
                            if(l1 + l2 + l3 + l4 + l5 == num){
                                cnt +=1;
                            }
                            
                            for(int l6=1; l6<=3; l6++){
                                if(l1 + l2 + l3 + l4 + l5 + l6 == num){
                                    cnt +=1;
                                }
                                
                                for(int l7=1; l7<=3; l7++){
                                    if(l1 + l2 + l3 + l4 + l5 + l6 + l7 == num){
                                        cnt +=1;
                                    }
                                    
                                    for(int l8=1; l8<=3; l8++){
                                        if(l1 + l2 + l3 + l4 + l5 + l6 + l7 + l8 == num){
                                            cnt +=1;
                                        }
                                        
                                        for(int l9=1; l9<=3; l9++){
                                            if(l1 + l2 + l3 + l4 + l5 + l6 + l7 + l8 + l9 == num){
                                                cnt +=1;
                                            }
                                            
                                            for(int l10=1; l10<=3; l10++){
                                                if(l1 + l2 + l3 + l4 + l5 + l6 + l7 + l8 + l9 + l10 == num){
                                                    cnt +=1;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
            
            
        }
        cout << cnt << '\n';
    }
    
    return 0;
}
