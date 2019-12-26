// Groovy-Style Builder

#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <fstream>
#include <vector>
#include <sstream>
#include <memory>
using namespace std;


struct Tag
{
  string name, text;
  vector<Tag> children;
  vector<pair<string, string>> attributes;

  friend ostream& operator <<(ostream& os, const Tag& tag)
  {
    os << "<" << tag.name;

    for (const auto& att: tag.attributes)
      os << " " << att.first << "=\"" << att.second << "\"";
    
    if (tag.children.size() == 0 && tag.text.length() == 0)
    {
      os << "/>" << endl;
    }
    else 
    {
      os << ">" << endl;

      if (tag.text.length())
        os << tag.text << endl;

      for (const auto& child : tag.children)
        os << child;

      os << "</" << tag.name << ">" << endl;
    }

    return os;
  }
protected:

  Tag(const string& name, const string& text) : name{name}, text{text} {}
  Tag(const string& name, const vector<Tag>& children) : name{name}, children{children} {}

};

struct P : Tag  // paragraph 
{
  P(const string &text) : Tag("p", text) {}
  P(initializer_list<Tag> children)
    : Tag{"p", children} {}
};

struct  IMG : Tag
{
  explicit IMG(const string& url)
    : Tag{"img", ""}
    {
      attributes.emplace_back(make_pair("src", url));
    }
};



int main()
{
  cout << 

    P {
      IMG { "http://pokemon.com/pikachu.png"}
    }

    << endl;
  return 0;
}