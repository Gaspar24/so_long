# so_long

## Overview

**so_long** is a basic 2D game developed as part of the 42 curriculum. The game challenges players to navigate a character through a map, collecting all items (collectibles) and finding the exit to escape. The game uses MiniLibX for graphical rendering and includes features for handling map input, game logic, and smooth interaction.

---

## Features
- **2D Gameplay**: Navigate using W, A, S, D (or ZQSD/arrow keys) for movement.
- **Collectibles**: Gather all collectibles on the map before reaching the exit.
- **Obstacles**: Avoid walls while exploring the map.
- **Live Movement Count**: Displays the number of moves made in the terminal.
- **Customizable Maps**: Load game maps from `.ber` files.
- **Clean Exit**: Quit the game using `ESC` or by clicking the window close button.

---

## Project Rules

### Game Requirements
1. The player must collect all collectibles before exiting the map.
2. Movement:
   - Allowed directions: Up, Down, Left, Right.
   - The character cannot move through walls.
3. The game displays the current move count in the terminal after each move.
4. Uses a 2D view (top-down or profile).
5. Game world is theme-free: Customize the character, collectibles, and environment.

### Graphics Management
- The game displays the map in a graphical window using MiniLibX.
- The window management must be smooth:
  - Switching between windows or minimizing is supported.
  - Exiting the game through the `ESC` key or the window's close button is required.

---

## Map Requirements

- **Components**:
  - `0`: Empty space
  - `1`: Wall
  - `C`: Collectible
  - `E`: Exit
  - `P`: Player's starting position

- **Rules**:
  1. Must include:
     - 1 exit (`E`)
     - At least 1 collectible (`C`)
     - 1 starting position (`P`)
  2. Must be rectangular.
  3. Must be enclosed by walls (`1`), with no gaps.
  4. Must have a valid path from the starting position to:
     - All collectibles.
     - The exit.
  5. Duplicates of critical components (e.g., multiple starting positions or exits) are invalid.

## How to run it : 
  -- type make inside src folder
  -- type ./so_long map   -- in terminal 
