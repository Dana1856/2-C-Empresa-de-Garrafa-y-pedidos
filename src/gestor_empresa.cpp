#include "gestor_empresa.hpp"
#include "garrafa_gas.hpp"
#include "accesorio.hpp"
#include <iostream>

namespace garrafa 
{
    GestorEmpresa::GestorEmpresa() 
    {
        cantidadProductos = 0;
        cantidadClientes = 0;
        cantidadPedidos = 0;
        cantidadEmpleados = 0;

        clientes = new Cliente[MAX_ITEMS];
        pedidos = new Pedido[MAX_ITEMS];
        empleados = new Empleado[MAX_ITEMS];

        int i = 0;
        while (i < MAX_ITEMS) 
        {
            productos[i] = nullptr;
            i++;
        }
    }

    GestorEmpresa::~GestorEmpresa() 
    {
        int i = 0;
        while (i < cantidadProductos) 
        {
            delete productos[i];
            i++;
        }
        delete[] clientes;
        delete[] pedidos;
        delete[] empleados;
    }

    bool GestorEmpresa::registrarGarrafa(int id, const std::string& nombre, double precio, int kilos) 
    {
        if (cantidadProductos >= MAX_ITEMS) 
        {
            return false;
        }
        
        GarrafaGas* nuevaGarrafa = new GarrafaGas();
        nuevaGarrafa->configurar(id, nombre, precio, kilos);
        
        productos[cantidadProductos] = nuevaGarrafa;
        cantidadProductos++;
        
        return true;
    }

    bool GestorEmpresa::registrarAccesorio(int id, const std::string& nombre, double precio, const std::string& tipo) 
    {
        if (cantidadProductos >= MAX_ITEMS) 
        {
            return false;
        }
        
        Accesorio* nuevoAccesorio = new Accesorio();
        nuevoAccesorio->configurar(id, nombre, precio, tipo);
        
        productos[cantidadProductos] = nuevoAccesorio;
        cantidadProductos++;
        
        return true;
    }

    bool GestorEmpresa::registrarCliente(int id, const std::string& nombre, const std::string& dni, const std::string& telefono) 
    {
        if (cantidadClientes >= MAX_ITEMS) 
        {
            return false;
        }
        
        clientes[cantidadClientes].configurar(id, nombre, dni, telefono);
        cantidadClientes++;
        
        return true;
    }

    bool GestorEmpresa::registrarEmpleado(int id, const std::string& nombre, const std::string& contacto) 
    {
        if (cantidadEmpleados >= MAX_ITEMS) 
        {
            return false;
        }
        
        empleados[cantidadEmpleados].configurar(id, nombre, contacto);
        cantidadEmpleados++;
        
        return true;
    }

    Pedido* GestorEmpresa::crearPedido(int idPedido, int idCliente) 
    {
        if (cantidadPedidos >= MAX_ITEMS) 
        {
            return nullptr;
        }

        Cliente* cli = buscarClientePorId(idCliente);
        if (cli == nullptr) 
        {
            return nullptr;
        }

        pedidos[cantidadPedidos].configurar(idPedido, cli);
        Pedido* nuevoPedidoPtr = &pedidos[cantidadPedidos]; 
        cantidadPedidos++;
        
        return nuevoPedidoPtr;
    }

    Producto* GestorEmpresa::buscarProductoPorId(int id) const 
    {
        int i = 0;
        while (i < cantidadProductos) 
        {
            if (productos[i]->obtenerId() == id) 
            {
                return productos[i];
            }
            i++;
        }
        return nullptr;
    }

    Cliente* GestorEmpresa::buscarClientePorId(int id) const 
    {
        int i = 0;
        while (i < cantidadClientes) 
        {
            if (clientes[i].obtenerId() == id) 
            {
                return &clientes[i];
            }
            i++;
        }
        return nullptr;
    }

    Pedido* GestorEmpresa::buscarPedidoPorId(int id) const 
    {
        int i = 0;
        while (i < cantidadPedidos) 
        {
            if (pedidos[i].obtenerId() == id) 
            {
                return &pedidos[i];
            }
            i++;
        }
        return nullptr;
    }

    Empleado* GestorEmpresa::buscarEmpleadoPorId(int id) const 
    {
        int i = 0;
        while (i < cantidadEmpleados) 
        {
            if (empleados[i].obtenerId() == id) 
            {
                return &empleados[i];
            }
            i++;
        }
        return nullptr;
    }

    void GestorEmpresa::listarProductos() const 
    {
        std::cout << "\n------------------ CATALOGO DE PRODUCTOS ------------------\n";
        int i = 0;
        while (i < cantidadProductos) 
        {
            productos[i]->mostrarInformacion();
            i++;
        }
    }

    void GestorEmpresa::listarClientes() const 
    {
        std::cout << "\n------------------- CLIENTES REGISTRADOS ------------------\n";
        int i = 0;
        while (i < cantidadClientes) 
        {
            clientes[i].mostrarInformacion();
            i++;
        }
    }

    void GestorEmpresa::mostrarTodosLosPedidos() const 
    {
        std::cout << "\n====================================================================\n";
        std::cout << "       REPORTE OFICIAL DE PEDIDOS DE CLIENTES (CONSOLA)             \n";
        std::cout << "====================================================================\n";
        
        if (cantidadPedidos == 0) 
        {
            std::cout << " No existen pedidos registrados.\n";
            return;
        }
        
        int i = 0;
        while (i < cantidadPedidos) 
        {
            pedidos[i].mostrarPedido();
            i++;
        }
    }

    void GestorEmpresa::listarEmpleados() const 
    {
        std::cout << "\n------------------- NOMINA DE EMPLEADOS -------------------\n";
        int i = 0;
        while (i < cantidadEmpleados) 
        {
            empleados[i].mostrarInformacion();
            i++;
        }
    }

}