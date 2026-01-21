#include <iostream>
#include <string>
using namespace std;

// ==========================
// Protein class
// ==========================
class Protein {
private:
    string id;
    string name;
    string sequence;

public:
    // Default constructor
    Protein()
        : id("UNKNOWN"), name("UNNAMED"), sequence("") {
        cout << "[Constructor] Protein created (default)" << endl;
    }

    // Constructor with initialization list
    Protein(string i, string n, string seq)
        : id(i), name(n), sequence(seq) {
        cout << "[Constructor] Protein " << name << " created." << endl;
    }

    // Destructor
    ~Protein() {
        cout << "[Destructor] Protein " << name << " destroyed." << endl;
    }

    // Description method
    void describe() const {
        cout << "Protein " << id << " (" << name << "): " << sequence << endl;
    }

    // Method that returns sequence length
    int length() const {
        return sequence.size();
    }
};

// ==========================
// Gene class
// ==========================
class Gene {
private:
    const string organism;  
    // const member – must be initialized using an initialization list

    string id;
    string name;
    string chrom;
    int start;
    int end;
    char strand;

public:
    // Default constructor with initialization list
    Gene()
        : organism("Unknown"), id("NA"), name("NA"), chrom("NA"),
          start(0), end(0), strand('+') {
        cout << "[Constructor] Gene created (default)" << endl;
    }

    // Constructor with parameters
    Gene(string i, string n, string ch, int s, int e, char str, string org)
        : organism(org), id(i), name(n), chrom(ch),
          start(s), end(e), strand(str) {
        cout << "[Constructor] Gene " << name << " from " << organism << " created." << endl;
    }

    // Destructor
    ~Gene() {
        cout << "[Destructor] Gene " << name << " destroyed." << endl;
    }

    // Description method
    void describe() const {
        cout << "Gene " << id << " (" << name << ") on "
             << chrom << ":" << start << "-" << end
             << " (" << strand << " strand) [" << organism << "]" << endl;
    }

    // Getter for organism (const member)
    const string& getOrganism() const {
        return organism;
    }
};

// ==========================
// main() function
// ==========================
int main() {
    cout << "===== Creating objects on the Stack =====" << endl;
    Protein p1("P001", "BRCA1_protein", "MNAAATARATLL");
    p1.describe();
    cout << "Sequence length: " << p1.length() << endl << endl;

    Gene g1("G001", "BRCA1", "chr17", 43044295, 43170245, '+', "Homo sapiens");
    g1.describe();
    cout << "Organism: " << g1.getOrganism() << endl << endl;

    cout << "===== Creating objects on the Heap =====" << endl;
    Protein* p2 = new Protein("P002", "TP53_protein", "MKSVLLVVVAA");
    p2->describe();

    Gene* g2 = new Gene("G002", "TP53", "chr17", 7668402, 7687550, '-', "Homo sapiens");
    g2->describe();

    cout << "\n===== Destroying objects on the Heap =====" << endl;
    delete p2;  // destructor is also called
    delete g2;  // destructor is also called

    cout << "\n===== End of main() execution =====" << endl;
    return 0;
}