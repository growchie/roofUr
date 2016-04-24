#include "formulas.h"
#include "math.h"


void InitAirData(void)
{
    airData[0].Temperature = -20; airData[0].Lambda = 2.280; airData[0].Ni = 12.790; airData[0].Pr = 0.7160;
    airData[1].Temperature = -19; airData[1].Lambda = 2.288; airData[1].Ni = 12.754; airData[1].Pr = 0.7156;
    airData[2].Temperature = -18; airData[2].Lambda = 2.296; airData[2].Ni = 12.718; airData[2].Pr = 0.7152;
    airData[3].Temperature = -17; airData[3].Lambda = 2.304; airData[3].Ni = 12.682; airData[3].Pr = 0.7148;
    airData[4].Temperature = -16; airData[4].Lambda = 2.312; airData[4].Ni = 12.646; airData[4].Pr = 0.7144;
    airData[5].Temperature = -15; airData[5].Lambda = 2.320; airData[5].Ni = 12.610; airData[5].Pr = 0.7140;
    airData[6].Temperature = -14; airData[6].Lambda = 2.328; airData[6].Ni = 12.574; airData[6].Pr = 0.7136;
    airData[7].Temperature = -13; airData[7].Lambda = 2.336; airData[7].Ni = 12.538; airData[7].Pr = 0.7132;
    airData[8].Temperature = -12; airData[8].Lambda = 2.344; airData[8].Ni = 12.502; airData[8].Pr = 0.7128;
    airData[9].Temperature = -11; airData[9].Lambda = 2.352; airData[9].Ni = 12.466; airData[9].Pr = 0.7124;
    airData[10].Temperature = -10; airData[10].Lambda = 2.360; airData[10].Ni = 12.430; airData[10].Pr = 0.7120;
    airData[11].Temperature = -9; airData[11].Lambda = 2.368; airData[11].Ni = 12.515; airData[11].Pr = 0.7115;
    airData[12].Temperature = -8; airData[12].Lambda = 2.376; airData[12].Ni = 12.600; airData[12].Pr = 0.7110;
    airData[13].Temperature = -7; airData[13].Lambda = 2.384; airData[13].Ni = 12.685; airData[13].Pr = 0.7105;
    airData[14].Temperature = -6; airData[14].Lambda = 2.392; airData[14].Ni = 12.770; airData[14].Pr = 0.7100;
    airData[15].Temperature = -5; airData[15].Lambda = 2.400; airData[15].Ni = 12.855; airData[15].Pr = 0.7095;
    airData[16].Temperature = -4; airData[16].Lambda = 2.408; airData[16].Ni = 12.940; airData[16].Pr = 0.7090;
    airData[17].Temperature = -3; airData[17].Lambda = 2.416; airData[17].Ni = 13.025; airData[17].Pr = 0.7085;
    airData[18].Temperature = -2; airData[18].Lambda = 2.424; airData[18].Ni = 13.110; airData[18].Pr = 0.7080;
    airData[19].Temperature = -1; airData[19].Lambda = 2.432; airData[19].Ni = 13.195; airData[19].Pr = 0.7075;
    airData[20].Temperature = 0; airData[20].Lambda = 2.440; airData[20].Ni = 13.280; airData[20].Pr = 0.7070;
    airData[21].Temperature = 1; airData[21].Lambda = 2.447; airData[21].Ni = 13.368; airData[21].Pr = 0.7068;
    airData[22].Temperature = 2; airData[22].Lambda = 2.454; airData[22].Ni = 13.456; airData[22].Pr = 0.7066;
    airData[23].Temperature = 3; airData[23].Lambda = 2.461; airData[23].Ni = 13.544; airData[23].Pr = 0.7064;
    airData[24].Temperature = 4; airData[24].Lambda = 2.468; airData[24].Ni = 13.632; airData[24].Pr = 0.7062;
    airData[25].Temperature = 5; airData[25].Lambda = 2.475; airData[25].Ni = 13.720; airData[25].Pr = 0.7060;
    airData[26].Temperature = 6; airData[26].Lambda = 2.482; airData[26].Ni = 13.808; airData[26].Pr = 0.7058;
    airData[27].Temperature = 7; airData[27].Lambda = 2.489; airData[27].Ni = 13.896; airData[27].Pr = 0.7056;
    airData[28].Temperature = 8; airData[28].Lambda = 2.496; airData[28].Ni = 13.984; airData[28].Pr = 0.7054;
    airData[29].Temperature = 9; airData[29].Lambda = 2.503; airData[29].Ni = 14.072; airData[29].Pr = 0.7052;
    airData[30].Temperature = 10; airData[30].Lambda = 2.510; airData[30].Ni = 14.160; airData[30].Pr = 0.7050;
    airData[31].Temperature = 11; airData[31].Lambda = 2.518; airData[31].Ni = 14.250; airData[31].Pr = 0.7048;
    airData[32].Temperature = 12; airData[32].Lambda = 2.526; airData[32].Ni = 14.340; airData[32].Pr = 0.7046;
    airData[33].Temperature = 13; airData[33].Lambda = 2.534; airData[33].Ni = 14.430; airData[33].Pr = 0.7044;
    airData[34].Temperature = 14; airData[34].Lambda = 2.542; airData[34].Ni = 14.520; airData[34].Pr = 0.7042;
    airData[35].Temperature = 15; airData[35].Lambda = 2.550; airData[35].Ni = 14.610; airData[35].Pr = 0.7040;
    airData[36].Temperature = 16; airData[36].Lambda = 2.558; airData[36].Ni = 14.700; airData[36].Pr = 0.7038;
    airData[37].Temperature = 17; airData[37].Lambda = 2.566; airData[37].Ni = 14.790; airData[37].Pr = 0.7036;
    airData[38].Temperature = 18; airData[38].Lambda = 2.574; airData[38].Ni = 14.880; airData[38].Pr = 0.7034;
    airData[39].Temperature = 19; airData[39].Lambda = 2.582; airData[39].Ni = 14.970; airData[39].Pr = 0.7032;
    airData[40].Temperature = 20; airData[40].Lambda = 2.590; airData[40].Ni = 15.060; airData[40].Pr = 0.7030;
    airData[41].Temperature = 21; airData[41].Lambda = 2.598; airData[41].Ni = 15.154; airData[41].Pr = 0.7028;
    airData[42].Temperature = 22; airData[42].Lambda = 2.606; airData[42].Ni = 15.248; airData[42].Pr = 0.7026;
    airData[43].Temperature = 23; airData[43].Lambda = 2.614; airData[43].Ni = 15.342; airData[43].Pr = 0.7024;
    airData[44].Temperature = 24; airData[44].Lambda = 2.622; airData[44].Ni = 15.436; airData[44].Pr = 0.7022;
    airData[45].Temperature = 25; airData[45].Lambda = 2.630; airData[45].Ni = 15.530; airData[45].Pr = 0.7020;
    airData[46].Temperature = 26; airData[46].Lambda = 2.638; airData[46].Ni = 15.624; airData[46].Pr = 0.7018;
    airData[47].Temperature = 27; airData[47].Lambda = 2.646; airData[47].Ni = 15.718; airData[47].Pr = 0.7016;
    airData[48].Temperature = 28; airData[48].Lambda = 2.654; airData[48].Ni = 15.812; airData[48].Pr = 0.7014;
    airData[49].Temperature = 29; airData[49].Lambda = 2.662; airData[49].Ni = 15.906; airData[49].Pr = 0.7012;
    airData[50].Temperature = 30; airData[50].Lambda = 2.670; airData[50].Ni = 16.000; airData[50].Pr = 0.7010;
}


double getU(double Rs, double Rsi, double Rse)
{
    return 0;
}
