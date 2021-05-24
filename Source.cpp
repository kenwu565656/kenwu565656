#include <cmath>
#include <iostream>
#include <iomanip>
using namespace std;

void insert(double y[], int len)
{
	for (int e = 0; e < len; e++)
	{
		cin >> y[e];
		cout << "you have input " << y[e] << endl;
	}
	cout << "finish input" << endl;
}
double mean(double y[], int len)
{
	double sum = 0;
	for (int i = 0; i < len; i++)
	{
		sum += y[i];

	}
	cout << "mean =" <<  sum / len << endl;
	return sum / len;
}

double s_r_square(double r, double y[], double x[], int len)
{
	double sum = 0;
	for (int w = 0; w < len; w++)
	{
		sum += pow((y[w] - r * x[w]), 2);
	}
	double lenn = len - 1;
	cout << "s_r_square =" << sum / (lenn) << endl;
	return sum / (lenn);
}

double s_y_square(double mean_of_y, double y[], int len_y)
{
	double sum = 0;
	for (int z = 0; z < len_y; z++)
	{
		sum += pow(y[z], 2);

	}
	double answer = sum - len_y * pow(mean_of_y, 2);
	double lenn = len_y - 1;
	answer = answer / (lenn);
	cout << "s_y_square = " << answer << endl;
	return answer;
}

void regression(double y[], double x[], int len, double mean_of_y, double mean_of_x)
{
	double sum = 0;
	for (int q = 0; q < len; q++)
	{
		sum += pow(y[q], 2);
	}
	double answer = sum - len * pow(mean_of_y, 2);
	double lenn = len - 1;
	answer = answer / (lenn);
	cout << "s_y_square = " << answer << endl;
	sum = 0; 
	for (int t = 0; t < len; t++)
	{
		sum += pow(x[t], 2);
	}
	double answer1 = sum - len * pow(mean_of_x, 2);
	answer1 = answer1 / (lenn);
	cout << "s_x_square = " << answer1 << endl;
	sum = 0;
	for (int r = 0; r < len; r++)
	{
		sum += y[r] * x[r];
	}
	double answer2 = sum - len * mean_of_x * mean_of_y;
	answer2 = answer2 / (lenn);
	cout << "s_x_y_square = " << answer2 << endl;
	double betla = answer2 / answer1;
	cout << "betla = " << betla << endl;
	double s_regression_square = answer - 2 * betla * answer2 + pow(betla, 2) * answer1;
	cout << "s_regression_square = " << s_regression_square << endl;
}
int main()
{
	cout << fixed << setprecision(8);
	cout << "pls input the number of sample" << endl << endl;
	int len_y, len_x;
	cin >> len_y >> len_x;
	cout << "start to input the sample values of y" << endl;
	double* y = new double[len_y];
	double* x = new double[len_x];
	insert(y, len_y);
	cout << "start to input the sample values of x" << endl;
	insert(x, len_x);
	double mean_of_y = mean(y, len_y);
	double mean_of_x = mean(x, len_x);
	double r = mean_of_y / mean_of_x;
	cout << "r = " << r << endl;
	s_r_square(r, y, x, len_y);
	s_y_square(mean_of_y, y, len_y);
	regression(y, x, len_x, mean_of_y, mean_of_x);
}