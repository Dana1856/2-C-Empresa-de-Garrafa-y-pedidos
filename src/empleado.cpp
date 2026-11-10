#include "empleado.hpp"
#include <iostream>
#include <iomanip>

namespace garrafa 
{
    Empleado::Empleado() 
    {
        id = 0;
        nombre = "";
        contacto = "";
    }

    void Empleado::configurar(int _id, const std::string& _nombre, const std::string& _contacto) 
    {
        id = _id;
        nombre = _nombre;
        contacto = _contacto;
    }

    int Empleado::obtenerId() const 
    { 
        return id; 
    }
    
    std::string Empleado::obtenerNombre() const 
    { 
        return nombre; 
    }
    
    std::string Empleado::obtenerContacto() const 
    { 
        return contacto; 
    }

    void Empleado::mostrarInformacion() const 
    {
        std::cout << "  [Empleado #" << id << "] " 
                  << std::left << std::setw(20) << nombre 
                  << " | Contacto: " << contacto << "\n";
    }
}