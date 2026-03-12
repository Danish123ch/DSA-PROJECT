# UOG Campus Navigation System 🎓📍

A high-performance C++ navigation tool designed for the **University of Gujrat** campus. This project solves pathfinding problems by representing the campus as a weighted graph and applying advanced Data Structures and Algorithms (DSA).

### 🚀 Key Logic & Algorithms
As a **Logical Builder**, I implemented three primary algorithms from scratch to ensure efficient navigation:
* **Dijkstra’s Algorithm:** Calculates the absolute shortest physical distance (in meters) between any two locations using a weighted adjacency matrix.
* **BFS (Breadth-First Search):** Finds the "Minimum Building" path, perfect for users wanting the fewest stops between locations.
* **DFS (Depth-First Search):** Performs a pre-check to verify if a valid path exists before running more complex calculations.

### 🛠 Technical Features
* **Custom Graph Implementation:** Uses a 16x16 adjacency matrix to map 16 key campus locations including the Admin Block, CS Department, and various Cafes.
* **Recursive Path Reconstruction:** Utilizes a recursive backtracking function to display the full route names in the correct sequence.
* **String-to-Int Mapping:** Includes a custom parser that allows users to input location names directly instead of IDs, improving the user experience.

### 📂 Project Structure
* **Language:** C++
* **Paradigm:** Procedural with a focus on Algorithm Efficiency.
* **Storage:** In-memory graph representation with real-world distance data.

### 👤 Author
**[Danish Shafique]** *Computer Science Student | Logical Builder | Communication Expert*

---
*Developed as part of my deep dive into Graph Theory and Pathfinding Algorithms.*
