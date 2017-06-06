#include <time.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define  N 500000000
int* tmp;
void mergesort(int *a, int L, int R) 
{
    int num = R - L + 1;
    int i, j, k, t,  rght,  rend,  m;
    for (int k=1; k < num; k *= 2 ) {       
        for (int left=0; left+k < num; left += k*2 ) {
            rght = left + k;        
            rend = rght + k;
            if (rend > num) rend = num; 
            m = 0; i = left; j = rght; 
            while (i < rght && j < rend) { 
                if (a[i] <= a[j]) {         
                    tmp[m++] = a[i++];
                } else {
                    tmp[m++] = a[j++];
                }
            }
            while (i < rght) { 
                tmp[m++]=a[i++]; 
            }
            while (j < rend) { 
                tmp[m++]=a[j++]; 
            }
            memcpy(a+left, tmp,  sizeof(int) * (rend-left));
        }
    }
}
int main () 
{
	int *arr = (int*) malloc(sizeof(int) * N);
	tmp = (int *) malloc(sizeof(int) * N);
	for(int i=0; i<N; ++i) arr[i] = rand() * 1.0;
	
		for(int i=N+1;i>N-10;i--)
			printf("A[%d]=%d\n",i,arr[i]);
		
	clock_t a1 = clock();
	mergesort(arr, 0, N-1);
	clock_t a2 = clock();
	printf("Time usage: %.2f\n", (float)(a2 - a1) / CLOCKS_PER_SEC);
	
		for(int i=N;i>N-10;i--)
			printf("A[%d]=%d\n",i,arr[i]);
			
			
	
	free(tmp);
	free(arr);
	return 0;
}
