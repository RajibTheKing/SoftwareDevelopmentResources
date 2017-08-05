#include <iostream>
using namespace std;

int main()
{
	/*unsigned int len = 27;
	unsigned int var = ~3;
	cout<<var<<endl;
	cout<<(len&~3)<<endl;*/

	const char *p1 = "Hell00000000000";
	const char *p2 = "Hell00000000000";
	cout<<p1<<", "<<p2<<endl;

	if(p1 == p2)
	{
		cout<<"Yes"<<endl;
	}
	else
	{
		cout<<"No"<<endl;

	}

	const unsigned char p3[] = "Hello" ;
	const unsigned char p4[] = "Hello" ;

	int arr[100];

	if(p3 == p4)
	{
		cout<<"Yes"<<endl;
	}
	else
	{
		cout<<"No"<<endl;

	}


	//cout<<typeof(p1)<<endl;

	int *a;


	cout<<strlen(p1)<<endl;
	cout<<sizeof(p1)<<endl;


	cout<<sizeof(p3)<<endl;
	cout<<sizeof(arr)/sizeof(int)<<endl;

	cout<<sizeof(a)<<endl;


	return 0;
}