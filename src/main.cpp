#include <iostream>
#include "types/ListRand.h"

int main() {
    { // Serialize & print
        // Generate test data
        ListNode node1("Node#1");
        ListNode node2("Node#2");
        ListNode node3("Node#3");
        ListNode node4("Node#4");
        ListNode node5("Node#5");
        node2.Rand = &node2;
        node3.Rand = &node5;
        node4.Rand = &node1;

        ListRand listRand;
        listRand.PushBack(&node1);
        listRand.PushBack(&node2);
        listRand.PushBack(&node3);
        listRand.PushBack(&node4);
        listRand.PushBack(&node5);

        // Print list
        std::cout << listRand << std::endl;

        { // Write to file
            fstream file("data.bin", ios::binary | ios::out);
            listRand.Serialize(file);
            file.close();
        }
    }

    { // Deserialize & print
        ListRand listRand;

        { // Read from file
            fstream file("data.bin", ios::binary | ios::in);
            listRand.Deserialize(file);
            file.close();
        }

        // Print list
        std::cout << listRand << std::endl;
    }

    return 0;
}