#include <iostream>
#include <vector>

const int INF = INT_MAX;

class load_balancer{
private:
    int num_servers;
    std::vector<std::vector<int>> adj_matrix;
    std::vector<int> request_per_server;
public:
    load_balancer(int n, const std::vector<std::vector<int>>& matrix);
    int distribute_request(int start_server);
    void complete_request();
    void display_server_loads();
};

load_balancer::load_balancer(int n, const std::vector<std::vector<int>>& matrix):
num_servers(n), request_per_server(n,0), adj_matrix(matrix){};

int load_balancer::distribute_request(int start_server){
    int min_cost = INF;
    int selected_server = -1;

    for(int i=0; i<num_servers;i++){
        if(i != start_server && adj_matrix[start_server][i] != INF){
            if((request_per_server[i] < request_per_server[selected_server] || selected_server != -1)&&(adj_matrix[start_server][i] < min_cost)){
                min_cost = adj_matrix[start_server][i];
                selected_server = i;
            }
        }
    }

    if(selected_server != -1){
        request_per_server[selected_server]++;
        std::cout << "Solicitud asignada al servidor :" << selected_server << "\n";
    } else{
        std::cout << "No hay servidores disponibles :" << start_server << "\n";
    }

    return selected_server;
}

int main(){
    int num_servers = 4;
    std::vector<std::vector<int>> matrix = {
        {0,10,3,INF},
        {10,0,1,2},
        {3,1,0,8},
        {INF,2,8,0}
    };

    load_balancer lb(4, matrix);

    return 0;
}