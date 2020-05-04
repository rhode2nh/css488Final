# CS488 Final Project

This is my final project for CS488 - Computer Graphics. It is a small program that simulates non-euclidean geometry with the use of portals.

## Getting Started

These instructions will show you how to get this project up and running on your machine. **This has only been tested in a Linux Mint environment.**

### Prerequisites

#### Install CMake

```
sudo apt-get install cmake
```

#### Boost

Boost is a dependency of assimp, and is used for multithreading purposes. Assimp will not compile correctly without it.

```
sudo apt-get install libboost-dev
```

#### Assimp

Assimp is an open source model loading library that supports over 40+ formats. 
It is recommended to build assimp from source. 
First, clone the repository:

```
git clone https://github.com/assimp/assimp.git
```

Then, in the repository, run:

```
cmake CMakeLists.txt
```
```
sudo make install -j4
```

#### GLEW

```
sudo apt-get install libglew-dev
```


All of the other required headers are located in the include directory.

### Installing

Clone the repository:

```
git clone https://github.com/rhode2nh/css488Final.git
```

Then, go into the build directory, create a new directory and run cmake:

```
cd build
mkdir example
cmake ../../
```

Run the binary:

```
./final
```


## Acknowledgments

* Credit to Gerzi 3D Art for the model: https://www.turbosquid.com/FullPreview/Index.cfm/ID/464428
* Inspiration:
  - Portal By Valve: https://store.steampowered.com/app/400/Portal/
  - Sebastian Lague: https://www.youtube.com/watch?v=cWpFZbjtSQg
  - Professor Bernstein: https://users.cs.jmu.edu/bernstdh/Web/?_ga=2.29241532.1490873841.1588529661-940155904.1579021428
