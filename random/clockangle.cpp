#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	int hh,mm;
	scanf("%d:%d",&hh,&mm);
	//cout << hh+1 << " " << mm-1 << "\n";
	int dist = abs(hh - mm/5) * 30;
	float tilt = (float)mm * 0.5;
	float res;
	if( hh >= mm/5 )
		 res = (float)dist + tilt;
	else res = (float)dist - tilt;
	if(res > 180) res = (float)360 - res;
	cout << res << "\n";
	return 0;
}
