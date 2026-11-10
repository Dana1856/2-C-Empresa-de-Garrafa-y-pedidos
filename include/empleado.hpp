#ifndef EMPLEADO_HPP
#define EMPLEADO_HPP

#include <string>

namespace garrafa 
{
    class Empleado 
    {
    private:
        int id;
        std::string nombre;
        std::string contacto;

    public:
        Empleado();
        
        void configurar(int _id, const std::string& _nombre, const std::string& _contacto);
        
        int obtenerId() const;
        std::string obtenerNombre() const;
        std::string obtenerContacto() const;
        
        void mostrarInformacion() const;
    };
}

#endif // EMPLEADO_HPP