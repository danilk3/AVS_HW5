#include <iostream>
#include <vector>
#include <thread>
#include "Visitor/visitor.h"
#include "Painting/Painting.h"

// Method generate random painting for visitor.
void startLooking(Visitor visitor, std::vector<Painting *> paintings) {
    paintings[rand() % 5]->look(visitor);
}

// Creates paintings.
void createPaintings(std::vector<Painting *> &paintings) {
    std::string painting_names[5] = {"Mona Lisa", "The Last Supper", "The Starry Night", "The Scream", "Guernica"};
    std::string authors_names[5] = {"Leonardo da Vinci", "Leonardo da Vinci", "Vincent van Gogh", "Edvard Munch",
                                    "Pablo Picasso"};

    paintings.resize(5, nullptr);

    for (int i = 0; i < 5; ++i) {
        paintings[i] = new Painting(painting_names[i], authors_names[i]);
    }
}

// Method to generate visitors.
void enterVisitors(std::vector<Visitor *> &visitors) {
    int number_of_visitors = -1;
    while (number_of_visitors <= 0) {
        std::cout << "Please, enter number of visitors:  ";
        std::cin >> number_of_visitors;
        if (number_of_visitors <= 0) {
            std::cout << "Please, enter in a positive integer\n";
        }
    }

    visitors.resize(number_of_visitors, nullptr);

    for (int i = 0; i < number_of_visitors; ++i) {
        visitors[i] = new Visitor(i);
    }
}

int main() {
    std::cout << "Start of the program.\n";

    std::vector<Visitor *> visitors;
    std::vector<Painting *> paintings;
    std::vector<std::thread> threads_;

    createPaintings(paintings);

    enterVisitors(visitors);

    // Creating threads.
    for (Visitor *visitor: visitors) {
        std::thread state(startLooking, *visitor, paintings);
        threads_.push_back(std::move(state));
    }

    // joining threads.
    for (int i = 0; i < threads_.size(); ++i) {
        threads_[i].join();
    }

    std::cout << "\nEnd of the program.";

    return 0;
}
