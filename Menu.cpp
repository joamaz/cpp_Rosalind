#include "Menu.h"
#include <iostream>
#include <limits>
#include <string>
#include <vector>

using namespace std;

void Menu::show_menu() {
    cout << "1 - Zliczanie nukleotydów (DNA)\n";
    cout << "2 - Transkrypcja DNA → RNA\n";
    cout << "3 - Odwrócony komplement\n";
    cout << "4 - GC content (FASTA)\n";
    cout << "5 - Translacja RNA → białko\n";
    cout << "Podaj numer i zatwierdź\n";
}

void Menu::dna_counter() {
    string dna;
    cout << "Podaj sekwencję DNA: ";
    cin >> dna;
    cout << solver.dna_counter(dna) << endl;
}

void Menu::rna_transcribe() {
    string dna;
    cout << "Podaj sekwencję DNA: ";
    cin >> dna;
    cout << solver.rna_transcribe(dna) << endl;
}

void Menu::reverse_complement() {
    string dna;
    cout << "Podaj sekwencję DNA: ";
    cin >> dna;
    cout << solver.reverse_complement(dna) << endl;
}

void Menu::gc_content() {
    vector<string> lines;
    string line;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Wklej dane FASTA (pusta linia kończy):\n";

    while (true) {
        getline(cin, line);
        if (line.empty()) break;
        lines.push_back(line);
    }

    cout << solver.gc_content(lines) << endl;
}

void Menu::prot_translate() {
    string rna;
    cout << "Podaj sekwencję RNA: ";
    cin >> rna;
    cout << solver.prot_translate(rna) << endl;
}

void Menu::run() {
    show_menu();
    int choice;
    cin >> choice;

    switch (choice) {
        case 1: dna_counter(); break;
        case 2: rna_transcribe(); break;
        case 3: reverse_complement(); break;
        case 4: gc_content(); break;
        case 5: prot_translate(); break;
        default:
            cout << "Nieprawidłowa opcja\n";
    }

}

