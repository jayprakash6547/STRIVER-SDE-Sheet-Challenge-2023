#include<bits/stdc++.h>
bool isValidParenthesis(string s) {
        vector <char> stack ; 
        int i ; 
      
        for(i = 0 ; i < s.size() ; i++){
            if(s[i] == '(' || s[i] == '{' || s[i] == '['){
                stack.push_back(s[i]) ; 
            }
            else{
                if(stack.size() == 0 ){
                    return false ; 
                }
                else{
                    if(stack[stack.size() - 1 ] == '(' ){
                        if(s[i] != ')'){
                            return false ; 
                        }
                    }
                    else if(stack[stack.size() - 1 ] == '{' ){
                         if(s[i] != '}'){
                            return false ; 
                        }
                    }
                    else if(stack[stack.size() - 1 ] == '[' ){
                        if(s[i] != ']'){
                            return false ; 
                        }
                    }
                    
                    
                    stack.pop_back() ; 
                        
                    
                }
            }
        }
        if(stack.size() == 0 ){
            return true  ; 
        }
        else{
            return false  ; 
        }
        
    }