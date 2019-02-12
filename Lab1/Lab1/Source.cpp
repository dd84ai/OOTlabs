#define _USE_MATH_DEFINES
#include <random>
#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;
#define N 100000
double set[N], v, a, b;
void define_input_values()
{
	v = 5, a = 0, b = 0;
	a = (v + 1) / 2; b = 1;
}
double generated_x(double g1, double g2)
{
	return (2 / M_PI)*asin(((2 * g1) / (g1 + g2)) - 1);
}
double MomentPoryadka(int poryadok, double MathOjid)
{
	double Summ = 0, InternalSumm = 1; int j = 0;
	for (int i = 0; i < N; i++)
	{
		for (InternalSumm = 1, j = 0; j < poryadok; j++) InternalSumm *= (set[i] - MathOjid);

		Summ += InternalSumm;
	}
	return Summ;
}
int main()
{
	define_input_values();

	typedef mt19937 G;
	typedef gamma_distribution<> D;
	G g;  // seed if you want with integral argument
	double k = a;      // http://en.wikipedia.org/wiki/Gamma_distribution
	double theta = b;
	D d(k, theta);

	for (int i = 0; i < N; i++)
		set[i] = generated_x(d(g), d(g));

	double MathOjid = MomentPoryadka(1, 0) / N;
	double Dispersion = MomentPoryadka(2, MathOjid) / N;
	double SredneKvadrat = sqrt(Dispersion);
	double Assimetry = MomentPoryadka(3, MathOjid) / (N * sqrt(Dispersion * Dispersion * Dispersion));
	double Excess = MomentPoryadka(4, MathOjid) / (N * Dispersion * Dispersion);
	std::sort(std::begin(set), std::end(set));

	cout << "N = " << N << endl;
	cout << "MathOjid = " << MathOjid << endl;
	cout << "Dispersion = " << Dispersion << endl;
	cout << "SredneKvadrat = " << SredneKvadrat << endl;
	cout << "SredneKvadrat^2 = " << SredneKvadrat * SredneKvadrat << endl;
	cout << "Assimetry = " << Assimetry << endl;
	cout << "Excess = " << Excess << endl;
	cout << "Min = " << set[0] << endl;
	cout << "Median = " << set[int(N / 2)] << endl;
	cout << "Max = " << set[N - 1] << endl;

	cout << "press any key to exit...";
	getchar();
	exit;
}
