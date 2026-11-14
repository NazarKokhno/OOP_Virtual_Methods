# OOP Homework — Shape & BitString

A collection of C++ projects focused on object-oriented programming concepts and practical implementation.

## Task 1 — Shape

A class hierarchy for representing and managing 2D geometric shapes.

**Implemented:**
- Abstract `Shape` base class.
- Virtual methods: `Show()`, `Save()`, `Load()`.
- Derived classes: `Square`, `Rectangle`, `Circle`, `Ellipse`.
- Saving and loading shapes from files.
- Polymorphic object handling through a base class array.

## Task 2 — String & BitString

Implementation of a dynamic string class and a derived bit string class.

**String:**
- Dynamic memory management.
- Constructors, copy constructor, and destructor.
- Assignment operator.
- String length and clearing methods.
- Concatenation operators (`+`, `+=`).
- Comparison operators (`==`, `!=`).

**BitString:**
- Inherits from `String`.
- Accepts only `0` and `1` characters.
- Represents signed integers in binary.
- Uses two's complement for negative numbers.
- Sign conversion.
- Arithmetic addition operators (`+`, `+=`).
- Comparison operators (`==`, `!=`).

## Concepts & Technologies

- C++
- Object-Oriented Programming
- Inheritance
- Polymorphism
- Abstract Classes
- Operator Overloading
- Dynamic Memory Allocation
- File Handling
