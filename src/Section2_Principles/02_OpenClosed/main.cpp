// Open-Closed Principle

// open for extension, closed for modification

#include <iostream>
// #include <cstdio>
#include <string>
#include <vector>


using namespace std;


enum class Color { red, green, blue };
enum class Size { small, medium, large };

struct Product
{
  string name;
  Color color;
  Size size;
};

struct ProductFilter
{
  vector<Product*> by_color(vector<Product*> items, Color color)
  {
    vector<Product*> result;
    for (auto& i : items)
      if (i->color == color)
        result.push_back(i);
    return result;
  }

  vector<Product*> by_size(vector<Product*> items, Size size)
  {
    vector<Product*> result;
    for (auto& i : items)
      if (i->size == size)
        result.push_back(i);
    return result;
  }

  vector<Product*> by_size_and_color(vector<Product*> items, 
                                    Size size, Color color)
  {
    vector<Product*> result;
    for (auto& i : items)
      if (i->size == size && i->color == color)
        result.push_back(i);
    return result;
  }
};

template <typename T> struct AndSpecification;

template <typename T> struct Specification
{
  virtual ~Specification() = default;
  virtual bool is_satisfied(T* item) const = 0;
  
  /*AndSpecification<T> operator&&(Specification<T>&& other)
  {
    return AndSpecification<T>(*this, other);
  }*/
};

template <typename T> AndSpecification<T> operator&&
  (const Specification<T>& first, const Specification<T>& second)
{
  return { first, second };
}

template <typename T> struct Filter
{
  virtual vector<T*> filter(vector<T*> items, 
                            Specification<T>& spec) = 0;
};

struct BetterFilter : Filter<Product>
{
  vector<Product *> filter(vector<Product *> items,
                           Specification<Product> &spec) override
  {
    vector<Product*> result;
    for (auto& item : items)
      if (spec.is_satisfied(item))
        result.push_back(item);
    return result;
  }
};

struct ColorSpecification : Specification<Product>
{
  Color color;

  ColorSpecification(Color color) : color(color) {}

  bool is_satisfied(Product *item) const override {
    return item->color == color;
  }
};

struct SizeSpecification : Specification<Product>
{
  Size size;

  explicit SizeSpecification(Size size) : size(size) {}

  bool is_satisfied(Product *item) const override {
    return item->size == size;
  }
};

template <typename T> struct AndSpecification : Specification<T>
{
  const Specification<T>& first;
  const Specification<T>& second;

  AndSpecification(const Specification<T> &first, 
                   const Specification<T> &second) : first(first), second(second) {}

  bool is_satisfied(T *item) const override {
    return first.is_satisfied(item) && second.is_satisfied(item);
  }
};


int main()
{
  Product apple{"Apple", Color::green, Size::small};
  Product tree{"Tree", Color::green, Size::large};
  Product house{"House", Color::blue, Size::large};

  const vector<Product*> items { &apple, &tree, &house };

  BetterFilter bf;

  ColorSpecification green(Color::green);
  for (auto& item : bf.filter(items, green))
    cout << item->name << " is green\n";

  SizeSpecification large(Size::large);
  for (auto& item : bf.filter(items, large))
  cout << item->name << " is large\n";

  // AndSpecification<Product> green_and_large(green, large);
  // for (auto& x : bf.filter(items, green_and_large))
  //   cout << x->name << " is green and large\n";

  auto spec = green && large;
  for (auto& x : bf.filter(items, spec))
    cout << x->name << " is green and large\n";


  // ProductFilter pf;
  // auto green_things = pf.by_color(items, Color::green);
  // for (auto& item : green_things)
  //   cout << item->name << " is green\n";

  // auto large_things = pf.by_size(items, Size::large);
  // for (auto& item : large_things)
  //   cout << item->name << " is large\n";

  // auto large_and_green_things = pf.by_size_and_color(items, Size::large, Color::green);
  // for (auto& item : large_and_green_things)
  //   cout << item->name << " is large and green\n";

  return 0;
}
