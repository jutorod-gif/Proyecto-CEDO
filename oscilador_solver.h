#pragma once
#include <eigen3/Eigen/Dense>

// Función actualizada para aceptar t_max (esencial para ver la ergodicidad en el Caso 2)
Eigen::MatrixXd construirDatasetLineal(double omega_x, double omega_y, double Ax, double Ay, double desfase, double t_max, int N, double desviacion_ruido);
