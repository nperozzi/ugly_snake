# Ugly Snake
A tiny, terminal-based Snake game written in C.

## Controls
- Arrow keys to move the snake (Up / Down / Left / Right).

## Build
- Requires a GCC toolchain.

## Configuration
- Edit `include/config.h` to change the playing area size:
  - `SIZE_X` - width (including borders)
  - `SIZE_Y` - height (including borders)

## TODO / Known quirks
- Display flickers. It can be improved by redrawing only changed characters.
- Rapid arrow presses may queue input. Consider debouncing or reading input differently.

## License
- This repository is provided as-is for learning purposes. Feel free to reuse or modify.


# TODO:
* Display flickers. I should be redrawing the characters that change only.
* A state-machine to make a "Start Page" and a "Game Over" page.

