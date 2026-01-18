import pandas as pd
import matplotlib.pyplot as plt

# Charger les données
df = pd.read_csv("rk4_simulation.csv")


# Tracer les courbes
plt.figure(figsize=(10, 6))
plt.plot(df['t'], df['H'], label='H(t)', color='green')
plt.plot(df['t'], df['L'], label='L(t)', color='blue')
plt.plot(df['t'], df['R'], label='R(t)', color='red')

# Personnalisation du graphique
plt.xlabel('Temps')
plt.ylabel('Population')
plt.title('Évolution des populations (herbe, lapins, renards) ')
plt.legend()
plt.grid(True)
plt.tight_layout()


# Affichage
plt.show()
