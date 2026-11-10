#include <iostream>
#include <cstdlib>
#include "utilidades.hpp"

    void pauseConsole() {
        std::cin.ignore();
        std::cin.get();
    }

    void clearConsole() {
        // Corrección de la sintaxis de las directivas del preprocesador
        #if defined(_WIN32) || defined(_WIN64)
            system("cls");
        #elif defined(__APPLE__) || defined(__unix__)
            system("clear");
        #endif
    }
