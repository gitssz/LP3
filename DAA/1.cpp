#include<iostream>
#include<vector>
using namespace std;

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

 int n;
    cout << "Enter the length of series: ";
    cin >> n;
    int choice = 1;
    do
    {
        cout << "***Enter your choice***" << endl;
        cout << "[1] Recursive" << endl;
        cout << "[2] Iterative" << endl;
        cout << "[3] ESC" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            cout<<"fibonacci series: "<<fib_recursive(n)<<endl;
            cout<<"step count of recursive function: "<<count_steps_rec(n)<<endl;
            break;
        }
        case 2:
        {
            cout<<"fibonacci series: "<<fib_itr(n)<<endl;
            cout<<"step count of recursive function: "<<count_steps_itr(n)<<endl;;
            break;
        }
        default:
            break;
        }
    } while (choice != 3);
    return 0;
}
