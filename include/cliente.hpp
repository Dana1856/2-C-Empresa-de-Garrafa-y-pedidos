#ifndef CLIENTE_HPP
#define CLIENTE_HPP

#include <string>

namespace garrafa 
{
    /**
     * @class Cliente
     * @brief Modela a un comprador registrado en el sistema.
     * 
     * Mantiene en memoria los datos de contacto y de identificación personal
     * del cliente para ser vinculados posteriormente a sus pedidos.
     */
    class Cliente 
    {
    private:
        int id;
        std::string nombreCompleto;
        std::string dni;            
        std::string telefono;       

    public:
        /**
         * @brief Constructor por defecto.
         */
        Cliente();

        /**
         * @brief Inicializa los datos del cliente en el bloque de memoria asignado.
         * 
         * @param _id ID del cliente.
         * @param _nombre Nombre completo.
         * @param _dni Número de documento.
         * @param _telefono Número telefónico.
         */
        void configurar(int _id, const std::string& _nombre, const std::string& _dni, const std::string& _telefono);

        // Getters
        int obtenerId() const;
        std::string obtenerNombreCompleto() const;
        std::string obtenerDni() const;
        std::string obtenerTelefono() const;

        /**
         * @brief Imprime en consola los detalles del cliente.
         */
        void mostrarInformacion() const;
    };
}

#endif // CLIENTE_HPP