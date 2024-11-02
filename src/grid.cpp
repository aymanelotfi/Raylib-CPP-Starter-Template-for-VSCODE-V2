#include "grid.h"
#include<iostream>

const std::vector<std::vector<std::pair<int,int>>> Grid::motifs = {{{0,0}, {-1,1}, {-1,0}, {0,1}}};
const int cellSize = 30;
inline bool ColorsAreEqual(Color c1, Color c2) {
    return (c1.r == c2.r && c1.g == c2.g && c1.b == c2.b && c1.a == c2.a);
}
void Grid::addMotif(int type, int bottom_corner_y, Color c){
    std::vector<std::pair<int,int>> motif = motifs[type];
    int cur_x = 0;
    int stop_x = -1;
    while(stop_x != -1){
        for(auto component: motif){
            int cur_y = bottom_corner_y + component.second;
            if(cur_x + 1 >= height  || !ColorsAreEqual(grid_[cur_x + 1][cur_y], darkGrey)){
                stop_x = cur_x;
                break;
            }
        }
    }
     for(auto component: motif){
            int cur_x = stop_x + component.first;
            int cur_y = bottom_corner_y + component.second;
            grid_[cur_x][cur_y] = c;
    }
}

void Grid::Draw(){
    //std::cout << height << " " << width << std::endl;
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            //std::cout << i << " "  << j << std::endl;
            std::cout << grid_[i][j].r << " "; 
            DrawRectangle(i*cellSize + 1 , j * cellSize + 1, cellSize -1  ,cellSize -1, grid_[i][j]);
        }
        std::cout<< std::endl;
    }
}