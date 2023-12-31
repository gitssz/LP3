#include<iostream>
using namespace std;
int main(){
int capacity = 50;
int items = 3;
int price[items + 1] = {0,60,100,120};
int wt[items + 1] = {0,10,20,30};
int dp[items + 1][capacity + 1];
for(int i = 0; i <= items; i++){
for(int j = 0; j <= capacity; j++){
if(i == 0 || j == 0){
//There's nothing to add to Knapsack
dp[i][j] = 0;
}
else if(wt[i] <= j){
//Choose previously maximum or value of current item + value of remaining weight
dp[i][j] = max(dp[i - 1][j], price[i] + dp[i - 1][j -
wt[i]]);
}
else{
//Add previously added item to knapsack
dp[i][j] = dp[i - 1][j];
}
}
}
cout << "Maximum Profit Earned: " << dp[items][capacity] << "\n";
return 0;
}
