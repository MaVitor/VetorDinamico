#ifndef __ARRAY_LIST_IFRN__
#define __ARRAY_LIST_IFRN__

class array_list {
private:
    int* data;
    unsigned int size_;
    unsigned int capacity_;

    void increase_capacity() {
        capacity_ *= 2;
        int* new_data = new int[capacity_];
        for (unsigned int i = 0; i < size_; ++i) {
            new_data[i] = data[i];
        }
        delete[] data;
        data = new_data;
    }
    // Aumenta a capacidade do array O(n)
public:
    array_list(){
        data = new int[8];
        size_ = 0;
        capacity_ = 8;
    }
    // Construtor O(1)
    ~array_list() {
        delete[] data;
    }
    // Destrutor O(1)
    unsigned int size() {
        return size_;
    }
    // Retorna o tamanho da lista O(1)
    unsigned int capacity() {
        return capacity_;
    }
    // Retorna a capacidade da lista O(1)
    double percent_occupied() {
        return static_cast<double>(size_) / capacity_;
    }
    // Percentual Ocupado O(1)
    bool insert_at(unsigned int index, int value) {
        if (index > size_) {
            return false;
        }
        if (size_ == capacity_) {
            increase_capacity();
        }
        for (unsigned int i = size_; i > index; --i) {
            data[i] = data[i - 1];
        }
        data[index] = value;
        ++size_;
        return true;
    }
    // Insere um elemento em uma posição específica O(n)
    bool remove_at(unsigned int index) {
        if (index >= size_) {
            return false;
        }
        for (unsigned int i = index; i < size_ - 1; ++i) {
            data[i] = data[i + 1];
        }
        --size_;
        return true;
    }
    // Remove um elemento em uma posição específica O(n)
    int get_at(unsigned int index) {
        if (index >= size_) {
            return -1;
        }
        return data[index];
    }
    // Retorna o elemento em uma posição específica O(1)
    void clear() {
        size_ = 0;
    }
    // Limpa a lista O(1)
    void push_back(int value) {
        if (size_ == capacity_) {
            increase_capacity();
        }
        data[size_++] = value;
    }
    // Insere um elemento no final da lista O(1)
    void push_front(int value) {
        insert_at(0, value);
    }
    // Insere um elemento no início da lista O(n)
    bool pop_back() {
        if (size_ == 0) {
            return false;
        }
        --size_;
        return true;
    }
    // Remove o elemento no final da lista O(1)
    bool pop_front() {
        return remove_at(0);
    }
    // Remove o elemento no início da lista O(n)
    int back() {
        if (size_ == 0) {
            return -1;
        }
        return data[size_ - 1];
    }
    // Retorna o elemento no final da lista O(1)
    int front() {
        if (size_ == 0) {
            return -1;
        }
        return data[0];
    }
    // Retorna o elemento no início da lista O(1)
    bool remove(int value) {
        int index = find(value);
        if (index != -1) {
            remove_at(index);
            return true;
        }
        return false;
    }
    // Remove o primeiro elemento com o valor especificado O(n)
    int find(int value) {
        for (unsigned int i = 0; i < size_; ++i) {
            if (data[i] == value) {
                return i;
            }
        }
        return -1;
    }
    // Retorna o índice do primeiro elemento com o valor especificado O(n)
    int count(int value) {
        int count = 0;
        for (unsigned int i = 0; i < size_; ++i) {
            if (data[i] == value) {
                ++count;
            }
        }
        return count;
    }
    // Retorna a quantidade de elementos com o valor especificado O(n)
    int sum() {
        int total = 0;
        for (unsigned int i = 0; i < size_; ++i) {
            total += data[i];
        }
        return total;
    }
};
    // Retorna a soma de todos os elementos da lista O(n)

#endif // __ARRAY_LIST_IFRN__