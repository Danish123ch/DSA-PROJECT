University of Gujrat (UOG) Navigation System 🎓📍
🚀 Overview
The UOG Navigation System is a C++ application designed to help students and visitors find the most efficient routes within the university campus. By representing the campus as a Weighted Graph, the system calculates paths based on both the number of buildings (BFS) and the actual physical distance in meters (Dijkstra).

🛠 Technical Logic & Algorithms
As a Logical Builder, I implemented three core graph traversal algorithms to power this system:

DFS (Depth First Search): Used for initial route verification to check if a path exists between two locations.

BFS (Breadth-First Search): Optimized to find the path with the minimum number of buildings/stops.

Dijkstra’s Algorithm: Implemented to calculate the shortest physical distance between two points using an adjacency matrix with weighted edges.

🗺 Campus Mapping
The system features 16 key campus locations, including:

Main Gate & Admin Block

CS Department & Library

Academic Blocks: Aljazri, Arfa Karim, Ibn-e-Sina, Ibn-e-Khuldun, etc.

Student Hubs: Hostel, Sports Complex, and various Cafes.

💻 Key Features
String-to-Int Mapping: Users can type full location names instead of ID numbers for a better user experience.

Recursive Path Reconstruction: Uses a recursive showRoute function to backtrack and display the full path from start to finish.

Real-world Distance: The adjacency matrix is populated with real-world distance estimates in meters.

👤 Author
[Danish Shafique] Computer Science Student | Logical Builder | Communication Expert
