#include "accesorio.hpp"
#include <iostream>
#include <iomanip>

namespace garrafa 
{
    Accesorio::Accesorio() 
    {
        tipo = "";
    }

    void Accesorio::configurar(int _id, const std::string& _nombre, double _precio, const std::string& _tipo) 
    {
        configurarBase(_id, _nombre, _precio);
        tipo = _tipo;
    }

    double Accesorio::calcularPrecioFinal() const 
    {
        return precioBase * 1.21;
    }

    void Accesorio::mostrarInformacion() const 
    {
        std::cout << "  [ACCESORIO ID " << std::setw(2) << id << "] " 
                  << std::left << std::setw(20) << nombre 
                  << " | Tipo: " << std::left << std::setw(11) << tipo
                  << " | Precio Final: $" << std::fixed << std::setprecision(2) << calcularPrecioFinal() << "\n";
    }
}