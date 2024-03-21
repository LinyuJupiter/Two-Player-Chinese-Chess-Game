# Two-Player Chinese Chess Game
<p align="center">
  <a href="./README_en.md">English</a> |
  <a href="./README.md">简体中文</a>
</p>


This project is a two-player Chinese chess game based on C++.

The content of this project was completed from November 29, 2022, to December 4, 2022. All original code was typed by myself. Except for the Array class, which borrowed and adapted content from previous lab exercises, all classes and functions were conceived and implemented by myself during this period.

## Features

- **Move Validation**: Automatically detects whether the current move complies with the <a href="./中国象棋/rule.txt">Chinese chess rules</a>.
- **Checkmate Detection**: Automatically detects whether the player is in checkmate to determine victory or defeat. However, it cannot currently detect stalemate situations.
- **Support for Saving or Loading Game State**: Provides functionality to save and load game states, preserving the current positions of pieces and game turns. When loaded, the game state can be perfectly restored.
- **More Features**: Still in development.

## Installation

To run this project, you need to clone this repository:

```bash
git clone https://github.com/LinYujupiter/Two-Player-Chinese-Chess-Game.git
cd Two-Player-Chinese-Chess-Game
```
Then you can run the <a href="./中国象棋/chess.msi">installer package program</a> and follow the instructions to install.

## Running

After installation, you can run the game by double-clicking the "Chinese Chess" shortcut on your desktop.

## Usage

After running the game, you should follow this format to play:
Input format for gameplay:

Number Number Number Number

These are respectively the index of the piece to move, the number after the piece's name (1 for king, 2 for general), the row number after movement, and the column number after movement.

For example: If the red player wants to move the "chariot1" to the position at row 4, column 5, inputting 3 1 4 5 will suffice.

If the move violates Chinese chess rules or the input format is not standard, the operation will be invalidated, and an error message will be displayed.

For more details, please refer to the <a href="./中国象棋/read me！！！.txt">documentation</a>.

## Contribution

We welcome contributions in any form, whether it's proposing new features, improving code, or reporting issues. Please make sure to follow best practices and code style guidelines.