#ifndef __HASHTABLE_H__
#define __HASHTABLE_H__
#include <pthread.h>
#include <stdio.h>
#include <string>

#include "linkedlist.h"

inline long strSimpleHash(std::string string)
{
    size_t len = string.size();
    long hash = 0;
    for(size_t i = 0; i < len; ++i) 
        hash = 65599 * hash + string[i];
    return hash ^ (hash >> 16);
}

template<typename K>
struct HashFunc
{
    typedef long (*type)(K);
};

template<typename K>
struct DefaultHash;

template<>
struct DefaultHash<std::string>
{
    static constexpr HashFunc<std::string>::type func = &strSimpleHash;
};

template <class K, class V>
class HashTableIterator
{
public:
    HashTableIterator(ListItemIterator<K, ListItem<K, V>* > *item);
    K Key();
    HashTableIterator& operator++ (int);
    V& operator *();
    HashTableIterator& operator++ ();
    bool operator==(const HashTableIterator<K, V>& o) const;
    bool operator!=(const HashTableIterator<K, V>& o) const;

protected:
    ListItem<K, ListItem<K, V> *> *inner_item;
};

template<class K, class V>
K HashTableIterator<K, V>::Key()
{
    return this->inner_item->key;
}

template<class K, class V>
HashTableIterator<K, V>::HashTableIterator(ListItemIterator<K, ListItem<K, V>* > *item)
{
    inner_item = item->getInner();
}

template<class K, class V>
HashTableIterator<K, V>& HashTableIterator<K, V>::operator++ (int)
{
    HashTableIterator<K, V> tmp(*this);
    if(NULL != this->inner_item)
        this->inner_item = this->inner_item->next;
    return tmp;
}

template<class K, class V>
V& HashTableIterator<K, V>::operator *()
{
    return this->inner_item->value->value;
}

template<class K, class V>
HashTableIterator<K, V>& HashTableIterator<K, V>::operator++ ()
{
    if(NULL != this->inner_item)
        this->inner_item = this->inner_item->next;
    return *this;
}

template<class K, class V>
bool HashTableIterator<K, V>::operator==(const HashTableIterator<K, V>& o) const 
{
    return this->inner_item == o.inner_item;
}

template<class K, class V>
bool HashTableIterator<K, V>::operator!=(const HashTableIterator<K, V>& o) const 
{ 
    return !(*this == o); 
}

template <class K, class V, typename HashFunc<K>::type H = DefaultHash<K>::func>
class HashTableAbs
{
public:
    HashTableIterator<K, V> begin();
    HashTableIterator<K, V> end();
    //ListItemIterator<K, ListItem<K, V> *> begin();
    //ListItemIterator<K, ListItem<K, V> *> end();
    HashTableAbs();
    void set(const K& key, const V& value);
    V* get(const K& key);
    V getOrDef(const K& key, const V& def);
    bool erase(const K& key);
    ~HashTableAbs();
    long size();
    void reset();
    void setByArrays(K *keys, V* values, long count);
    HashTableAbs(HashTableIterator<K, V> &it, HashTableIterator<K, V> &end);
private:
    long getIndex(const K& key);
    void clear();
    void create();
    long sizeOfTable;
    long _size;
    LinkedList<K, V>** values;
    LinkedList<K, ListItem<K, V> *> *linked_values;
    bool operator==(const HashTableAbs<K, V, H>& o) const {}
    bool operator!=(const HashTableAbs<K, V, H>& o) const {}
};

template <class K, class V, typename HashFunc<K>::type H>
HashTableAbs<K, V, H>::HashTableAbs(HashTableIterator<K, V> &it, HashTableIterator<K, V> &end):HashTableAbs<K, V, H>()
{
    for(; it != end; it++)
    {
        this->set(it.Key(), (*it));
    }
}


template <class K, class V, typename HashFunc<K>::type H>
void HashTableAbs<K, V, H>::setByArrays(K *keys, V* values, long count)
{
    for(long i = 0; i < count; i++)
    {
        this->set(keys[i], values[i]);
    }

}

//template <class K, class V, long H(K)>
template <class K, class V, typename HashFunc<K>::type H>
//ListItemIterator<K, ListItem<K, V> *> HashTableAbs<K, V, H>::begin()
HashTableIterator<K, V> HashTableAbs<K, V, H>::begin()
{
    auto tmp = this->linked_values->begin();
    HashTableIterator<K, V> tmp2(&tmp);
    return tmp2;//this->linked_values->begin();
}

//template <class K, class V, long H(K)>
template <class K, class V, typename HashFunc<K>::type H>
//ListItemIterator<K, ListItem<K, V> *> HashTableAbs<K, V, H>::end()
HashTableIterator<K, V> HashTableAbs<K, V, H>::end()
{
    auto tmp = this->linked_values->end();
    return HashTableIterator<K, V>(&tmp);//this->linked_values->end();
}

//template <class K, class V, long H(K)>+

template <class K, class V, typename HashFunc<K>::type H>
HashTableAbs<K, V, H>::HashTableAbs()
{
    this->sizeOfTable = 100000;
    this->_size = 0;
    this->create();
}

//template <class K, class V, long H(K)>
template <class K, class V, typename HashFunc<K>::type H>
void HashTableAbs<K, V, H>::set(const K& key, const V& value)
{
    //printf("in set\n");
    long index = this->getIndex(key);
    //auto p = this->values[index];
    //printf("in set %d %ld\n", index, p);
    ListItem<K, V> *tmp = this->values[index]->find(key);
    if(NULL == tmp)
    {
        this->_size++;
        this->linked_values->add(key, this->values[index]->add(key, value));
    }
    else
    {
        tmp->value = value;
    }
}

//template <class K, class V, long H(K)>
template <class K, class V, typename HashFunc<K>::type H>
V* HashTableAbs<K, V, H>::get(const K& key)
{
    long index = this->getIndex(key);
    ListItem<K, V> *tmp = this->values[index]->find(key);
    if(NULL == tmp) return NULL;
    return &tmp->value;
}

//template <class K, class V, long H(K)>
template <class K, class V, typename HashFunc<K>::type H>
V HashTableAbs<K, V, H>::getOrDef(const K& key, const V& def)
{
    V* tmp = this->get(key);
    if(NULL == tmp) return def;
    return *tmp;
}

//template <class K, class V, long H(K)>
template <class K, class V, typename HashFunc<K>::type H>
bool HashTableAbs<K, V, H>::erase(const K& key)
{
    long index = this->getIndex(key);
    bool res = this->values[index]->erase(key);
    this->linked_values->erase(key);
    if(res)
    {
        this->_size--;
        return true;
    }
    return false;
}

//template <class K, class V, long H(K)>
template <class K, class V, typename HashFunc<K>::type H>
HashTableAbs<K, V, H>::~HashTableAbs()
{
    this->clear();
}

//template <class K, class V, long H(K)>
template <class K, class V, typename HashFunc<K>::type H>
long HashTableAbs<K, V, H>::size()
{
    return this->_size;
}

//template <class K, class V, long H(K)>
template <class K, class V, typename HashFunc<K>::type H>
void HashTableAbs<K, V, H>::reset()
{
    this->clear();
    this->_size = 0;
    this->create();
}

//template <class K, class V, long H(K)>
template <class K, class V, typename HashFunc<K>::type H>
long HashTableAbs<K, V, H>::getIndex(const K& key)
{
    //printf("key %ld size\n", H(key), this->sizeOfTable);
    return H(key) % this->sizeOfTable;
}


//template <class K, class V, long H(K)>
template <class K, class V, typename HashFunc<K>::type H>
void HashTableAbs<K, V, H>::create()
{
    this->linked_values = new LinkedList<K, ListItem<K, V> *>();
    this->values = new LinkedList<K, V> *[sizeOfTable];
    for(int i = 0; i < this->sizeOfTable; i++)
        this->values[i] = new LinkedList<K, V>();
}

//template <class K, class V, long H(K)>
template <class K, class V, typename HashFunc<K>::type H>
void HashTableAbs<K, V, H>::clear()
{
    delete this->linked_values;
    for(int i = 0; i < this->sizeOfTable; i++)
        delete this->values[i];
    delete[] this->values;
}

template <class K, class V, typename HashFunc<K>::type H = DefaultHash<K>::func>
class HashTable:public HashTableAbs<K, V, H> 
{
public:
    HashTable(HashTableIterator<K, V> &it, HashTableIterator<K, V> &end):HashTableAbs<K, V, H>(it, end){}
    HashTable(K *keys, V* values, long count);
    HashTable():HashTableAbs<K, V, H>() {}
};
/*
template <class K, class V, typename HashFunc<K>::type H>
HashTable<K, V, H>::HashTable(HashTableIterator<K, V> &it, HashTableIterator<K, V> &end)
{
    for(; it != end; it++)
    {
        this->set(it.Key(), (*it));
    }
}
*/
template <class K, class V, typename HashFunc<K>::type H>
HashTable<K, V, H>::HashTable(K *keys, V* values, long count)
{
    this->setByArrays(keys, values, count);
    /*for(long i = 0; i < count; i++)
    {
        this->set(keys[i], values[i]);
    }*/
}



template <class V> 
class HashTable<std::string, V, DefaultHash<std::string>::func>:public HashTableAbs<std::string, V, DefaultHash<std::string>::func> 
{
public:
    HashTable(HashTableIterator<std::string, V> &it, HashTableIterator<std::string, V> &end) :HashTableAbs<std::string, V, DefaultHash<std::string>::func>(it, end){}
    HashTable(std::string *keys, V* values, long count);
    HashTable() {}
};
/*
template <class V>
HashTable<std::string, V, DefaultHash<std::string>::func >::HashTable(HashTableIterator<std::string, V> &it, HashTableIterator<std::string, V> &end)
{
    for(; it != end; it++)
    {
        this->set(it.Key(), (*it));
    }
}
*/
template <class V>
HashTable<std::string, V, DefaultHash<std::string>::func >::HashTable(std::string *keys, V* values, long count)
{
    this->setByArrays(keys, values, count);
    /*for(long i = 0; i < count; i++)
    {
        this->set(keys[i], values[i]);
    }*/
}

#endif
