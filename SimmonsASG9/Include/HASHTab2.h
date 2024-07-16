#include <cstdlib>
#include <vector>
using namespace std;
template <class RecordType, size_t TABLESIZE,
    int hashkey(const RecordType&)>
class Table {
public:
    static const size_t CAPACITY = TABLESIZE;
    Table()
    {
        data.resize(CAPACITY);
    }
    void quadraticProbe(const RecordType& entry, size_t& index) const
    {
        int key = hashkey(entry);
        size_t originalIndex = hash(key);
        size_t i = 1;

        while (!isVacant(index)) {
            index = (originalIndex + i * i) % CAPACITY;
            ++i;
        }
    }
    void insert(const RecordType& entry)
    {
        int key = hashkey(entry);
        size_t index = hash(key);

        quadraticProbe(entry, index);

        data[index].push_back(entry);
        totalRecords++;
    }

    void remove(int key) 
    {
        size_t index = hash(key);
        for (auto it = data[index].begin(); it != data[index].end(); ++it) {
            if (hashkey(*it) == key) 
            {
                data[index].erase(it);
                totalRecords--;
                return;
            }
        }
    }

    void find(int key, bool& found, RecordType& result) const
    {
        size_t index = hash(key);

        for (const auto& record : data[index])
        {
            if (hashkey(record) == key)
            {
                found = true;
                result = record;
                return;
            }
        }
        found = false;
    }

    bool isPresent(int key) const
    {
        bool found;
        RecordType result;
        find(key, found, result);
        return found;
    }
    size_t secondHash(int key, int i) const
    {
        return (7 - (key % 7)) * i;
    }
    size_t size() const { return CAPACITY; }
private:
    static const int NEVERUSED = -1;
    static const int PREVIOUSLYUSED = -2;
    vector<vector<RecordType>> data;
    size_t totalRecords = 0;


    size_t nextIndex(size_t index) const
    {
        return (index + 1) % CAPACITY;
    }

    void findIndex(int key, bool& found, size_t& index) const
    {
        index = hash(key);
        int count = 0;

        while ((count < CAPACITY) && !neverUsed(index) && (data[index] != key))
        {
            index = nextIndex(index);
            ++count;
        }

        found = (data[index] == key);
    }

    bool neverUsed(size_t index) const
    {
        return (data[index].empty());
    }

    bool isVacant(size_t index) const
    {
        return (data[index] == NEVERUSED || data[index] == PREVIOUSLYUSED);
    }

    size_t hash(int key) const
    {
        return key % TABLESIZE;
    }
    
};


