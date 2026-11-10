#ifndef PRODUCTO_HPP
#define PRODUCTO_HPP

#include <string>

namespace garrafa 
{
    class Producto 
    {
    protected:
        int id;
        std::string nombre;
        double precioBase;

    public:
        Producto();
        
        virtual ~Producto();

        void configurarBase(int _id, const std::string& _nombre, double _precio);

        int obtenerId() const;
        std::string obtenerNombre() const;
        double obtenerPrecioBase() const;

        virtual void mostrarInformacion() const = 0;
        virtual double calcularPrecioFinal() const = 0;
    };
}

#endif