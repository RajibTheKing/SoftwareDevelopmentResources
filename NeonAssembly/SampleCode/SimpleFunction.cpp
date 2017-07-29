#include <iostream>
using namespace std;

#include <arm_neon.h>

/*

// void sfNEONbad(unsigned short * pDst, short * pSrc, short coeff, short intercept, unsigned int count);
.code 32
.globl _sfNEONbad
.private_extern _sfNEONbad
 
pDst    .req    r0
pSrc    .req    r1
coeff   .req    r2
interc  .req    r3
count   .req    r12
 
.align 2
_sfNEONbad:
.cfi_startproc
 ldr     count, [sp]
 vdup.16 d0, coeff
 vdup.16 d1, interc
 
 1:
  vld1.16   {d2}, [pSrc]!
  vmull.s16  q1, d2, d0[0]
  vaddw.s16  q1, q1, d1
  vqrshrun.s32 d2, q1, #8
  vst1.16   {d2}, [pDst]!
  subs   count, count, #4
 bgt     1b
bx      lr
.cfi_endproc
*/

void sfC(unsigned short * pDst, unsigned short * pSrc, short coeff, short intercept, unsigned int count)
{
	int res;
	do {

		res = *pSrc++ * coeff + intercept;
		cout<<"Now Res1 = "<<res<<endl;

		if (res & 0x80) 
		{
			res += 256;
			cout<<"Now Res2 = "<<res<<endl;
		}

		
		res >>= 8;
		cout<<"Now Res3 = "<<res<<endl;

		if (res < 0) 
		{
			res = 0;
			cout<<"Now Res4 = "<<res<<endl;
		}
		

		if (res>0xffff)
		{
			res = 0xffff;
			cout<<"Now Res5 = "<<res<<endl;
		}

		*pDst++ = (unsigned short) res;
		cout<<"Finally Res6 = "<<*(pDst-1)<<endl;

	} while (--count);

	cout<<endl;
	
	float a = 10.12;
    int y;

    __asm__(
    	"fcvtzs %w0, %s1\n\t" : "=r"(y) : "w"(a)
    	);
    
    cout<<"here Y = "y<<endl;
}

#define MX 10
int main()
{
	unsigned short *dst = new unsigned short[MX];
	unsigned short *src = new unsigned short[MX];

	for(int i=0; i<MX;i++)
	{
		src[i] = i*i;
	}

	short coeff = 5;
	short intercept = 2;
	unsigned int count = MX;

	sfC(dst, src, coeff, intercept, count);
	return 0;
}