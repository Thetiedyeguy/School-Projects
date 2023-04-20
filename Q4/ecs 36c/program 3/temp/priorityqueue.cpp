#include <iostream>
#include "json.hpp"

#include "priorityqueue.h"

PriorityQueue::PriorityQueue(std::size_t max_size) :
	nodes_(max_size + 1, KeyValuePair()),
	max_size_(max_size),
	size_(0) {
}

void PriorityQueue::insert(Key k) {
	insert(std::make_pair(k, std::make_pair(0, 0)));
}

void PriorityQueue::insert(KeyValuePair kv) {
    size_++;
    nodes_[size_] = kv;
    heapifyUp(size_);
}

KeyValuePair PriorityQueue::min() {
	return nodes_[1];
}

KeyValuePair PriorityQueue::removeMin() {
	KeyValuePair minimum = min();
    removeNode(1);
    return minimum;
}

bool PriorityQueue::isEmpty() const {
	if(size_ == 0){
        return true;
    }
    return false;
}

size_t PriorityQueue::size() const {
	return size_;
}

nlohmann::json PriorityQueue::JSON() const {
    nlohmann::json result;
    for (size_t i = 1; i <= size_; i++) {
        nlohmann::json node;
        KeyValuePair kv = nodes_[i];
        node["key"] = kv.first;
        node["value"] = kv.second;
        if (i != ROOT) {
            node["parent"] = std::to_string(i / 2);
        }
        if (2 * i <= size_) {
            node["leftChild"] = std::to_string(2 * i);
        }
        if (2 * i + 1 <= size_) {
            node["rightChild"] = std::to_string(2 * i + 1);
        }
        result[std::to_string(i)] = node;
    }
    result["metadata"]["max_size"] = max_size_;
    result["metadata"]["size"] = size_;
	return result;
}

void PriorityQueue::heapifyUp(size_t i) {
	size_t j = i / 2;
    if(getKey(i) < getKey(j)){
        KeyValuePair temp = nodes_[j];
        nodes_[j] = nodes_[i];
        nodes_[i] = temp;
        if(j > 1){
            heapifyUp(j);
        }
    }
}

void PriorityQueue::heapifyDown(size_t i) {
    size_t j = i * 2;
    double left = getKey(j);
    double right = getKey(j + 1);
    size_t current;
    if(left < right){
        current = j;
    }else{
        current = j + 1;
    }
    if(getKey(i) > getKey(current)){
        KeyValuePair temp = nodes_[current];
        nodes_[current] = nodes_[i];
        nodes_[i] = temp;
        if(size_ > current * 2){
            heapifyDown(current);
        }
    }
}

void PriorityQueue::removeNode(size_t i) {
	nodes_[i] = nodes_[size_];
    size_ = size_ - 1;
    heapifyDown(i);
}

Key PriorityQueue::getKey(size_t i) {
	return std::get<0>(nodes_[i]);
}
