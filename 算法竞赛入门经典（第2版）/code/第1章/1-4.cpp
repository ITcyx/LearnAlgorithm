#define _USE_MATH_DEFINES
#include<stdio.h>
#include<math.h>

int main()
{
	int n;
	scanf("%d", &n);
	printf("%.3f %.3f\n", sin(n / 180.0 * M_PI), cos(n / 180.0 * M_PI));
	return 0;
}