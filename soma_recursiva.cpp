#include<bits/stdc++.h>
using namespace std;

double func(int n){
	if (n==0)
	  return 0;
	return (n + func(n - 1));
}

int main(){
	int n;
	cin>>n;
	int C = func(n);
    cout << C << "\n";
    
	return 0;
}
