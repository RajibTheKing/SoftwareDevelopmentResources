#include <iostream>
using namespace std;

void xcorr_kernel(int sum[4], const short *x, const short *y, int len)
{

	for(int i = 0; i<4; i++)
	{
		sum[i] = 0;
		for(int j=0; j<n; j++)
		{
			sum[i] += x[j] * y[i+j];
		}
	}
}




int main()
{
	
	return 0;
}