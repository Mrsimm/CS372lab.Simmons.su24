using namespace std;
template <class RecordType>
class Table 
{
public:
    static const size_t CAPACITY = 811;
    Table() : used(0) {}
    void insert(const RecordType& entry) {
        bool alreadyPresent;
        size_t index;
        assert(entry.key >= 0);
        findIndex(entry.key, alreadyPresent, index);
        if (!alreadyPresent) {
            assert(size() < CAPACITY);
            index = hash(entry.key);
            size_t count = 0;
            while (!isVacant(index)) {
                count++;
                index = nextIndex(index, count);
            }
            ++used;
        }
        data[index] = entry;
    }
    void remove(int key) {
        bool found;
        size_t index;
        assert(key >= 0);
        findIndex(key, found, index);
        if (found) {
            data[index].key = PREVIOUSLYUSED;
            --used;
        }
    }
    bool isPresent(int key) const {
        bool found;
        size_t index;
        findIndex(key, found, index);
        return found;
    }
    void find(int key, bool& found, RecordType& result) const {
        size_t index;
        findIndex(key, found, index);
        if (found) {
            result = data[index];
        }
    }
    size_t size() const { return used; }

private:
    static const int NEVERUSED = -1;
    static const int PREVIOUSLYUSED = -2;
    RecordType data[CAPACITY];
    size_t used;

    size_t hash(int key) const {
        return key % CAPACITY;
    }

    size_t nextIndex(size_t index, size_t count) const {
        return (index + count * count) % CAPACITY;
    }

    void findIndex(int key, bool& found, size_t& index) const {
        size_t count = 0;
        index = hash(key);
        while (count < CAPACITY && !neverUsed(index) && data[index].key != key) {
            count++;
            index = nextIndex(index, count);
        }
        found = (data[index].key == key);
    }

    bool neverUsed(size_t index) const { return (index == NEVERUSED); }
    bool isVacant(size_t index) const { return (index == PREVIOUSLYUSED); }
};

