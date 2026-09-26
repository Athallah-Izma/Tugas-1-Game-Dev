#include <iostream>
#include <cmath>
#include <vector>

// 1. Identifikasi Algoritma: 
// - Finite State Machine (FSM) untuk pengambilan keputusan (Patrol/Chase).
// - Euclidean Distance untuk mendeteksi jarak Player.
// - A* Pathfinding untuk mencari rute terpendek menuju Player (disimulasikan di sini).

struct Point { int x, y; };

// Algoritma Euclidean Distance
double calculateDistance(Point a, Point b) {
    return std::sqrt(std::pow(b.x - a.x, 2) + std::pow(b.y - a.y, 2));
}

// Simulasi A* Pathfinding (Simplified)
std::vector<Point> findPathAStar(Point start, Point goal) {
    std::vector<Point> path;
    // Logika A* sebenarnya memerlukan heuristic, open list, dan closed list.
    // Di sini kita asumsikan fungsi mengembalikan rute (path).
    path.push_back(start);
    // ... kalkulasi rute ...
    path.push_back(goal);
    return path;
}

// Finite State Machine (FSM)
enum class State { PATROL, CHASE };

int main() {
    Point player = {10, 10};
    Point enemy = {2, 2};
    State enemyState = State::PATROL;
    
    double detectionRadius = 15.0;
    
    // FSM Update
    double distance = calculateDistance(enemy, player);
    
    if (distance <= detectionRadius) {
        enemyState = State::CHASE;
        std::cout << "Player terdeteksi! Jarak: " << distance << "\n";
        
        // Mencari jalur jika dalam mode CHASE
        std::vector<Point> path = findPathAStar(enemy, player);
        std::cout << "Mengejar player...\n";
    } else {
        enemyState = State::PATROL;
        std::cout << "Patroli mencari player...\n";
    }

    return 0;
}
