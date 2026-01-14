#ifndef SOLVE_H
#define SOLVE_H

#include <string>
#include <vector>

class solve {
public:
    std::string dna_counter(const std::string& dna);
    std::string rna_transcribe(const std::string& dna);
    std::string reverse_complement(const std::string& dna);
    std::string gc_content(const std::vector<std::string>& lines);
    std::string prot_translate(const std::string& rna);
};

#endif
