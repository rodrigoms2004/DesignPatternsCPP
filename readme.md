# Design Patterns in C++

Solid design patterns

* Creational
  * Builder
  * Factories
    * Abstract Factory
    * Factory Method
  * Prototype
  * Singleton

* Structural
  * Adapter
  * Bridge
  * Composite
  * Decorator
  * Facade
  * Flyweight
  * Proxy

* Behavioral
  * Chain of Responsability
  * Command
  * Interpreter
  * Mediator
  * Memento
  * Observer
  * State
  * Strategy
  * Template Method
  * Visitor


#### Install Boost lib 

Boost lib
```
sudo apt-get install libboost-all-dev
```


#### Compile
```
g++ main.cpp -o main.o
```

### Section 2: SOLID Design Patterns

Robert C. Martin (aka Uncle Bob)

**Single Responsability Principle**
* A class should only have one reason to change
* *Separation of concerns* - different classes handling different, independent tasks/problems

**Open-Closed Principle**
* Classes should be open for extensions but closed for modification

**Liskov Substition Principle**
* You should be able to substitute a base type for a subtype

**Interface Segregation Principle**
* Don't put too much into an interface; split into separated interfaces
* *YAGNI* - You Ain't Going to Need It

**Dependency Inversion Principle**
* High-level modules should not depend upon low-level ones; use abstractions


### Section 3: Builder

#### Gamma Categorization

Design Patterns are typically split into three categories
This is called *Gamma Categorization* after Erich Gamma, one of GoF (Gang Of Four)

**Creational Patterns**
* Deal wuth creation (construction) of objects
* Explicit (constructor) vs implicit (DI, reflection, etc.)
* Wholesale (single statement) vs piecewise (step-by-step)

**Structural Patterns**
* Concerned with the structure (e.g., class members)
* Many patterns are wrappers that mimic the underlying class interface
* Stress the importance of good API design

**Behavioral Patterns**
* They are all different; no central theme
