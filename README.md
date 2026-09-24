*This project has been created as part of the 42 curriculum by nhamad, dshirais.*

# cub3D

## Description

**cub3D** is a small 3D maze renderer written in C as part of the 42 curriculum. Inspired by *Wolfenstein 3D*, it uses raycasting to turn a 2D map into a first-person view. The project covers scene-file parsing and validation, ray traversal, textured wall rendering, camera movement, and MiniLibX window events.

The scene file defines a maze, the player's starting position and direction, four wall textures, and the floor and ceiling colors. The renderer uses a separate texture for each wall face. Invalid scene data, unclosed maps, and missing or unreadable textures produce an error.

## Features

- First-person maze rendering using the DDA raycasting algorithm.
- North, south, east, and west wall textures loaded from XPM files.
- Configurable floor and ceiling RGB colors.
- WASD movement with wall collision handling.
- Left and right arrow keys to rotate the view.
- Map and scene validation, including checking that the map is enclosed by walls.
- Clean exit using **Esc** or the window close button.

## Instructions

### Requirements

This project targets Linux and uses the Linux version of MiniLibX. You need:

- A C compiler and GNU Make.
- X11 development libraries and a running graphical session.
- The Linux MiniLibX source directory at `minilibx-linux/`.

On Debian or Ubuntu, install the system packages with:

```sh
sudo apt update
sudo apt install build-essential libx11-dev libxext-dev libbsd-dev zlib1g-dev
```

The repository's Makefile runs `make` inside `minilibx-linux/`. That directory is not included in this repository, so add the MiniLibX source there before building:

```sh
git clone https://github.com/42Paris/minilibx-linux.git minilibx-linux
```

### Build

From the repository root:

```sh
make
```

This creates the `cub3D` executable. The Makefile also provides the `clean`, `fclean`, `re`, and `bonus` rules.

### Run

Pass one scene file with the `.cub` extension:

```sh
./cub3D maps/test.cub
```

The sample scene uses texture paths relative to the repository root. Run the command from that directory so the paths resolve correctly. The application opens an X11 window, so it needs access to a graphical display; a headless container needs X11 forwarding or another configured display.

### Controls

| Key | Action |
| --- | --- |
| `W` / `S` | Move forward / backward |
| `A` / `D` | Move left / right |
| `←` / `→` | Rotate the view |
| `Esc` | Close the window and quit |

### Scene file format

A `.cub` file contains one entry for each wall texture, one floor color, one ceiling color, and then the map. The map must be the final section. Map cells use `1` for walls, `0` for empty space, and one of `N`, `S`, `E`, or `W` for the player's single starting position and direction.

```text
NO ./textures/north.xpm
SO ./textures/south.xpm
WE ./textures/west.xpm
EA ./textures/east.xpm
F 70,70,70
C 120,180,255

11111111
10000001
10001001
10N0001
10000001
11111111
```

RGB values must be in the range 0–255. The map must be enclosed by walls. See [maps/test.cub](maps/test.cub) for a runnable example.

## Technical overview

- **Language:** C
- **Graphics:** MiniLibX for Linux
- **Rendering:** DDA ray traversal and per-column textured wall drawing
- **Build flags:** `-Wall -Wextra -Werror`
- **Project layout:** application headers in `inc/`, implementation in `src/`, sample scenes in `maps/`, textures in `textures/`, and the permitted 42 Libft functions in `libft/`.

## Resources

- [cub3D subject](https://github.com/42cursus/cub3d) — project goals and scene format.
- [Lode's Computer Graphics Tutorial: Raycasting](https://lodev.org/cgtutor/raycasting.html) — raycasting and DDA concepts.
- [Permadi's Ray-Casting Tutorial](https://permadi.com/1996/05/ray-casting-tutorial-table-of-contents/) — foundational raycasting explanations.
- [MiniLibX for Linux](https://github.com/42Paris/minilibx-linux) — graphics library source used by the Makefile.
- [42 MiniLibX documentation](https://harm-smits.github.io/42docs/libs/minilibx) — window, image, and event functions.
- [42 Norminette](https://github.com/42School/norminette) — 42 C coding standard checker.

### AI use

AI tools were used as a support resource for discussing implementation questions and preparing documentation, including raycasting and map-parsing concepts, debugging approaches, and texture-path or invalid-texture error handling. AI suggestions were reviewed and adapted by the project authors; they are responsible for understanding and validating the submitted code.
