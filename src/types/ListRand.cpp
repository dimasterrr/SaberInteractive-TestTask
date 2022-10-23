#include <iostream>
#include <iomanip>
#include <map>
#include <cassert>
#include "ListRand.h"

void ListRand::Serialize(fstream &fs) {
    assert(fs.good());

    // Write nodes count
    fs.write((char *) &Count, sizeof(Count));

    // Write nodes
    auto      TargetNode = Head;
    for (auto i          = 0; i < Count; ++i) {
        fs.write((char *) &TargetNode, sizeof(TargetNode));
        fs.write((char *) &TargetNode->Rand, sizeof(TargetNode->Rand));
        fs.write((char *) &TargetNode->Data, sizeof(TargetNode->Data));

        TargetNode = TargetNode->Next;
    }
}

void ListRand::Deserialize(fstream &fs) {
    assert(fs.good());

    // Internal mapper
    std::map<ListNode * /* From */, ListNode * /* To */>       OriginalMapper;
    std::map<ListNode * /* From */, ListNode * /* FromRand */> RandMapper;

    // Read nodes count
    auto TempCount = 0;
    fs.read((char *) &TempCount, sizeof(TempCount));

    // Read nodes
    for (auto i = 0; i < TempCount; ++i) {
        auto Node = new ListNode();

        ListNode *TempKey, *TempRand;
        fs.read((char *) &TempKey, sizeof(TempKey));
        fs.read((char *) &TempRand, sizeof(TempRand));
        fs.read((char *) &Node->Data, sizeof(Node->Data));

        // Save mappers
        OriginalMapper.emplace(TempKey, Node);
        if (TempRand) { RandMapper.emplace(TempKey, TempRand); }

        PushBack(Node);
    }

    for (auto Item: RandMapper) {
        OriginalMapper[Item.first]->Rand = OriginalMapper[Item.second];
    }
}

void ListRand::PushBack(ListNode *Node) {
    if (!Count) {
        Head = Node;
        Tail = Node;
    } else {
        Node->Prev = Tail;
        Tail->Next = Node;
        Tail = Node;
    }
    ++Count;
}

ostream &operator<<(ostream &out, const ListRand &list) {
    // Header
    cout << setw(20) << "Node*"
         << setw(20) << "Prev"
         << setw(20) << "Next"
         << setw(20) << "Rand"
         << setw(20) << "Data"
         << endl;

    // Data
    auto TargetNode = list.Head;
    while (TargetNode != nullptr) {
        out << setw(20) << TargetNode
            << setw(20) << TargetNode->Prev
            << setw(20) << TargetNode->Next
            << setw(20) << TargetNode->Rand
            << setw(20) << TargetNode->Data
            << endl;

        TargetNode = TargetNode->Next;
    }

    return out;
}
