import pandas as pd
import matplotlib.pyplot as plt

# Charger les données
df = pd.read_csv("rk4_simulation.csv")

# Tracer les courbes
plt.figure(figsize=(10, 6))
plt.plot(df['H'], df['L'], label='L(H)', color='blue')
# Personnalisation du graphique
plt.xlabel('herbes')
plt.ylabel('lapins')
plt.title('diagramme de phase L(H) ')
plt.legend()
plt.grid(True)
plt.tight_layout()

# Affichage
plt.show()
