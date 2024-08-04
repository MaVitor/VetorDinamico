#ifndef __LINKED_LIST_IFRN__
#define __LINKED_LIST_IFRN__

class linked_list {
private:
    // Atributos
    struct int_node {
        int value;
        struct int_node* next;        
        struct int_node* prev;
    };
    int_node* head;
    int_node* tail;
    int size_;
public:
    linked_list() {
        this->head = nullptr;
        this->tail = nullptr;
        this->size_ = 0;
    }
    // Construtor O(1)
    ~linked_list() {
       this->clear();
    }
    // Destrutor O(n)
    unsigned int size() {
        return this->size_;
    }
    // Retorna o tamanho da lista O(1)
    unsigned int capacity() {
        return this->size_; // Em uma lista encadeada, capacidade é igual ao tamanho
    }
    // Retorna a capacidade da lista O(1)
    double percent_occupied() {
        return this->size_ > 0 ? 1.0 : 0.0; // Em uma lista encadeada, se a lista tem elementos, ela está 100% ocupada
    }
    // Percentual Ocupado O(1)
    bool insert_at(unsigned int index, int value) {
        if (index > this->size_) return false;
        if (index == 0) {
            this->push_front(value);
            return true;
        } 
        if (index == this->size_) {
            this->push_back(value);
            return true;
        }
        int_node* new_node = new int_node{value, nullptr, nullptr};
        int_node* current = this->head;
        for (unsigned int i = 0; i < index; ++i) {
            current = current->next;
        }
        new_node->next = current;
        new_node->prev = current->prev;
        current->prev->next = new_node;
        current->prev = new_node;
        ++this->size_;
        return true;
    }
    // Insere um elemento em uma posição específica O(n)
    bool remove_at(unsigned int index) {
        if (index >= this->size_) return false;
        int_node* current = this->head;
        for (unsigned int i = 0; i < index; ++i) {
            current = current->next;
        }
        if (current->prev) current->prev->next = current->next;
        if (current->next) current->next->prev = current->prev;
        if (current == this->head) this->head = current->next;
        if (current == this->tail) this->tail = current->prev;
        delete current;
        --this->size_;
        return true;
    }
    // Remove um elemento de uma posição específica O(n)
    int get_at(unsigned int index) const {
        if (index >= this->size_) return -1;
        int_node* current = this->head;
        for (unsigned int i = 0; i < index; ++i) {
            current = current->next;
        }
        return current->value;
    }
    // Retorna o elemento em uma posição específica O(n)
    void clear() {
        while (this->head != nullptr) {
            int_node* temp = this->head;
            this->head = this->head->next;
            delete temp;
        }
        this->tail = nullptr;
        this->size_ = 0;
    }
    // Limpa a lista O(n)
    void push_front(int value) {
        int_node* new_node = new int_node{value, this->head, nullptr};
        if (this->head != nullptr) {
            this->head->prev = new_node;
        } else {
            this->tail = new_node;
        }
        this->head = new_node;
        ++this->size_;
    }
    // Insere um elemento no início da lista O(1)
    void push_back(int value) {
        int_node* new_node = new int_node{value, nullptr, this->tail};
        if (this->tail != nullptr) {
            this->tail->next = new_node;
        } else {
            this->head = new_node;
        }
        this->tail = new_node;
        ++this->size_;
    }
    // Insere um elemento no final da lista O(1)
    bool pop_back() {
        if (this->tail == nullptr) return false;
        int_node* temp = this->tail;
        this->tail = this->tail->prev;
        if (this->tail != nullptr) {
            this->tail->next = nullptr;
        } else {
            this->head = nullptr;
        }
        delete temp;
        --this->size_;
        return true;
    }
    // Remove o elemento no final da lista O(1)
    bool pop_front() {
        if (this->head == nullptr) return false;
        int_node* temp = this->head;
        this->head = this->head->next;
        if (this->head != nullptr) {
            this->head->prev = nullptr;
        } else {
            this->tail = nullptr;
        }
        delete temp;
        --this->size_;
        return true;
    }
    // Remove o elemento no início da lista O(1)
    int back() {
        if (this->tail != nullptr) {
            return this->tail->value;
        } else {
            return -1;
        }
    }
    // Retorna o elemento no final da lista O(1)
    int front() {
        if (this->head != nullptr) {
            return this->head->value;
        } else {
            return -1;
        }
    }
    // Retorna o elemento no início da lista O(1)
    bool remove(int value) {
        int_node* current = this->head;
        while (current != nullptr) {
            if (current->value == value) {
                if (current->prev) current->prev->next = current->next;
                if (current->next) current->next->prev = current->prev;
                if (current == this->head) this->head = current->next;
                if (current == this->tail) this->tail = current->prev;
                delete current;
                --this->size_;
                return true;
            }
            current = current->next;
        }
        return false;
    }
    // Remove o primeiro elemento com o valor especificado O(n)
    int find(int value) {
        int_node* current = this->head;
        int index = 0;
        while (current != nullptr) {
            if (current->value == value) return index;
            current = current->next;
            ++index;
        }
        return -1;
    }
    // Retorna o índice do primeiro elemento com o valor especificado O(n)
    int count(int value) {
        int_node* current = this->head;
        int count = 0;
        while (current != nullptr) {
            if (current->value == value) ++count;
            current = current->next;
        }
        return count;
    }
    // Retorna a quantidade de elementos com o valor especificado O(n)
    int sum() {
        int_node* current = this->head;
        int sum = 0;
        while (current != nullptr) {
            sum += current->value;
            current = current->next;
        }
        return sum;
    }
    // Retorna a soma de todos os elementos da lista O(n)
};
#endif // __LINKED_LIST_IFRN__