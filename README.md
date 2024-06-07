# cub3D - My First RayCaster with miniLibX

This project is inspired by the world-famous 90’s game, Wolfenstein 3D, the first FPS ever. The goal is to create a dynamic view inside a maze using ray-casting, where you’ll have to find your way.

## Guidelines
- The project is written in C.
- The code follows the Norm coding standards.
- Functions do not cause unexpected crashes (segfaults, bus errors, etc.).
- All heap-allocated memory is freed; no memory leaks.
- A Makefile is provided with rules: `$(NAME)`, `all`, `clean`, `fclean`, and `re`.
- Bonuses are in separate `_bonus.{c/h}` files.
- The `libft` library is used if needed.
- 3D graphically “realistic” representation from inside a maze using ray-casting principles.
- Use the miniLibX library.
- Smooth window management (minimization, etc.).
- Display different wall textures based on compass direction (North, South, East, West).
- Display an item (sprite) instead of a wall.
- Set different floor and ceiling colors.
- Save the first rendered image in bmp format if the second argument is `--save`.
- Control:
  - Arrow keys to look left and right.
  - W, A, S, D keys to move.
  - ESC to close the window and quit.
  - Clicking the red cross on the window to close and quit.
- If the declared screen size exceeds the display size, adjust the window size accordingly.
- Use miniLibX images.
- Scene description file with `.cub` extension containing:
  - Map with only 0 (empty), 1 (wall), 2 (item), and N, S, E, W (player start position and orientation).
  - Map must be enclosed by walls.
  - Elements separated by empty lines and spaces are allowed.
  - Type identifier followed by specific information:
    - `R 1920 1080` for resolution.
    - `NO ./path_to_the_north_texture` for North texture.
    - `SO ./path_to_the_south_texture` for South texture.
    - `WE ./path_to_the_west_texture` for West texture.
    - `EA ./path_to_the_east_texture` for East texture.
    - `S ./path_to_the_sprite_texture` for sprite texture.
    - `F 220,100,0` for floor color (RGB).
    - `C 225,30,0` for ceiling color (RGB).
- Wall collisions.
- Floor and/or ceiling texture.
- Ability to look up and down.
- Distance-related shadow effect.
- Life bar.
- Object collisions.
- Earning points and/or losing life by picking up objects/traps.
- Doors that open and close.
- Secret doors.
- Sounds and music.
- Rotate the point of view with the mouse.

## Creator's Note
Project made with ❤️ by [**cgangaro**](https://github.com/cgangaro).

If you found this project and README helpful, please consider giving it a ⭐ and following me!

Connect with me on [LinkedIn](https://fr.linkedin.com/in/camille-gangarossa-2ab929227)!

Feel free to reach out with any questions.