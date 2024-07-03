#ifndef SENECA_PROTEINDATABASE_H
#define SENECA_PROTEINDATABASE_H

#include <string>

namespace seneca {
    class ProteinDatabase {
        std::string* sequences;
        size_t num_sequences;
        void storeSequence(const std::string& sequence);
    public:
        ProteinDatabase();
        ProteinDatabase(const std::string& filename);
        ~ProteinDatabase();
        ProteinDatabase(const ProteinDatabase& other);
        ProteinDatabase& operator=(const ProteinDatabase& other);
        ProteinDatabase(ProteinDatabase&& other) noexcept;
        ProteinDatabase& operator=(ProteinDatabase&& other) noexcept;
        size_t size() const;
        std::string operator[](size_t index) const;
    };
}

#endif
