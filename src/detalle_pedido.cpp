#include "detalle_pedido.hpp"
#include <iostream>
#include <iomanip>

namespace garrafa 
{
    DetallePedido::DetallePedido() 
    {
        producto = nullptr;
        cantidad = 0;
    }

    void DetallePedido::configurar(Producto* _producto, int _cantidad) 
    {
        producto = _producto;
        cantidad = _cantidad;
    }

    double DetallePedido::calcularSubtotal() const 
    {
        if (producto != nullptr) 
        {
            // Resolución dinámica de métodos (Dynamic Dispatch)
            return producto->calcularPrecioFinal() * cantidad;
        }
        return 0.0;
    }

    void DetallePedido::mostrarDetalle() const 
    {
        if (producto != nullptr) 
        {
            std::cout << "    - " << std::left << std::setw(25) << producto->obtenerNombre()
                      << " Cant: " << std::setw(3) << cantidad
                      << " ($" << std::fixed << std::setprecision(2) << producto->calcularPrecioFinal() << " c/u)"
                      << " -> Subtotal: $" << calcularSubtotal() << "\n";
        }
    }
}