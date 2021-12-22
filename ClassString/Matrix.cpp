#include "matrixString.h"
#include "matrixString.cpp"

// #define OPERATORS
int main()
{
    srand(time(0));

#ifdef OPERATORS
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

#endif // DEBUG

    // Matrix s1(3,3);
    // cout << "S1: " << s1 << endl;
    // Matrix s2 = std::move(s1); ///((String &&)string)
    // cout << "S2: " << s2 << endl;
    // cout << "S1: " << s1 << endl;



    Matrix S3(3,3);
    cout << "S3: " << S3 << endl;
    Matrix S4;
    S4 = std::move(S3);
    cout << "S4: " << S4 << endl;
    cout << "S3: " << S3 << endl;

    return 0;
}
