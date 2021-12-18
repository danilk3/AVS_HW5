//
// Created by dahil on 16.12.2021.
//

#include <string>
#include <iostream>
#include <thread>
#include "Painting.h"
#include "../Visitor/visitor.h"


Painting::Painting(std::string name, std::string author) {
    this->name = name;
    this->author = author;
    this->number_of_visitors = 0;
}

std::string Painting::getAuthor() {
    return author;
}

std::string Painting::getName() {
    return name;
}

std::string Painting::display() {
    std::string res = "Painting: name = " + name + ", author = " + author;
    return res;
}

void Painting::look(Visitor &visitor) {
    std::cout << visitor.display() << " waiting in the queue to " << display() << "\n";

    std::cout << visitor.display() << " looks at the painting.\n";
    visitor.viewPicture();
    ++number_of_visitors;
    if (number_of_visitors >= 10) {
        mtx.lock();
    }

    std::cout << visitor.display() << " left the painting.\n";

    --number_of_visitors;
    mtx.unlock();
    std::this_thread::sleep_for(std::chrono::milliseconds(rand() % 1000 + 1000));
}

