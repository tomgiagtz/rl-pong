### Getting Started

This project was start using [raylib-quickstart](https://github.com/raylib-extras/raylib-quickstart). See their readme for info on building this project.


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

## June 29th, 2026 - **I'm baaackkk!**

It's been way too long, lets get this polished and playable, in one sprint!
Here's the current state. Previously implemented a Quad Tree to handle collisions. It's overkill but the journey into a spatial partitioning data structure was fun!

https://github.com/user-attachments/assets/268ef13e-4035-4d3a-8c8f-4dc4cca62853

At 128 balls this runs a consistent 60fps, but pushing to 512 and the frames are around 35-40fps.  

https://github.com/user-attachments/assets/24397e9b-13c2-4f3d-87d9-1670c2d4df18

I thought drawing the QuadTree boundaries would be dragging down the results. I added togggling to check this aaaand no, it doesn't make much of a difference.
Looks like time to learn how to profile a raylib game!
