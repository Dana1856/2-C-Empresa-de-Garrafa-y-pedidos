#include "garrafa_gas.hpp"
#include <iostream>
#include <iomanip>

namespace garrafa 
{
    GarrafaGas::GarrafaGas() 
    {
        capacidadKilos = 0;
    }

    void GarrafaGas::configurar(int _id, const std::string& _nombre, double _precio, int _kilos) 
    {
        configurarBase(_id, _nombre, _precio);
        capacidadKilos = _kilos;
    }

    double GarrafaGas::calcularPrecioFinal() const 
    {
        return precioBase + (capacidadKilos * 200.0);
    }

    void GarrafaGas::mostrarInformacion() const 
    {
        std::cout << "  [GARRAFA ID " << std::setw(3) << id << "] " 
                  << std::left << std::setw(20) << nombre 
                  << " | Capacidad: " << std::setw(2) << capacidadKilos << " kg"
                  << " | Precio Final: $" << std::fixed << std::setprecision(2) << calcularPrecioFinal() << "\n";
    }
}