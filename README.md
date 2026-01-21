#  C++ Bioinformatics OOP Labs

A series of C++ programming labs demonstrating core **Object-Oriented Programming** principles through bioinformatics examples. The project progresses from basic classes to advanced concepts like inheritance and polymorphism across five assignments.

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
![C++](https://img.shields.io/badge/C++-00599C?style=flat&logo=c%2B%2B&logoColor=white)
![Bioinformatics](https://img.shields.io/badge/Domain-Bioinformatics-green)

---

##  Table of Contents

- [Project Overview](#project-overview)
- [Key Technical Concepts](#key-technical-concepts)
- [Lab Overview](#lab-overview)
- [Detailed Lab Descriptions](#detailed-lab-descriptions)
- [Usage](#usage)
- [Domain Model](#domain-model)
- [License](#license)
- [Author](#author)

---

##  Project Overview

The repository follows a hands-on learning approach where each lab introduces a new OOP concept while extending the same codebase. By Lab 5, simple `Gene` and `Protein` classes evolve into a polymorphic system with abstract base classes and specialized sequence types.

**Academic Context**: University OOP Course  
**Domain**: Bioinformatics

---

##  Key Technical Concepts

<table>
<tr>
<td width="50%">

### Core OOP Principles
-  **Encapsulation** & data hiding
-  **Composition** (has-a relationships)
-  **Inheritance** (is-a relationships)
-  **Polymorphism** (runtime behavior)
-  **Abstraction** (pure virtual functions)

</td>
<td width="50%">

### C++ Features
-  Classes & member functions
-  Constructors & destructors
-  Virtual methods & destructors
-  Abstract base classes
-  STL containers (`vector`, `string`)
-  Memory management (stack & heap)

</td>
</tr>
</table>

---

##  Lab Overview

| Lab | Focus Area | Key Concepts | File |
|:---:|------------|--------------|------|
| **1** | **Foundation** | Class design, encapsulation, getters/setters, `this` pointer | [lab1.cpp](lab1.cpp) |
| **2** | **Modern C++** | STL integration, constructors/destructors, initialization lists, object lifecycle | [lab2.cpp](lab2.cpp) |
| **3** | **Composition** | Has-a relationships, nested objects, object destruction order | [lab3.cpp](lab3.cpp) |
| **4** | **Inheritance** | Is-a relationships, base/derived classes, `protected` members, static counters | [lab4.cpp](lab4.cpp) |
| **5** | **Polymorphism** | Abstract classes, pure virtual functions, runtime polymorphism, virtual destructors | [lab5.cpp](lab5.cpp) |

---

##  Detailed Lab Descriptions

### Lab 1: Foundation - Classes & Encapsulation
**Concepts**: Basic OOP, encapsulation, member functions

- Implemented `Gene` and `Protein` classes with private data members
- Created getters/setters for controlled data access
- Demonstrated the `this` pointer and memory addressing
- Built foundation for biological data modeling

**Classes**: `Gene`, `Protein`

---

### Lab 2: Modern C++ - STL & Object Lifecycle
**Concepts**: Constructors, destructors, STL containers

- Migrated from C-style strings to `std::string`
- Implemented constructor initialization lists
- Added destructors with logging to track object lifecycle
- Explored stack vs heap allocation
- Introduced `const` member variables

**Key Addition**: Proper object lifecycle management

---

### Lab 3: Composition - Building Complex Structures
**Concepts**: Object composition, has-a relationships

- Created `Sequence` class for biological sequence data
- Implemented `Isoform` containing a `Sequence` (composition)
- Extended `Gene` to contain multiple `Isoform` objects
- Demonstrated constructor/destructor call order in composed objects
- Used `std::vector` for dynamic collections

**Architecture**: `Gene` → contains → `Isoform` → contains → `Sequence`

---

### Lab 4: Inheritance - Type Hierarchies
**Concepts**: Inheritance, protected members, static members

- Established `Sequence` as a base class
- Derived specialized sequence types:
  - `DNASequence` (validates A, C, G, T)
  - `RNASequence` (validates A, C, G, U)
  - `ProteinSequence` (validates 20 amino acids)
- Implemented static counters for tracking active objects
- Used `protected` access for shared base class data

**Hierarchy**: `Sequence` ← inherited by ← `DNASequence`, `RNASequence`, `ProteinSequence`

---

### Lab 5: Polymorphism - Runtime Flexibility
**Concepts**: Abstract classes, virtual functions, polymorphism

- Converted `Sequence` to an abstract base class
- Defined pure virtual functions: `describe()`, `isValid()`
- Implemented virtual destructors for proper cleanup
- Used base class pointers to achieve runtime polymorphism
- Stored heterogeneous objects in `vector<Sequence*>`
- Demonstrated dynamic dispatch with polymorphic method calls

**Polymorphic Architecture**:
```cpp
Sequence* → DNASequence
         → RNASequence
         → ProteinSequence
```

---

##  Usage

### Compilation
```bash
# Compile any lab (example: Lab 5)
g++ lab5.cpp -o lab5

# Run
./lab5
```

### Example Output (Lab 5)
```
--- Polymorphic standalone sequences ---
Sequence created
DNASequence created
DNA sequence: ACGTACGT
Length: 8
Valid? Yes

Sequence created
RNASequence created
RNA sequence: AUGGCCAUGG
Length: 10
Valid? Yes

Sequence created
ProteinSequence created
Protein sequence: MTAPQLR
Length: 7
Valid? Yes

[Destruction sequence with virtual destructors...]
```

---

##  Domain Model

The project models fundamental bioinformatics entities:

- **Sequence**: Abstract representation of biological sequences
  - **DNASequence**: Deoxyribonucleic acid (A, C, G, T)
  - **RNASequence**: Ribonucleic acid (A, C, G, U)
  - **ProteinSequence**: Amino acid chains (20 standard amino acids)
- **Isoform**: Alternative splice variants of genes
- **Gene**: Genomic regions with chromosomal coordinates
- **Protein**: Protein entities with identifiers and sequences

---

##  License

This project is licensed under the MIT License - see the [LICENSE.txt](LICENSE.txt) file for details.

---

##  Author

**Andreas Soldatos**  
Department of Informatics and Telecommunications | UoA

 [LinkedIn](https://linkedin.com/in/andreas-soldatos) |  [GitHub](https://github.com/and-soldatos)

---

<div align="center">

</div>