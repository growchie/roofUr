#include "formulas.h"
#include "math.h"
#include <vector>

using namespace std;

struct Air {
    vector<double> Temperature = { -20, -19, -18, -17, -16, -15, -14, -13, -12, -11,
                                   -10, -9, -8, -7, -6, -5, -4, -3, -2, -1,
                                   0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
                                   11, 12, 13, 14, 15, 16, 17, 18, 19, 20,
                                   21, 22, 23, 24, 25, 26, 27, 28, 29, 30 };
    vector<double> Lambda = { 2.280E-2, 2.288E-2, 2.296E-2, 2.304E-2, 2.312E-2, 2.320E-2, 2.328E-2, 2.336E-2, 2.344E-2, 2.352E-2,
                              2.360E-2, 2.368E-2, 2.376E-2, 2.384E-2, 2.392E-2, 2.400E-2, 2.408E-2, 2.416E-2, 2.424E-2, 2.432E-2,
                              2.440E-2, 2.447E-2, 2.454E-2, 2.461E-2, 2.468E-2, 2.475E-2, 2.482E-2, 2.489E-2, 2.496E-2, 2.503E-2, 2.510E-2,
                              2.518E-2, 2.526E-2, 2.534E-2, 2.542E-2, 2.550E-2, 2.558E-2, 2.566E-2, 2.574E-2, 2.582E-2, 2.590E-2,
                              2.598E-2, 2.606E-2, 2.614E-2, 2.622E-2, 2.630E-2, 2.638E-2, 2.646E-2, 2.654E-2, 2.662E-2, 2.670E-2 };
    vector<double> Ni = { 12.790E-6, 12.754E-6, 12.718E-6, 12.682E-6, 12.646E-6, 12.610E-6, 12.574E-6, 12.538E-6, 12.502E-6, 12.466E-6,
                          12.430E-6, 12.515E-6, 12.600E-6, 12.685E-6, 12.770E-6, 12.855E-6, 12.940E-6, 13.025E-6, 13.110E-6, 13.195E-6,
                          13.280E-6, 13.368E-6, 13.456E-6, 13.544E-6, 13.632E-6, 13.720E-6, 13.808E-6, 13.896E-6, 13.984E-6, 14.072E-6, 14.160E-6,
                          14.250E-6, 14.340E-6, 14.430E-6, 14.520E-6, 14.610E-6, 14.700E-6, 14.790E-6, 14.880E-6, 14.970E-6, 15.060E-6,
                          15.154E-6, 15.248E-6, 15.342E-6, 15.436E-6, 15.530E-6, 15.624E-6, 15.718E-6, 15.812E-6, 15.906E-6, 16.000E-6 };
    vector<double> Pr = { 0.7160, 0.7156, 0.7152, 0.7148, 0.7144, 0.7140, 0.7136, 0.7132, 0.7128, 0.7124,
                          0.7120, 0.7115, 0.7110, 0.7105, 0.7100, 0.7095, 0.7090, 0.7085, 0.7080, 0.7075,
                          0.7070, 0.7068, 0.7066, 0.7064, 0.7062, 0.7060, 0.7058, 0.7056, 0.7054, 0.7052, 0.7050,
                          0.7048, 0.7046, 0.7044, 0.7042, 0.7040, 0.7038, 0.7036, 0.7034, 0.7032, 0.7030,
                          0.7028, 0.7026, 0.7024, 0.7022, 0.7020, 0.7018, 0.7016, 0.7014, 0.7012, 0.7010 };
} airData;

double forecast(double x, const std::vector<double> &known_X, const std::vector<double> &known_Y )
{
    if (known_X.size() != known_Y.size())
        throw "Vector size mismatch.";

   if ( (x < known_X.front()) && ( x > known_X.back()) )
        throw "Value X out of range.";

    int index = 0;
    for (int i = 0; i < (int)known_X.size(); i++)
    {
        if (x < known_X[i])
            break;
        index = i;
    }

    return known_Y[index] + ((x - known_X[index])/(known_X[index+1] - known_X[index]))*(known_Y[index+1] - known_Y[index]);

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
        double Ni = forecast(Tu, airData.Temperature, airData.Ni);
        Gr = 9.81*beta*pow(Bbc, 3)*(Tse1 - Tsi2)/pow(Ni, 2);
        Pr = forecast(Tu, airData.Temperature, airData.Pr);

        double Ek = 0;

        if( (Pr*Gr) < pow(10,3) )
            Ek = 1;
        else if( (Pr*Gr) < pow(10,6) )
            Ek = 0.105*pow((Pr*Gr), 0.3);
        else
            Ek = 0.4*pow((Pr*Gr), 0.25);

        double LambdaEkv = Ek*forecast(Tu, airData.Temperature, airData.Lambda);

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
