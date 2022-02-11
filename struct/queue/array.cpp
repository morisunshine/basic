#include <iostream>
using namespace std;

template <class T>
class LinerQueue
{
public:
    LinerQueue(int length);
    virtual ~LinerQueue();
    int QueueLen();
    bool QueueEmpty();
    bool QueueFull();
    void ClearQueue();
    bool InsertElement(T element);
    bool GetElement(T &element);
    void TraversalQueue();

private:
    T *m_iQueue;
    int m_iHead;
    int m_iTail;
    int m_iQueueLength;
    int m_iQueueCapacity;
};

//队列的构造函数
template <class T>
LinerQueue<T>::LinerQueue(int length)
{
    m_iQueueCapacity = length;
    m_iQueue = new T[m_iQueueCapacity];
    m_iHead = 0;
    m_iTail = 0;
    m_iQueueLength = 0;
    //ClearQueue();
}
//队列的析构函数
template <class T>
LinerQueue<T>::~LinerQueue()
{
    delete[] m_iQueue;
    m_iQueue = NULL;
}
//队列的队长函数
template <class T>
int LinerQueue<T>::QueueLen() { return m_iQueueLength; }
//队列的判空函数
template <class T>
bool LinerQueue<T>::QueueEmpty() { return m_iQueueLength == 0 ? true : false; }
//队列的判满函数
template <class T>
bool LinerQueue<T>::QueueFull() { return m_iTail == m_iQueueCapacity ? true : false; }
//队列的清空函数
template <class T>
void LinerQueue<T>::ClearQueue()
{
    m_iHead = 0;
    m_iTail = 0;
    m_iQueueLength = 0;
}
//队列新插入元素函数
template <class T>
bool LinerQueue<T>::InsertElement(T element)
{
    if (QueueFull())
    {
        cout << "该队列已满，不能再插入新的元素！" << endl;
        return false;
    }
    else
    {
        m_iQueue[m_iTail] = element;
        m_iQueueLength++;
        m_iTail++;
    }
}
//队列取队头元素的函数
template <class T>
bool LinerQueue<T>::GetElement(T &element)
{
    if (QueueEmpty())
    {
        cout << "该队列为空，不能取到队头元素！" << endl;
        return false;
    }
    else
    {
        element = m_iQueue[m_iHead];
        m_iQueueLength--;
        m_iHead++;
    }
}
//队列的遍历函数
template <class T>
void LinerQueue<T>::TraversalQueue()
{
    for (int i = m_iHead; i < (m_iHead + m_iQueueLength); i++)
    {
        cout << m_iQueue[i] << endl;
    }
}

int main(void)
{
    LinerQueue<double> *p = new LinerQueue<double>(5);
    p->InsertElement(10.1);
    p->InsertElement(11.2);
    p->InsertElement(12.3);
    p->InsertElement(13.4);
    p->InsertElement(14.5);
    p->TraversalQueue();
    double e = 0;
    p->GetElement(e);
    cout << endl;
    cout << e << endl;
    cout << endl;
    p->TraversalQueue();
    cout << endl;
    p->ClearQueue();
    cout << endl;
    cout << p->QueueLen() << endl;
    p = NULL;

    return 0;
}