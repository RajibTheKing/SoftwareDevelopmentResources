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

r0 = sum
r1 = x
r2 = y
r3 = len
#increment r1 and r2 in each iteration
#decrement r3 as loop counter

AREA | .txt |, CODE, READONLY

EXPORT xcorr_kernel_neon

xcorr_kernel_neon PROC

VMOV.I32 q0, #0
CMP r3, #0
BLE xcorr_kernel_done
#Assume len > 0 and load y[0...3]
VLD1.16 {d3}, [r2]!
#If len <= 4, go to the end
SUBS r3, r3, #4
BLE xcorr_kernel_process4_done

xcorr_kernel_process4
	#j--
	SUBS r3, r3, #4
	#Load y[4...7]
	VLD1.16 {d4}, [r2]!
	VLD1.16 {d2}, [r1]!
	#Pull elements {i...i+3} from (d3,d4)
	VEXT.16 d5, d3, d4, #1
	VEXT.16 d6, d3, d4, #2
	VEXT.16 d7, d3, d4, #3
	#VMLAL = Vector MuLtiply and Accumulate Long
	VMLAL.S16 q0, d3, d2[0]
	VMLAL.S16 q0, d5, d2[1]
	VMLAL.S16 q0, d6, d2[2]
	VMLAL.S16 q0, d7, d2[3]
	VMOV d3, d4
	BGE xcorr_kernel_process4