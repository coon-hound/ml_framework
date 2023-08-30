#ifndef LAYER_H
#define LAYER_H

#include "matrix.h"
#include <cstddef>


class Layer
{
public:
  Layer(int nodes); 

  double GetWEl(int row, int col);
  void SetWEl(int row, int col, double value);

  double GetAEl(int row, int col);
  void SetAEl(int row, int col, double value);

  double GetBEl(int row, int col);
  void SetBEl(int row, int col, double value);



  int GetSize();
  

private:
  int _size;
  std::shared_ptr<Matrix> _w;
  std::shared_ptr<Matrix> _a;
  std::shared_ptr<Matrix> _b;
  
};

#endif //LAYER_H