import numpy as np
import matplotlib.pyplot as plt
from sklearn.neural_network import MLPRegressor

# Definimos los 3 casos a procesar iterativamente
casos = [

    {"archivo": "oscilador_caso3_ergodico_moderado.dat", "titulo": "Caso 3: Sensibilidad a la Fase (Desfase $\delta=\pi/2$)"}
]

for caso in casos:
    print(f"\n--- Procesando {caso['archivo']} ---")
    try:
        datos = np.loadtxt(caso["archivo"], skiprows=1)
    except FileNotFoundError:
        print(f"Error: No se encontró '{caso['archivo']}'. Ejecuta el código de C++ primero.")
        continue

    t = datos[:, 0].reshape(-1, 1)
    x_real = datos[:, 1]
    y_real = datos[:, 2]
    x_ruido = datos[:, 3]
    y_ruido = datos[:, 4]

    print("Entrenando la Inteligencia Artificial (MLP)...")
    target_ruidoso = np.column_stack((x_ruido, y_ruido))

    # Misma arquitectura robusta de tu diseño original
    mlp = MLPRegressor(hidden_layer_sizes=(100, 100),
                       activation='tanh',
                       solver='lbfgs',
                       max_iter=10000,
                       random_state=42)
    
    mlp.fit(t, target_ruidoso)
    prediccion = mlp.predict(t)
    
    x_pred = prediccion[:, 0]
    y_pred = prediccion[:, 1]

    print("Generando imagen de grado académico...")
    plt.figure(figsize=(9, 7))
    
    # Ajuste dinámico de visualización: El caso 2 tiene 5000 puntos, por lo que 
    # necesitamos que el ruido sea más sutil (alpha menor, puntos más pequeños)
    es_caso2 = "Inconmensurable" in caso["titulo"]
    s_ruido = 1 if es_caso2 else 15
    alpha_ruido = 0.3 if es_caso2 else 0.5
    
    plt.scatter(x_ruido, y_ruido, color='gray', alpha=alpha_ruido, s=s_ruido, label='Observaciones (Ruido)')
    plt.plot(x_real, y_real, color='black', linewidth=1.5 if es_caso2 else 2.5, label='Topología Teórica')
    plt.plot(x_pred, y_pred, color='red', linestyle='--', linewidth=1.5 if es_caso2 else 2.5, label='Reconstrucción (IA)')

    plt.title(caso["titulo"], fontsize=14, fontweight='bold')
    plt.xlabel("Posición X", fontsize=12)
    plt.ylabel("Posición Y", fontsize=12)
    plt.legend(loc='upper right')
    plt.grid(True, linestyle=':', alpha=0.7)
    plt.tight_layout()
    
    nombre_img = caso["archivo"].replace('.dat', '.png')
    plt.savefig(nombre_img, dpi=300)
    print(f"-> Guardado exitosamente como {nombre_img}")

print("\n¡Todo listo! Las nuevas figuras con los nudos topológicos se han generado.")