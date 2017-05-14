// ****************
// 3.2 Stack Min
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

// *******************
// 3.4 Two Stack Queue
// *******************

template<typename T>
struct SQueue
{
    static SQueue<T> *fromVector(const std::vector<T>& v)
    {
        auto q = new SQueue<T>;
        q->m_entryStack = Stack<T>::fromVector(v);
        q->m_exitStack = new Stack<T>;
        return q;
    }
    
    void drain()
    {
        while(!m_entryStack->empty())
        {
            m_exitStack->push(m_entryStack->top());
            m_entryStack->pop();
        }
    }
    
    void push(T data)
    {
        m_entryStack->push(data);
    }
    
    void pop()
    {
        if (m_exitStack->empty()) { drain(); }
        m_exitStack->pop();
    }
    
    T top()
    {
        if (m_exitStack->empty()) { drain(); }
        return m_exitStack->top();
    }
    
    bool empty()
    {
        return m_entryStack->empty() && m_exitStack->empty();
    }
    
    void print()
    {
        drain();
        m_exitStack->print();
    }
    
    Stack<T> *m_entryStack = nullptr;
    Stack<T> *m_exitStack = nullptr;
};

void problem3_4()
{
    
    auto q = SQueue<int>::fromVector({1, 2, 3});
    std:: cout << q->top() << std::endl; // Should be 1
    q->push(4);
    std::cout << q->top() << std::endl; // Should be 1
    while (!q->empty())
    {
        std::cout << q->top() << " ";
        q->pop();
    }
    std::cout << std::endl;

}
