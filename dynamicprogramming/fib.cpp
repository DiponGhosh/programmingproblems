/*  fib.cpp
 *  to get the nth fibonacci number
 */


#include <bits/stdc++.h>
#define MAX 100

using namespace std;

int  fib[MAX];

int main()
{
	ios_base::sync_with_stdio(false);
	
	int	 n;
	fib[1] = 0;  
	fib[2] = 1;

	cin >> n;

	for(int i = 3; i<=n; i++)
		fib[i] = fib[i-1] + fib[i-2];

	cout << fib[n] << endl;

	return 0;

}
