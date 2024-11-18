# Ludo : A Token-Based Multiplayer Game with Concurrency

## Overview

This is a C++ turn-based multiplayer game where players compete using tokens on a board. The project showcases advanced C++ programming concepts, including threading, semaphores, and dynamic player interactions. Each player is represented by a unique token, and their actions are managed through concurrent threads.

## Features

- **Multiplayer Gameplay**: Supports up to 4 players, each represented by a distinct token.
- **Concurrency**: Implements threading for player actions and semaphores for managing critical sections.
- **Dynamic Turns**: Player turn orders are shuffled randomly in each round.
- **Interactive Input**: User-friendly input system for initializing and controlling the game.

## File Structure

- **`board.h`**: Manages the game board and its interactions.
- **`grid.h`**: Provides grid-related utilities.
- **`player.h`**: Defines the player class and its attributes.
- **`threadMaster.h`**: Controls the main threading logic.
- **`threadPlayer.h`**: Manages player-specific threads.
- **`threadVictim.h`**: Handles victim scenarios or inter-player interactions.
- **`game.cpp`**: The main entry point of the application.

## Setup and Usage

### Prerequisites

- A C++ compiler (e.g., GCC or Clang) with support for C++11 or later.
- A terminal or IDE that supports C++ development.

### Compilation

To compile the project, use the following command in the terminal:

```bash
g++ -pthread -o game game.cpp
