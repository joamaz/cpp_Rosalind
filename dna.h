#ifndef DNA_H
#define DNA_H

#include <string>
#include <sstream>

class dna {
private:
    std::string seq;

public:
    dna(const std::string& s) {
        seq = s;
    }

std::string count_acgt() const {
    int a = 0, c = 0, g = 0, t = 0;

    for (auto it = seq.begin(); it != seq.end(); ++it) {
        switch (*it) {
            case 'A': ++a; break;
            case 'C': ++c; break;
            case 'G': ++g; break;
            case 'T': ++t; break;
        }
    }

	std::stringstream ss;
ss << a << " " << c << " " << g << " " << t;
return ss.str();
}

std::string to_rna() const {
        	std::string rna = seq;
        for (char& c : rna) {
            if (c == 'T') c = 'U';
        }
        return rna;
    }



std::string reverse_complement() const {
    std::string result = "";
    for (int i = seq.size() - 1; i >= 0; i--) {
        switch (seq[i]) {
            case 'A': result += 'T'; break;
            case 'T': result += 'A'; break;
            case 'C': result += 'G'; break;
            case 'G': result += 'C'; break;
        }
    }

    return result;
}



    double gc_percent() const {
        int gc = 0;

        for (char c : seq) {
            if (c == 'G' || c == 'C') gc++;
        }

        if (seq.empty() == 0) return 0.0;
        return 100.0 * gc / seq.size();
    }
};

#endif

