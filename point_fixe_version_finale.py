# Coefficients
rH = 0.1
cL = 0.05
rL = 0.02
dL = 0.15
cR = 0.03
rR = 0.01
dR = 0.1
H_max = 200


# Liste des points d'équilibre
solutions = []

# 1) Extinction totale
solutions.append((0, 0, 0))

# 2) point fixe non trivial dans le cas sans limite d'herbe
L = rH / cL
H = dR*cL / rR*rH
R = (rH*H - dL)/cR
solutions.append((H, L, R))

#point fixe non trivial dans le cas avec limite d'herbe 
#L = dR/ rR
#H = H_max* ( 1 - (dR*cL / rR*rH))
#R = (rH*H - dL)/cR
#solutions.append((H, L, R))

# Affichage
print("Points d'équilibre trouvés :")
for i, (H, L, R) in enumerate(solutions, 1):
    print(f"{i}) H = {H:.4f}, L = {L:.4f}, R = {R:.4f}")

