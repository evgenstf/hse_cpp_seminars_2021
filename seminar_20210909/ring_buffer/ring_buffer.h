#include <vector>

class RingBuffer
{
public:
    RingBuffer(int reserved_size);


    void push(int x);
    int pop();
    int size();

private:
    std::vector<int> buffer_;

    int head_ = 0;
    int tail_ = 0;
};
