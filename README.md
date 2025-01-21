![Minishell](https://github.com/user-attachments/assets/bc9d3626-f764-40b8-ac2c-9750540e6f1b)
<h1 align="center">
	42 Project - Cub3D
</h1>

<p align="center">
	<b><i> My first RayCaster with miniLibX </i></b>
</p>

<p align="center">
	<img src="https://raw.githubusercontent.com/ayogun/42-project-badges/refs/heads/main/badges/cub3dm.png" alt="mimishell_logo" />
</p>

---
<p align="center">
	<img src="https://img.shields.io/badge/Score-120-darkgreen?style=none&logo=42" alt="Score project :125"/>
	<img alt="Static Badge" src="https://img.shields.io/badge/Outstanding-0-blue?style=none&logo=42">
	<img alt="GitHub repo size" src="https://img.shields.io/github/repo-size/LeSabreDeDieu/Cub3D?style=none&logo=github">
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
- The libft library is required and can be obtained from [here](https://github.com/LeSabreDeDieu/libft).

## Installation

1. Clone the repository to your local machine :

```sh
git clone --recursive https://github.com/LeSabreDeDieu/Cub3D.git
cd Cub3D
```
2. Then compile the project using make :

```sh
make
```

## Usage

To launch the game, run the generated binary :

```sh
./cub3D [path_to_map_file]
```

Ensure that you provide a valid map file as an argument. Map files must adhere to the specific format "file.ber" to be correctly interpreted by the game.

## Features

- Real-time movement in a 3D environment
- Collision with walls
- Texture rendering on walls
- Keyboard input handling for movement and interaction

### Credits

Thanks to [**Luma-3**](https://github.com/luma-3) and [**MonsieurC**](https://github.com/monsieurCanard) for the image banner.

This work is published under the terms of **[42 Unlicense](https://github.com/gcamerli/42unlicense)**.
