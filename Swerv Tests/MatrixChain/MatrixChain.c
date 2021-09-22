/* A naive recursive implementation that simply
follows the above optimal substructure property */
#include <limits.h>
#include <stdio.h>

// Matrix Ai has dimension p[i-1] x p[i] for i = 1..n
int MatrixChainOrder(int p[], int i, int j)
{
	if (i == j)
		return 0;
	int k;
	int min = INT_MAX;
	int count;

	// place parenthesis at different places between first
	// and last matrix, recursively calculate count of
	// multiplications for each parenthesis placement and
	// return the minimum count
	for (k = i; k < j; k++)
	{
		count = MatrixChainOrder(p, i, k)
				+ MatrixChainOrder(p, k + 1, j)
				+ p[i - 1] * p[k] * p[j];

		if (count < min)
			min = count;
	}

	// Return minimum count
}

// Driver code
void main()
{
	int arr[] = {40, 20, 30, 10, 30};
	int n = sizeof(arr) / sizeof(arr[0]);

		MatrixChainOrder(arr, 1, n - 1);
}
