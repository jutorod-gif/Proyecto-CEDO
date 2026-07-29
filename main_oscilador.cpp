#include <fstream>
#include <print>
#include "oscilador_solver.h"
#include <cmath>
#include <string>

// Función auxiliar para guardar los datos
void guardarDatos(const Eigen::MatrixXd& datos, const std::string& nombre_archivo) {
    std::ofstream file(nombre_archivo);
    if (!file.is_open()) {
        std::println("Error al intentar escribir {}.", nombre_archivo);
        return;
    }
    file << "# t\tx_real\ty_real\tx_ruido\ty_ruido\n";
    for (int i = 0; i < datos.rows(); i++) {
        file << datos(i, 0) << "\t" << datos(i, 1) << "\t" << datos(i, 2) << "\t"
             << datos(i, 3) << "\t" << datos(i, 4) << "\n";
    }
    file.close();
    std::println("Dataset {} creado con éxito!", nombre_archivo);
}

int main() {
    // Amplitudes normalizadas a 1.0 para coincidir con tus imágenes (ejes de -1 a 1)
    double Ax = 1.0; 
    double Ay = 1.0;
    // Ruido bajo para que la IA demuestre su capacidad sin perder la forma visual original
    double ruido = 0.02; 

    std::println("Generando los 3 casos específicos de las imágenes...\n");

    // --- IMAGEN 1: Patrón predefinido (Frecuencias conmensurables clásicas, ej. 3:2) ---
    // Usamos t_max = 2*PI para un ciclo completo cerrado.
    //Eigen::MatrixXd datos_img1 = construirDatasetLineal(3.0, 2.0, Ax, Ay, M_PI/2.0, 2.0 * M_PI, 800, ruido);
    //guardarDatos(datos_img1, "oscilador_caso1_conmensurable.dat");

    // --- IMAGEN 2: Curva abierta a tiempo corto (Tus valores exactos) ---
    // w_x = 5.42, w_y = 8.32, delta = 1.5700. 
    // Usamos un t_max pequeño (ej. 1.5 * PI) para que la curva no alcance a llenar el espacio.
    //Eigen::MatrixXd datos_img2 = construirDatasetLineal(5.42, 8.32, Ax, Ay, 1.5700, 1.5 * M_PI, 1000, ruido);
    //guardarDatos(datos_img2, "oscilador_caso2_inconmensurable_corto.dat");

    // --- IMAGEN 3: Llenado denso / Ergodicidad (Tus valores exactos) ---
    // Mismos parámetros que la Imagen 2, pero dejamos evolucionar el tiempo (t_max = 50 * PI)
    // Aumentamos N a 10000 para capturar la densidad de la malla.
    Eigen::MatrixXd datos_img3 = construirDatasetLineal(5.42, 8.32, Ax, Ay, 1.5700, 15.0 * M_PI, 3000, ruido);
    guardarDatos(datos_img3, "oscilador_caso3_ergodico_moderado.dat");

    return 0;
}