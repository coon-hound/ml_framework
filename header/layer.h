#ifndef LAYER_H
#define LAYER_H

#include "matrix.h"
#include <cstddef>


class Layer
{
public:
  Layer(int nodes, int next_nodes); 

  void RandParams();
  void RandActivation();

  double GetWEl(int row, int col);
  void SetWEl(int row, int col, double value);

  void SetA(Matrix a);
  double GetAEl(int row, int col);
  void SetAEl(int row, int col, double value);

  double GetBEl(int row, int col);
  void SetBEl(int row, int col, double value);

  double GetZEl(int row, int col);
  void SetZEl(int row, int col, double value);

  double GetBackPropagationValues(int row, int col);
  void SetBackPropagationValues(int row, int col, double value);

  double GetBiasGradientVectorValues(int row, int col);
  void SetBiasGradientVectorValues(int row, int col, double value);

  double GetWeightGradientVectorValues(int row, int col);
  void SetWeightGradientVectorValues(int row, int col, double value);

  int GetSize();
  int GetNextSize();

  Matrix Forward(); //returns a matrix of the activation values for the next layer. 
  
  void ResetBackProp();

  void ApplyGradients(double learn_rate);

  //debugging
  void Print();

private:
  Matrix applyActivationFunction(Matrix &a);

  void updateWeights(int layer, double carry, double learn_rate);

  int _size;
  int _next_size;
  std::shared_ptr<Matrix> _w;
  std::shared_ptr<Matrix> _a;
  std::shared_ptr<Matrix> _b; 
  std::shared_ptr<Matrix> _z; 

  std::shared_ptr<Matrix> _backPropagationValues;

  std::shared_ptr<Matrix> _wGradientVector;
  std::shared_ptr<Matrix> _bGradientVector;
};

#endif //LAYER_H
