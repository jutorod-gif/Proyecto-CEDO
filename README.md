# Proyecto-CEDO
Proyecto: Sofía Lugo y Juliana Toro
# Topología y Ergodicidad en el Oscilador Bidimensional: Reconstrucción de curvas de Lissajous bajo ruido experimental mediante una red neuronal


Este repositorio contiene la implementación computacional para la simulación y posterior análisis de un oscilador armónico bidimensional. El proyecto genera trayectorias paramétricas exactas (Curvas de Lissajous) modeladas mediante Sistemas de Ecuaciones Diferenciales Ordinarias (EDOs) y les inyecta ruido gaussiano para simular incertidumbre observacional.

Los datos generados son posteriormente utilizados por un modelo de Inteligencia Artificial (Red Neuronal Multicapa - MLP) implementado en Python, con el objetivo de reconstruir la topología de la órbita en el espacio de fase, superando las limitaciones de los métodos estadísticos clásicos frente a sistemas ergódicos y auto-intersectantes.

## Casos de Estudio Simulados

El programa en C++ genera de forma automática los datasets para tres escenarios topológicos distintos, ajustando el tiempo máximo de evolución (t_max) y la resolución para optimizar el entrenamiento de la red neuronal:

1. **Caso 1: Frecuencias Conmensurables (`oscilador_caso1_conmensurable.dat`)**
   * Relación de frecuencias 3:2.
   * Genera una curva cerrada y estrictamente periódica con auto-intersecciones en el plano XY.
2. **Caso 2: Frecuencias Inconmensurables (`oscilador_caso2_inconmensurable_corto.dat`)**
   * Preludio a la ergodicidad. La trayectoria no se cierra sobre sí misma.
   * Evolución de tiempo corto para validar el mapeo paramétrico sin colapso espacial.
3. **Caso 3: Sensibilidad a la Fase y Límite de Reconstrucción (`oscilador_caso3_ergodico_moderado.dat`)**
   * Inclusión de un desfase crítico.
   * Llenado moderado del espacio acotado para demostrar los límites del modelo MLP (subajuste espacial frente a alta densidad).

## Requisitos del Sistema (Dependencias)

Para compilar y ejecutar este proyecto completo desde cero, necesitarás:

* **Compilador de C++:** Soporte para **C++23** (requerido para `<print>`). Recomendado: GCC 14+ o MSVC reciente.
* **Librería Eigen (v3):** Biblioteca de plantillas de C++ para álgebra lineal.
* **Python 3.8+:** Entorno de Python instalado en el sistema.

---

## Guía de Compilación y Ejecución Paso a Paso

Sigue estos pasos en tu terminal para replicar todo el proyecto (generación de datos y reconstrucción con IA).

### Paso 1: Preparar el Entorno de Python
Es recomendable crear un entorno virtual e instalar las librerías necesarias para la Red Neuronal y la graficación.

```bash
# Crear un entorno virtual (opcional pero recomendado)
python -m venv venv

# Activar el entorno virtual
# En Windows:
venv\Scripts\activate
# En Linux/Mac:
source venv/bin/activate

# Instalar dependencias necesarias
pip install numpy pandas matplotlib scikit-learn

# Copilar el simulador
g++ -std=c++23 -I /ruta/a/eigen main_oscilador.cpp oscilador_solver.cpp -o oscilador_simulador

# Ejecutar simulador
# En Linux/Mac
./oscilador_simulador

# En Windows
oscilador_simulador.exe

# Ejecutar red neuronal y gráficas
python grafica.py
