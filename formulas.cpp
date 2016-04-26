#include "formulas.h"
#include "math.h"
#include <vector>
#include <numeric>

struct Air {
    std::vector<double> Temperature = { -20, -19, -18, -17, -16, -15, -14, -13, -12, -11,
                                        -10, -9, -8, -7, -6, -5, -4, -3, -2, -1,
                                        0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
                                        11, 12, 13, 14, 15, 16, 17, 18, 19, 20,
                                        21, 22, 23, 24, 25, 26, 27, 28, 29, 30 };
    std::vector<double> Lambda = { 2.280, 2.288, 2.296, 2.304, 2.312, 2.320, 2.328, 2.336, 2.344, 2.352,
                                   2.360, 2.368, 2.376, 2.384, 2.392, 2.400, 2.408, 2.416, 2.424, 2.432,
                                   2.440, 2.447, 2.454, 2.461, 2.468, 2.475, 2.482, 2.489, 2.496, 2.503, 2.510,
                                   2.518, 2.526, 2.534, 2.542, 2.550, 2.558, 2.566, 2.574, 2.582, 2.590,
                                   2.598, 2.606, 2.614, 2.622, 2.630, 2.638, 2.646, 2.654, 2.662, 2.670 }; //Warning!!! Values must be used after pow(10,-2).
    std::vector<double> Ni = { 12.790, 12.754, 12.718, 12.682, 12.646, 12.610, 12.574, 12.538, 12.502, 12.466,
                               12.430, 12.515, 12.600, 12.685, 12.770, 12.855, 12.940, 13.025, 13.110, 13.195,
                               13.280, 13.368, 13.456, 13.544, 13.632, 13.720, 13.808, 13.896, 13.984, 14.072, 14.160,
                               14.250, 14.340, 14.430, 14.520, 14.610, 14.700, 14.790, 14.880, 14.970, 15.060,
                               15.154, 15.248, 15.342, 15.436, 15.530, 15.624, 15.718, 15.812, 15.906, 16.000 }; //Warning!!! Values must used after pow(10,-6).
    std::vector<double> Pr = { 0.7160, 0.7156, 0.7152, 0.7148, 0.7144, 0.7140, 0.7136, 0.7132, 0.7128, 0.7124,
                               0.7120, 0.7115, 0.7110, 0.7105, 0.7100, 0.7095, 0.7090, 0.7085, 0.7080, 0.7075,
                               0.7070, 0.7068, 0.7066, 0.7064, 0.7062, 0.7060, 0.7058, 0.7056, 0.7054, 0.7052, 0.7050,
                               0.7048, 0.7046, 0.7044, 0.7042, 0.7040, 0.7038, 0.7036, 0.7034, 0.7032, 0.7030,
                               0.7028, 0.7026, 0.7024, 0.7022, 0.7020, 0.7018, 0.7016, 0.7014, 0.7012, 0.7010 };
} airData;

double forecast(const double &x, const std::vector<double> &known_X, const std::vector<double> &known_Y )
{
    if (known_X.size() != known_Y.size())
        return 0;

    /*if ( (x < known_X.begin()) && ( x > known_X.end()) )
        return 0;*/


    int index = 0;
    for (int i = 0; i < (int)known_X.size(); i++)
    {
        if (x < known_X[i])
            break;
        index = i;
    }

    return known_Y[index] + ((x - known_X[index])/(known_X[index+1]-known_X[index]))*(known_Y[index+1] - known_Y[index]);

}

inline double getBbc(double V, double A)
{
    return V/A;
}

inline double getU(double Rs, double Rsi, double Rse)
{
    return 1/(Rs + Rsi + Rse);
}

double getUr(Variables var)
{
    double Rse1 = 0.1;
    double Rsi2 = 0.17;
    double Bbc = getBbc(var.V, var.A1);

    double delta = 1;
    double temTu = -100;

    double U1 = 0;
    double U2 = 0;
    double Tu = 0;
    double Gr = 0;
    double Pr = 0;

    do
    {
        U1 = getU(var.Rs1, Rse1, 0.1);
        U2 = getU(var.Rs2, Rsi2, 0.04);
        Tu = (var.Ti*U1*var.A1 + var.Te*U2*var.A2 + var.Te*var.Uw*var.Aw + var.Te*0.33*var.n*var.V)/
                (U1*var.A1 + U2*var.A2 + var.Uw*var.Aw + 0.33*var.n*var.V);
        double Tse1 = Tu + Rse1*U1*(var.Ti - Tu);
        double Tsi2 = Tu - Rsi2*U2*(Tu - var.Te);
        double beta = 1/(Tu + 273.15);
        double Ni = forecast(Tu, airData.Temperature, airData.Ni)*pow(10,-6);
        Gr = 9.81*beta*pow(Bbc, 3)*(Tse1 - Tsi2)/pow(Ni,2);
        Pr = forecast(Tu, airData.Temperature, airData.Pr);

        double Ek;

        if( (Pr*Gr) < pow(10,3) )
            Ek = 1;
        else if( (Pr*Gr) < pow(10,6) )
            Ek = 0.105*pow((Pr*Gr),0.3);
        else
            Ek = 0.4*pow((Pr*Gr),0.25);

        double LambdaEkv = Ek*forecast(Tu, airData.Temperature, airData.Lambda)*pow(10,-2);

        Rse1 = Bbc/(2*LambdaEkv);
        Rsi2 = Rse1;

        delta = Tu - temTu;
        temTu = Tu;
    }
    while( fabs(delta) >= 0.01 );

    double Ur = 1/(1/U1 + var.A1/(var.A2*U2 + var.Aw*var.Uw + 0.33*var.n*var.V));
    *var.Tu = Tu;
    *var.Gr = Gr;
    *var.Pr = Pr;
    *var.Rse = Rse1;

    return Ur;
}
