# Lotka–Volterra Three-Species Ecosystem Model

## Overview

This repository contains a **numerical and theoretical study of a three-species predator–prey ecosystem**, developed as part of a **Numerical Methods** course project.

The system models the interactions between:
- **Grass (H)** as a renewable resource,
- **Rabbits (L)** as herbivores,
- **Foxes (R)** as predators.

The objective of the project is to **model, simulate, and analyze** the dynamics of this ecosystem using a system of **nonlinear differential equations**, combined with **numerical methods and stability analysis**.

The project includes:
- a numerical solver implemented in **C** using RK4,
- data visualization scripts written in **Python**,
- theoretical analysis of **fixed points and stability**,
- a detailed written report (in French).

---

## Mathematical Model

The ecosystem is modeled using an extension of the classical **Lotka–Volterra equations** to three populations.

Each population evolves according to:
- growth or reproduction rates,
- consumption or predation terms,
- natural mortality rates.

The resulting system is **nonlinear** and exhibits a rich variety of behaviors depending on the chosen parameters:
- stable equilibria,
- oscillatory dynamics,
- limit cycles,
- partial or total extinction scenarios.

---

## Project Goals

The main goals of this project are to:

- Model a three-level trophic ecosystem mathematically
- Solve nonlinear differential equations numerically
- Implement the **fourth-order Runge–Kutta method (RK4)**
- Analyze equilibrium points (fixed points)
- Study local stability using the **Jacobian matrix**
- Visualize trajectories using **phase diagrams**
- Interpret numerical results from a biological perspective

---

## Repository Structure

```text
.
├── rk4_version_finale.c                 # RK4 numerical solver (C)
├── rk4_simulation.csv                  # Simulation output data
│
├── evolution_temporelle_version_finale.py  # Time evolution plots H(t), L(t), R(t)
├── diagramme_phase_version_finale.py       # Phase diagram visualization
├── point_fixe_version_finale.py            # Fixed point computation
├── jacobienne_version_finale.py             # Jacobian matrix & eigenvalues
│
├── rapport_projet_Doha_Eve.pdf           # Final written report (French)
├── README.md                             # Project documentation
└── LICENSE                               # MIT License

```
---

## Methods Used

- Lotka–Volterra differential equations
- Fourth-order Runge–Kutta method (RK4)
- Fixed point analysis
- Jacobian matrix computation
- Eigenvalue-based stability analysis
- Phase diagrams and trajectory visualization

---

## How to Run

### Requirements

To run this project, you need:
- GCC (or any C compiler)
- Python 3

- Python libraries:
    - pandas
    - matplotlib

Install Python dependencies with:
```bash
pip install pandas matplotlib
```

### Running the Numerical Simulation (C)

Compile and execute the RK4 solver:
```bash
gcc rk4_version_finale.c -o rk4
./rk4
```

This generates the file:
```bash
rk4_simulation.csv
```
which contains the numerical results.

### Plotting the Results (Python)

Run the visualization scripts:
```bash
python evolution_temporelle_version_finale.py
python diagramme_phase_version_finale.py
```
These scripts produce:
- population evolution over time,
- phase diagrams illustrating system dynamics.

---

## Report

The file rapport_projet_Doha_Eve.pdf contains the full project report.

The report is written in French, it includes:
- mathematical modeling,
- numerical method explanations,
- simulation results,
- phase diagrams,
- stability analysis and interpretations.

This report was prepared for an academic project evaluation.
---

## Authors

- Eve Lin
- Doha Bentaoussy

---

## License & Usage

This project is licensed under the MIT License.

You are allowed to:
- use, modify, and distribute the code,
- study and reuse it for educational purposes.

You are not allowed to:
- submit this work as your own in an academic context,
- reuse it for graded assignments without proper attribution.

This repository is intended as a learning and reference resource.
Academic integrity must be respected at all times.
