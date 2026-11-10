#include "aplicacion.hpp"
#include "utilidades.hpp"
#include <iostream>
#include <limits> 

namespace garrafa 
{
    Aplicacion::Aplicacion() 
    {
        enEjecucion = true;
        cargarDatosDePrueba();
    }

    void Aplicacion::cargarDatosDePrueba() 
    {
        gestor.registrarGarrafa(101, "Garrafa YPF", 5000.00, 10);
        gestor.registrarGarrafa(102, "Cilindro Industrial", 12000.00, 45);
        gestor.registrarAccesorio(201, "Regulador de Presion", 8500.00, "Bronce");
        gestor.registrarAccesorio(202, "Manguera Homologada", 2300.00, "Goma Reforzada");

        gestor.registrarCliente(1, "Mariana Gomez", "34567890", "223-5123456");
        gestor.registrarCliente(2, "Laura Benitez", "29876543", "223-4987654");

        Pedido* p1 = gestor.crearPedido(1001, 1);
        if (p1 != nullptr) 
        {
            p1->agregarArticulo(gestor.buscarProductoPorId(101), 2);
            p1->agregarArticulo(gestor.buscarProductoPorId(201), 1);
        }

        Pedido* p2 = gestor.crearPedido(1002, 2);
        if (p2 != nullptr) 
        {
            p2->agregarArticulo(gestor.buscarProductoPorId(102), 1);
        }
    }

    void Aplicacion::ejecutar() 
    {
        while (enEjecucion) 
        {
            clearConsole();

            mostrarMenu();

            if (enEjecucion)
            {
                pauseConsole();
            }
        }
    }

    void Aplicacion::mostrarMenu() 
    {

        std::cout << "\n====================================================================\n";
        std::cout << "  SISTEMA DE GESTION DE GAS Y ACCESORIOS\n";
        std::cout << "====================================================================\n";
        std::cout << " 1. Registrar Garrafa de Gas\n";
        std::cout << " 2. Registrar Accesorio\n";
        std::cout << " 3. Registrar Cliente\n";
        std::cout << " 4. Crear Pedido\n";
        std::cout << " 5. Agregar Producto a Pedido\n";
        std::cout << " 6. Listar Catalogo de Productos\n";
        std::cout << " 7. Listar Clientes\n";
        std::cout << " 8. Reporte Completo de Pedidos\n";
        std::cout << " 9. Registrar Empleado\n";
        std::cout << " 10. Listar Empleados\n";
        std::cout << " 0. Salir\n";
        std::cout << "--------------------------------------------------------------------\n";
        std::cout << " Ingrese opcion: ";


        int opcion;
        std::cin >> opcion;

        if (std::cin.fail()) 
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            opcion = -1;
        }

        switch (opcion) 
        {


            case 1: accionRegistrarGarrafa();
                    break;
            case 2: accionRegistrarAccesorio();
                    break;
            case 3: accionRegistrarCliente();
                    break;
            case 4: accionCrearPedido();
                    break;
            case 5: accionAgregarArticuloAPedido();
                    break;
            case 6: accionListarProductos();
                    break;
            case 7: accionListarClientes();
                    break;
            case 8: accionListarPedidos();
                    break;
            case 9: accionRegistrarEmpleado();
                    break;
            case 10: accionListarEmpleados();
                    break;

            case 0: enEjecucion = false;
                    break;

            default: std::cout << " [!] Opcion invalida.\n"; break;
        }
    }

    void Aplicacion::accionRegistrarGarrafa() 
    {
        int id, kilos;
        std::string nombre;
        double precio;

        std::cout << "\n-- NUEVA GARRAFA --\nID: ";
        std::cin >> id;
        std::cin.ignore();
        
        std::cout << "Nombre: ";
        std::getline(std::cin, nombre);
        
        std::cout << "Precio Base: $";
        std::cin >> precio;

        std::cout << "Capacidad (kg): ";
        std::cin >> kilos;

        if (gestor.registrarGarrafa(id, nombre, precio, kilos)) 
        {
            std::cout << " [+] Garrafa registrada correctamente.\n";
        } 
        else 
        {
            std::cout << " [-] Error: Capacidad maxima alcanzada.\n";
        }
    }

    void Aplicacion::accionRegistrarAccesorio() 
    {
        int id;
        std::string nombre, tipo;
        double precio;

        std::cout << "\n-- NUEVO ACCESORIO --\nID: ";
        std::cin >> id;
        std::cin.ignore();
        
        std::cout << "Nombre: ";
        std::getline(std::cin, nombre);
        
        std::cout << "Tipo/Material: ";
        std::getline(std::cin, tipo);
        
        std::cout << "Precio Base: $";
        std::cin >> precio;

        if (gestor.registrarAccesorio(id, nombre, precio, tipo)) 
        {
            std::cout << " [+] Accesorio registrado correctamente.\n";
        } 
        else 
        {
            std::cout << " [-] Error: Capacidad maxima alcanzada.\n";
        }
    }

    void Aplicacion::accionRegistrarCliente() 
    {
        int id;
        std::string nombre, dni, telefono;

        std::cout << "\n-- NUEVO CLIENTE --\nID: ";
        std::cin >> id;
        std::cin.ignore();
        
        std::cout << "Nombre Completo: ";
        std::getline(std::cin, nombre);
        
        std::cout << "DNI: ";
        std::getline(std::cin, dni);
        
        std::cout << "Telefono: ";
        std::getline(std::cin, telefono);

        if (gestor.registrarCliente(id, nombre, dni, telefono)) 
        {
            std::cout << " [+] Cliente registrado correctamente.\n";
        } 
        else 
        {
            std::cout << " [-] Error: Capacidad maxima alcanzada.\n";
        }
    }

    void Aplicacion::accionCrearPedido() 
    {
        int idPedido, idCliente;
        
        std::cout << "\n-- CREAR PEDIDO --\nNro de Pedido: ";
        std::cin >> idPedido;
        
        std::cout << "ID del Cliente existente: ";
        std::cin >> idCliente;

        if (gestor.crearPedido(idPedido, idCliente) != nullptr) 
        {
            std::cout << " [+] Pedido #" << idPedido << " generado exitosamente.\n";
        } 
        else 
        {
            std::cout << " [-] Error: Cliente no existe o limite de pedidos alcanzado.\n";
        }
    }

    void Aplicacion::accionAgregarArticuloAPedido() 
    {
        int idPedido, idProducto, cantidad;
        
        std::cout << "\n-- AGREGAR ITEM A PEDIDO --\nNro de Pedido: ";
        std::cin >> idPedido;
        
        Pedido* pedido = gestor.buscarPedidoPorId(idPedido);
        if (pedido == nullptr) 
        {
            std::cout << " [-] Error: El pedido no existe.\n";
            return;
        }

        std::cout << "ID del Producto a agregar: ";
        std::cin >> idProducto;
        
        Producto* producto = gestor.buscarProductoPorId(idProducto);
        if (producto == nullptr) 
        {
            std::cout << " [-] Error: El producto no existe en el catalogo.\n";
            return;
        }

        std::cout << "Cantidad: ";
        std::cin >> cantidad;

        if (pedido->agregarArticulo(producto, cantidad)) 
        {
            std::cout << " [+] Item agregado al pedido #" << idPedido << ".\n";
        } 
        else 
        {
            std::cout << " [-] Error: Limite de items en pedido alcanzado o cantidad invalida.\n";
        }
    }

    void Aplicacion::accionListarProductos() 
    {
        gestor.listarProductos();
    }

    void Aplicacion::accionListarClientes() 
    {
        gestor.listarClientes();
    }

    void Aplicacion::accionListarPedidos() 
    {
        gestor.mostrarTodosLosPedidos();
    }

    void Aplicacion::accionRegistrarEmpleado() 
    {
        int id;
        std::string nombre, contacto;

        std::cout << "\n-- NUEVO EMPLEADO --\nID: ";
        std::cin >> id;
        std::cin.ignore();
        
        std::cout << "Nombre Completo: ";
        std::getline(std::cin, nombre);
        
        std::cout << "Numero de Contacto: ";
        std::getline(std::cin, contacto);

        if (gestor.registrarEmpleado(id, nombre, contacto)) 
        {
            std::cout << " [+] Empleado registrado correctamente.\n";
        } 
        else 
        {
            std::cout << " [-] Error: Capacidad maxima alcanzada.\n";
        }
    }

    void Aplicacion::accionListarEmpleados() 
    {
        gestor.listarEmpleados();
    }
}