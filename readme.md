# Design Patterns in C++

Solid design patterns

* Creational
* Structural
* Behavioral

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