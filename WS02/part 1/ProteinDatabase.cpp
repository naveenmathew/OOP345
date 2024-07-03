#include "ProteinDatabase.h"
#include <fstream>
#include <iostream>
#include <string>




namespace seneca {
    void ProteinDatabase::storeSequence(const std::string &sequence)
    {
        size_t capacity{};
        if (num_sequences == capacity) {
            capacity = (capacity == 0) ? 1 : capacity * 2;
            std::string* newSequences = new std::string[capacity];
            std::copy(sequences, sequences + num_sequences, newSequences);
            delete[] sequences;
            sequences = newSequences;
        }
        sequences[num_sequences++] = sequence;
    }


   ProteinDatabase::ProteinDatabase(): sequences(nullptr), num_sequences(0) {}

    ProteinDatabase::ProteinDatabase(const std::string& filename) : sequences(nullptr), num_sequences(0) {
        std::ifstream file(filename);

        if (!file) {
            std::cerr << "Error: Failed to open file: " << filename << std::endl;
            return;
        }

        std::string line;
        std::string sequence;
        bool readingSequence = false;

        while (std::getline(file, line)) {
            if (line[0] == '>') {
                if (readingSequence) {
                    storeSequence(sequence);
                    sequence.clear();
                }
                readingSequence = true;
            } else {
                sequence += line;
            }
        }

        if (readingSequence) {
            storeSequence(sequence);
        }
    }
    
    ProteinDatabase::~ProteinDatabase() {
        delete[] sequences;
    }

    ProteinDatabase::ProteinDatabase(const ProteinDatabase& other) : sequences(nullptr), num_sequences(other.num_sequences) {
        if (num_sequences > 0) {
            sequences = new std::string[num_sequences];
            for (size_t i = 0; i < num_sequences; ++i) {
                sequences[i] = other.sequences[i];
            }
        }
    }

    ProteinDatabase& ProteinDatabase::operator=(const ProteinDatabase& other) {
        if (this != &other) {
            delete[] sequences;
            num_sequences = other.num_sequences;
            if (num_sequences > 0) {
                sequences = new std::string[num_sequences];
                for (size_t i = 0; i < num_sequences; ++i) {
                    sequences[i] = other.sequences[i];
                }
            } else {
                sequences = nullptr;
            }
        }
        return *this;
    }

    ProteinDatabase::ProteinDatabase(ProteinDatabase&& other) noexcept : sequences(other.sequences), num_sequences(other.num_sequences) {
        other.sequences = nullptr;
        other.num_sequences = 0;
    }

    ProteinDatabase& ProteinDatabase::operator=(ProteinDatabase&& other) noexcept {
        if (this != &other) {
            delete[] sequences;
            sequences = other.sequences;
            num_sequences = other.num_sequences;
            other.sequences = nullptr;
            other.num_sequences = 0;
        }
        return *this;
    }

    size_t ProteinDatabase::size() const {
        return num_sequences;
    }

    std::string ProteinDatabase::operator[](size_t index) const {
        if (index >= num_sequences) {
            return std::string();
        }
        return sequences[index];
    }
}
