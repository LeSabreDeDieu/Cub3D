# Cub3D

# Description
Cub3D est un projet de jeu en 3D basé sur le moteur graphique miniLibX. Il s'agit d'une interprétation simple d'un jeu de type Wolfenstein, où le joueur peut se déplacer dans un labyrinthe et interagir avec son environnement.

## Table des matières
- [Prérequis](#prérequis)
- [Installation](#installation)
- [Utilisation](#utilisation)
- [Fonctionnalités](#fonctionnalités)

## Prérequis

Avant de commencer, assurez-vous d'avoir les éléments suivants installés sur votre machine :

    Un système d'exploitation Unix (MacOS, Linux)
    gcc ou un autre compilateur C
    make
    La bibliothèque miniLibX

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

