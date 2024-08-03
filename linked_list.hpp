#ifndef __LINKED_LIST_IFRN__
#define __LINKED_LIST_IFRN__


class linked_list {
private:
    struct int_node {
        int value;
        int_node* next, * prev;
    };
    int_node* head, * tail;
    unsigned int size_;
public:
    linked_list() {
        this->head = 0;
        this->tail = 0;
        this->size_ = 0;
    }
    ~linked_list() {
        int_node* current = this->head;
        while (current != nullptr) {
            int_node* to_remove = current;
            current = current->next;
            delete to_remove;
        }
    }
    unsigned int size() {}
    unsigned int capacitty() {}
    double percent_occupied() {}
    bool insert_at(unsigned int index, int value) {}
    bool remove_at(unsigned int index) {
        if (index >= this->size_)
            return false; // Não removeu
        int_node* to_remove = this->head;
        for (unsigned int i = 0; i < index; ++i)
            to_remove = to_remove->next;
        if (to_remove->prev != nullptr)
            to_remove->prev->next = to_remove->next;
        if (to_remove->next != nullptr)
            to_remove->next->prev = to_remove->prev;
        delete to_remove;
        return true; // Removeu
    }
    int get_at(unsigned int index) {}
    void clear() {}
    void push_back(int value) {}
    void push_front(int value) {
        int_node* new_node = new int_node;
        new_node->value = value;
        new_node->next = this->head;
        new_node->prev = nullptr;
        if (this->head == nullptr)
            this->tail = new_node;
        else
            this->head->prev = new_node;
        this->head = new_node;
    }
    bool pop_back() {}
    bool pop_front() {}
    int front() {}
    int back() {}
    bool remove(int value) {}
    int find(int value) {}
    int count(int value) {}
    int sum() {}
};

#endif // __LINKED_LIST_IFRN__