#include <time.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define  N 200000000
int*L=(int *) malloc(sizeof(int) *(N/2+1)); //int L[N/2+1]; L¡¢RµÄÔªËØ¸öÊý²»³¬¹ýN/2+1 
int*R=(int *) malloc(sizeof(int) * (N/2+1));
void MERGE(int *A, int p, int q, int r)
{
	
	int i,j,k;
	int n1=q-p+1;
	int n2=r-q;
	
	for (i=1;i<=n1;i++)
  	  L[i-1]=A[p+i-1];
	
	for (j=1;j<=n2;j++)
    	R[j-1]=A[q+j];   

	i=0;j=0;
	for (k=p;k<=r;k++)
 	{
		if (i<n1 && (j==n2 || L[i]<R[j]))
 	    {A[k]=L[i]; i++;}
  	else
  	  {A[k]=R[j]; j++;}
	}
}

void mergeSort(int *A,int p,int r)
{
	int q;
	if (p<r)
	 {
	 q=(p+r)/2;
   mergeSort(A,p,q);
   mergeSort(A,q+1,r);
   MERGE(A,p,q,r);
   } 
}

//-------------------------------------------------

int main () 
{
	//
	int *A=(int*) malloc(sizeof(int) * N);//int A[N];
	int i;
	clock_t S, E;

	for(i=0; i<N; ++i) A[i] = rand() * 1.0;

	
		for(i=N-1;i>N-10;i--)
		printf("A[%d]=%d\n",i,A[i]);

		//printf("11/3=%d\n",11/3);
		S = clock();
	mergeSort(A,0,N-1);
		E = clock();
		printf("Time usage: %.2f\n", (float)(E - S) / CLOCKS_PER_SEC);
		
		for(i=N-1;i>N-10;i--)
		printf("A[%d]=%d\n",i,A[i]);
}
