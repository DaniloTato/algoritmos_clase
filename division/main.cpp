#include <iostream>
#include <cmath>  // Para usar std::abs

int division_por_restas(int dividendo, int divisor) {
    if (divisor == 0) {
        std::cerr << "Error: División por cero no permitida." << std::endl;
        return -1; // Error
    }

    // Determinar el signo del resultado
    bool es_resultado_negativo = (dividendo < 0) ^ (divisor < 0); // XOR para detectar si tienen signos opuestos

    // Convertir a valores positivos para la operación
    int dividendo_abs = std::abs(dividendo);
    int divisor_abs = std::abs(divisor);

    int cociente = 0;
    int residuo = dividendo_abs;

    // Bucle de restas iterativas
    while (residuo >= divisor_abs) {
        residuo -= divisor_abs;
        cociente++;
    }

    // Ajustar el signo del cociente si es necesario
    if (es_resultado_negativo) {
        cociente = -cociente;
    }

    // Ajustar el signo del residuo (el residuo toma el mismo signo que el dividendo)
    residuo = (dividendo < 0) ? -residuo : residuo;

    std::cout << "Residuo: " << residuo << std::endl;
    return cociente;
}

int main() {
    int dividendo, divisor;

    std::cout << "Ingresa el dividendo: ";
    std::cin >> dividendo;

    std::cout << "Ingresa el divisor: ";
    std::cin >> divisor;

    int cociente = division_por_restas(dividendo, divisor);

    if (cociente != -1) {
        std::cout << "Cociente: " << cociente << std::endl;
    }

    return 0;
}