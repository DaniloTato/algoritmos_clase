#include "include/header.hpp"
#include "src/functions.cpp"
#include "src/sorter.cpp"
#include "src/ui.cpp"
#include "src/camera_sensitive.cpp"

#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

int SCREEN_WIDTH = 1280;
int SCREEN_HEIGHT = 720;
int camera_x = 0;
int camera_y = 0;
sf::Vector2i mouse_pos;
int go_to_camera_x = 0;
int go_to_camera_y = 0;
float camera_zoom = 1;
float go_to_camera_zoom = 1;
int resized_window_width = SCREEN_WIDTH;
int resized_window_height = SCREEN_HEIGHT;
unsigned long frames;

int main(){
    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Typing RPG");
    window.setFramerateLimit(200);

    //se carga la fuente a un ibjeto de sfml
    sf::Font font;
    if (!font.loadFromFile("arial.ttf")) {
        std::cerr << "Could not load font\n";
        return -1;
    }

    //se asigna fuente al texto que mostrará los fps del proyecto
    sf::Text fpsText;
    fpsText.setFont(font);
    fpsText.setCharacterSize(20);
    fpsText.setFillColor(sf::Color(0,0,0));
    fpsText.setPosition(10, 10);

    sf::Clock clock;

    float lastTime = 0;
    int frame_count = 0;
    float fps = 0;

    std::vector<camera_sensitive*> rectangle_vector;
    std::vector<camera_sensitive*> triangle_vector;

    std::vector<int> vec = generate_random_vector(100,2,100);

    auto max_it = std::max_element(vec.begin(), vec.end());
    int max_element = *max_it;

    int selection = 2;

    std::vector<void (sorter::*)(std::vector<int>&,int,int)> sorting_methods = {&sorter::bubble_sort, &sorter::selection_sort ,&sorter::quick_sort};

    sorter sort;
    sort.solve(vec, sorting_methods[selection]);

    while (window.isOpen()){
        frames++;

        mouse_pos = sf::Mouse::getPosition(window);

        sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if(event.type == sf::Event::Resized){
                sf::FloatRect view(0, 0, event.size.width, event.size.height);
                window.setView(sf::View(view));
                resized_window_width = event.size.width;
                resized_window_height = event.size.height;
            }

            if(event.type == sf::Event::KeyPressed){
                if (event.key.code == sf::Keyboard::W){
                    go_to_camera_zoom += 0.5;
                } else if(event.key.code == sf::Keyboard::S){
                    go_to_camera_zoom -= 0.5;
                }

                if (event.key.code == sf::Keyboard::R){
                    std::vector<int> vec = generate_random_vector(100,2,100);
                    sort.solve(vec, sorting_methods[selection]);
                }
            }
        }

        int go_to_camera_x_sum = go_to_camera_x + ((camera_zoom - 1) * resized_window_width)*0.5;
        int go_to_camera_y_sum = go_to_camera_y + ((camera_zoom - 1) * resized_window_height)*0.5;

        camera_zoom += (go_to_camera_zoom - camera_zoom) * 0.03;
        camera_x += (go_to_camera_x_sum - camera_x) * 0.1;
        camera_y += (go_to_camera_y_sum - camera_y) * 0.1;

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
            go_to_camera_y -= 3;
        } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
            go_to_camera_y += 3;
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
            go_to_camera_x -= 3;
        } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
            go_to_camera_x += 3;
        }

        // Update FPS every second
        float current_time = clock.getElapsedTime().asSeconds();
        frame_count++;

        if (current_time - lastTime >= 1.0) {
            fps = frame_count / (current_time - lastTime);

            lastTime = current_time;
            frame_count = 0;
        }
        fpsText.setString("FPS: " + std::to_string(static_cast<int>(fps)));
        
        int exageration = 5;
        int floor = (resized_window_height -  max_element * exageration)*0.5 + max_element * exageration;
        int frame_delay = 1;
        int rect_width = 7;
        int spaces = 2;
        int starting_point_x = (resized_window_width - (rect_width + spaces) * vec.size() - spaces)*0.5;

        std::tuple<std::vector<int>*, std::vector<int>> next_step = {};
        if(frames % frame_delay == 0) next_step = sort.next_step();
        std::vector<int>* history_info = std::get<0>(next_step);

        if(history_info){
            std::vector<int> vec = *history_info;
            clear_and_delete(rectangle_vector);

            for(int i = 0; i < vec.size(); i++){
                rectangle_vector.push_back(new camera_sensitive(0, 0, rect_width, -exageration*vec[i]));
            }
        }

        for(int i = 0; i < rectangle_vector.size(); i++){
            rectangle_vector[i] -> set_x(starting_point_x + (rect_width + spaces) * (i - 1));
            rectangle_vector[i] -> set_y(floor);
        }

        std::vector<int> triangle_indexes = std::get<1>(next_step);
        if(triangle_indexes.size()){

            clear_and_delete(triangle_vector);

            for(int i = 0; i < triangle_indexes.size(); i++){
                int pointer_pos = triangle_indexes[i];
                int left_face_rectangle = rectangle_vector[pointer_pos] -> get_x();

                triangle_vector.push_back(new camera_sensitive(left_face_rectangle, floor + 10, rect_width, rect_width));
            }

        }

        

        window.clear(sf::Color(255,255,255));

        for(auto i: rectangle_vector){
            i -> draw_rectangle(window);
        }
        for(auto i: triangle_vector){
            i -> draw_triangle(window);
        }

        window.draw(fpsText);
        window.display();

    }

    return 0;
}