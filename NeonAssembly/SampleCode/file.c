/* file.c */

#include <stdio.h>

unsigned int vector_add_of_n(unsigned int* ptr, unsigned int items)
{
unsigned int result=0;
unsigned int i;
for (i=0; i<(items*4); i+=1)
{
result+=ptr[i];
}
return result;
}


int main()
{
	return 0;
}
