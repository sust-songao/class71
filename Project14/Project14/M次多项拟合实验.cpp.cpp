#include<iostream>
#include<cmath>
#define MAX 20
using namespace std;     //����������������  (XΪ��������EΪȫ����󣬷ǵ�λ����Ҳ�����ǵ�λ����)
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
	cout << "�����������ϵĵ�ĸ���:";
	cin >> n;
	cout << endl << "������" << n << "�����X��������:";
	for (i = 0; i<n; i++)
		cin >> X[i];
	cout << endl << "������" << n << "�����Y��������:";
	for (i = 0; i<n; i++)
		cin >> Y[i];
	cout << endl << "��������Ҫ��ϵĴ���:";
	cin >> M;
	for (i = 0; i<n; i++)
	for (k = 1; k <= M + 1; k++)
		F[i][k - 1] = pow(X[i], k - 1);
	for (i = 0; i<n; i++)        //��F��ת��
	{
		for (j = 0; j<M + 1; j++)
		{
			BF[j][i] = F[i][j];
		}
	}
	for (i = 0; i<M + 1; i++)   	//����F����ת�õ�BF�ĳ�
	for (j = 0; j<M + 1; j++)
	for (k = 0; k<n; k++)
		A[i][j] += BF[i][k] * F[k][j];
	for (i = 0; i<M + 1; i++)      //����F��ת��BF��Y�ĳ�
	for (j = 0; j<n; j++) B[i] += BF[i][j] * Y[j];
	inv(A, n, E);
	for (i = 0; i<M + 1; i++)     //����A����E��B�ĳ�
	for (j = 0; j<n; j++)
		C[i] += E[i][j] * B[j];
	cout << endl << "��Ϻ��" << M << "�ζ���ʽϵ��Ϊ���ݴ��ɸߵ���:" << endl;
	for (i = M; i >= 0; i--)
	{
		cout << C[i] << "   ";
	}
	cout << endl << "��Ϻ��" << M << "�ζ���ʽΪ:" << endl;
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

