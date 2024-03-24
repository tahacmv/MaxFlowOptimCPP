//
// Created by tmmot on 24/03/2024.
//
#include "GraphGenerator.hpp"

#define MIN_CAP 1
#define MAX_CAP 100

// Helper function to generate a random capacity
int randomCapacity() {
    static std::mt19937 rng(std::random_device{}()); // Random number generator initialized with non-deterministic seed
    std::uniform_int_distribution<int> dist(MIN_CAP, MAX_CAP);
    return dist(rng);
}

// Function to generate a filename based on the current date and time
std::string generateFilename() {
    // Get the current working directory
    std::filesystem::path cwd = std::filesystem::current_path();

    // Build the path to the graphs folder within the current working directory
    std::filesystem::path graphsDir = cwd / "graphs";

    // Get the current time to use in the filename
    auto now = std::chrono::system_clock::now();
    auto now_c = std::chrono::system_clock::to_time_t(now);

    // Use a stringstream to build the filename with the date and time
    std::stringstream ss;
    ss << graphsDir.string() << "/maxflow_graph_" << std::put_time(std::localtime(&now_c), "%Y%m%d_%H%M%S.dimacs");

    return ss.str();
}

void CreateGraph(int numUC, int numIT) {

    auto start = std::chrono::high_resolution_clock::now();

    std::string filename = generateFilename();
    std::ofstream outputFile(filename);

    if (!outputFile) {
        std::cerr << "Could not open file for writing." << std::endl;
        return;
    }

    // Write the problem line (assuming 'a' for arc in max flow problems)
    int numVertices = numUC + numIT + 2; // +2 for source and sink
    outputFile << "p max " << numVertices << " " << (numUC + numUC*numIT + numIT + numIT) << "\n";

    // Connect source (vertex 1) to all UC nodes
    for (int i = 1; i <= numUC; ++i) {
        outputFile << "a 1 " << (i + 1) << " " << randomCapacity() << "\n";
    }

    // Connect all UC nodes to IT nodes
    for (int i = 1; i <= numUC; ++i) {
        for (int j = 1; j <= numIT; ++j) {
            outputFile << "a " << (i + 1) << " " << (numUC + j + 1) << " " << randomCapacity() << "\n";
        }
    }

    // Connect all IT nodes to the sink
    for (int i = 1; i <= numIT; ++i) {
        outputFile << "a " << (numUC + i + 1) << " " << (numVertices) << " " << randomCapacity() << "\n";
    }

    // Optionally, connect source to IT nodes directly for more paths
    for (int i = 1; i <= numIT; ++i) {
        outputFile << "a 1 " << (numUC + i + 1) << " " << randomCapacity() << "\n";
    }

    outputFile.close();
    std::cout << "DIMACS file for max flow problem generated: maxflow_graph.dimacs" << std::endl;


    // End timing
    auto end = std::chrono::high_resolution_clock::now();

    // Calculate and print execution time
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "DIMACS file for max flow problem generated: maxflow_graph.dimacs\n";
    std::cout << "Execution time: " << duration.count() << " milliseconds\n";
}