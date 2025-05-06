#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include <sstream>
// Grid parameters
const int GRID_SIZE = 50; // Grid size
const double DELTA_X = 1.0; // Distance between points
const double DELTA_T = 0.01; // Time step
const double ALPHA = 0.01; // Thermal diffusivity
const int TIME_STEPS = 100; // Number of time steps

// Update the temperature grid using the heat diffusion equation
void updateTemperature(std::vector<std::vector<double>>& grid, std::vector<std::vector<double>>& newGrid) {
    for (int i = 1; i < GRID_SIZE - 1; ++i) {
        for (int j = 1; j < GRID_SIZE - 1; ++j) {
            newGrid[i][j] = grid[i][j] + ALPHA * DELTA_T / (DELTA_X * DELTA_X) * (
                grid[i + 1][j] + grid[i - 1][j] + grid[i][j + 1] + grid[i][j - 1] - 4 * grid[i][j]
                );
        }
    }
}

// Save the grid data to a file for visualization
void saveGrid(const std::vector<std::vector<double>>& grid, int step) {
    std::ofstream file("heatmap_" + std::to_string(step) + ".dat");
    for (int i = 0; i < GRID_SIZE; ++i) {
        for (int j = 0; j < GRID_SIZE; ++j) {
            file << i << " " << j << " " << grid[i][j] << "\n";
        }
        file << "\n";
    }
    file.close();
}

int main() {
    // Initialize the grid
    std::vector<std::vector<double>> grid(GRID_SIZE, std::vector<double>(GRID_SIZE, 0.0));
    std::vector<std::vector<double>> newGrid(GRID_SIZE, std::vector<double>(GRID_SIZE, 0.0));

    // Set initial heat source at the center
    int mid = GRID_SIZE / 2;
    grid[mid][mid] = 100.0;

    // Run the simulation
    for (int step = 0; step < TIME_STEPS; ++step) {
        updateTemperature(grid, newGrid);
        grid.swap(newGrid);
        saveGrid(grid, step);
        std::cout << "Step " << step << " completed.\n";
    }

    std::cout << "Simulation completed. Data saved to files.\n";
    return 0;
}
