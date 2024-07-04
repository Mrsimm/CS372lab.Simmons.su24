#include <iostream>
#include <list>
using namespace std;

template<typename T1, typename T2>
class Pair 
{
public:
    T1 first;
    T2 second;

    Pair(const T1& f, const T2& s) : first(f), second(s) {}
};

template<typename KeyType, typename ValueType>
class Dictionary 
{
private:
    struct TreeNode 
    {
        Pair<KeyType, ValueType> data;
        TreeNode* left;
        TreeNode* right;

        TreeNode(const KeyType& key, const ValueType& value)
            : data(key, value), left(nullptr), right(nullptr) {}
    };

    TreeNode* root;

    
    ValueType& find(TreeNode* node, const KeyType& key)
    {
        if (node == nullptr) 
        {
            throw std::out_of_range("Key not found");
        }

        if (key < node->data.first) 
        {
            return find(node->left, key);
        }
        else if (key > node->data.first) 
        {
            return find(node->right, key);
        }
        else 
        {
            return node->data.second;
        }
    }


    
    void insert(TreeNode*& node, const KeyType& key, const ValueType& value)
    {
        if (node == nullptr)
            node = new TreeNode(key, value);
        else if (key < node->data.first)
            insert(node->left, key, value);
        else if (key > node->data.first)
            insert(node->right, key, value);
        else
            node->data.second = value;
    }


    
    void getKeys(TreeNode* node, std::list<KeyType>& keys) const 
    {
        if (node != nullptr) 
        {
            getKeys(node->left, keys);
            keys.push_back(node->data.first);
            getKeys(node->right, keys);
        }
    }

    
    void getValues(TreeNode* node, list<ValueType>& values) const 
    {
        if (node != nullptr) 
        {
            getValues(node->left, values);
            values.push_back(node->data.second);
            getValues(node->right, values);
        }
    }

    
    void clear(TreeNode*& node) 
    {
        if (node != nullptr) {
            clear(node->left);
            clear(node->right);
            delete node;
            node = nullptr;
        }
    }

public:
   
    Dictionary() : root(nullptr) {}

    ~Dictionary() {
        clear(root);
    }

    ValueType& get(KeyType key) {
        return find(root, key);
    }

    void set(KeyType key, ValueType value) {
        insert(root, key, value);
    }

    list<KeyType> getKeys() const {
        std::list<KeyType> keys;
        getKeys(root, keys);
        return keys;
    }

    list<ValueType> getValues() const 
    {
        list<ValueType> values;
        getValues(root, values);
        return values;
    }

    
    ValueType& operator[](const KeyType& key) 
    {
        return find(root, key);
    }
};

