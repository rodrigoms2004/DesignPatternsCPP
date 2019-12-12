// Interface Segregation Principle

#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Document;

// struct IMachine
// {
//   virtual void print(Document& doc) = 0;
//   virtual void scan(Document& doc) = 0;
//   virtual void fax(Document& doc) = 0;
// };

// struct MFP : IMachine
// {
//   void print(Document& doc) override {
//     // ok
//   }

//   void scan(Document& doc) override {

//   }

//   void fax(Document& doc) override {

//   }
// };

// struct Scanner : IMachine
// {
//   void print(Document& doc) override {
    
//   }

//   void scan(Document& doc) override {
//     // ok
//   }

//   void fax(Document& doc) override {

//   }
// };


// make different interfaces for printer, scanner and fax 
struct IPrinter
{
  virtual void print(Document& doc) = 0;  
};

struct IScanner
{
  virtual void scan(Document& doc) = 0;  
};

struct IFax
{
  virtual void fax(Document& doc) = 0;  
};

// so it you wanna to implement just a printer you just need to implement print function
struct Printer : IPrinter
{
  void print(Document& doc) override {

  }
};

struct Scanner : IScanner
{
  void scan(Document& doc) override {

  }
};

// If you need a machine with printer and scanner
struct IMachine : IPrinter, IScanner {};

struct Machine : IMachine
{
  IPrinter& printer;
  IScanner& scanner;

  Machine(IPrinter &printer, IScanner &scanner) : printer(printer), scanner(scanner) {}

  void print(Document &doc) override {
    printer.print(doc);
  }

  void scan(Document &doc) override {
    scanner.scan(doc);
  }
};

int main()
{

  return 0;
}