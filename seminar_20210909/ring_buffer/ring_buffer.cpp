#include "ring_buffer.h"

RingBuffer::RingBuffer(int reserved_size)
    : buffer_(reserved_size + 1)
{}

void RingBuffer::push(int x)
{
    if (size() >= buffer_.size()) {
        throw "buffer limit exceeded";
    }
    buffer_[tail_] = x;
    tail_ = (tail_ + 1) % buffer_.size();
}

int RingBuffer::pop()
{
    if (size() == 0) {
        throw "empty buffer";
    }
    int x = buffer_[head_];
    head_ = (head_ + 1) % buffer_.size();
    return x;
}

int RingBuffer::size()
{
    return ((tail_ - head_) % buffer_.size() + buffer_.size()) % buffer_.size();
}

