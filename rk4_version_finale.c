#include <stdio.h> // Inclusion de la bibliothèque standard pour les entrées/sorties

// Définition de constantes pour la simulation
#define DT 0.1             // Pas de temps
#define TMAX 1000.0        // Temps total de la simulation
#define STEPS (int)(TMAX / DT) // Nombre d’itérations (pas de temps)

// Définition d’une structure représentant l’état du système
// H = quantité d’herbe, L = population de lapins, R = population de renards
typedef struct {
    double H, L, R;
} etat;

// Paramètres biologiques du modèle (croissance, consommation, mortalité)
double rH = 0.1;     // Taux de croissance de l’herbe
double cL = 0.02;    // Taux de consommation de l’herbe par les lapins
double rL = 0.01;    // Taux de reproduction des lapins (fonction de la nourriture)
double dL = 0.1;     // Taux de mortalité des lapins
double cR = 0.005;   // Taux de prédation des renards sur les lapins
double rR = 0.02;    // Taux de reproduction des renards (lié à la prédation)
double dR = 0.1;     // Taux de mortalité des renards
double H_max = 200;  // Capacité maximale de l’herbe (limite de croissance)

// Fonction calculant la dérivée (variation) des populations à un instant donné
etat derivation(etat s) {
    etat ds;

    // Taux de variation de l’herbe :
    // croissance logistique - consommation par les lapins
    ds.H = rH * s.H * (1 - s.H / H_max) - cL * s.H * s.L;

    // Taux de variation des lapins :
    // reproduction (avec nourriture) - mortalité - prédation par les renards
    ds.L = rL * s.H * s.L - dL * s.L - cR * s.L * s.R;

    // Taux de variation des renards :
    // reproduction (grâce à la chasse) - mortalité naturelle
    ds.R = rR * s.L * s.R - dR * s.R;

    return ds;
}

// Fonction d’intégration numérique utilisant la méthode de Runge-Kutta d’ordre 4 (RK4)
etat rk4(etat s, double dt) {
    // Calcul des 4 pentes intermédiaires (k1 à k4)
    etat k1 = derivation(s);

    etat s2 = {s.H + dt * k1.H / 2, s.L + dt * k1.L / 2, s.R + dt * k1.R / 2};
    etat k2 = derivation(s2);

    etat s3 = {s.H + dt * k2.H / 2, s.L + dt * k2.L / 2, s.R + dt * k2.R / 2};
    etat k3 = derivation(s3);

    etat s4 = {s.H + dt * k3.H, s.L + dt * k3.L, s.R + dt * k3.R};
    etat k4 = derivation(s4);

    // Calcul de l’état suivant à l’aide d’une moyenne pondérée des dérivées
    etat result;
    result.H = s.H + dt / 6 * (k1.H + 2 * k2.H + 2 * k3.H + k4.H);
    result.L = s.L + dt / 6 * (k1.L + 2 * k2.L + 2 * k3.L + k4.L);
    result.R = s.R + dt / 6 * (k1.R + 2 * k2.R + 2 * k3.R + k4.R);

    return result;
}

// Fonction principale du programme
int main() {
    // Initialisation de l’état du système : herbe, lapins, renards
    etat s = {100.0, 40.0, 5};

    // Ouverture d’un fichier CSV pour enregistrer les résultats
    FILE *fp = fopen("rk4_simulation.csv", "w");
    if (!fp) return 1; // Vérification de l’ouverture

    // Écriture de l’en-tête du fichier CSV
    fprintf(fp, "t,H,L,R\n");

    // Boucle de simulation : itère sur le nombre de pas de temps
    for (int i = 0; i <= STEPS; i++) {
        double t = i * DT; // Temps courant
        // Écriture des valeurs dans le fichier
        fprintf(fp, "%.4f,%.4f,%.4f,%.4f\n", t, s.H, s.L, s.R);
        // Calcul de l’état suivant avec RK4
        s = rk4(s, DT);
    }

    // Fermeture du fichier et message de fin
    fclose(fp);
    printf("Simulation terminée dans 'rk4_simulation.csv'\n");
    return 0;
}
