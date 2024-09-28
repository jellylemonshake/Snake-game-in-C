# **Snake Game in C - Readme**

## Introduction:
This is a simple Snake Game implemented in C. The game is played on a 10x20 grid where the player controls a snake, trying to eat fruit that randomly appears. Each time the snake eats a fruit, it grows longer and the player's score increases. The game ends if the snake collides with itself or the walls.

![Screenshot (115)](https://github.com/user-attachments/assets/89030acf-2ad2-48f3-8c17-5d4623e2f4c9)

## Features:
* Snake movement using keyboard controls.
* Random fruit spawning on the grid.
* Score tracking based on the number of fruits eaten.
* Game over conditions when the snake hits a wall or itself.
  
## Controls:
* **w:** Move Up
* **s:** Move Down
* **a:** Move Left
* **d:** Move Right

## How to Compile and Run
### Requirements:
* A C compiler (e.g., GCC).
* A Windows terminal or command prompt to run the game.
   
### Steps to Compile:
* Save the code in a file named **snake_game.c**
* Open a terminal and navigate to the directory where the file is saved.

**Compile the code using this command:**
   
      gcc snake_game.c -o snake_game.exe
  
**Run the game with the following command:**

      ./snake_game.exe
  
## Important Notes:
* The code is written specifically for Windows using **conio.h** and **windows.h** for input handling and screen clearing.
* **system("CLS")** is used to clear the console screen, which may not work on non-Windows platforms.
* Similarly, **sleep(700)** is used to control the speed of the game.

## Game Rules
1. **Goal:** 
   * Control the snake and eat as many fruits as possible to increase your score.
2. **Game Over Conditions:**
   * The snake hits the wall.
   * The snake collides with itself.
   
## Game Loop
* **Input Handling:**
  The player can change the direction of the snake using **w**, **s**, **a**, or **d**. The snake cannot move in the opposite direction of its current movement.
* **Snake Movement:**
  The snake moves one step in the current direction, and each segment of the body follows the previous segment.
* **Collision Detection:**
  The game checks for collisions with the walls or the snake's own body after each movement.
* **Fruit Check:**
  If the snake eats the fruit, its length increases, and a new fruit is randomly placed on the grid.
* **Drawing the Grid:**
  The grid, including the snake and fruit, is redrawn after each movement.

## Future Improvements
* Adding a high score system.
* Increasing the game speed as the snake grows.
* Implementing different levels or difficulties.
