#ifndef GARRAFA_GAS_HPP
#define GARRAFA_GAS_HPP

#include "producto.hpp"

namespace garrafa 
{
    /**
     * @class GarrafaGas
     * @brief Clase derivada concreta que representa un cilindro de gas.
     */
    class GarrafaGas : public Producto 
    {
    private:
        int capacidadKilos;

    public:
        GarrafaGas();
        
        void configurar(int _id, const std::string& _nombre, double _precio, int _kilos);

        void mostrarInformacion() const override;

        double calcularPrecioFinal() const override;
    };
}

#endif // GARRAFA_GAS_HPP