// Fluent Builder

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <memory>
using namespace std;

struct HtmlElement
{
  // friend class HtmlBuilder;
  string name, text;
  vector<HtmlElement> elements;

  const size_t indent_size = 2;

  HtmlElement() {}

  HtmlElement(const string &name, const string &text) : name(name), text(text) {}

  string str(int indent = 0) const {
    ostringstream oss;
    string i(indent_size * indent, ' ');
    oss << i << "<" << name << ">" << endl;
    if (text.size() > 0) {
      oss << string(indent_size * (indent + 1), ' ') << text << endl;
    }

    for (const auto& e : elements)
      oss << e.str(indent + 1);

    oss << i << "</" << name << ">" << endl;
    return oss.str();
  }
  
  // HtlmBuilder build(string root_name)
  // {
  //   return { root_name };
  // }

  // static unique_ptr<HtlmBuilder> build;
};

struct HtlmBuilder
{
  HtmlElement root;

  HtlmBuilder(string root_name)
  {
    root.name = root_name;
  }

  HtlmBuilder& add_child(string child_name, string child_text)
  {
    HtmlElement e { child_name, child_text };
    root.elements.emplace_back(e);
    return *this;
  }

  // HtlmBuilder* add_child_2(string child_name, string child_text)
  // {
  //   HtmlElement e { child_name, child_text };
  //   root.elements.emplace_back(e);
  //   return this;
  // }


  string str() const { return root.str(); }

  operator HtmlElement() const { return root; }

};


int main() 
{
  HtlmBuilder builder("ul");
  builder.add_child("li", "hello").add_child("li", "world");
  cout << builder.str() << endl;

  // HtmlElement elem = HtmlElement::build("ul").add_child("li", "hello");

  return 0;
}