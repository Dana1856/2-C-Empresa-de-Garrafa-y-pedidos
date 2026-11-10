#ifndef APLICACION_HPP
#define APLICACION_HPP

#include "gestor_empresa.hpp"

namespace garrafa 
{
    /**
     * @class Aplicacion
     * @brief Interfaz de usuario de consola encapsulada.
     */
    class Aplicacion 
    {
    private:
        GestorEmpresa gestor;
        bool enEjecucion;

        void mostrarMenu();
        void accionRegistrarGarrafa();
        void accionRegistrarAccesorio();
        void accionRegistrarCliente();
        void accionCrearPedido();
        void accionAgregarArticuloAPedido();
        void accionListarProductos();
        void accionListarClientes();
        void accionListarPedidos();
        void accionRegistrarEmpleado();
        void accionListarEmpleados();
        
        void cargarDatosDePrueba();

    public:
        Aplicacion();
        void ejecutar();
    };
}

#endif // APLICACION_HPP