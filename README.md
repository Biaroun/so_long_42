<div align="center">
  <img src="https://upload.wikimedia.org/wikipedia/commons/8/8d/42_Logo.svg" alt="42 logo" width="120"/>
  <h1>so_long</h1>
  <p>Jeu 2D en C (projet 42) utilisant <strong>MiniLibX</strong></p>

  <p>
    <img src="https://img.shields.io/badge/Language-C-00599C?logo=c&logoColor=white" alt="C"/>
    <img src="https://img.shields.io/badge/Build-Makefile-427819?logo=gnu&logoColor=white" alt="Makefile"/>
    <img src="https://img.shields.io/badge/School-42-black?logo=42&logoColor=white" alt="42"/>
    <img src="https://img.shields.io/badge/Norminette-friendly-success" alt="Norminette"/>
  </p>
</div>

---

## 📚 Description

`so_long` est un petit jeu 2D où le joueur doit récupérer tous les collectibles puis atteindre la sortie.

Ce dépôt contient :

- un moteur de rendu avec **MiniLibX**
- le parsing/contrôle des maps `.ber`
- la vérification de validité et de solvabilité de la carte
- la gestion des déplacements joueur et des collectibles

---

## 🗂️ Structure

- `src/` : logique du jeu (parsing, affichage, mouvements, erreurs)
- `inc/so_long.h` : structures, constantes et prototypes
- `img/` : textures `.xpm`
- `map/` : exemples de cartes `.ber`
- `libft/` : dépendance libft utilisée par le projet
- `Makefile` : compilation du binaire `so_long`

---

## ⚙️ Compilation

### 1. Cloner le projet (avec la MiniLibX)

Pour récupérer le projet et son sous-module `mlx`, clonez avec l'option `--recursive` :

```bash
git clone --recursive git@github.com:Biaroun/so_long_42.git
```

Si le projet a déjà été cloné sans cette option, initialisez le sous-module avec :

```bash
git submodule update --init --recursive
```

### 2. Construire le projet

```bash
make
```

Génère : `so_long`

### 3. Nettoyer

```bash
make clean
make fclean
make re
```

> Note : Le `Makefile` actuel détecte et gère automatiquement la compilation sur Linux (avec X11) et macOS (avec OpenGL/AppKit).

---

## 🚀 Utilisation

Lancer le jeu avec une map `.ber` :

```bash
./so_long map/map.ber
```

Si aucun argument n'est fourni, le programme affiche : `Need map.ber`.

### Contrôles

- `W` : haut
- `A` : gauche
- `S` : bas
- `D` : droite
- `ESC` : quitter

---

## 🗺️ Format de map

Éléments autorisés :

- `1` : mur
- `0` : sol
- `P` : position du joueur (exactement 1)
- `C` : collectible (au moins 1)
- `E` : sortie (exactement 1)

Contraintes validées par le parsing :

- extension de fichier en `.ber`
- map rectangulaire
- map fermée par des murs
- map solvable (tous les `C` et la sortie doivent être atteignables)

## 🎯 Objectif du jeu

- récupérer tous les collectibles
- atteindre la sortie pour terminer la partie
- le nombre de mouvements et de collectibles restants est affiché dans le terminal

## ✅ Norme & qualité

- Code C compilé avec : `-Wall -Wextra -Werror`
- Organisation pensée pour les exigences du cursus 42 (MiniLibX + parsing robuste)

---

## 👤 Auteur

- `biaroun` — 42

---

## 📄 Licence

Projet académique 42.
Usage pédagogique et personnel.
