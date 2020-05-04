# CS488 Final

One Paragraph of project description goes here

## Getting Started

These instructions will get you a copy of the project up and running on your local machine for development and testing purposes. See deployment for notes on how to deploy the project on a live system.

### Prerequisites

#### Install CMake

```
sudo apt-get install cmake
```

#### Boost

Boost is a dependancy of assimp, and is used for multithreading purposes. Assimp will not compile correctly without it.

```
sudo apt-get install libboost-all-dev
```

#### Assimp

Assimp is an open source model loading library that supports over 40+ formats. 
It is recommended to build assimp from source. 
First, run this command:

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

All of the other required headers are located in the include directory.

### Installing

A step by step series of examples that tell you how to get a development env running

Say what the step will be

```
Give the example
```

And repeat

```
until finished
```

End with an example of getting some data out of the system or using it for a little demo

## Running the tests

Explain how to run the automated tests for this system

### Break down into end to end tests

Explain what these tests test and why

```
Give an example
```

### And coding style tests

Explain what these tests test and why

```
Give an example
```

## Acknowledgments

* Hat tip to anyone whose code was used
* Inspiration
* etc

