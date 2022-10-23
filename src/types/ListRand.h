#ifndef SABERINTERACTIVE_LISTRAND_H
#define SABERINTERACTIVE_LISTRAND_H

#include <fstream>
#include "ListNode.h"

class ListRand {
public:
    ListNode* Head = nullptr;
    ListNode* Tail = nullptr;
    int Count = 0;

public:
    friend ostream &operator<<(ostream &out, const ListRand &list);

    void PushBack(ListNode *Node);
    void Serialize(fstream &fs);
    void Deserialize(fstream &fs);
};

#endif //SABERINTERACTIVE_LISTRAND_H
