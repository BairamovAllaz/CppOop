#include "matrixString.h"
#include "matrixString.cpp"
int main()
{
    srand(time(0));

    Matrix m(3, 3);

    cout << "M: " << m << endl;

    Matrix N = m;
    cout << "N : " << N << endl;

    Matrix F;
    F = N;
    cout << "F: " << F << endl;

    Matrix H = F + N;
    cout << "H: " << H << endl;

    Matrix L = H - N;
    cout << "L: " << L << endl;

    Matrix K = N * N;
    cout << "K: " << K << endl;

    Matrix D = K / F;
    cout << "D: " << D << endl;
    return 0;
}
