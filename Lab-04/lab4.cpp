#include <iostream>
#include <string>
#include <vector>
#include <cctype> // classic character handling functions like toupper()

using namespace std;

/* ============================================================
   BASE CLASS: Sequence
   Contains common data and common functionality.
   Will be inherited by DNASequence, RNASequence, ProteinSequence.
   ============================================================ */

class Sequence {
protected:  // protected means derived classes have access,
            // but external users do not.
    string data;            // The actual biological sequence
    static int count;       // Counter of active Sequence objects

public:
    // Constructor
    Sequence(const string& d)
        : data(d) {
        ++count;
        cout << "Sequence created. Active sequences: " << count << endl;
    }

    // Destructor
    ~Sequence() {
        --count;
        cout << "Sequence destroyed. Active sequences: " << count << endl;
    }

    size_t length() const {
        return data.size();
    }

    // Base describe() (will be hidden by derived classes)
    void describe() const {
        cout << "Generic sequence: " << data << endl;
    }

    static int getCount() {
        return count;
    }
};

// Initialization of static member
int Sequence::count = 0;


/* ============================================================
   DERIVED CLASS: DNASequence
   ============================================================ */

class DNASequence : public Sequence {
public:
    // The base class constructor is ALWAYS called first,
    // before the body of the derived constructor.
    DNASequence(const string& d)
        : Sequence(d) {
        cout << "DNASequence created\n";
    }

    ~DNASequence() {
        cout << "DNASequence destroyed\n";
    }

    void describe() const {
        cout << "DNA sequence: " << data << endl;
    }

    static bool isValidBase(char c) {
        char u = toupper(static_cast<unsigned char>(c));
        return (u=='A' || u=='C' || u=='G' || u=='T');
    }

    bool isValid() const {
        for (char c : data) {
            if (!isValidBase(c)) return false;
        }
        return true;
    }
};


/* ============================================================
   DERIVED CLASS: RNASequence
   ============================================================ */

class RNASequence : public Sequence {
public:
    RNASequence(const string& d)
        : Sequence(d) {
        cout << "RNASequence created\n";
    }

    ~RNASequence() {
        cout << "RNASequence destroyed\n";
    }

    void describe() const {
        cout << "RNA sequence: " << data << endl;
    }

    static bool isValidBase(char c) {
        char u = toupper(static_cast<unsigned char>(c));
        return (u=='A' || u=='C' || u=='G' || u=='U');
    }

    bool isValid() const {
        for (char c : data) {
            if (!isValidBase(c)) return false;
        }
        return true;
    }
};


/* ============================================================
   DERIVED CLASS: ProteinSequence
   ============================================================ */

class ProteinSequence : public Sequence {
public:
    ProteinSequence(const string& d)
        : Sequence(d) {
        cout << "ProteinSequence created\n";
    }

    ~ProteinSequence() {
        cout << "ProteinSequence destroyed\n";
    }

    void describe() const {
        cout << "Protein sequence: " << data << endl;
    }

    static bool isValidAA(char c) {
        const string valid = "ACDEFGHIKLMNPQRSTVWY"; // The 20 amino acids
        char u = toupper(static_cast<unsigned char>(c));
        return valid.find(u) != string::npos;
    }

    bool isValid() const {
        for (char c : data) {
            if (!isValidAA(c)) return false;
        }
        return true;
    }
};


/* ============================================================
   CLASS: Isoform (Composition with RNASequence)
   ============================================================ */

class Isoform {
private:
    string id;
    string name;
    RNASequence seq;  // Each isoform has its own RNASequence

public:
    Isoform(const string& i, const string& n, const string& rna)
        : id(i), name(n), seq(rna) {
        cout << "Isoform created: " << name << endl;

        if (!seq.isValid()) {
            cout << "Warning: RNA sequence of " << name << " has invalid bases\n";
        }
    }

    ~Isoform() {
        cout << "Isoform destroyed: " << name << endl;
    }

    void describe() const {
        cout << "Isoform " << id << " (" << name << ")\n";
        seq.describe();
        cout << "Length: " << seq.length() << " bases\n";
    }
};


/* ============================================================
   CLASS: Gene (contains vector<Isoform>)
   ============================================================ */

class Gene {
private:
    string id;
    string name;
    string chrom;
    int start;
    int end;
    char strand;
    vector<Isoform> isoforms;

public:
    Gene(const string& gid,
         const string& gname,
         const string& chr,
         int s,
         int e,
         char st)
         : id(gid), name(gname), chrom(chr), start(s), end(e), strand(st) {
        cout << "Gene created: " << name << endl;
    }

    ~Gene() {
        cout << "Gene destroyed: " << name << endl;
    }

    void addIsoform(const Isoform& iso) {
        isoforms.push_back(iso);
    }

    void describe() const {
        cout << "Gene " << id << " (" << name << ") on "
             << chrom << ":" << start << "-" << end
             << " (" << strand << " strand)\n";

        cout << "Active sequences: " << Sequence::getCount() << endl;

        if (isoforms.empty()) {
            cout << "No isoforms\n";
            return;
        }

        cout << "Isoforms:\n";
        for (auto it = isoforms.begin(); it != isoforms.end(); ++it) {
            it->describe();
        }
    }
};


/* ============================================================
   MAIN
   ============================================================ */

int main() {

    cout << "--- Testing standalone sequences ---\n";

    DNASequence dna("ACGTACGT");
    dna.describe();
    cout << "Valid? " << (dna.isValid() ? "Yes" : "No") << endl;

    RNASequence rna("AUGCCAGGAU");
    rna.describe();
    cout << "Valid? " << (rna.isValid() ? "Yes" : "No") << endl;

    ProteinSequence prot("MTAKPL");
    prot.describe();
    cout << "Valid? " << (prot.isValid() ? "Yes" : "No") << endl;

    cout << "Active sequences now: " << Sequence::getCount() << endl;


    cout << "\n--- Gene with Isoforms ---\n";

    Gene g1("ENSG000001", "TP53", "chr17", 7668402, 7687550, '-');

    Isoform iso1("ENST0001", "TP53-201", "AUGGCCAUGGCGCCC");
    Isoform iso2("ENST0002", "TP53-202", "AUGCCUGAUGCUGUAG");

    g1.addIsoform(iso1);
    g1.addIsoform(iso2);

    cout << endl;
    g1.describe();

    cout << "\n--- End of main ---\n";
    return 0;
}
