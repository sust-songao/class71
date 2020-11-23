#include<iostream>
#include<cmath>
#define MAX 20
using namespace std;     //求解任意可逆矩阵的逆  (X为待求解矩阵，E为全零矩阵，非单位矩阵，也可以是单位矩阵)
void inv(double X[MAX][MAX], int n, double E[MAX][MAX])
{
	int i = 0, j = 0, k = 0;
	double temp = 0.0;
	for (i = 0; i<MAX; i++)
	{
		for (j = 0; j<MAX; j++)
		if (i == j)
			E[i][j] = 1;
	}
	for (i = 0; i<n - 1; i++)
	{
		temp = X[i][i];
		for (j = 0; j<n; j++)
		{
			X[i][j] = X[i][j] / temp;
			E[i][j] = E[i][j] / temp;
		}

		for (k = 0; k<n; k++)
		{
			if (k == i)
				continue;
			temp = -X[i][i] * X[k][i];
			for (j = 0; j<n; j++)
			{
				X[k][j] = X[k][j] + temp*X[i][j];
				E[k][j] = E[k][j] + temp*E[i][j];
			}
		}
	}
}
int main()
{
	int n = 0, M = 0, i = 0, j = 0, k = 0;
	double X[MAX] = { 0 }, Y[MAX] = { 0 }, F[MAX][MAX] = { 0 }, B[MAX] = { 0 };
	double A[MAX][MAX] = { 0 }, BF[MAX][MAX] = { 0 }, E[MAX][MAX] = { 0 }, C[MAX] = { 0 };
	cout << "请先输入待拟合的点的个数:";
	cin >> n;
	cout << endl << "请输入" << n << "个点的X坐标序列:";
	for (i = 0; i<n; i++)
		cin >> X[i];
	cout << endl << "请输入" << n << "个点的Y坐标序列:";
	for (i = 0; i<n; i++)
		cin >> Y[i];
	cout << endl << "请输入需要拟合的次数:";
	cin >> M;
	for (i = 0; i<n; i++)
	for (k = 1; k <= M + 1; k++)
		F[i][k - 1] = pow(X[i], k - 1);
	for (i = 0; i<n; i++)        //求F的转置
	{
		for (j = 0; j<M + 1; j++)
		{
			BF[j][i] = F[i][j];
		}
	}
	for (i = 0; i<M + 1; i++)   	//计算F与其转置的BF的乘
	for (j = 0; j<M + 1; j++)
	for (k = 0; k<n; k++)
		A[i][j] += BF[i][k] * F[k][j];
	for (i = 0; i<M + 1; i++)      //计算F的转置BF与Y的乘
	for (j = 0; j<n; j++) B[i] += BF[i][j] * Y[j];
	inv(A, n, E);
	for (i = 0; i<M + 1; i++)     //计算A的逆E与B的乘
	for (j = 0; j<n; j++)
		C[i] += E[i][j] * B[j];
	cout << endl << "拟合后的" << M << "次多项式系数为，幂次由高到低:" << endl;
	for (i = M; i >= 0; i--)
	{
		cout << C[i] << "   ";
	}
	cout << endl << "拟合后的" << M << "次多项式为:" << endl;
	cout << endl << "P(x)=";
	for (i = M; i >= 0; i--)
	{
		if (i == 0)
			cout << "+" << C[i];
		else
			cout << C[i] << "*x^" << i;
	}
	return 0;
}

