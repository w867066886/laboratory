#include "paLouTi.h"
#include<iostream>
using namespace std;

int i = 0;
int f(int n) {
	if (n < 0) {
		i--;
		return 0;
	}
		if (n > 0) {
		i++;
		f(n - 2);
		f(n - 1);
	}
}
int main()
{		
	int n;
	while (1) {
		cin >> n;
		f(n);
		cout << i<<endl;
	}




}