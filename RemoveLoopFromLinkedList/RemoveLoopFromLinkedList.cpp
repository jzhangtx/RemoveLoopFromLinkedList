// RemoveLoopFromLinkedList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <unordered_set>

class ListNode
{
public:
    int data;
    ListNode* next;
    ListNode(int data)
        : data(data)
        , next(nullptr)
    {}
};

ListNode* GetListFromInput(ListNode** ppHead, int count)
{
    if (count == 0)
        return nullptr;

    std::cout << "Enter " << count << " numbers of the list: ";
    ListNode* pTail = *ppHead;
    for (int i = 0; i < count; ++i)
    {
        int data = 0;
        std::cin >> data;
        if (*ppHead == nullptr)
        {
            *ppHead = new ListNode(data);
            pTail = *ppHead;
        }
        else
        {
            pTail->next = new ListNode(data);
            pTail = pTail->next;
        }
    }

    return pTail;
}

void PrintList(ListNode* pHead)
{
    if (pHead == nullptr)
        return;

    std::cout << pHead->data;
    pHead = pHead->next;

    while (pHead != nullptr)
    {
        std::cout << ", " << pHead->data;
        pHead = pHead->next;
    }
}

void FreeList(ListNode* pNode)
{
    if (pNode == nullptr)
        return;

    FreeList(pNode->next);
    delete pNode;
}

ListNode* GetNodeByIndex(ListNode* pHead, int index)
{
    if (index == -1)
        return nullptr;

    for (int i = 0; i < index; ++i)
    {
        pHead = pHead->next;
    }

    return pHead;
}

ListNode* EndNodeOfLoop(ListNode* list)
{
    std::unordered_set<ListNode*> nodes;
    ListNode* lastNode = nullptr;

    while (list != nullptr)
    {
        if (nodes.find(list) != nodes.cend())
            return lastNode;

        nodes.insert(list);
        lastNode = list;
        list = list->next;
    }

    return nullptr;
}

void RemoveLoop(ListNode* list)
{
    ListNode* pTail = EndNodeOfLoop(list);
    if (pTail != nullptr)
        pTail->next = nullptr;
}

int main()
{
    while (true)
    {
        int count = 0;
        std::cout << "Number of nodes in list: ";
        std::cin >> count;
        if (count < 0)
            break;

        ListNode* pHead = nullptr;
        ListNode* pTail = GetListFromInput(&pHead, count);

        std::cout << "The index of starting node of the loop: ";
        int index = -1;
        std::cin >> index;
        if (pHead != 0)
            pTail->next = GetNodeByIndex(pHead, index);

        RemoveLoop(pHead);

        std::cout << "The list after loop removed: ";
        PrintList(pHead);
        std::cout << std::endl;

        FreeList(pHead);
    }
}
