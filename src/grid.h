#pragma once
#include<vector>
#include <raylib.h>
static Color darkGrey = {26,31,40,255};

class Grid{

public:
  Grid() :grid_(std::vector<std::vector<Color>>(height,std::vector<Color>(width,darkGrey))){};
  void addMotif(int type, int top_corner_y, Color c);
  void Draw();
private:
    // motifs : square 2*2 ,  
    const static std::vector<std::vector<std::pair<int,int>>> motifs;
    const static int height = 50;
    const static int width = 10;
    std::vector<std::vector<Color>> grid_;
};