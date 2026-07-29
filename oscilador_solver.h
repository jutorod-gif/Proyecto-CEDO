#pragma once
#include <eigen3/Eigen/Dense>

Eigen::MatrixXd construirDatasetLineal(double omega_x, double omega_y, double Ax, double Ay, double desfase, double t_max, int N, double desviacion_ruido);
