// Open-Closed Principle

// open for extension, closed for modification

#include <iostream>
#include <string>
#include <vector>


using namespace std;

enum class Auth { aaa, radius, diameter };
enum class Api { kite, legacy, hlr };

struct Apn
{
  string name;
  Auth auth;
  Api api;
};


/*
  TEMPLATES
*/
template <typename T> struct Specification
{
  virtual ~Specification() = default;
  virtual bool is_satisfied(T* item) const = 0; // const do not modify anything
};

template <typename T> struct AndSpecification;

// operator && overloaded 
template <typename T> AndSpecification<T> operator&&(const Specification<T>& first, const Specification<T>& second)
{
  return { first, second };
};

template <typename T> struct Filter
{
  virtual vector<T*> filter(vector<T*> items, Specification<T>& spec) = 0;
};

/* 
IMPLEMENTATION
*/
struct ApnFilter : Filter<Apn>
{
  vector<Apn*> filter(vector<Apn*> items, Specification<Apn>& spec) override
  {
    vector<Apn*> result;
    for(auto& item: items)
      if (spec.is_satisfied(item))
        result.push_back(item);

    return result;
  }
};

struct AuthSpecification : Specification<Apn>
{
  Auth auth;

  AuthSpecification(Auth auth) : auth(auth) {}

  bool is_satisfied(Apn *item) const override {
    return item->auth == auth;
  }

};

struct ApiSpecification : Specification<Apn>
{
  Api api;

  ApiSpecification(Api api) : api(api) {}

  bool is_satisfied(Apn *item) const override {
    return item->api == api;
  }

};

template <typename T> struct AndSpecification : Specification<T>
{
  const Specification<T>& first;
  const Specification<T>& second;

  AndSpecification(const Specification<T> &first, const Specification<T> &second) : first(first), second(second) {}

  bool is_satisfied(T *item) const override {
    return first.is_satisfied(item) && second.is_satisfied(item);
  }
};


int main() 
{
  Apn XPTO { "XPTO", Auth::radius, Api::kite };
  Apn ACME { "ACME", Auth::aaa, Api::kite };
  Apn ABCD { "ABCD", Auth::radius, Api::legacy };
  Apn blasterCompany { "blasterCompany", Auth::diameter, Api::kite };

  const vector<Apn*> allCustomers { &XPTO, &ACME, &ABCD, &blasterCompany };

  ApnFilter af;

  AuthSpecification radius(Auth::radius);
  for (auto& customer: af.filter(allCustomers, radius))
    cout << customer->name << " has radius\n";

  ApiSpecification kite(Api::kite);
  for (auto& customer: af.filter(allCustomers, kite))
    cout << customer->name << " uses Kite\n";

  auto spec = radius && kite;
  for (auto& customer: af.filter(allCustomers, spec))
    cout << customer->name << " has radius and uses Kite\n";


  return 0;
}

