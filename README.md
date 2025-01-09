![Minishell](https://github.com/user-attachments/assets/bc9d3626-f764-40b8-ac2c-9750540e6f1b)
<h1 align="center">
	42 Project - Cub3D
</h1>

<p align="center">
	<b><i> My first RayCaster with miniLibX </i></b>
</p>

<p align="center">
	<img src="https://raw.githubusercontent.com/ayogun/42-project-badges/refs/heads/main/badges/minishelle.png" alt="mimishell_logo" />
</p>

---
<p align="center">
	<img src="https://img.shields.io/badge/Score-120-green?style=flat-square&logo=42" alt="Score project :125"/>
	<img alt="Static Badge" src="https://img.shields.io/badge/Outstanding-0-blue?style=flat-square&logo=42">
	<img alt="GitHub repo size" src="https://img.shields.io/github/repo-size/LeSabreDeDieu/Cub3D?style=flat-square&logo=github">
</p>

# Description
Cub3D is a 3D game project based on the miniLibX graphics engine. It is a simple interpretation of a Wolfenstein-type game, where the player can move through a maze and interact with the environment.

## Table des matières
- [Prerequisites](#Prerequisites)
- [Installation](#Installation)
- [Usage](#Usage)
- [Features](#Features)

## Prerequisites

Before you begin, make sure you have the following installed on your machine:

- A Unix operating system (MacOS, Linux)
- gcc or another C compiler
- make
- The miniLibX library
- The libft that you can get it [here](https://github.com/LeSabreDeDieu/libft)

## Installation

1. Clonez le dépôt sur votre machine locale :

```sh
git clone https://github.com/LeSabreDeDieu/Cub3D.git
cd Cub3D
```
2. Ensuite, compilez le projet en utilisant make :

```sh
make
```

## Utilisation

Pour lancer le jeu, exécutez le binaire généré :

```sh
./cub3D [chemin_vers_fichier_carte]
```

Assurez-vous d'avoir un fichier de carte valide en tant qu'argument. Les fichiers de carte doivent suivre un format spécifique pour être interprétés correctement par le jeu.

## Fonctionnalités

- Mouvement en temps réel dans un environnement 3D
- Collision avec les murs
- Affichage de textures sur les murs
- Gestion des entrées clavier pour le déplacement et l'interaction

