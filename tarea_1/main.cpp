#include <iostream>
#include <unordered_map>
#include <cmath>

std::unordered_map<char, int> conversion;

struct empleado{
    std::string name;
    int age;
    std::string skills;
    std::string fav_lenguaje;
};


long get_alphabetic_value(std::string str) {
    long value = 0;
    for (int i = 0; i < str.length(); i++) {
        if(i > 0){
            value += conversion[str[i]] * (10000000000000000/std::pow(100,i));
        } else{
            value += conversion[str[i]] * (10000000000000000);
        }
    }
    return value;
}


int binary_search(std::vector<empleado> vec, std::string target){
    int low = 0;
    int high = vec.size() - 1;
    int mid = high;
    if (vec[0].name == target) return 0;
    while (vec[mid].name != target){
        mid = (high + low) * 0.5;
        if (mid == low) return -1;
        get_alphabetic_value(vec[mid].name) <= get_alphabetic_value(target) ? low = mid : high = mid;
    }
    return mid;

}

struct chunk{
    std::vector<empleado> contents;
    chunk* merge_with(chunk other_chunk){
        int point_1 = 0;
        int point_2 = 0;
        std::vector<empleado> new_contents;
        while (point_1 < contents.size() && point_2 < other_chunk.contents.size()){

            if (get_alphabetic_value(contents[point_1].name) < get_alphabetic_value(other_chunk.contents[point_2].name) || contents[point_1].name == other_chunk.contents[point_2].name){
                new_contents.push_back(contents[point_1]);
                point_1++;
            } else{
                new_contents.push_back(other_chunk.contents[point_2]);
                point_2++;
            }
        }

        int diff_1 = contents.size() - point_1;
        while(diff_1){
            new_contents.push_back(contents[contents.size() - diff_1]);
            diff_1--;
        }
        int diff_2 = other_chunk.contents.size() - point_2;
        while(diff_2){
            new_contents.push_back(other_chunk.contents[other_chunk.contents.size() - diff_2]);
            diff_2--;
        }

        chunk* new_chunk = new chunk;
        new_chunk -> contents = new_contents;
        return new_chunk;
    }
};

std::vector<chunk*> merger(std::vector<chunk*> vector_of_chunks){
    std::vector<chunk*> new_vector_of_chunks;
    for(int i = 0; i < floor(vector_of_chunks.size()/2); i++){
        chunk* new_chunk = vector_of_chunks[i*2]->merge_with(*vector_of_chunks[i*2+1]);
        new_vector_of_chunks.push_back(new_chunk);
    }
    if(vector_of_chunks.size() % 2 == 1){
        new_vector_of_chunks.push_back(vector_of_chunks.back());
    }
    if(new_vector_of_chunks.size() == 1){
        return new_vector_of_chunks;
    } else return merger(new_vector_of_chunks);
}

//fun but pointless sort using object logic
void sort(std::vector<empleado> &vec){
    std::vector<chunk*> vector_of_chunks;
    for(int i = 0; i < vec.size(); i++){
        vector_of_chunks.push_back(new chunk);
        vector_of_chunks[i] -> contents = {vec[i]};
    }

    vec = merger(vector_of_chunks)[0]->contents;
}

int main(){

    // Adding position of letter in the alphabet so its value can be converted to an integer easily later.
    for (char c = 'A'; c <= 'Z'; ++c) {
        conversion[c] = c - 'A' + 1;
    }
    for (char c = 'a'; c <= 'z'; ++c) {
        conversion[c] = c - 'a' + 1;
    }

    std::vector<empleado> empleados = { {"Alice", 25, "Leer, Correr", "C++"}, {"Bob", 30, "Programar, Música", "Java"}, {"Charlie", 22, "Videojuegos, Pintura", "Python"}, {"David", 28, "Fútbol, Viajar", "JavaScript"}, {"Eve", 35, "Cocina, Jardinería", "C#"}, {"Frank", 27, "Ciclismo, Lectura", "Ruby"}, {"Grace", 32, "Natación, Ajedrez", "Go"}, {"Hank", 24, "Esquí, Fotografía", "Swift"}, {"Ivy", 29, "Yoga, Teatro", "TypeScript"}, {"Jack", 31, "Escalar, Piano", "Kotlin"}, {"Kathy", 26, "Leer, Cocina", "PHP"}, {"Leo", 33, "Correr, Ciclismo", "Perl"}, {"Mona", 29, "Cine, Teatro", "Scala"}, {"Nina", 24, "Natación, Viajes", "Rust"}, {"Oscar", 28, "Videojuegos, Música", "Haskell"}, {"Paul", 30, "Fotografía, Esquí", "SQL"}, {"Quincy", 27, "Ajedrez, Jardinería", "HTML/CSS"}, {"Rachel", 31, "Escalar, Yoga", "SASS"}, {"Steve", 34, "Piano, Correr", "R"}, {"Tina", 23, "Cocina, Videojuegos", "Lua"}, {"Uma", 29, "Teatro, Pintura", "Elixir"}, {"Victor", 32, "Viajar, Escalar", "MATLAB"}, {"Wendy", 25, "Ciclismo, Leer", "Dart"}, {"Xander", 30, "Música, Fútbol", "VB.NET"}, {"Yara", 28, "Correr, Jardinería", "Shell Scripting"}, {"Zane", 26, "Fotografía, Cine", "Objective-C"}, {"Albert", 35, "Leer, Pintura", "Clojure"}, {"Brenda", 31, "Yoga, Natación", "Erlang"}, {"Calvin", 33, "Ajedrez, Videojuegos", "C"}, {"Diana", 29, "Escalar, Esquí", "Fortran"}, {"Eli", 24, "Teatro, Piano", "Julia"}, {"Fiona", 27, "Cocina, Viajar", "Racket"}, {"George", 28, "Natación, Música", "Tcl"}, {"Helen", 30, "Correr, Fotografía", "F#"}, {"Isaac", 32, "Escalar, Jardinería", "Groovy"}, {"Jenny", 26, "Pintura, Leer", "PowerShell"}, {"Kevin", 31, "Ciclismo, Yoga", "Lisp"}, {"Linda", 34, "Cine, Teatro", "Prolog"}, {"Mike", 28, "Ajedrez, Programar", "PostgreSQL"}, {"Nora", 27, "Esquí, Escalar", "SQLite"}, {"Owen", 29, "Leer, Piano", "Cassandra"}, {"Paula", 25, "Viajar, Correr", "MongoDB"}, {"Quentin", 33, "Fotografía, Cine", "Redis"}, {"Rita", 30, "Ciclismo, Videojuegos", "Memcached"}, {"Sam", 26, "Correr, Jardinería", "MySQL"}, {"Tracy", 32, "Teatro, Leer", "MariaDB"}, {"Ulysses", 28, "Programar, Natación", "Oracle"}, {"Vera", 29, "Yoga, Música", "SQL Server"}, {"Will", 31, "Esquí, Jardinería", "Firebase"}, {"Xena", 27, "Escalar, Cine", "Neo4j"}, {"Yuri", 35, "Leer, Programar", "GraphQL"}, {"Zara", 24, "Fotografía, Pintura", "Docker"}, {"Arthur", 30, "Cocina, Música", "Kubernetes"}, {"Bella", 26, "Videojuegos, Esquí", "Ansible"}, {"Cody", 28, "Piano, Yoga", "Terraform"}, {"Derek", 33, "Leer, Jardinería", "Chef"}, {"Eva", 31, "Ciclismo, Cine", "Puppet"}, {"Fred", 29, "Programar, Escalar", "Jenkins"}, {"Gina", 34, "Natación, Ajedrez", "Travis CI"}, {"Harry", 27, "Escalar, Música", "CircleCI"}, {"Irene", 25, "Videojuegos, Fotografía", "GitLab CI"}, {"Jacob", 32, "Cocina, Leer", "GitHub Actions"}, {"Kara", 29, "Yoga, Correr", "Azure DevOps"}, {"Louis", 31, "Ajedrez, Programar", "AWS"}, {"Molly", 28, "Escalar, Natación", "GCP"}, {"Nate", 26, "Ciclismo, Teatro", "Heroku"}, {"Olivia", 30, "Fotografía, Jardinería", "Lambda"}, {"Peter", 35, "Leer, Programar", "S3"}, {"Quinn", 24, "Pintura, Cine", "EC2"}, {"Rose", 27, "Cocina, Escalar", "CloudFormation"}, {"Sean", 29, "Videojuegos, Música", "Elastic Beanstalk"}, {"Tara", 33, "Teatro, Ajedrez", "Azure Functions"}, {"Uri", 31, "Natación, Jardinería", "Cloudflare"}, {"Vince", 28, "Leer, Escalar", "Fastly"}, {"Willa", 30, "Yoga, Cine", "Kong"}, {"Ximena", 27, "Correr, Pintura", "Nginx"}, {"Yusuf", 29, "Ciclismo, Jardinería", "HAProxy"}, {"Zoe", 26, "Natación, Fotografía", "Consul"}, {"Andre", 31, "Escalar, Ajedrez", "Vault"}, {"Beth", 28, "Leer, Videojuegos", "Prometheus"}, {"Chris", 35, "Correr, Música", "Grafana"}, {"Daisy", 24, "Natación, Escalar", "Kibana"}, {"Ethan", 27, "Fotografía, Ciclismo", "ElasticSearch"}, {"Faith", 29, "Teatro, Piano", "Logstash"}, {"Gabe", 30, "Cocina, Leer", "Fluentd"}, {"Hazel", 32, "Ajedrez, Jardinería", "Kafka"}, {"Ian", 28, "Correr, Yoga", "RabbitMQ"}, {"Judy", 26, "Videojuegos, Fotografía", "ActiveMQ"}, {"Karl", 34, "Ciclismo, Programar", "Kafka Streams"}, {"Lena", 29, "Escalar, Cine", "Spark Streaming"}, {"Mick", 31, "Leer, Música", "Flink"}, {"Nina", 27, "Pintura, Jardinería", "Samza"} };
    sort(empleados);

    int errors = 0;
    for(auto i : empleados){
        int res = binary_search(empleados, i.name);
        if (empleados[res].name != i.name){
            errors += 1;
            std::cout << "error when finding " << i.name << "\n";
        }
    }

    if(!errors){
        std::cout << "good to go" << "\n";
        std::cout << "Empleado a buscar" << "\n";
        std::string response;
        std::cin >> response;
        int index = binary_search(empleados, response);

        if(index != -1){
            std::cout << "\n";
            std::cout << empleados[index].name << "\n";
            std::cout << empleados[index].age << "\n";
            std::cout << empleados[index].skills << "\n";
            std::cout << empleados[index].fav_lenguaje << "\n";
        } else{
            std::cout << "not found" << "\n";
        }
    }

    return 0;
}