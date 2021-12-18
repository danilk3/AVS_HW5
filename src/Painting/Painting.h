//
// Created by dahil on 16.12.2021.
//

#ifndef AVS_HW5_PAINTING_H
#define AVS_HW5_PAINTING_H

#include "../Visitor/visitor.h"
#include <queue>

class Painting {
private:
    // Name of the painting.
    std::string name;
    // Author of the painting.
    std::string author;
    int number_of_visitors;
    std::mutex mtx;
public:
    Painting(std::string name, std::string author);

    std::string getName();

    std::string getAuthor();

    void look(Visitor &visitor);

    std::string display();
};


#endif //AVS_HW5_PAINTING_H
