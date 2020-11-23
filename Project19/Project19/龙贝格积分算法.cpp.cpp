#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define f(x) (4/(1+pow(x,2)))
#define N_H 20
#define MAX 10//最大迭代次数
#define a 0//积分上下限
#define b 1
#define e 1e-6//精度
double lgkt(double aa, double bb, long int n)
{
	int i;
	double sum, h = (bb - aa) / n;
	sum = 0;
	for (i = 1; i < n; i++)
		sum += f(aa + i*h);
	sum += (f(aa) + f(bb)) / 2;
	return(h*sum);
}
void main()
{
	int i;
	long int n = N_H, m;
	double R[2][MAX + 1];
	R[1][0] = lgkt(a, b, n);
	n *= 2;
	for (m = 1; m < MAX; m++)
	{
		for (i = 0; i < m; i++)
		{
			R[0][i] = R[1][i];
		}
		R[1][0] = lgkt(a, b, n);
		n *= 2;
		for (i = 1; i <= m; i++)
		{
			R[1][i] = R[1][i - 1] + (R[1][i - 1] - R[0][i - 1]) / (pow(2.0, 2 * m) - 1);
			if ((R[0][m - 1] - R[1][m]) < e)
				printf("T=%.10lf\n", R[1][m]);
			printf("\n");
			system("pause");
		}
	}
	return;
}