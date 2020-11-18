/* 
@Author: Jing
@Date: 2020.11.18
@Desc: 底层数据结构:hash table的实现
*/

#ifndef __HASH_TABLE_H__
#define __HASH_TABLE_H__

#include <memory>
#include <string>

#include "MydisObj.h"

// hash table 中的节点
struct Entry{
    // 作为链表的一个节点
    // 使用多态, 保存数据对象
    // 使用shared_ptr管理对象
    std::string key;    // 键一定是一个string
    std::shared_ptr<MydisObj> value;    // 即使是简单的整数,也不直接存储
    Entry* next;
    Entry* pre;
    Entry(): next(nullptr), pre(nullptr){}
    Entry(const string& key, std::shared_ptr<MydisObj> value) : key(key), value(value), next(nullptr), pre(nullptr){} 
};

// hash table的实现
// 使用链地址法解决冲突
class HashTable{
    public:
        HashTable();
        ~HashTable();
    private:
        void reHash();
    private:
        double loadFactor; // 最大负载因子
        unsigned int capacity; // 当前容量,hash table的大小
        unsigned int size; // 保存的节点数量
        Entry** table; // table是一个Entry*数组
        
};

#endif

// 使用什么hash函数