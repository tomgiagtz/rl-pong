### Getting Started

Requires [CMake](https://cmake.org/), a C/C++ compiler, and Git (raylib and uuid_v4 are
fetched automatically on configure).

```sh
git clone https://github.com/tomgiagtz/rl-pong.git
cd rl-pong-game
cmake -B build && cmake --build build
```

Run the game (output goes to `bin/Debug/`):

```sh
./bin/Debug/rl-pong-game        # Windows: bin\Debug\rl-pong-game.exe
```

This project was started using [raylib-quickstart](https://github.com/raylib-extras/raylib-quickstart).


# Progress Updates

## Sept 14, 2024 - **DVD video ?**
  
https://github.com/user-attachments/assets/3bffbb22-072c-44db-ad4a-05d62410e302
  - entities could be generalized as rectangles.

## Sept 28, 2024 - **Collision between Rectangles**

https://github.com/user-attachments/assets/7fe28a8c-5f28-4b80-8e5e-096b6859ce4d
  - multiple colliders handled with a set
  
https://github.com/user-attachments/assets/ddf9fb6e-ffce-42a4-92b8-123c03dbcd79
  - plays nice enough for pong to be playable


## Sept 29, 2024 - **Collision between many Rectangles**

https://github.com/user-attachments/assets/8ff7628e-5b6a-4512-a7ba-a8e38e3631d4
  - collisions need a nicer resolution, balls getting stuck on each other
  - 20 fps with 512 balls, can do better!

