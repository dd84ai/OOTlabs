#define _USE_MATH_DEFINES
#include <random>
#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

#define N 100000

double v = 5;
double a = 0;
double b = 0;
double set[N];
void define_input_values()
{
	//cout << "v = "; cin >> v;
	a = (v + 1) / 2;
	b = 1;
}
double generated_x(double g1, double g2)
{
	//cout << g1 << endl << g2 << endl;

	return (2 / M_PI)*asin(((2 * g1) / (g1 + g2)) - 1);
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

	//cout << d(g) << '\n';

	for (int i = 0; i < N; i++)
		set[i] = generated_x(d(g), d(g));

	double MathOjid = 0;
	for (int i = 0; i < N; i++)
		MathOjid += set[i];
	MathOjid /= N;

	double SredneKvadrat = 0;
	for (int i = 0; i < N; i++)
		SredneKvadrat += (set[i] - MathOjid)*(set[i] - MathOjid);
	double Dispersion = SredneKvadrat / N;//Remember!
	SredneKvadrat = sqrt(Dispersion);

	double Assimetry = 0;
	for (int i = 0; i < N; i++)
		Assimetry += (set[i] - MathOjid)*(set[i] - MathOjid)*(set[i] - MathOjid);
	Assimetry /= (N * sqrt(Dispersion * Dispersion * Dispersion));

	double Excess = 0;
	for (int i = 0; i < N; i++)
		Excess += (set[i] - MathOjid)*(set[i] - MathOjid)*(set[i] - MathOjid)*(set[i] - MathOjid);
	Excess /= (N * Dispersion * Dispersion);

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