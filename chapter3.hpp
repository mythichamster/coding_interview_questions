// ****************
// 3.1 Stack Min
// ****************

template<typename T>
struct Node
{
    Node(const T& data, Node<T> *next = nullptr) 
    {
        m_data = data;
        m_next = next;
        if (m_next && m_next->m_min < data) 
        {
            m_min = m_next->m_min;
        }
        else 
        {
            m_min = m_data;
        }
    }
    
    static Node<T>* fromVector(const std::vector<T>& v)
    {
        Node<T> *head = nullptr;
        for (auto it = v.begin(); it != v.end(); it++)
        {
            head = new Node<T>(*it, head);
        }
        return head;
    }
    
    void print()
    {
        Node<T> *curr = this;
        while (curr)
        {
            std::cout << curr->m_data << " ";
            curr = curr->m_next;
        }
        std::cout << std::endl;
    }
    
    T m_data;
    T m_min;
    Node<T> *m_next;
};

template<typename T>
struct Stack
{   
    static Stack<T> *fromVector(const std::vector<T>& v)
    {
        Stack<T> *stack = new Stack<T>();
        stack->m_head = Node<T>::fromVector(v);
        return stack;
    }
    
    // Add a node to the head of the linked list
    void push(T data)
    {
       m_head = new Node<T>(data, m_head);
    }
    
    void pop()
    {
        if (m_head)
        {
            Node<T> *temp = m_head;
            m_head = m_head->m_next;
            delete temp;
        }
    }
    
    // Throws exception if stack is empty
    T top()
    {
        return m_head->m_data;
    }
    
    bool empty()
    {
        return m_head == nullptr;
    }
    
    void print()
    {
        if (m_head) m_head->print();
    }
    
    T min()
    {
        return m_head->m_min;
    }
    
    Node<T> *m_head = nullptr;
};

void problem3_2()
{
    auto stack = Stack<int>::fromVector({4, 3, 6, 1});
    while (!stack->empty())
    {
        std::cout << stack->min() << "->";
        stack->print();
        stack->pop();
    }
}
