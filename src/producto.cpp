#include "producto.hpp"

namespace garrafa 
{
    Producto::Producto() 
    {
        id = 0;
        nombre = "";
        precioBase = 0.0;
    }

    Producto::~Producto() 
    {
        // Se ejecuta automáticamente en la jerarquía polimórfica
    }

    void Producto::configurarBase(int _id, const std::string& _nombre, double _precio) 
    {
        id = _id;
        nombre = _nombre;
        precioBase = _precio;
    }

    int Producto::obtenerId() const 
    { 
        return id; 
    }

    std::string Producto::obtenerNombre() const 
    { 
        return nombre; 
    }

    double Producto::obtenerPrecioBase() const 
    { 
        return precioBase; 
    }
}