# Singly Linked List in C

A menu-driven singly linked list implemented from scratch in C, with manual
memory management. Every operation lives in its own function and is reachable
through an interactive console menu.

**Authors:** [Dmitriy Kuramshin](https://github.com/Krmsh1n5) · [Kamal Yalchin](https://github.com/Camrado) · [Luis Markus Torres](https://github.com/LuisMarkusTorres)

## Features

- **Create** a list of `n` nodes from user input
- **Insert** at the beginning, at a given position, or at the end
- **Display** forward (ascending) and reverse (descending)
- **Delete** at the beginning, at the end, or at a given position
- **Count** the number of nodes
- **Search** for a value and report its 1-based position
- Full cleanup of allocated nodes on exit

## Build

With `make`:

```bash
make
```

Or directly with `gcc`:

```bash
gcc -Wall -Wextra -std=c11 -O2 -o sll main.c
```

## Run

```bash
./sll
```

The program first asks how many nodes to create, then loops on the main menu:

```
1. Insert
2. Display
3. Delete
4. Count
5. Search
6. Create a new list
0. Exit
```

Insert, Display, and Delete open a short submenu to pick the variant
(front / position / end, or ascending / descending).

## Project structure

```
singly-linked-list/
├── main.c      application and all list operations
├── Makefile    build/run/clean targets
├── README.md
└── .gitignore
```

## Notes

Positions are 1-based. Inserting at a position past the end, or at the front
when the list is empty, is handled gracefully.

## Course

This is a course project for **Data Structures and Algorithms 1** (Computer
Science 1, 11 ECTS) at UFAZ. The course covers fundamental data structures and
their algorithms, implemented in C:

- Arrays
- Queues
- Stacks
- Linked lists
- Trees
- Algorithms used to manage these data structures
- Implementation in the C programming language

This project corresponds to the linked list portion of that syllabus.
