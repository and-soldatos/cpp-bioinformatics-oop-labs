#include <iostream>
#include <cstring>
using namespace std;

// Class representing a Protein
class Protein {
private:
    char id[20];
    char name[50];
    char sequence[200];

public:
    // Methods for setting data (setters)
    void setId(const char* newId) {
        strcpy(id, newId);
    }

    void setName(const char* newName) {
        strcpy(name, newName);
    }

    void setSequence(const char* newSeq) {
        strcpy(sequence, newSeq);
    }

    // Methods for reading data (getters)
    const char* getId() const { return id; }
    const char* getName() const { return name; }
    const char* getSequence() const { return sequence; }

    // Method that prints a description of the protein
    void describe() const {
        cout << "Protein " << id << " (" << name << "): " << sequence << endl;
    }

    // Example usage of the this pointer
    void printAddress() const {
        cout << "This protein object is located at memory address: "
             << this << endl;
    }

    // Calculate sequence length
    int length() const {
        return strlen(sequence);
    }
};

// Class representing a Gene
class Gene {
private:
    char id[20];
    char name[50];
    char chrom[10];
    int start;
    int end;
    char strand;

public:
    // Setters
    void setId(const char* newId) {
        strcpy(id, newId);
    }

    void setName(const char* newName) {
        strcpy(name, newName);
    }

    void setChrom(const char* newChrom) {
        strcpy(chrom, newChrom);
    }

    void setStart(int s) {
        start = s;
    }

    void setEnd(int e) {
        end = e;
    }

    void setStrand(char s) {
        strand = s;
    }

    // Getters
    const char* getId() const { return id; }
    const char* getName() const { return name; }
    const char* getChrom() const { return chrom; }
    int getStart() const { return start; }
    int getEnd() const { return end; }
    char getStrand() const { return strand; }

    // Print gene description
    void describe() const {
        cout << "Gene " << id << " (" << name << ") on "
             << chrom << ":" << start << "-" << end
             << " (" << strand << " strand)" << endl;
    }

    // Example usage of the this pointer
    void showAddress() const {
        cout << "This gene object is located at memory address: "
             << this << endl;
    }
};

int main() {
    // Create and use Protein objects
    Protein p1, p2;

    p1.setId("P1");
    p1.setName("Hemoglobin");
    p1.setSequence("MQLVD...");
    p1.describe();
    p1.printAddress();
    cout << "Length of sequence: " << p1.length() << endl;

    // Example usage of getter
    cout << "Protein name via getter: " << p1.getName() << endl << endl;

    p2.setId("P2");
    p2.setName("Myosin");
    p2.setSequence("MAGTR...");
    p2.describe();

    // Create and use Gene objects
    Gene g1, g2;

    g1.setId("G1");
    g1.setName("BRCA1");
    g1.setChrom("chr17");
    g1.setStart(43044295);
    g1.setEnd(43170245);
    g1.setStrand('+');
    g1.describe();
    g1.showAddress();
    cout << "Gene start via getter: " << g1.getStart() << endl << endl;

    g2.setId("G2");
    g2.setName("TP53");
    g2.setChrom("chr17");
    g2.setStart(7668402);
    g2.setEnd(7687550);
    g2.setStrand('-');
    g2.describe();

    return 0;
}
