Controls:
- `A` / `D` = rotate camera left/right
- `W` / `S` = zoom in/out
- `Up` / `Down` = move camera height
- `Left` / `Right` = rotate with arrow keys
- `J` / `L` = move camera focus left/right
- `I` / `K` = move camera focus up/down
- `R` = reset camera
- `Esc` = close

sudo apt update
sudo apt install freeglut3-dev libglu1-mesa-dev
```

Manual build:
```bash
g++ -std=c++17 -g src/main.cpp -o bin/classroom -lglut -lGLU -lGL
./bin/classroom
```
Green Color