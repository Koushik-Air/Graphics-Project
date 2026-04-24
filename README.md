# Improved OpenGL Classroom Project

This is a beginner-friendly OpenGL classroom scene with a richer environment and more camera controls.

What it shows:
- Classroom room with floor, walls, and ceiling
- Blackboard, clock, and front teaching platform
- Teacher table and chair
- Student desks and chairs
- Windows, a door, tube lights, ceiling fans, and a bookshelf

Controls:
- `A` / `D` = rotate camera left/right
- `W` / `S` = zoom in/out
- `Up` / `Down` = move camera height
- `Left` / `Right` = rotate with arrow keys
- `J` / `L` = move camera focus left/right
- `I` / `K` = move camera focus up/down
- `R` = reset camera
- `Esc` = close

How to run in VS Code:
1. Open the `G Project 2` folder in VS Code.
2. Press `Ctrl+Shift+B` to build.
3. Press `F5` to run.

Ubuntu packages needed:
```bash
sudo apt update
sudo apt install freeglut3-dev libglu1-mesa-dev
```

Manual build:
```bash
g++ -std=c++17 -g src/main.cpp -o bin/classroom -lglut -lGLU -lGL
./bin/classroom
```
