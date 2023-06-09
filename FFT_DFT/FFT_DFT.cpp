
#define _USE_MATH_DEFINES
#include <iostream>
#include <complex>
#include "math.h"
#include <vector>
using namespace std;

const double pi = std::acos(-1);
const std::complex<double> i(0, 1);



complex<double>* dft(double* f, int N) {
	complex<double>* cDFT = new complex<double>[N];
	for (int k = 0; k < N; k++) {				//przedzial 0 n-1
		cDFT[k] = complex<double>(0.0, 0.0);  
		for (int n = 0; n < N; n++) {
			cDFT[k] = cDFT[k] + f[n] * exp(i * (-2 * pi * k * n / N));
		}
	}
	return cDFT;
}




complex<double>* fft(double* f, int N)
{
	complex<double>* cFFT = new complex<double>[N];
	if (N == 1)
	{																									
		cFFT[0] = complex<double>(f[0], 0);
		return cFFT;
	}
	else {
		double* probka_parzysta = new double[N / 2];													
		double* probka_nieparzysta = new double[N / 2];
		for (int k = 0; k < N / 2; k++)                              
		{
			probka_parzysta[k] = f[2 * k];
			probka_nieparzysta[k] = f[2 * k + 1];
		}
		complex<double>* result_parzysty = fft(probka_parzysta, N / 2);  
		complex<double>* result_nieparzysty = fft(probka_nieparzysta, N / 2);
		for (int j = 0; j < N / 2; j++)
		{

			complex<double> W = exp(i * (-2 * pi * j / N));
			cFFT[j] = result_parzysty[j] + W * result_nieparzysty[j];
			cFFT[j + N / 2] = result_parzysty[j] - W * result_nieparzysty[j];
		}
		delete[] probka_parzysta;
		delete[] probka_nieparzysta;
		delete[] result_parzysty;
		delete[] result_nieparzysty;
		return cFFT;
	}
}




int main()
{
	
		const int N = 15; // rozmiar 
		double* f = new double[N];
		for (int n = 0; n < N; n++)
			f[n] = (n * n) / ((double)N * (double)N); 
		//f[n] = n / (double)N; // funkcja liniowa
		clock_t t1 = clock();
		complex < double >* cDFT = dft(f, N);
		clock_t t2 = clock();
		double dft_time = (t2 - t1) / (double)CLOCKS_PER_SEC * 1000.0;
		printf("DFT czas[ms] : % f \n", dft_time);




		t1 = clock();
		complex < double >* cFFT = fft(f, N);
		t2 = clock();
		double fft_time = (t2 - t1) / (double)CLOCKS_PER_SEC * 1000.0;
		printf("FFT czas[ms] : % f \n", fft_time);


		for (int k = 0; k < N; k++) {
			printf("k = %d, rzeczywistaFFT = %f, urojonaFFT = %f\n", k, cFFT[k].real(), cFFT[k].imag());

			printf("k = %d, rzeczywistaDFT = %f, urojonaDFT = %f\n", k, cDFT[k].real(), cDFT[k].imag());
			cout << endl;
		}
		
		delete[] f;
		delete[] cDFT;
		delete[] cFFT;


	
	return 0;
}

