#include "cliente.hpp"
#include <iostream>
#include <iomanip>

namespace garrafa 
{
    Cliente::Cliente() 
    {
        id = 0;
        nombreCompleto = "";
        dni = "";
        telefono = "";
    }

    void Cliente::configurar(int _id, const std::string& _nombre, const std::string& _dni, const std::string& _telefono) 
    {
        id = _id;
        nombreCompleto = _nombre;
        dni = _dni;
        telefono = _telefono;
    }

    int Cliente::obtenerId() const 
    { 
        return id; 
    }
    
    std::string Cliente::obtenerNombreCompleto() const 
    { 
        return nombreCompleto; 
    }
    
    std::string Cliente::obtenerDni() const 
    { 
        return dni; 
    }
    
    std::string Cliente::obtenerTelefono() const 
    { 
        return telefono; 
    }

    void Cliente::mostrarInformacion() const 
    {
        std::cout << "  [Cliente #" << id << "] " 
                  << std::left << std::setw(30) << nombreCompleto 
                  << " | DNI: " << std::setw(10) << dni 
                  << " | Tel: " << telefono << "\n";
    }
}