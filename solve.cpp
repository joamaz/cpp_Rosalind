#include "solve.h"
#include "dna.h"
#include <sstream>
#include <iomanip>

using namespace std;

string solve::dna_counter(const string& dna_str) {
    dna d(dna_str);
    return d.count_acgt();
}

string solve::rna_transcribe(const string& dna_str) {
    dna d(dna_str);
    return d.to_rna();
}

string solve::reverse_complement(const string& dna_str) {
    dna d(dna_str);
    return d.reverse_complement();
}

string solve::gc_content(const vector<string>& lines) {
    string id = "";
    string best_id = "";
    string seq = "";

    double best_gc = -1.0;

    for (string line : lines) {
        if (line.size() == 0) continue;

        if (line[0] == '>') {
            if (seq.size() > 0) {
                dna d(seq);
                double gc = d.gc_percent();
                if (gc > best_gc) {
                    best_gc = gc;
                    best_id = id;
                }
            }
            id = line.substr(1);
            seq = "";
        } else {
            seq += line;
        }
    }

    if (seq.size() > 0) {
        dna d(seq);
        double gc = d.gc_percent();
        if (gc > best_gc) {
            best_gc = gc;
            best_id = id;
        }
    }

    stringstream ss;
    ss << best_id << "\n" << fixed << setprecision(6) << best_gc;
    return ss.str();
}



string solve::prot_translate(const string& rna) {
    static const pair<string, char> table[] = {
        {"UUU",'F'},{"CUU",'L'},{"AUU",'I'},{"GUU",'V'},
        {"UUC",'F'},{"CUC",'L'},{"AUC",'I'},{"GUC",'V'},
        {"UUA",'L'},{"CUA",'L'},{"AUA",'I'},{"GUA",'V'},
        {"UUG",'L'},{"CUG",'L'},{"AUG",'M'},{"GUG",'V'},
        {"UCU",'S'},{"CCU",'P'},{"ACU",'T'},{"GCU",'A'},
        {"UCC",'S'},{"CCC",'P'},{"ACC",'T'},{"GCC",'A'},
        {"UCA",'S'},{"CCA",'P'},{"ACA",'T'},{"GCA",'A'},
        {"UCG",'S'},{"CCG",'P'},{"ACG",'T'},{"GCG",'A'},
        {"UAU",'Y'},{"CAU",'H'},{"AAU",'N'},{"GAU",'D'},
        {"UAC",'Y'},{"CAC",'H'},{"AAC",'N'},{"GAC",'D'},
        {"UAA",'*'},{"CAA",'Q'},{"AAA",'K'},{"GAA",'E'},
        {"UAG",'*'},{"CAG",'Q'},{"AAG",'K'},{"GAG",'E'},
        {"UGU",'C'},{"CGU",'R'},{"AGU",'S'},{"GGU",'G'},
        {"UGC",'C'},{"CGC",'R'},{"AGC",'S'},{"GGC",'G'},
        {"UGA",'*'},{"CGA",'R'},{"AGA",'R'},{"GGA",'G'},
        {"UGG",'W'},{"CGG",'R'},{"AGG",'R'},{"GGG",'G'}
    };

    auto get_aa = [&](const string& codon) -> char {
        for (auto &p : table) {
            if (p.first == codon) return p.second;
        }
        return '?'; // gdyby było coś dziwnego w danych
    };

    string protein = "";

    for (int i = 0; i + 2 < (int)rna.size(); i += 3) {
        string codon = rna.substr(i, 3);
        char aa = get_aa(codon);

        if (aa == '*') break;
        if (aa == '?') continue;   // ignoruj nieznane
        protein += aa;
    }

    return protein;
}
