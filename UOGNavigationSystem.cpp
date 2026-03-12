#include <iostream>
#include<string>
using namespace std;

int totalPlaces = 16;

bool visited[16] = {false};

  int universityMap[16][16] =
{
    //0    1     2     3     4     5     6     7     8     9    10    11    12    13    14    15
    {0,   400,  250,   0,   0,   200,  150,   0,    0,    0,    0,    0,   150,    0,    0,    0}, // 0 Main Gate
    {400,   0,   0,   350, 200,   0,    0,    300, 300,  300,  300,  300,   0,     0,    0,    300}, // 1 Admin Block
    {250,   0,   0,   200, 350,   0,    0,     70,   60,   80,   80,   70,   0,     0,    0,    80}, // 2 CS Department
    {0,   350, 200,    0,  200,  50,    0,     0,    0,    0,    0,    0,   50,     0,    0,    0}, // 3 Library
    {0,   200, 350,   200,   0,  100,   0,     0,    0,    0,    0,    0,    0,     0,    50,    0}, // 4 Hostel
    {200,   0,   0,    50, 100,   0,   50,     0,    0,    0,    0,    0,    0,     0,    0,     0}, // 5 P Cafe
    {150,   0,   0,     0,   0,  50,    0,     0,    0,    0,    0,    0,   50,     0,    0,     0}, // 6 M Cafe
    {0,   300,  70,     0,   0,   0,    0,     0,   60,   60,   50,   50,   0,     0,    0,    50}, // 7 Aljazri Block
    {0,   300,  60,     0,   0,   0,    0,    60,    0,   50,   50,   50,   0,     0,    0,    50}, // 8 Arfa Karim Block
    {0,   300,  80,     0,   0,   0,    0,    60,   50,    0,   60,   50,   0,     0,    0,    50}, // 9 Ibn-e-Sina Block
    {0,   300,  80,     0,   0,   0,    0,    50,   50,   60,    0,   50,   0,     0,    0,    50}, //10 Ibn-e-Khuldun Block
    {0,   300,  70,     0,   0,   0,    0,    50,   50,   50,   50,    0,   60,     0,    0,    50}, //11 Al Khawazmi
    {150,   0,   0,    50,   0,   0,   50,     0,    0,    0,    0,   60,    0,    40,    0,     0}, //12 Main Cafe
    {0,     0,   0,     0,   0,   0,    0,     0,    0,    0,    0,    0,   40,     0,   100,     0}, //13 Sports Complex
    {0,     0,   0,     0,  50,   0,    0,     0,    0,    0,    0,    0,    0,   100,    0,    50}, //14 Ground
    {0,   300,  80,     0,   0,   0,    0,    50,   50,   50,   50,   50,    0,     0,    50,     0}  //15 New Block
};

// Location names
string place[16] = {
    "Main Gate",
    "Admin Block",
    "CS Department",
    "Library",
    "Hostel",
    "P Cafe",
    "M Cafe",
    "Aljazri Block",
    "Arfa Karim Block",
    "Ibn-e-Sina Block",
    "Ibn-e-Khuldun Block",
    "Al Khawazmi",
    "Main Cafe",
    "Sports Complex",
    "Ground",
    "New Block"
};

int stringtoint(string str){
    for(int i=0;i<=15;i++){
        if(place[i]==str){
            return i;
        }
    }
    cout<<"place not found"<<endl;
}

void showRoute(int previousLocation[], int destination)
{
    if (previousLocation[destination] == -1)
    {
        cout << place[destination];
        return;
    }
    
    showRoute(previousLocation, previousLocation[destination]);
    
    cout << " -> " << place[destination];
}

bool checkRouteDFS(int map[16][16], int start, int end, bool visited[])
{
    if (start == end)
        return true;

    visited[start] = true;

    for (int i = 0; i < totalPlaces; i++)
    {
        if (map[start][i] != 0 && !visited[i])
        {
            if (checkRouteDFS(map, i, end, visited))
                return true;
        }
    }
    return false;
}

void showBFSPath(int map[16][16], int start, int end)
{
    bool visited[16] = {false};
    int parent[16];
    int queue[50];
    int front = 0, rear = 0;

    for (int i = 0; i < totalPlaces; i++){
        parent[i] = -1;
    }

    visited[start] = true;
    queue[rear++] = start;

    while (front < rear)
    {
        int current = queue[front++];

        if (current == end)
            break;

        for (int i = 0; i < totalPlaces; i++)
        {
            if (map[current][i] != 0 && !visited[i])
            {
                visited[i] = true;
                parent[i] = current;
                queue[rear++] = i;
            }
        }
    }

    cout << "\nBFS Path (Minimum Buildings):\n";
    showRoute(parent, end);
    cout << endl;
}

// ---------- Dijkstra: Shortest distance ----------
void showShortestPath(int map[16][16], int start, int end)
{
    int distance[16];
    bool visited[16];
    int parent[16];

    for (int i = 0; i < totalPlaces; i++)
    {
        distance[i] = 1000;
        visited[i] = false;
        parent[i] = -1;
    }

    distance[start] = 0;

    for (int count = 0; count < totalPlaces - 1; count++)
    {
        int smallest = 1000;
        int current = -1;

        for (int i = 0; i < totalPlaces; i++)
        {
            if (!visited[i] && distance[i] < smallest)
            {
                smallest = distance[i];
                current = i;
            }
        }

        if (current == -1)
            break;

        visited[current] = true;

        for (int i = 0; i < totalPlaces; i++)
        {
            if (!visited[i] && map[current][i] != 0 &&
                distance[current] + map[current][i] < distance[i])
            {
                distance[i] = distance[current] + map[current][i];
                parent[i] = current;
            }
        }
    }

    cout << "\nDijkstra Path (Shortest Distance):\n";
    cout << "Route: ";
    showRoute(parent, end);
    cout << "\nTotal Distance: " << distance[end] << " meters\n";
}

// ---------- Main ----------
int main()
{
    cout << "===== University of Gujrat Navigation System =====\n\n";
    cout << "Locations:\n";
    for (int i = 0; i < totalPlaces; i++)
        cout << i << " - " << place[i] << endl;

    string starts, ends;
    cout << "\nEnter current location : ";
    getline(cin,starts);
    int start=stringtoint(starts);

    cout << "Enter destination : ";
    getline(cin,ends);
    int end=stringtoint(ends);

    if (start == end)
    {
    cout << "\nYou are already standing at " << place[start] << endl;
    return 0;
    }

    cout << "\nChecking route (DFS)...\n";
    if (!checkRouteDFS(universityMap, start, end, visited))
    {
        cout << "No route exists.\n";
        return 0;
    }

    cout << "Route exists\n";

    showBFSPath(universityMap, start, end);
    showShortestPath(universityMap, start, end);

    return 0;
}