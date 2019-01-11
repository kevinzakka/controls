#include <iostream>
#include "mpc.h"

int main() {
    Matrix<2> A;
    A << 1.0, 0.01,
         -0.01, 1.0;
    Matrix<2, 1> B;
    B << 0.0,
         0.01;
    Matrix<2> Q = Matrix<2>::Identity();
    Matrix<1> R = Matrix<1>::Zero();

    Vector<2> x(2, 2);

    ModelPredictiveController<2, 1> mpc(A, B, Vector<1>(-1), Vector<1>(1), Q, R, 100);
    for (int i = 0; i < 1000; i++) {
        auto u = mpc.control(x, Vector<2>(1.0, 0.0));
        std::cout << x[0] << ", " << x[1] << ", " << u << std::endl;
        x = A * x + B * u;
    }
}
