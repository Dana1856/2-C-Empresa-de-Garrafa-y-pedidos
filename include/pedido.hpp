#ifndef PEDIDO_HPP
#define PEDIDO_HPP

#include "cliente.hpp"
#include "detalle_pedido.hpp"

namespace garrafa 
{
    const int MAX_DETALLES = 256;

    /**
     * @class Pedido
     * @brief Compone un arreglo de detalles e implementa agregación con un Cliente.
     */
    class Pedido 
    {
    private:
        int id;
        Cliente* cliente;
        DetallePedido* detalles;
        int cantidadDetalles;

    public:
        Pedido();
        ~Pedido();

        void configurar(int _id, Cliente* _cliente);
        bool agregarArticulo(Producto* producto, int cantidad);
        double calcularTotal() const;
        int obtenerId() const;
        void mostrarPedido() const;
    };
}

#endif // PEDIDO_HPP