#include <bits/stdc++.h> 
int findMinimumCoins(int amount) 
{
    // Write your code here
   int a[]={1,2,5,10,20,50,100,500,1000};
   int coins=0;
   int i=8;
   while(amount && i>=0){
       if(amount<a[i]){
           i--;
           continue;
       }
       coins++;
       amount-=a[i];
   }
   return coins;
}
