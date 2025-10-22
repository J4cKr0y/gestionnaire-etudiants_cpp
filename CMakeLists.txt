cmake_minimum_required(VERSION 3.10)
project(GestionnaireEtudiants CXX)
set(CMAKE_CXX_STANDARD 11) 
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Inclure les dossiers pour les headers
include_directories(include .)

# Définir la cible et les sources
add_executable(
    Gest_app
    main.cpp
    src/demonstration_pointeur.cpp
    src/etudiant.cpp
)

# Configuration de base pour C++11 (pour std::cout, etc.)
target_compile_features(Gest_app PRIVATE cxx_std_11)
