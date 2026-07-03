class DynamicArray {
public:
    DynamicArray(int capacity) : capacity_(capacity) {
        buf = new int[capacity];
    }
    ~DynamicArray() {delete[] buf;}

    int getSize() const {return size_;}
    int getCapacity() const {return capacity_;}
    int get(int i) const {return buf[i];}
    void set(int i, int n) {buf[i] = n;}
    void pushback(int n) {
        if (size_ == capacity_){
            resize();
        }
        set(size_, n);
        size_++;
    }

    int popback() {
        size_--;
        return buf[size_];
    }
private:
    int* buf;
    int size_ = 0;
    int capacity_ = 0;

    void resize() {
        if (capacity_ != 0){
            capacity_ *= 2;
        } else {
            capacity_++;
        }
        int* tempBuf = new int[capacity_];
        for (int i = 0; i < size_; i++){
            tempBuf[i] = buf[i];
        }
        delete[] buf;
        buf = tempBuf;
    }
};
