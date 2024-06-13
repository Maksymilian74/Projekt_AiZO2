cmake_minimum_required(VERSION 3.27)
project(Projekt_AiZO2)

set(CMAKE_CXX_STANDARD 17)

add_executable(Projekt_AiZO2 Main/Main.cpp
        Algorithms/Prim.cpp
        Algorithms/Prim.h
        Main/Menu.cpp
        Main/Menu.h
        Algorithms/Dijkstra.cpp
        Algorithms/Dijkstra.h
        Algorithms/BellmanFord.cpp
        Algorithms/BellmanFord.h
        Utils/FillStructure.cpp
        Utils/FillStructure.h
        Submenu/SimulationSolving.cpp
        Submenu/SimulationSolving.h
        Submenu/TestSolving.cpp
        Submenu/TestSolving.h
        Structures/IncidenceMatrix.cpp
        Structures/IncidenceMatrix.h
        Structures/AdjacencyList.cpp
        Structures/AdjacencyList.h
        Algorithms/Kruskal.cpp
        Algorithms/Kruskal.h
        Structures/MinHeap.cpp
        Structures/MinHeap.h
        Main/Main.cpp
)

set(CMAKE_EXE_LINKER_FLAGS "-static")
