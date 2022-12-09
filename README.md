# APCSA NIFTY PROJECT #1
## Food Web Zombies

![Build Status](https://travis-ci.org/joemccann/dillinger.svg?branch=master)

This is my first extra credit submission for APCSA

- [Food Web Zombies](http://nifty.stanford.edu/2022/stephenson-hudson-food-web-zombies/)
- Coded in C++
- Works on Mac and Windows
- Requires GCC for `<bits/stdc++.h>` (could manually import libaries seperately)

---

## Features

- Takes an input text file and returns and output based on problem specifications
- Create an ouput for both food web and zombie
- Optimized Time Complexity of O(nlogn) where n is the number of input words *replace all **map**s with **unordered_map**s for O(n) time complexity and less *pretty* output
- Optimized Space Complexity of O(n) where n is the number of input words
- Includes elements of *OOP* and *DSA*

---

## Input
- A **txt** file in the form of **csv** (can change this but must be comma seperated)
```txt
Fox,Rabbit,Squirrel,Mouse,Seed Eating Bird,Insectivor Bird,Toad
Alice,Bob,Carol,Darryl,Ettienne Fourth,Forbert Findlesworth II,Gordie
```
- First item in the line is a organsim or a zombie that eats or contacts, respectively, to all the remaining items
- Inputs must form a *DAG* and fully complete (no missing nodes or edges), otherwise the program won't work

---

## Output
- **FOOD WEB**
    - First section shows all the prey of one organism
    - Second section shows, Apex Predators, Producers, Intermediates, Most Flexible Eaters, and Tastiest
    - Third section shows the heights of each organism in the food web with producers at 0
    - Fourth section shows the types of each organism (Carnivore, Herbivore, Omnivore)
- **ZOMBIE**
    - First section shows all the infections of one zombie
    - Second section shows, Patient Zeros, Potential Zombies, Neither Patient Zero or Potential Zombie, Most Viral People, and Tastiest
    - Third section shows the heights of each organism in the food web with Potential Zombies at 0
    - Fourth section shows the types of each organism (Spreader Zombies, Regular Zombies, and Zombie Predators)

---

## How to Use
Paste input text into **input.txt** file or replace **input.txt** with your own file name in the main code
```cpp 
freopen("input.txt", "r", stdin); //line 268
```
Get output text in **output.txt** file or replace **output.txt** with your own file name in the main code
```cpp
freopen("output.txt", "w", stdout); //line 269
```
Put what type of graph you're trying to analyze, **food** or **zombie**
```cpp
str type = "type"; //line 271
```
Compile the code and Run, output should be stored in the output file

---

## Sample I/O
Input:
```txt
Fox,Rabbit,Squirrel,Mouse,Seed Eating Bird,Insectivor Bird,Toad
Hawk,Rabbit,Squirrel,Seed Eating Bird,Insectivor Bird
Snake,Mouse,Seed Eating Bird,Insectivor Bird,Herbivor Insect,Predaceous Insect,Toad
Herbivor Insect,Plants
Insectivor Bird,Spider,Herbivor Insect
Predaceous Insect,Herbivor Insect
Mouse,Plants
Rabbit,Plants
Seed Eating Bird,Plants
Squirrel,Plants
Spider,Herbivor Insect,Predaceous Insect
Toad,Predaceous Insect
```
Output:
```txt
Predators and Prey: 
    Fox eats Rabbit, Squirrel, Mouse, Seed Eating Bird, Insectivor Bird and Toad
    Hawk eats Rabbit, Squirrel, Seed Eating Bird and Insectivor Bird
    Herbivor Insect eats Plants
    Insectivor Bird eats Spider and Herbivor Insect
    Mouse eats Plants
    Predaceous Insect eats Herbivor Insect
    Rabbit eats Plants
    Seed Eating Bird eats Plants
    Snake eats Mouse, Seed Eating Bird, Insectivor Bird, Herbivor Insect, Predaceous Insect and Toad
    Spider eats Herbivor Insect and Predaceous Insect
    Squirrel eats Plants
    Toad eats Predaceous Insect

Apex Predators: Fox, Hawk and Snake
Producers: Plants
Intermediates: Herbivor Insect, Insectivor Bird, Mouse, Predaceous Insect, Rabbit, Seed Eating Bird, Spider, Squirrel and Toad
Most Flexible Eaters: Fox and Snake
Tastiest: Plants

Heights: 
    Fox: 5
    Hawk: 5
    Herbivor Insect: 1
    Insectivor Bird: 4
    Mouse: 1
    Plants: 0
    Predaceous Insect: 2
    Rabbit: 1
    Seed Eating Bird: 1
    Snake: 5
    Spider: 3
    Squirrel: 1
    Toad: 3

Types: 
    Herbivores: Herbivor Insect, Mouse, Rabbit, Seed Eating Bird and Squirrel
    Omnivores: 
    Carnivores: Fox, Hawk, Insectivor Bird, Predaceous Insect, Snake, Spider and Toad
```
