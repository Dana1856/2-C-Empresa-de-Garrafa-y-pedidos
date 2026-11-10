#!/bin/bash
echo "Iniciando proceso de compilación..."
g++ -std=c++17 -Wall -Wextra -Wpedantic -Werror -I./include src/*.cpp -o app.exe

if [ $? -eq 0 ]; then
    echo "Compilación finalizada exitosamente. Ejecute ./app.exe para iniciar."
else
    echo "Error en la compilación."
fi