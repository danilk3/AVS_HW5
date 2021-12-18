//
// Created by dahil on 16.12.2021.
//

#include <string>
#include "visitor.h"

Visitor::Visitor(int id) {
    this->id = id;
    this->number_of_viewed_pictures = 0;
}

void Visitor::viewPicture() {
    this->number_of_viewed_pictures += 1;
}

std::string Visitor::display() {
    std::string res = "Visitor: id = [" + std::to_string(id) + "]";
    return res;
}

