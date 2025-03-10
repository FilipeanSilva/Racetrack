# Racing Championship Simulation - C++ Project

## About the Project

This project was developed as part of the **Object-Oriented Programming (POO)** course in the **Computer Engineering** degree at the Instituto Superior de Engenharia de Coimbra (ISEC). The project consists of a **racing championship simulation**, where users can manage race tracks, cars, and pilots while competing in a championship.

The application follows object-oriented programming principles, using encapsulation, polymorphism, and inheritance to create an efficient and scalable system.

## Features

### **Core Functionality**
- **Championship Management**
  - Create and configure racing championships
  - Manage race tracks (Autodromo)
  - Simulate races with different conditions
  
- **Car Management**
  - Register and configure different types of cars
  - Assign performance statistics to vehicles
  - Simulate mechanical failures and performance degradation
  
- **Pilot Management**
  - Add pilots with different abilities and behaviors
  - Implement various types of pilots (e.g., aggressive, cautious, unpredictable)
  
- **User Interaction**
  - Command-line interface (CLI) to interact with the system
  - Configure and execute race simulations
  - Display race results and championship standings
  
## Object-Oriented Design

The project is structured using several key classes:

### **Main Classes**
- **Championship** – Manages all elements of the championship, including races, cars, and pilots.
- **Autodromo** – Represents the race track and its properties.
- **Car** – Stores car attributes such as speed, durability, and fuel consumption.
- **Pilot** – Represents different types of pilots with unique racing behaviors.
- **Simulation** – Handles the logic behind race execution and interactions between cars and pilots.
- **Console (TextUI)** – Manages user input and output, allowing users to configure and run simulations.

## Technical Details

### **Programming Language:** C++
### **Development Environment:** Any C++ compiler supporting the C++11 standard or higher

## Command List
The program operates via a **command-line interface (CLI)** where users can input various commands to manage the championship. Some key commands include:

- **add_autodromo <name> <length>** – Adds a new race track.
- **add_car <model> <speed> <durability> <fuel>** – Registers a new car.
- **add_pilot <name> <type>** – Adds a new pilot with a specific behavior.
- **start_race** – Begins a race with the registered cars and pilots.
- **list_cars** – Displays all registered cars.
- **list_pilots** – Shows all pilots and their statistics.
- **exit** – Closes the program.

## Implementation Details

The system utilizes:
- **Encapsulation** – Each class manages its own data and behavior.
- **Polymorphism** – Different types of pilots behave uniquely during races.
- **Inheritance** – The `Pilot` class is extended by specific pilot behavior classes.


This project was developed to enhance **object-oriented programming (OOP) skills**, focusing on **inheritance, polymorphism, encapsulation, and simulation design** in C++.