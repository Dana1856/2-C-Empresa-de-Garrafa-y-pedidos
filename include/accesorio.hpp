#ifndef ACCESORIO_HPP
#define ACCESORIO_HPP

#include "producto.hpp"

namespace garrafa 
{
    /**
     * @class Accesorio
     * @brief Clase derivada que representa reguladores o mangueras.
     */
    class Accesorio : public Producto 
    {
    private:
        std::string tipo;

    public:
        Accesorio();
        
        void configurar(int _id, const std::string& _nombre, double _precio, const std::string& _tipo);

        void mostrarInformacion() const override;
        /**
         * @brief Implementación polimórfica del precio para accesorios.
         * Aplica un 21% de IVA sobre el precio base.
         */
        double calcularPrecioFinal() const override;
    };
}

#endif // ACCESORIO_HPP