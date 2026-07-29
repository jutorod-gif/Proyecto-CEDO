#include "oscilador_solver.h"
#include <cmath>
#include <random>

Eigen::MatrixXd construirDatasetLineal(double omega_x, double omega_y, double Ax, double Ay, double desfase, double t_max, int N, double desviacion_ruido) {
    Eigen::MatrixXd dataset(N, 5);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::normal_distribution<double> ruido(0.0, desviacion_ruido);

    for (int i = 0; i < N; i++) {
        double t = (t_max * i) / N;

        // Ecuaciones de movimiento (como en la deducción hamiltoniana)
        double x_real = Ax * std::cos(omega_x * t);
        double y_real = Ay * std::cos(omega_y * t + desfase);

        dataset(i, 0) = t;
        dataset(i, 1) = x_real;
        dataset(i, 2) = y_real;
        dataset(i, 3) = x_real + ruido(gen);
        dataset(i, 4) = y_real + ruido(gen);
    }
    return dataset;
}