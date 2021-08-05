//
// Created by pollini on 05/08/2021.
//

#include "geo_utils.h"


std::vector<raylib::Vector2> plot_line_low(const raylib::Vector2 &from, const raylib::Vector2 &to) {
    auto points= std::vector<raylib::Vector2>();
    auto dx = to.x - from.x;
    auto dy = to.y - from.y;
    auto yi = 1;

    if (dy < 0) {
        yi = -1;
        dy = -dy;
    }

    auto D = (2 * dy) - dx;

    auto y = from.y;
    for (int x = from.x; x < to.x; ++x) {
        points.emplace_back(x,y);
        if (D > 0) {
            y += yi;
            D = D + (2 * (dy - dx));
        } else {
            D = D + 2*dy;
        }

    }
    return points;
}

std::vector<raylib::Vector2> plot_line_high(const raylib::Vector2 &from, const raylib::Vector2 &to) {
    auto points= std::vector<raylib::Vector2>();
    auto dx = to.x - from.x;
    auto dy = to.y - from.y;
    auto xi = 1;

    if (dy < 0) {
        xi = -1;
        dy = -dy;
    }

    auto D = (2 * dx) - dy;

    auto x = from.x;
    for (int y = from.y; y < to.y; ++y) {
        points.emplace_back(x,y);
        if (D > 0) {
            x += xi;
            D = D + (2 * (dx - dy));
        } else {
            D = D + 2*dx;
        }

    }
    return points;
}



std::vector<raylib::Vector2> geo_utils::get_point_line_path(const raylib::Vector2 &from, const raylib::Vector2 &to) {
    auto points= std::vector<raylib::Vector2>();
    std::vector<raylib::Vector2>points_to_add;
    auto dx = to.x - from.x;
    auto dy = to.y - from.y;
    if (abs(dy)< abs(dx)) {
        if (dx < 0) {
            points_to_add = plot_line_low(to,from);

        } else {
            points_to_add = plot_line_low(from,to);
        }
    } else {
        if (dy < 0) {
            points_to_add = plot_line_high(to,from);
        } else {
            points_to_add = plot_line_high(from,to);
        }
    }
    points.insert(points.end(),points_to_add.begin(),  points_to_add.end());
    return points;
}



std::vector<raylib::Vector2>
geo_utils::get_point_segments_path(const raylib::Vector2 &from, const raylib::Vector2 &to, int max_turns) {
     std::vector<raylib::Vector2> points{from};
     std::vector<raylib::Vector2> points_to_add{};

     auto make_horizontal_segment = [](int x_start, int x_end, int y){
         std::vector<raylib::Vector2> points{};
         for (int x = std::min(x_start,x_end); x < std::max(x_start,x_end); ++x) {
             points.push_back({static_cast<float>(x),static_cast<float>(y)});
         }
         return points;
     };

     auto make_vertical_segment = [](int y_start, int y_end, int x){
         std::vector<raylib::Vector2> points{};
         for (int y = std::min(y_start,y_end); y < std::max(y_start,y_end); ++y) {
             points.push_back({static_cast<float>(x),static_cast<float>(y)});
         }
         return points;
     };


     if(GetRandomValue(0,2)==1) {
         points_to_add = make_horizontal_segment(from.x,to.x,from.y);
         points.insert(points.end(),points_to_add.begin(),points_to_add.end());
         points_to_add = make_vertical_segment(from.y,to.y,to.x);
         points.insert(points.end(),points_to_add.begin(),points_to_add.end());
     } else {
         points_to_add = make_vertical_segment(from.y,to.y,from.x);
         points.insert(points.end(),points_to_add.begin(),points_to_add.end());
         points_to_add = make_horizontal_segment(from.x,to.x,to.y);
         points.insert(points.end(),points_to_add.begin(),points_to_add.end());
     }
     points.push_back(to);
     //     if rng.range(0,2) == 1 {
//         apply_horizontal_tunnel(&mut map, prev_x, new_x, prev_y);
//         apply_vertical_tunnel(&mut map, prev_y, new_y, new_x);
//     } else {
//         apply_vertical_tunnel(&mut map, prev_y, new_y, prev_x);
//         apply_horizontal_tunnel(&mut map, prev_x, new_x, new_y);
//     }
    return points;
}
