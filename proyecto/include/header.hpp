#ifndef HEADER_HPP
#define HEADER_HPP

#include "../src/functions.cpp"

#include <iostream>
#include <vector>
#include <array>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

extern int camera_x;
extern int camera_y;
extern int SCREEN_WIDTH;
extern int SCREEN_HEIGHT;
extern float camera_zoom;
extern sf::Vector2i mouse_pos;

class sorter{
public:
    sorter();
    std::tuple<std::vector<int>*, std::vector<int>> next_step();
    void solve(std::vector<int> vec, void (sorter::*sorting_method)(std::vector<int>&,int,int));
    void bubble_sort(std::vector<int> &vec, int useless, int useless2);
    void selection_sort(std::vector<int> &vec, int useless, int useless2);
    int get_i();
    std::vector<std::vector<int>> get_history();
    void quick_sort(std::vector<int>& vec, int left, int right);
    int partition(std::vector<int>& vec, int left, int right, int pivot);
private:
    std::vector<std::vector<int>> _history;
    std::vector<std::vector<int>> _iterator_position;
    int _i = 0;
};

class ui{
public:
    ui(int x, int y, int width, int height);
    virtual void draw(sf::RenderWindow &window);
    void set_x( int x);
    void set_y( int y);
    int get_x();
    int get_y();
    int get_height();
    virtual void draw_rectangle(sf::RenderWindow& window);
    virtual void draw_triangle(sf::RenderWindow& window);
    void draw_circle(sf::RenderWindow& window);
    virtual sf::Vector2f return_position();
    bool check_mouse_collision();
    bool being_clicked();
protected:
    int _x;
    int _y;
    int _width;
    int _height;
};

class slider: public ui{
public:
    slider(int x, int y, int width, float min_value, float max_value, int starting_value);
    void draw(sf::RenderWindow &window) override;
private:
    float _min_value;
    float _max_value;
    std::array<ui*, 4> _parts;
    ui* _knob;
    
};

class camera_sensitive: public ui{
public:
    camera_sensitive(int x, int y, int width, int height, float paralax = 1);
    void draw_rectangle(sf::RenderWindow& window) override;
    virtual sf::Vector2f return_position() override;
private:
    float _paralax;
};

#endif