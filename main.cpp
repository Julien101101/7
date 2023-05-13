// Assignment 7 - Skip Lists

// Develop software to implement a dictionary using a skip list.
// Identify the output of pseudo random number generator that was
// used (true or false). Test all dictionary methods.
// After inputting the data
// • Output each level of the skip list
// • Output the size of the dictionary
// • Output the number of nodes in the dictionary
/*
18 Laguna Niguel
41 Mission Viejo
22 San Clemente
44 Irvine
Delete key 41
58 Lake Forest
32 San Diego
49 Anaheim
Delete key 58
31 Los Angeles
17 Orange
72 Palms Springs
41 Riverside
Delete key 72
19 Brea
60 Santa Ana
35 Tustin
103 Oceanside
11 La Jolla
18 Del Mar
22 Aliso Viejo
49 Laguna Beach
Delete key 41
42 Vista
49 San Diego
99 San Juan
29 Dana Point
88 El Segundo
41 San Clemente
62 Laguna Hills
44 Irvine
Delete key 41
Delete key 42
58 Lake Forest
32 San Diego
49 Anaheim
Delete key 58
31 Los Angeles
17 Orange
72 Palms Springs
41 Riverside
Delete key 72
19 Brea
60 Santa Ana
35 Tustin
103 Oceanside
11 La Jolla
18 Del Mar
22 Aliso Viejo
49 Laguna Beach
Delete key 41
42 Vista
49 San Diego
99 San Juan
29 Dana Point
88 El Segundo
41 San Clemente
62 Laguna Hills*/

#include <iostream>
using namespace std;

#include "skiplist.h"

int main()
{
    // Create a new skip list
    SkipList dict;

    // Insert some key-value pairs
    dict.insert(18, "Laguna Niguel");
    dict.insert(41, "Mission Viejo");
    dict.insert(22, "San Clemente");
    dict.insert(44, "Irvine");
    dict.remove(41);
    dict.insert(58, "Lake Forest");
    dict.insert(32, "San Diego");
    dict.insert(49, "Anaheim");
    dict.remove(58);
    dict.insert(31, "Los Angeles");
    dict.insert(17, "Orange");
    dict.insert(72, "Palms Springs");
    dict.insert(41, "Riverside");
    dict.remove(72);
    dict.insert(19, "Brea");
    dict.insert(60, "Santa Ana");
    dict.insert(35, "Tustin");
    dict.insert(103, "Oceanside");
    dict.insert(11, "La Jolla");
    dict.insert(18, "Del Mar");
    dict.insert(22, "Aliso Viejo");
    dict.insert(49, "Laguna Beach");
    dict.remove(41);
    dict.insert(42, "Vista");
    dict.insert(49, "San Diego");
    dict.insert(99, "San Juan");
    dict.insert(29, "Dana Point");
    dict.insert(88, "El Segundo");
    dict.insert(41, "San Clemente");
    dict.insert(62, "Laguna Hills");
    dict.insert(44, "Irvine");
    dict.remove(41);
    dict.remove(42);
    dict.insert(58, "Lake Forest");
    dict.insert(32, "San Diego");
    dict.insert(49, "Anaheim");
    dict.remove(58);
    dict.insert(31, "Los Angeles");
    dict.insert(17, "Orange");
    dict.insert(72, "Palms Springs");
    dict.insert(41, "Riverside");
    dict.remove(72);
    dict.insert(19, "Brea");
    dict.insert(60, "Santa Ana");
    dict.insert(35, "Tustin");
    dict.insert(103, "Oceanside");
    dict.insert(11, "La Jolla");
    dict.insert(18, "Del Mar");
    dict.insert(22, "Aliso Viejo");
    dict.insert(49, "Laguna Beach");
    dict.remove(41);
    dict.insert(42, "Vista");
    dict.insert(49, "San Diego");
    dict.insert(99, "San Juan");
    dict.insert(29, "Dana Point");
    dict.insert(88, "El Segundo");
    dict.insert(41, "San Clemente");
    dict.insert(62, "Laguna Hills");

    // Output each level of the skip list
    dict.print();

    // Output the size of the dictionary
    std::cout << "Size: " << dict.getSize() << std::endl;

    // Output the number of nodes in the dictionary
    std::cout << "Nodes: " << dict.getNumNodes() << std::endl;
};