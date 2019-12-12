//  Liskov Substitution Principle

// Objects in a program should be replaceable with instances of their subtypes
// w/o altering the correctness of the program


#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Rectangle
{
protected:
  int width, height;
public:
  Rectangle(int width, int height) : width(width), height(height) {}

  // getters and setters
  int getWidth() const { return width; }
  virtual void setWidth(int width) { Rectangle::width = width; }

  int getHeight() const { return height; }
  virtual void setHeight(int height) { Rectangle::height = height; }

  int area() const { return width * height; }
};

class Square : public Rectangle
{
public:
  Square(int size): Rectangle(size, size) {}

  void setWidth(int width) {
    this->width = this->height = width;
  }

  void setHeight(int height) {
    this->height = this->width = height;
  }

};

void process(Rectangle& r)
{
  int w = r.getWidth();
  r.setHeight(10);
  
  cout << "expected area = " << (w*10) 
       << ", got " << r.area() << endl;
}

// due the structure is impossible to solve it
struct RectangleFactory
{
  static Rectangle create_rectangle(int w, int h);
  static Rectangle create_square(int size);
};

int main() 
{
  Rectangle r{3, 4};
  process(r);           // expected area = 30, got 30

  Square sq{5};
  process(sq);          // expected area = 50, got 100


  return 0;
}