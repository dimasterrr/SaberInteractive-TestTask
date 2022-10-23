#ifndef SABERINTERACTIVE_LISTNODE_H
#define SABERINTERACTIVE_LISTNODE_H

#include "string"

using namespace std;

class ListNode {
public:
    ListNode *Prev = nullptr;
    ListNode *Next = nullptr;
    ListNode *Rand = nullptr;
    string   Data;

public:
    ListNode() = default;

    explicit ListNode(string Data);
};

#endif //SABERINTERACTIVE_LISTNODE_H
