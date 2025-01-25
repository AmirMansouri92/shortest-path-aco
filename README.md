# **Shortest Path Problem Solver Using Ant Colony Optimization**

![Project Logo (optional)](path/to/logo.png)

## **Overview**
This repository contains a C++ implementation of the **Shortest Path Problem (SPP)** using the nature-inspired **Ant Colony Optimization (ACO)** algorithm. The objective is to find an optimal or near-optimal path between two nodes in a graph while minimizing the total distance.  

The algorithm is designed to handle dynamic and complex graphs, making it suitable for real-world applications like logistics, network routing, and robotics.

---

## **Features**
- Implements Ant Colony Optimization to solve SPP.
- Efficient for large and complex graphs.
- Adapts dynamically to changes in graph weights.
- Easily extendable for other optimization problems.

---

## **Getting Started**

### Prerequisites
Ensure the following software is installed on your system:
- **C++ Compiler**: GCC 9.0+ or equivalent.
- **CMake** (optional, for building the project).
- Any modern IDE or command-line tools for C++.

### Installation
### Installation
1. Clone the repository:
   ```bash
   git clone https://github.com/AmirMansouri92/shortest-path-aco.git
   cd shortest-path-aco
   ```
2. Compile the program using a C++ compiler:
   ```bash
   g++ -o ANTSPP ANTSPP.cpp
   ```

3. Run the program:
   ```bash
   ./ANTSPP
   ```
---

## **Usage**
Provide an example of how users can interact with your program:

### Input Format
Define the graph in the file (`SPP_data.txt`):
   ```
   6   // Number of nodes
   7   // Number of edges
   4   // source node
   5   // destination node 
   0 1 1   // Distance between node 0 and 1 is 1
   0 3 2   // Distance between node 0 and 3 is 2
   1 3 6   // Distance between node 1 and 3 is 6
   ```


### Running the Program
Run the compiled program with `SPP_data.txt` as input:
```bash
./ANTSPP
```

### Output
The program will display:
- The best path.
- The total distance (the best path length found by the algorithm).
- Performance metrics (e.g., iterations, the best path length in each iteration).

---

## **Algorithm Details**
The **Ant Colony Optimization (ACO)** algorithm works as follows:
1. **Initialization**: Ants are placed on the source node, and the graph is initialized with pheromone levels.
2. **Path Construction**: Ants explore paths based on pheromone levels and heuristic information.
3. **Pheromone Update**:
   - Shorter paths are reinforced with higher pheromone levels.
   - Pheromones evaporate over time to avoid over-reinforcement.
4. **Convergence**: The algorithm iterates until the shortest path is found or a stopping criterion is met.
### Termination Criterion
The algorithm terminates after a predefined number of iterations, ensuring computational feasibility.

---

## **File Structure**
```plaintext
.
├── ANTSPP                 # Compiled binary (generated after compilation)
├── ANTSPP.cpp             # Source code for the algorithm
├── README.md              # Documentation (this file)
├── SPP_data.txt           # Input graph data
├── SPP_data_explanation.txt # Explanation of the input file format
├── a.out                  # Alternate compiled binary (optional)
```

---

## **Examples**
Include an example run:
```bash
Input Graph:
Nodes: 6
Edges: 7

Shortest Path from Node 4 to Node 5:
best path: 4 3 5
Total Distance: 7
```

---

## **Dependencies**
List any libraries or frameworks used in your project:
- Standard C++ STL
- CMake (optional for building)

---

## **Contributing**
Contributions are welcome!  
1. Fork the repository.
2. Create a feature branch:
   ```bash
   git checkout -b feature-name
   ```
3. Commit your changes:
   ```bash
   git commit -m "Add feature-name"
   ```
4. Push to the branch:
   ```bash
   git push origin feature-name
   ```
5. Open a pull request.

---


## **Acknowledgments**
- Inspired by natural ant behavior and optimization techniques.
- Based on research in combinatorial optimization problems.

---

## **Contact**
For any questions, feel free to reach out:  
Amir Mansouri 
Amir_mansouri92@yahoo.com  
https://github.com/AmirMansouri92/
