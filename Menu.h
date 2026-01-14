#ifndef MENU_H
#define MENU_H

#include "solve.h"

class Menu {
private:
    solve solver;

    void show_menu();
    void dna_counter();
    void rna_transcribe();
    void reverse_complement();
    void gc_content();
    void prot_translate();

public:
    void run();
};

#endif
