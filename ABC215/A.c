#include<stdio.h>
#include <math.h>
#include<string.h>
#include<limits.h>

int main(void)
{
	unsigned long long int n;
	scanf("%lld", &n);
	long int ans = 0;
	ans = log2(n);
	printf("%ld\n", ans);
	return 0;
}
