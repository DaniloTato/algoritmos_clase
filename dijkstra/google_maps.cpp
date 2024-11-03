#include <iostream>
#include <curl/curl.h>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

// Función de callback para manejar los datos recibidos de la API
size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* buffer) {
    size_t totalSize = size * nmemb;
    buffer->append((char*)contents, totalSize);
    return totalSize;
}

// Función para obtener las coordenadas de una ubicación
void getCoordinates(const std::string& location, const std::string& apiKey) {
    // URL de la solicitud
    std::string url = "https://maps.googleapis.com/maps/api/geocode/json?address=" + location + "&key=" + apiKey;

    // Inicializa CURL
    CURL* curl = curl_easy_init();
    if (!curl) {
        std::cerr << "Error inicializando CURL" << std::endl;
        return;
    }

    // Resultado de la respuesta
    std::string response;

    // Configuración de CURL
    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

    // Ejecuta la solicitud
    CURLcode res = curl_easy_perform(curl);
    if (res != CURLE_OK) {
        std::cerr << "Error en la solicitud: " << curl_easy_strerror(res) << std::endl;
        curl_easy_cleanup(curl);
        return;
    }

    // Analiza el JSON de respuesta
    json jsonResponse = json::parse(response);
    if (jsonResponse["status"] == "OK") {
        // Extrae las coordenadas de la primera ubicación encontrada
        auto location = jsonResponse["results"][0]["geometry"]["location"];
        double lat = location["lat"];
        double lng = location["lng"];
        
        std::cout << "Coordenadas de " << location << ": " << "Latitud: " << lat << ", Longitud: " << lng << std::endl;
    } else {
        std::cerr << "Error en la respuesta de la API: " << jsonResponse["status"] << std::endl;
    }

    // Limpieza de CURL
    curl_easy_cleanup(curl);
}

int main() {
    // Configura tu clave de API y la ubicación que deseas buscar
    std::string apiKey = "AIzaSyCwIL32CK8i4SZ53X9t1-6kPJjA4aIKmNQ";
    std::string location = "1600+Amphitheatre+Parkway,+Mountain+View,+CA";

    // Llama a la función para obtener las coordenadas
    getCoordinates(location, apiKey);

    return 0;
}