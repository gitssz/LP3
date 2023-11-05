#include<iostream>
#include<vector>
using namespace std;

// void fibonacci(int num){
//     int n1=0,n2=1;
//     int res;
//     cout<<n1<< " "<<n2<<" ";
//     for(int i=1;i<num;i++){
//         res = n1+n2;
//         cout<<res<<" ";
//         n1=n2;
//         n2=res;
//     }
// }

int fib_itr(int num){
    if(num<=1) return num;
    vector<int> n(num+1);
    n[0]=0,n[1]=1;
    for(int i=2;i<=num;i++){
        n[i] = n[i-1]+n[i-2];
    }
return n[num];
}


int fib_recursive(int num){
    if(num<=0) return 0;
    if(num<=1) return num;
    return fib_recursive(num-1)+fib_recursive(num-2);
}

int count_steps_rec(int n){
    if(n<=0) return 0;
    if(n==1) return 1;
    return 1 + count_steps_rec(n-1) + count_steps_rec(n-2);
}

int count_steps_itr(int n){
    if(n<=0) return 0;
    if(n==1) return 1;

    vector<int> steps(n+1);
    steps[0]=0, steps[1]=1;

    for(int i=2; i<n+1; i++){
        steps[i] = 1 + steps[i-1] + steps[i-2];
    }
    return steps[n];
}

int main(){

// fibonacci(5);
cout<<fib_itr(5)<<endl;
cout<<count_steps_itr(5)<<endl;
cout<<fib_recursive(5)<<endl;
cout<<count_steps_rec(5)<<endl;

    return 0;
}
