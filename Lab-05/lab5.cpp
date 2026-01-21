#include <iostream>
#include <vector>
#include <string>
using namespace std;

/* ============================================================
   Abstract Base Class: Sequence
   ============================================================ */
class Sequence {
protected:
    string data;

public:
    Sequence(const string& d) : data(d) {
        cout << "Sequence created\n";
    }

    virtual ~Sequence() {
        cout << "Sequence destroyed\n";
    }

    // Pure virtual methods → Sequence becomes abstract
    virtual void describe() const = 0;
    virtual bool isValid() const = 0;

    int length() const {
        return data.size();
    }
};

/* ============================================================
   Derived Class: DNASequence
   ============================================================ */
class DNASequence : public Sequence {
public:
    DNASequence(const string& d) : Sequence(d) {
        cout << "DNASequence created\n";
    }

    ~DNASequence() override {
        cout << "DNASequence destroyed\n";
    }

    void describe() const override {
        cout << "DNA sequence: " << data << endl;
    }

    bool isValid() const override {
        for (char c : data)
            if (c!='A' && c!='C' && c!='G' && c!='T')
                return false;
        return true;
    }
};

/* ============================================================
   Derived Class: RNASequence
   ============================================================ */
class RNASequence : public Sequence {
public:
    RNASequence(const string& d) : Sequence(d) {
        cout << "RNASequence created\n";
    }

    ~RNASequence() override {
        cout << "RNASequence destroyed\n";
    }

    void describe() const override {
        cout << "RNA sequence: " << data << endl;
    }

    bool isValid() const override {
        for (char c : data)
            if (c!='A' && c!='C' && c!='G' && c!='U')
                return false;
        return true;
    }
};

/* ============================================================
   Derived Class: ProteinSequence
   ============================================================ */
class ProteinSequence : public Sequence {
public:
    ProteinSequence(const string& d) : Sequence(d) {
        cout << "ProteinSequence created\n";
    }

    ~ProteinSequence() override {
        cout << "ProteinSequence destroyed\n";
    }

    void describe() const override {
        cout << "Protein sequence: " << data << endl;
    }

    bool isValid() const override {
        for (char c : data)
            if (!isalpha(c))
                return false;
        return true;
    }
};

/* ============================================================
   Isoform: contains RNASequence (composition + derived class)
   ============================================================ */
class Isoform {
private:
    string id;
    string name;
    RNASequence rna;

public:
    Isoform(const string& i, const string& n, const string& seq)
        : id(i), name(n), rna(seq)
    {
        cout << "Isoform created: " << name << endl;
    }

    ~Isoform() {
        cout << "Isoform destroyed: " << name << endl;
    }

    void describe() const {
        cout << "Isoform " << id << " (" << name << ")\n";
        rna.describe();
        cout << "Length: " << rna.length() << " bases\n";
    }
};

/* ============================================================
   Gene: contains multiple Isoforms
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
    Gene(const string& i, const string& n,
         const string& c, int s, int e, char st)
        : id(i), name(n), chrom(c), start(s), end(e), strand(st)
    {
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

        cout << "Isoforms:\n";
        for (const auto& iso : isoforms)
            iso.describe();
    }
};

/* ============================================================
   MAIN
   ============================================================ */
int main() {

    cout << "--- Polymorphic standalone sequences ---\n";

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

    // Deletion (virtual destructor → correct order)
    for (Sequence* s : seqs)
        delete s;

    cout << "\n--- Gene with polymorphic Isoforms ---\n";

    Gene g("ENSG000001", "TP53", "chr17", 7668402, 7687550, '-');

    Isoform iso1("ENST0001", "TP53-201", "AUGGCCAUGGCGCCC");
    Isoform iso2("ENST0002", "TP53-202", "AUGCCUGAUGCUGUAG");

    g.addIsoform(iso1);
    g.addIsoform(iso2);

    g.describe();

    cout << "\n--- End of main ---\n";

    return 0;
}
