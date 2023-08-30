#include "layer.h"

Layer::Layer(int nodes) {
  _a = std::make_shared<Matrix>(1, nodes);
  _w = std::make_shared<Matrix>(nodes, 1);
  _b = std::make_shared<Matrix>(1, 1);
}

double Layer::GetWEl(int row, int col) {
  return _w->getEl(row, col);
}

void Layer::SetWEl(int row, int col, double value) {
  _w->setEl(row, col, value);
}

double Layer::GetAEl(int row, int col) {
  return _a->getEl(row, col);
}

void Layer::SetAEl(int row, int col, double value) {
  _a->setEl(row, col, value);
}

double Layer::GetBEl(int row, int col) {
  return _b->getEl(row, col);
}

void Layer::SetBEl(int row, int col, double value) {
  _b->setEl(row, col, value);
}



int Layer::GetSize() {
  return _size;
}
