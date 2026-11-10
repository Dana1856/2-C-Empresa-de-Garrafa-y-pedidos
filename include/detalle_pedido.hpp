#ifndef DETALLE_PEDIDO_HPP
#define DETALLE_PEDIDO_HPP

#include "producto.hpp"

namespace garrafa 
{
    class DetallePedido 
    {
    private:
        Producto* producto; //A la clase base
        int cantidad;

    public:
        DetallePedido();
        void configurar(Producto* _producto, int _cantidad);
        double calcularSubtotal() const;
        void mostrarDetalle() const;
    };
}

#endif // DETALLE_PEDIDO_HPP