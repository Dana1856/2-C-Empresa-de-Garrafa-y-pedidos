#include "pedido.hpp"
#include <iostream>
#include <iomanip>

namespace garrafa 
{
    Pedido::Pedido() 
    {
        id = 0;
        cliente = nullptr;
        detalles = new DetallePedido[MAX_DETALLES];
        cantidadDetalles = 0;
    }

    Pedido::~Pedido() 
    {
        if (detalles != nullptr) 
        {
            delete[] detalles;
            detalles = nullptr;
        }
        cliente = nullptr; 
    }

    void Pedido::configurar(int _id, Cliente* _cliente) 
    {
        id = _id;
        cliente = _cliente;
        cantidadDetalles = 0; 
    }

    bool Pedido::agregarArticulo(Producto* producto, int cantidad) 
    {
        if (producto == nullptr || cantidad <= 0 || cantidadDetalles >= MAX_DETALLES) 
        {
            return false;
        }

        detalles[cantidadDetalles].configurar(producto, cantidad);
        cantidadDetalles++;
        
        return true;
    }

    double Pedido::calcularTotal() const 
    {
        double total = 0.0;
        int i = 0;
        
        while (i < cantidadDetalles) 
        {
            total += detalles[i].calcularSubtotal();
            i++;
        }
        
        return total;
    }

    int Pedido::obtenerId() const 
    { 
        return id; 
    }

    void Pedido::mostrarPedido() const 
    {
        std::cout << "\n====================================================================\n";
        std::cout << " PEDIDO NRO: #" << id << "\n";
        std::cout << "--------------------------------------------------------------------\n";
        std::cout << " CLIENTE ASIGNADO:\n";
        
        if (cliente != nullptr) 
        {
            std::cout << "   Nombre: " << cliente->obtenerNombreCompleto() 
                      << " | DNI: " << cliente->obtenerDni() 
                      << " | Tel: " << cliente->obtenerTelefono() << "\n";
        } 
        else 
        {
            std::cout << "   [Sin cliente asignado]\n";
        }
        
        std::cout << "--------------------------------------------------------------------\n";
        std::cout << " PRODUCTOS SOLICITADOS:\n";
        
        if (cantidadDetalles == 0) 
        {
            std::cout << "    (Sin productos cargados)\n";
        } 
        else 
        {
            int i = 0;
            while (i < cantidadDetalles) 
            {
                detalles[i].mostrarDetalle();
                i++;
            }
        }
        
        std::cout << "--------------------------------------------------------------------\n";
        std::cout << " TOTAL FACTURADO: $" << std::fixed << std::setprecision(2) << calcularTotal() << "\n";
        std::cout << "====================================================================\n";
    }
}