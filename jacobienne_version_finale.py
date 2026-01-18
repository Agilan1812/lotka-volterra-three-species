import numpy as np

# Tes paramètres
rH = 0.1     # Croissance herbe
cL = 0.02    # Consommation herbe par lapins
rL = 0.01    # Reproduction lapins
dL = 0.1     # Mortalité lapins
cR = 0.005   # Prédation lapins par renards
rR = 0.02    # Reproduction renards
dR = 0.1     # Mortalité renards

# Point autour duquel on veut évaluer la Jacobienne
H = 12.66
L = 4.85
R = 5.79

# Jacobienne calculée au point (H, L, R)
J = np.array([
    [rH - cL * L,         -cL * H,         0],
    [rL * L,              rL * H - dL - cR * R,   -cR * L],
    [0,                   rR * R,          rR * L - dR]
])

# Jacobienne calculée au point (H, L, R) avec limite d'herbe
#J = np.array([
#   [rH *(1 - 2*H/H_max) - cL * L,         -cL * H,         0],
#   [rL * L,              rL * H - dL - cR * R,    -cR * L],
#    [0,                   rR * R,          rR * L - dR]
#])


print(f"Matrice Jacobienne en (H={H:.2f}, L={L:.2f}, R={R:.2f}) :\n")
print(J)

# Valeurs propres
eigvals = np.linalg.eigvals(J)
print("\nValeurs propres de la Jacobienne :")
for i, val in enumerate(eigvals, 1):
    print(f"λ{i} = {val.real:.4f} {'+' if val.imag >= 0 else '-'} {abs(val.imag):.4f}i")
