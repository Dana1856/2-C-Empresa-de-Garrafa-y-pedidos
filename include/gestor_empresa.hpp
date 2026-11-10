#ifndef GESTOR_EMPRESA_HPP
#define GESTOR_EMPRESA_HPP

#include "producto.hpp"
#include "cliente.hpp"
#include "pedido.hpp"
#include "empleado.hpp"

namespace garrafa 
{
    const int MAX_ITEMS = 256;

    class GestorEmpresa 
    {
    private:
        /**
         * Arreglo estático de punteros simples a la clase base abstracta.
         * Esta estructura permite almacenar clases derivadas en el heap
         */
        Producto* productos[MAX_ITEMS]; 
        Cliente* clientes;      
        Pedido* pedidos; 
        Empleado* empleados;              
     
        int cantidadProductos;
        int cantidadClientes;
        int cantidadPedidos;
        int cantidadEmpleados;  

    public:
        GestorEmpresa();
        ~GestorEmpresa();

        bool registrarGarrafa(int id, const std::string& nombre, double precio, int kilos);
        bool registrarAccesorio(int id, const std::string& nombre, double precio, const std::string& tipo);
        bool registrarCliente(int id, const std::string& nombre, const std::string& dni, const std::string& telefono);
        bool registrarEmpleado(int id, const std::string& nombre, const std::string& contacto);




        Pedido* crearPedido(int idPedido, int idCliente);

        Producto* buscarProductoPorId(int id) const;
        Cliente* buscarClientePorId(int id) const;
        Pedido* buscarPedidoPorId(int id) const;
        Empleado* buscarEmpleadoPorId(int id) const;

        void listarProductos() const;
        void listarClientes() const;
        void mostrarTodosLosPedidos() const;
        void listarEmpleados() const;
    };
}

#endif // GESTOR_EMPRESA_HPP