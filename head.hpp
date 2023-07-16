#pragma once

#include <unordered_map>
#include <iostream>
#include <list>
#include <iterator>

namespace cache_lfu
{
    template<typename U, typename freq_node>
    struct freq_data
    {
        using freqIt = typename std::list<freq_node>::iterator;

        U data;
        freadIt freq_node

        freq_data(U data_, freqIt it) : data{data_}, freqIt{freq_node} {}
    };
    template<typename U, typename KeyT>
    struct freq_node
    {
        int frequency;

        std::list<freq_data<U, freq_node<U, KeyT>>> list_;

        freq_node(int frequency_) : frequency{frequency_} {}
    };
    template<typename U, typename KeyT>
    struct cache_
    {
        size_t sz;
        size_t ct;
        using freq_listIt = typename std::list<freq_data<U, KeyT>>::iterator;

        std::list<freq_node<U, KeyT>> freq_list;
        std::unordered_map<KeyT, freq_listIt> hash_table;

        cache_(size_t size, size_t capacity) sz{size}, ct{capacity} {}
        
    };
    

}
