# C++ Bioinformatics OOP Labs

This repository contains a series of university laboratory assignments focused on **Object-Oriented Programming (OOP) in C++**, using **bioinformatics-inspired examples** such as genes, proteins, sequences, isoforms, and biological data modeling.

The project was developed incrementally across five labs, each introducing new C++ concepts while extending the same biological model.

---

##  Educational Goals

- Understand and apply core OOP principles in C++
- Practice class design and data encapsulation
- Learn object lifecycle management (constructors / destructors)
- Use STL containers (`std::string`, `std::vector`)
- Model real-world biological entities
- Apply composition, inheritance, and polymorphism
- Use abstract base classes and virtual methods

---

##  Lab Overview

### Lab 1 – Introduction to Classes
- Classes: `Gene`, `Protein`
- Encapsulation with getters/setters
- Member functions and `this` pointer
- Basic object creation and usage

---

### Lab 2 – Constructors, Destructors & STL
- Use of `std::string` and `std::vector`
- Constructors and destructors
- Member initializer lists
- Object lifetime and scope
- Optional object counters

---

### Lab 3 – Composition
- New class: `Sequence`
- Composition with `Isoform` → contains `Sequence`
- `Gene` contains multiple `Isoform` objects
- Object creation and destruction order

---

### Lab 4 – Inheritance & Static Members
- Base class: `Sequence`
- Derived classes:
  - `DNASequence`
  - `RNASequence`
  - `ProteinSequence`
- `protected` members
- Static counters
- Sequence validation rules per type

---

### Lab 5 – Polymorphism & Virtual Methods
- Abstract base class `Sequence`
- Pure virtual methods:
  - `describe()`
  - `isValid()`
- Virtual destructors
- Runtime polymorphism via `Sequence*`
- `vector<Sequence*>` with mixed derived objects
- Polymorphic behavior inside composed objects (`Isoform → RNASequence`)

---

##  Example (Lab 5)

```cpp
// Example: Lab 5 - Polymorphic Sequences
// Base pointer → points to derived objects
    Sequence* s1 = new DNASequence("ACGTACGT");
    Sequence* s2 = new RNASequence("AUGGCCAUGG");
    Sequence* s3 = new ProteinSequence("MTAPQLR");

    vector<Sequence*> seqs = { s1, s2, s3 };

    for (Sequence* s : seqs) {
        s->describe();
        cout << "Length: " << s->length() << endl;
        cout << "Valid? " << (s->isValid() ? "Yes" : "No") << endl;
        cout << endl;
    }

    // Clean up memory
    // Deletion (virtual destructor → correct order)
    for (Sequence* s : seqs)
        delete s;