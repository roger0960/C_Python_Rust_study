#include <stdio.h>

unsigned int power(unsigned int n, unsigned int k)
{
	if (k <= 0)
		return 1;
	else
		return n*power(n, k - 1);
}

int main()
{
	unsigned int n = 16;
	unsigned int k = 7;

	// scanf("%d%d", &n, &k);
	int ret = power(n, k);
	printf("%d\n", ret);

	return 0;

}

