#include<bits/stdc++.h>
#include<iostream>
using namespace std;

void trocarComPonteiros(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;

}

int main(){

	int x = 10;
	int y = 20;
	
	std::cout << "Antes da troca: x = " << x << ", y = " << y << std::endl;
	
	trocarComPonteiros(&x, &y);
	
	std::cout << "Depois da troca: x = " << x << ", y = " << y << std::endl;
	
	return 0;
}